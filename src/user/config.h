#pragma once

#include <cstdint>

enum class ELanguage : uint32_t
{
    English = 1,
    Japanese,
    German,
    French,
    Spanish,
    Italian
};

namespace Config
{
    inline ELanguage Language = ELanguage::English;
}