#pragma once
#include "fixed_point.hpp"
#include <stdexcept>
#include <cmath>

template<size_t Fract, class T>
constexpr decltype(auto) abs(const fixed_point<Fract, T>& X) noexcept {
	return X >= 0 ? X : -X;
}

template<size_t Fract, class T>
constexpr decltype(auto) sqrt(const fixed_point<Fract, T>& X) {
	using base_type = typename fixed_point<Fract, T>::value_type;
	using limits = std::numeric_limits<fixed_point<Fract, T>>;
	using extended_type = fixed_point<
		limits::fractional * 2,
		typename get_fixed_point_base_type<limits::integer * 2, limits::fractional * 2>::unsigned_type
	>;

	if (X < 0)
		throw std::invalid_argument("Cannot square root of negative value");

	base_type Bit = base_type(1) << (std::numeric_limits<base_type>::digits + std::is_signed_v<base_type> -2);
	auto Value = extended_type(X).value();
	while (Bit > Value)
		Bit >>= 2;

	base_type Result = 0;
	for (; Bit != 0; Bit >>= 2)
	{
		const auto Sum = Result + Bit;
		Result >>= 1;
		if (Value >= Sum)
		{
			Value -= Sum;
			Result += Bit;
		}
	}

	fixed_point<Fract, T> Temp;
	Temp.value(Result);
	return Temp;
}