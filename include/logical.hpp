#pragma once
#include "operation.hpp"

//Template unary logical NOT
template<size_t Fract, class T>
constexpr bool operator!(const fixed_point<Fract, T>& Right) {
	return !static_cast<bool>(Right.value());
}

// Template binary logical AND
template<size_t Fract, class T>
constexpr bool operator&&(const fixed_point<Fract, T>& Left, const fixed_point<Fract, T>& Right) noexcept {
	return static_cast<bool>(Left) && static_cast<bool>(Right);
}

template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr bool operator&&(const Lhs& Left, const Rhs& Right) {
	return operation<std::logical_and<>>(Left, Right);
}

// Template binary logical OR
template<size_t Fract, class T>
constexpr bool operator||(const fixed_point<Fract, T>& Left, const fixed_point<Fract, T>& Right) noexcept {
	return static_cast<bool>(Left) || static_cast<bool>(Right);
}

template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr bool operator||(const Lhs& Left, const Rhs& Right) {
	return operation<std::logical_or<>>(Left, Right);
}