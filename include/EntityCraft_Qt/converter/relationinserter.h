#pragma once

#include "sfinae.h"

#include <vector>

namespace EntityCraft {
namespace Impl {

/**
 * Шаблонная функция которая реализует вставку в контейнер через оператор <<
 * @tparam Container Тип контейнера поддерживающий вставку через оператор <<
 * @tparam Type Тип данных который нужно вставить в контейнер
 * @param relation_property Объект контейнера в который нужно вставить данные
 * @param result Массив данных которые нужно вставить в контейнер
 */
template<typename Container, typename Type,
    std::enable_if_t<SFINAE::has_left_shift_operator_v<Container, Type>, bool> = true>
void insertInRelationProperty(Container& relation_property, const std::vector<Type>& result, int)
{
    for(const auto& value : result) {
        relation_property << value;
    }
}

} // namespace Impl
} // namespace EntityCraft