#pragma once
#include <cstdint>
#include <type_traits>
#include <limits>
#include <cassert>

// Struct template 2^Exp
template<class T, int Exp>
struct pow2 {
	constexpr static T result = static_cast<T>(2)* pow2<T, Exp - 1>::result;
};

template<class T>
struct pow2<T, 0> {
	constexpr static T result = 1;
};

template<size_t Fract, class T = std::int32_t>
class fixed_point;

// Class template numeric_limits
namespace std {
	template<size_t Fract, class T>
	struct numeric_limits<fixed_point<Fract, T>> : public std::numeric_limits<T> {

		using base = std::numeric_limits<T>;
		using fixed_point_type = fixed_point<Fract, T>;
		using value_type = typename fixed_point_type::value_type;
		
		_NODISCARD static constexpr value_type min() noexcept {
			return base::min() >> fractional;
		}

		_NODISCARD static constexpr value_type max() noexcept {
			return base::max() >> fractional;
		}

		static constexpr int fractional = Fract;
		static constexpr int integer = base::digits - fractional;
		static constexpr value_type scale = pow2<value_type, Fract>::result;
	};
}

// Class template fixed_point
template<size_t Fract, class T>
class fixed_point {
public:
	using value_type = T;
	using numeric_limits = std::numeric_limits<fixed_point>;

	static_assert(std::is_integral_v<value_type>, "T - template parameter must be an integer type");
	
protected:
	template<class From, std::enable_if_t<std::is_integral_v<From>, int> Dummy = 0>
	value_type Cast(const From& Value) const noexcept {
		return static_cast<value_type>(Value << numeric_limits::fractional);
	}

	template<class From, std::enable_if_t<std::is_floating_point_v<From>, int> Dummy = 0>
	value_type Cast(const From& Value) const noexcept {
		return static_cast<value_type>(std::round(Value * numeric_limits::scale));
	}

	template<size_t RhsFract, class RhsT, std::enable_if_t<(Fract-RhsFract) >= 0, int> Dummy = 0>
	void Copy(const fixed_point<RhsFract, RhsT>& Right) {
		_value = static_cast<value_type>(Right.value()) << (Fract - RhsFract);
	}

	template<size_t RhsFract, class RhsT, std::enable_if_t<(Fract - RhsFract) < 0, int> Dummy = 0>
	void Copy(const fixed_point<RhsFract, RhsT>& Right) {
		_value = static_cast<value_type>(Right.value() >> (RhsFract - Fract));
	}

public:
	fixed_point() = default;
	
	template<class Other>
	constexpr fixed_point(const Other& Value) noexcept
		: _value(Cast(Value))
	{
	}

	template<size_t RhsFract, class RhsT>
	constexpr fixed_point(const fixed_point<RhsFract, RhsT>& Right) {
		Copy(Right);
	}

	~fixed_point() = default;

	template<size_t RhsFract, class RhsT>
	fixed_point& operator=(const fixed_point<RhsFract, RhsT>& Right) {
		Copy(Right);
		return *this;
	}

	template<class Other>
	fixed_point& operator=(const Other& Value) {
		_value = Cast(Value);
		return *this;
	}

	// Arithmetic operators ADD
	fixed_point& operator+=(const fixed_point& Right) {
		_value += Right.value();
		return *this;
	}
	
	fixed_point operator+(const fixed_point& Right) const noexcept {
		fixed_point Temp(*this);
		return Temp += Right;
	}

	// Arithmetic operators SUB
	fixed_point& operator-=(const fixed_point& Right) {
		_value -= Right.value();
		return *this;
	}

	fixed_point operator-(const fixed_point& Right) const noexcept {
		fixed_point Temp(*this);
		return Temp -= Right;
	}

	// Arithmetic operators MPY
	fixed_point& operator*=(const fixed_point& Right) {
		using type = decltype(_value * Right.value());
		type Temp = static_cast<type>(_value) * Right.value();
		_value = static_cast<value_type>(Temp / numeric_limits::scale);
		return *this;
	}

	fixed_point operator*(const fixed_point& Right) const noexcept {
		fixed_point Temp(*this);
		return Temp *= Right;
	}

	// Arithmetic operators DIV
	fixed_point& operator/=(const fixed_point& Right) {
		using type = decltype(_value * Right.value());
		type Temp = static_cast<type>(_value) * numeric_limits::scale;
		_value = static_cast<value_type>(Temp / Right.value());
		return *this;
	}

	fixed_point operator/(const fixed_point& Right) const noexcept {
		fixed_point Temp(*this);
		return Temp /= Right;
	}

	// Arithmetic operators MOD
	fixed_point& operator%=(const fixed_point& Right) noexcept {
		_value %= Right.value();
		return *this;
	}

	fixed_point operator%(const fixed_point& Right) const noexcept {
		fixed_point Temp(*this);
		return Temp %= Right;
	}

	// Bitwise operators AND
	fixed_point& operator&=(const fixed_point& Right) noexcept {
		_value &= Right.value();
		return *this;
	}

	fixed_point operator&(const fixed_point& Right) const noexcept {
		fixed_point Temp(*this);
		return Temp &= Right;
	}

	// Bitwise operators OR
	fixed_point& operator|=(const fixed_point& Right) noexcept {
		_value |= Right.value();
		return *this;
	}

	fixed_point operator|(const fixed_point& Right) const noexcept {
		auto Temp(*this);
		return Temp |= Right;
	}

	// Bitwise operators XOR
	fixed_point& operator^=(const fixed_point& Right) noexcept {
		_value ^= Right.value();
		return *this;
	}

	fixed_point operator^(const fixed_point& Right) const noexcept {
		fixed_point Temp(*this);
		return Temp ^= Right;
	}

	// Bitwise operators SHIFT LEFT
	fixed_point& operator<<=(const int& Right) noexcept {
		_value <<= Right;
		return *this;
	}

	fixed_point operator<<(const int& Right) const noexcept {
		fixed_point Temp(*this);
		return Temp <<= Right;
	}

	// Bitwise operators SHIFT RIGHT
	fixed_point& operator>>=(const int& Right) noexcept {
		_value >>= Right;
		return *this;
	}

	fixed_point operator>>(const int& Right) const noexcept {
		fixed_point Temp(*this);
		return Temp >>= Right;
	}

	// Cast operators
	constexpr explicit operator bool() const noexcept {
		return static_cast<bool>(_value);
	}

	template<class To, class = std::enable_if_t<std::is_convertible_v<value_type, To>>>
	constexpr operator To() const noexcept {
		using type = std::conditional_t<std::is_integral_v<To>, std::common_type_t<To, value_type>, To>;
		return static_cast<To>(static_cast<type>(_value) / numeric_limits::scale);
	}

	// Access methods
	value_type value() const noexcept {
		return _value;
	}

	void value(const value_type& Value) noexcept {
		_value = Value;
	}

private:
	value_type _value = 0;
};