#pragma once

#include "sfinae.h"

#include <vector>

namespace EntityCraft {
namespace Impl {

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