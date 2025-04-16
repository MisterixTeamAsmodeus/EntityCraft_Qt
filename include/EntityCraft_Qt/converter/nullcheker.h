#pragma once

#include "sfinae.h"

#include <type_traits>

namespace EntityCraft {
namespace Helpers {

template<typename T,
    std::enable_if_t<SFINAE::has_is_null_v<T>, bool> = true>
bool isNull(const T& value, int)
{
    return value.isNull();
}

} // namespace Helpers
} // namespace EntityCraft
