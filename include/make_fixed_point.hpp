#pragma once
#include "fixed_point.hpp"

template<size_t IntDigits, size_t FractDigits>
struct get_fixed_point_base_type {
	using signed_type =
		std::conditional_t<((IntDigits + FractDigits) > std::numeric_limits<int32_t>::digits), std::int64_t,
		std::conditional_t<((IntDigits + FractDigits) > std::numeric_limits<int16_t>::digits), std::int32_t,
		std::conditional_t<((IntDigits + FractDigits) > std::numeric_limits<int8_t>::digits), std::int16_t,
		std::int8_t>>
	>;

	using unsigned_type =
		std::conditional_t<((IntDigits + FractDigits) > std::numeric_limits<int32_t>::digits), std::uint64_t,
		std::conditional_t<((IntDigits + FractDigits) > std::numeric_limits<int16_t>::digits), std::uint32_t,
		std::conditional_t<((IntDigits + FractDigits) > std::numeric_limits<int8_t>::digits), std::uint16_t,
		std::int8_t>>
	>;
};

// Template make_fixed_point
template<size_t FractDigits, class Other>
constexpr decltype(auto) make_fixed_point(Other&& Value) noexcept {
	return fixed_point<FractDigits>(std::forward<Other>(Value));
}

template<size_t IntDigits, size_t FractDigits, class Other>
constexpr decltype(auto) make_fixed_point(Other&& Value) noexcept {
	using fixed_point_type = fixed_point<FractDigits, typename get_fixed_point_base_type<IntDigits, FractDigits>::signed_type>;
	return fixed_point_type(std::forward<Other>(Value));
}

// Template make_ufixed_point
template<size_t FractDigits, class Other>
constexpr decltype(auto) make_ufixed_point(Other&& Value) noexcept {
	return fixed_point<FractDigits, std::make_unsigned_t<int32_t>>(std::forward<Other>(Value));
}

template<size_t IntDigits, size_t FractDigits, class Other>
constexpr decltype(auto) make_ufixed_point(Other&& Value) noexcept {
	using ufixed_point_type = fixed_point<FractDigits, typename get_fixed_point_base_type<IntDigits, FractDigits>::unsigned_type>;
	return ufixed_point_type(std::forward<Other>(Value));
}
