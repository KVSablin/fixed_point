#include "pch.h"

TEST(Bitwise, NOT) {
	fixed_point<16> x(3.141592);
	ASSERT_EQ((~x).value(), -205888);
}

TEST(Bitwise, AND) {
	auto left = fixed_point<12>(58.9);
	auto right = fixed_point<8>(24.836);
	ASSERT_EQ(left & right, 24.7734);
	ASSERT_EQ(left & 24.836, 24.7734);
}

TEST(Bitwise, OR) {
	auto left = fixed_point<12>(58.9);
	auto right = fixed_point<8>(24.836);
	ASSERT_EQ(left | right, 58.9625);
	ASSERT_EQ(left | 24.836, 58.9625);
}

TEST(Bitwise, XOR) {
	auto left = fixed_point<12>(58.9);
	auto right = fixed_point<8>(24.836);
	auto result = left ^ right;
	ASSERT_EQ(left ^ right, 34.189);
	ASSERT_EQ(left ^ 24.836, 34.189);
}

TEST(Bitwise, ShiftLeft) {
	auto left = fixed_point<8>(-7.125);
	auto result = left << 2;
	ASSERT_EQ(result, -28.5);
}

TEST(Bitwise, ShiftRight) {
	auto left = fixed_point<8>(150.0);
	auto result = left >> 4;
	ASSERT_EQ(result, 9.375);
}
