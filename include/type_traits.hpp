#pragma once
#include "fixed_point.hpp"

template<size_t Lhs, size_t Rhs>
struct common_fract {
	constexpr static size_t value = Lhs > Rhs ? Lhs : Rhs;
};

template<size_t LhsFract, class LhsT, size_t RhsFract, class RhsT>
struct common_fixed_point_type {
	using type = fixed_point<common_fract<LhsFract, RhsFract>::value, std::common_type_t<LhsT, RhsT>>;
};

template<size_t LhsFract, class LhsT, size_t RhsFract, class RhsT>
using common_fixed_point_t = typename common_fixed_point_type<LhsFract, LhsT, RhsFract, RhsT>::type;

template<class T>
struct is_fixed_point : public std::false_type {};

template<size_t Fract, class T>
struct is_fixed_point<fixed_point<Fract, T>> : public std::true_type {};

template<class T>
constexpr bool is_fixed_point_v = is_fixed_point<T>::value;

namespace std {
	template<size_t Fract, class T>
	struct is_signed<fixed_point<Fract, T>> {
		constexpr static bool value = std::is_signed_v<T>;
	};

	template<size_t Fract, class T>
	struct is_unsigned<fixed_point<Fract, T>> {
		constexpr static bool value = std::is_unsigned_v<T>;
	};
}
