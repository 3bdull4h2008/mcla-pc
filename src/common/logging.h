#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <fmt/format.h>
#include <string>
#include <memory>
#include <mutex>

namespace mcla::log {

enum class Level : int {
    Trace = 0,
    Debug = 1,
    Info = 2,
    Warn = 3,
    Error = 4,
    Critical = 5,
    Off = 6
};

inline void Initialize(const char* appName = "mcla", Level level = Level::Info, const char* logFile = nullptr) {
    static std::once_flag initFlag;
    std::call_once(initFlag, [&]() {
        auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        consoleSink->set_pattern("[%H:%M:%S.%e] [%^%l%$] %v");

        std::vector<spdlog::sink_ptr> sinks = {consoleSink};

        if (logFile) {
            try {
                auto fileSink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
                    logFile, 1024 * 1024 * 10, 5);
                fileSink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v");
                sinks.push_back(fileSink);
            } catch (...) {
            }
        }

        auto logger = std::make_shared<spdlog::logger>("mcla", sinks.begin(), sinks.end());
        logger->set_level(static_cast<spdlog::level::level_enum>(static_cast<int>(level)));
        logger->flush_on(spdlog::level::warn);
        spdlog::set_default_logger(logger);
        spdlog::set_pattern("[%H:%M:%S.%e] [%^%l%$] %v");
    });
}

inline void SetLevel(Level level) {
    if (auto logger = spdlog::default_logger()) {
        logger->set_level(static_cast<spdlog::level::level_enum>(static_cast<int>(level)));
    }
}

inline void Shutdown() {
    spdlog::shutdown();
}

template<typename... Args>
inline void Trace(fmt::format_string<Args...> fmt, Args&&... args) {
    SPDLOG_TRACE(fmt, std::forward<Args>(args)...);
}

template<typename... Args>
inline void Debug(fmt::format_string<Args...> fmt, Args&&... args) {
    SPDLOG_DEBUG(fmt, std::forward<Args>(args)...);
}

template<typename... Args>
inline void Info(fmt::format_string<Args...> fmt, Args&&... args) {
    SPDLOG_INFO(fmt, std::forward<Args>(args)...);
}

template<typename... Args>
inline void Warn(fmt::format_string<Args...> fmt, Args&&... args) {
    SPDLOG_WARN(fmt, std::forward<Args>(args)...);
}

template<typename... Args>
inline void Error(fmt::format_string<Args...> fmt, Args&&... args) {
    SPDLOG_ERROR(fmt, std::forward<Args>(args)...);
}

template<typename... Args>
inline void Critical(fmt::format_string<Args...> fmt, Args&&... args) {
    SPDLOG_CRITICAL(fmt, std::forward<Args>(args)...);
}

} // namespace mcla::log

#define MCLA_LOG_TRACE(...)  mcla::log::Trace(__VA_ARGS__)
#define MCLA_LOG_DEBUG(...)  mcla::log::Debug(__VA_ARGS__)
#define MCLA_LOG_INFO(...)   mcla::log::Info(__VA_ARGS__)
#define MCLA_LOG_WARN(...)   mcla::log::Warn(__VA_ARGS__)
#define MCLA_LOG_ERROR(...)  mcla::log::Error(__VA_ARGS__)
#define MCLA_LOG_CRITICAL(...) mcla::log::Critical(__VA_ARGS__)