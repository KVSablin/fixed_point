#pragma once
#include "operation.hpp"

// Template unary bitwise NOT
template<size_t Fract, class T>
constexpr fixed_point<Fract, T> operator~(const fixed_point<Fract, T>& Right) {
	fixed_point<Fract, T> Temp;
	Temp.value(~Right.value());
	return Temp;
}

// Template binary bitwise AND
template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr decltype(auto) operator&(const Lhs& Left, const Rhs& Right) {
	return operation<std::bit_and<>>(Left, Right);
}

// Template binary bitwise OR
template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr decltype(auto) operator|(const Lhs& Left, const Rhs& Right) {
	return operation<std::bit_or<>>(Left, Right);
}

// Template binary bitwise XOR
template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr auto operator^(const Lhs& Left, const Rhs& Right) {
	return operation<std::bit_xor<>>(Left, Right);
}