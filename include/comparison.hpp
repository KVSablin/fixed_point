#pragma once
#include "operation.hpp"

// Template binary EQUAL to
template<size_t Fract, class T>
constexpr bool operator==(const fixed_point<Fract, T>& Left, const fixed_point<Fract, T>& Right) noexcept {
	return Left.value() == Right.value();
}

template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr bool operator==(const Lhs& Left, const Rhs& Right) {
	return operation<std::equal_to<>>(Left, Right);
}

// Template binary NOT EQUAL to
template<size_t Fract, class T>
constexpr bool operator!=(const fixed_point<Fract, T>& Left, const fixed_point<Fract, T>& Right) noexcept {
	return !(Left == Right);
}

template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr bool operator!=(const Lhs& Left, const Rhs& Right) {
	return operation<std::not_equal_to<>>(Left, Right);
}

// Template binary LESS than
template<size_t Fract, class T>
constexpr bool operator<(const fixed_point<Fract, T>& Left, const fixed_point<Fract, T>& Right) noexcept {
	return Left.value() < Right.value();
}

template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr bool operator<(const Lhs& Left, const Rhs& Right) {
	return operation<std::less<>>(Left, Right);
}

// Template binary GREATER than
template<size_t Fract, class T>
constexpr bool operator>(const fixed_point<Fract, T>& Left, const fixed_point<Fract, T>& Right) noexcept {
	return !(Left < Right);
}

template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr bool operator>(const Lhs& Left, const Rhs& Right) {
	return operation<std::greater<>>(Left, Right);
}

// Template binary LESS than or EQUAL to
template<size_t Fract, class T>
constexpr bool operator<=(const fixed_point<Fract, T>& Left, const fixed_point<Fract, T>& Right) noexcept {
	return Left.value() <= Right.value();
}

template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr bool operator<=(const Lhs& Left, const Rhs& Right) {
	return operation<std::less_equal<>>(Left, Right);
}

// Template binary GREATER than or EQUAL to
template<size_t Fract, class T>
constexpr bool operator>=(const fixed_point<Fract, T>& Left, const fixed_point<Fract, T>& Right) noexcept {
	return Left.value() >= Right.value();
}

template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr bool operator>=(const Lhs& Left, const Rhs& Right) {
	return operation<std::greater_equal<>>(Left, Right);
}
