#pragma once

#include <type_traits>

template<typename Int,
         typename = std::enable_if_t<std::is_integral<Int>::value>>
constexpr std::size_t intLength(Int value) {
    return (value / 10 != 0) ? (intLength(value / 10) + 1) : (1);
}
