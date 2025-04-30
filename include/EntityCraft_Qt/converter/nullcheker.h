#pragma once

#include "sfinae.h"

#include <type_traits>

namespace EntityCraft {
namespace Helpers {

/**
 * Шаблонная функция которая обобщает работу с типами у которых есть функция isNull
 * @tparam T тип данных который нужно проверить на NULL
 * @return Возвращает true, если объект пустой, иначе false
 */
template<typename T,
    std::enable_if_t<SFINAE::has_is_null_v<T>, bool> = true>
bool isNull(const T& value, int)
{
    return value.isNull();
}

} // namespace Helpers
} // namespace EntityCraft
