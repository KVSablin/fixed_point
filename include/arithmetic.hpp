#pragma once
#include "operation.hpp"

// Template unary PLUS
template<size_t Fract, class T>
constexpr auto operator+(const fixed_point<Fract, T>& Right) {
	using result_type = decltype(+Right.value());
	fixed_point<Fract, result_type> Temp;
	Temp.value(+Right.value());
	return Temp;
}

// Template unary MINUS
template<size_t Fract, class T>
constexpr auto operator-(const fixed_point<Fract, T>& Right) {
	using result_type = decltype(-Right.value());
	fixed_point<Fract, result_type> Temp;
	Temp.value(-Right.value());
	return Temp;
}

// Template binary ADDITION
template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr auto operator+(const Lhs& Left, const Rhs& Right) {
	return operation<std::plus<>>(Left, Right);
}

// Template binary SUBTRACTION
template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr auto operator-(const Lhs& Left, const Rhs& Right) {
	return operation<std::minus<>>(Left, Right);
}

// Template binary MULTIPLIES
template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr auto operator*(const Lhs& Left, const Rhs& Right) {
	return operation<std::multiplies<>>(Left, Right);
}

// Template binary DIVIDES
template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr auto operator/(const Lhs& Left, const Rhs& Right) {
	return operation<std::divides<>>(Left, Right);
}

// Template binary MODULUS
template<class Lhs, class Rhs, class = enable_if_fixed_point<Lhs, Rhs>>
constexpr auto operator%(const Lhs& Left, const Rhs& Right) {
	return operation<std::modulus<>>(Left, Right);
}
