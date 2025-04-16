#pragma once
#include <type_traits>

namespace EntityCraft {
namespace SFINAE {

// Структура для проверки наличия оператора emplace_back
template<typename T, typename = void>
struct has_is_null : std::false_type
{
};

template<typename T>
struct has_is_null<T, std::void_t<decltype(std::declval<T>().isNull())>>
    : std::true_type
{
};

template<typename T>
constexpr bool has_is_null_v = has_is_null<T>::value;

} // namespace SFINAE
} // namespace EntityCraft