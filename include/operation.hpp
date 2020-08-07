#pragma once
#include "fixed_point.hpp"
#include "type_traits.hpp"
#include <functional>

template<class Lhs, class Rhs>
using enable_if_fixed_point = std::enable_if_t<is_fixed_point_v<Lhs> || is_fixed_point_v<Rhs>>;

template<class Operator, class Other, size_t Fract, class T,
	class = std::enable_if_t<!is_fixed_point_v<Other>>
>constexpr decltype(auto) operation(const fixed_point<Fract, T>& Left, const Other& Right) {
	return Operator()(Left, fixed_point<Fract, T>(Right));
}

template<class Operator, class Other, size_t Fract, class T,
	class = std::enable_if_t<!is_fixed_point_v<Other>>
>constexpr decltype(auto) operation(const Other& Left, const fixed_point<Fract, T>& Right) {
	return Operator()(fixed_point<Fract, T>(Left), Right);
}

template<class Operator, size_t LhsFract, class LhsT, size_t RhsFract, class RhsT>
constexpr decltype(auto) operation(const fixed_point<LhsFract, LhsT>& Left, const fixed_point<RhsFract, RhsT>& Right) {
	using result_type = common_fixed_point_t<LhsFract, LhsT, RhsFract, RhsT>;
	return Operator()(result_type(Left), result_type(Right));
}