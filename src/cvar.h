#pragma once

#include <string>
#include <string_view>
#include <unordered_map>
#include <mutex>
#include <optional>
#include <filesystem>
#include <fstream>
#include <sstream>

namespace mcla::cvar {

class CVarSystem {
public:
    static CVarSystem& Instance() {
        static CVarSystem instance;
        return instance;
    }

    void RegisterString(const char* name, const char* defaultValue, const char* category, const char* description) {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_cvars.find(name) == m_cvars.end()) {
            m_cvars[name] = {defaultValue, category, description};
        }
    }

    void RegisterInt(const char* name, int defaultValue, const char* category, const char* description) {
        RegisterString(name, std::to_string(defaultValue).c_str(), category, description);
    }

    void RegisterBool(const char* name, bool defaultValue, const char* category, const char* description) {
        RegisterString(name, defaultValue ? "true" : "false", category, description);
    }

    void RegisterFloat(const char* name, float defaultValue, const char* category, const char* description) {
        RegisterString(name, std::to_string(defaultValue).c_str(), category, description);
    }

    std::string_view GetString(const char* name) const {
        std::lock_guard<std::mutex> lock(m_mutex);
        auto it = m_cvars.find(name);
        if (it != m_cvars.end()) {
            return it->second.value;
        }
        return "";
    }

    int GetInt(const char* name) const {
        auto str = GetString(name);
        if (str.empty()) return 0;
        try { return std::stoi(std::string(str)); } catch (...) { return 0; }
    }

    bool GetBool(const char* name) const {
        auto str = GetString(name);
        return str == "true" || str == "1" || str == "yes" || str == "on";
    }

    float GetFloat(const char* name) const {
        auto str = GetString(name);
        if (str.empty()) return 0.0f;
        try { return std::stof(std::string(str)); } catch (...) { return 0.0f; }
    }

    bool SetString(const char* name, std::string_view value) {
        std::lock_guard<std::mutex> lock(m_mutex);
        auto it = m_cvars.find(name);
        if (it != m_cvars.end()) {
            it->second.value = value;
            return true;
        }
        return false;
    }

    bool SetInt(const char* name, int value) {
        return SetString(name, std::to_string(value));
    }

    bool SetBool(const char* name, bool value) {
        return SetString(name, value ? "true" : "false");
    }

    bool SetFloat(const char* name, float value) {
        return SetString(name, std::to_string(value));
    }

    void LoadConfig(const std::filesystem::path& path) {
        std::ifstream file(path);
        if (!file.is_open()) return;

        std::string line;
        while (std::getline(file, line)) {
            // Skip comments and empty lines
            size_t start = line.find_first_not_of(" \t");
            if (start == std::string::npos || line[start] == '#') continue;

            // Parse key=value
            size_t eq = line.find('=', start);
            if (eq == std::string::npos) continue;

            std::string key = line.substr(start, eq - start);
            // Trim trailing whitespace from key
            while (!key.empty() && std::isspace(key.back())) key.pop_back();

            std::string value = line.substr(eq + 1);
            // Trim leading/trailing whitespace from value
            size_t vstart = value.find_first_not_of(" \t");
            if (vstart != std::string::npos) {
                value = value.substr(vstart);
                while (!value.empty() && std::isspace(value.back())) value.pop_back();
            }

            SetString(key.c_str(), value);
        }
    }

    void SaveConfig(const std::filesystem::path& path) const {
        std::ofstream file(path);
        if (!file.is_open()) return;

        std::lock_guard<std::mutex> lock(m_mutex);
        for (const auto& [name, cvar] : m_cvars) {
            file << name << " = " << cvar.value << "\n";
        }
    }

private:
    struct CVar {
        std::string value;
        std::string category;
        std::string description;
    };

    std::unordered_map<std::string, CVar> m_cvars;
    mutable std::mutex m_mutex;

    CVarSystem() = default;
    ~CVarSystem() = default;
    CVarSystem(const CVarSystem&) = delete;
    CVarSystem& operator=(const CVarSystem&) = delete;
};

// Macro helpers for registration
#define MCLA_CVAR_STRING(name, default_val, category, desc) \
    namespace { \
        struct CVarRegistrar_##name { \
            CVarRegistrar_##name() { \
                mcla::cvar::CVarSystem::Instance().RegisterString(#name, default_val, category, desc); \
            } \
        } g_cvar_registrar_##name; \
    }

#define MCLA_CVAR_INT(name, default_val, category, desc) \
    namespace { \
        struct CVarRegistrar_##name { \
            CVarRegistrar_##name() { \
                mcla::cvar::CVarSystem::Instance().RegisterInt(#name, default_val, category, desc); \
            } \
        } g_cvar_registrar_##name; \
    }

#define MCLA_CVAR_BOOL(name, default_val, category, desc) \
    namespace { \
        struct CVarRegistrar_##name { \
            CVarRegistrar_##name() { \
                mcla::cvar::CVarSystem::Instance().RegisterBool(#name, default_val, category, desc); \
            } \
        } g_cvar_registrar_##name; \
    }

#define MCLA_CVAR_FLOAT(name, default_val, category, desc) \
    namespace { \
        struct CVarRegistrar_##name { \
            CVarRegistrar_##name() { \
                mcla::cvar::CVarSystem::Instance().RegisterFloat(#name, default_val, category, desc); \
            } \
        } g_cvar_registrar_##name; \
    }

// Getters
#define MCLA_CVAR_GET_STRING(name) mcla::cvar::CVarSystem::Instance().GetString(#name)
#define MCLA_CVAR_GET_INT(name) mcla::cvar::CVarSystem::Instance().GetInt(#name)
#define MCLA_CVAR_GET_BOOL(name) mcla::cvar::CVarSystem::Instance().GetBool(#name)
#define MCLA_CVAR_GET_FLOAT(name) mcla::cvar::CVarSystem::Instance().GetFloat(#name)

// Compatibility macros for existing REXCVAR_* usage
#define REXCVAR_DEFINE_STRING(name, default_val, category, desc) MCLA_CVAR_STRING(name, default_val, category, desc)
#define REXCVAR_DEFINE_INT(name, default_val, category, desc) MCLA_CVAR_INT(name, default_val, category, desc)
#define REXCVAR_DEFINE_BOOL(name, default_val, category, desc) MCLA_CVAR_BOOL(name, default_val, category, desc)
#define REXCVAR_DEFINE_FLOAT(name, default_val, category, desc) MCLA_CVAR_FLOAT(name, default_val, category, desc)

#define REXCVAR_GET(name) MCLA_CVAR_GET_STRING(name)
#define REXCVAR_GET_INT(name) MCLA_CVAR_GET_INT(name)
#define REXCVAR_GET_BOOL(name) MCLA_CVAR_GET_BOOL(name)
#define REXCVAR_GET_FLOAT(name) MCLA_CVAR_GET_FLOAT(name)

#define REXCVAR_DECLARE(type, name) extern type REXCVAR_GET_##name()