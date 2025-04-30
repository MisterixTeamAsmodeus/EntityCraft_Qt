#pragma once
#include <type_traits>

namespace EntityCraft {
namespace SFINAE {

/// Структура для проверки наличия оператора isNull
template<typename T, typename = void>
struct has_is_null : std::false_type
{
};

/// Структура для проверки наличия оператора isNull
template<typename T>
struct has_is_null<T, std::void_t<decltype(std::declval<T>().isNull())>>
    : std::true_type
{
};

/// Результат проверки наличия оператора isNull
template<typename T>
constexpr bool has_is_null_v = has_is_null<T>::value;

/// Структура для проверки наличия оператора <<
template<typename Container, typename T, typename = void>
struct has_left_shift_operator : std::false_type
{
};

/// Структура для проверки наличия оператора <<
template<typename Container, typename T>
struct has_left_shift_operator<Container, T, std::void_t<decltype((std::declval<Container&>() << std::declval<T>()))>>
    : std::true_type
{
};

/// Результат проверки наличия оператора <<
template<typename Container, typename T>
constexpr bool has_left_shift_operator_v = has_left_shift_operator<Container, T>::value;

} // namespace SFINAE
} // namespace EntityCraft