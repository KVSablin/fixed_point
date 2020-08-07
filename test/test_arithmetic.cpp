#include "pch.h"

TEST(Arithmetic, Plus) {
	auto x = fixed_point<10>(-59.55);
	auto result = +x;
	ASSERT_EQ(result, -59.55);
}

TEST(Arithmetic, Minus) {
	auto x = fixed_point<10>(-59.55);
	auto result = -x;
	ASSERT_EQ(result, 59.55);
}

TEST(Arithmetic, Add) {
	auto x = fixed_point<8>(-59.55);
	auto result = x + 80.45;
	ASSERT_EQ(result, 20.9);

	result += decltype(x)(10.1);
	ASSERT_EQ(result, 31.0);

	auto result2 = result + fixed_point<20, int64_t>(-30.75);
	ASSERT_EQ(result2, 0.25);
}

TEST(Arithmetic, Sub) {
	auto x = fixed_point<8>(7.98);
	auto result = x - 0.98;
	ASSERT_EQ(result, 7.);

	result -= decltype(x)(-5.25);
	ASSERT_EQ(result, 12.25);

	auto result2 = result - fixed_point<20, int64_t>(25.125);
	ASSERT_EQ(result2, -12.875);
}

TEST(Arithmetic, Mpy) {
	auto x = fixed_point<8>(7.25);
	auto result = x * (-2.5);
	ASSERT_EQ(result, -18.125);

	result *= decltype(x)(-0.5);
	ASSERT_EQ(result, 9.0625);

	auto result2 = result * fixed_point<20, int64_t>(14.5);
	ASSERT_EQ(result2, 131.40625);
}

TEST(Arithmetic, Div) {
	auto x = fixed_point<8>(88.5);
	auto result = x / (2.);
	ASSERT_EQ(result, 44.25);

	result /= decltype(x)(-0.75);
	ASSERT_EQ(result, -59.);

	auto result2 = result / fixed_point<20, int64_t>(-0.25);
	ASSERT_EQ(result2, 236.);
}

TEST(Arithmetic, Mod) {
	auto x = fixed_point<8>(1250.);
	auto result = x % (512);
	
	ASSERT_EQ(result, 226);

	result %= decltype(x)(13.5);
	ASSERT_EQ(result, 10.);

	auto result2 = result % fixed_point<20, int64_t>(2.0);
	ASSERT_EQ(result2, 0.);
}
