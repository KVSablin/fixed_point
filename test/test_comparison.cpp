#include "pch.h"

TEST(Compare, Equal) {
	auto left = fixed_point<16>(1.525);
	auto right = fixed_point<16>(1.525);
	
	ASSERT_EQ(left, right);
	ASSERT_EQ(left, 1.525);
	ASSERT_EQ(1.525, right);
	ASSERT_EQ(fixed_point<8>(123), fixed_point<20>(123));
}

TEST(Compare, NotEqual) {
	auto left = fixed_point<16>(1.525);
	auto right = fixed_point<16>(1.53);
	
	ASSERT_NE(left, right);
	ASSERT_NE(left, 1.53);
	ASSERT_NE(1.525, right);
	ASSERT_NE(fixed_point<8>(123), fixed_point<20>(124));
}

TEST(Compare, Less) {
	auto first = fixed_point<16>(1.525);
	auto second = fixed_point<16>(1.53);
	
	ASSERT_LT(first, second);
	ASSERT_LT(first, 1.6);
	ASSERT_LT(-1.6, first);
	ASSERT_LT(fixed_point<8>(123), fixed_point<20>(124));
}

TEST(Compare, LessEqual) {
	auto first = fixed_point<16>(1.525);
	auto second = fixed_point<16>(1.53);

	ASSERT_LE(first, second);
	ASSERT_LE(first, 1.525);
	ASSERT_LE(1.525, first);
	ASSERT_LE(fixed_point<8>(123), fixed_point<20>(123));
}

TEST(Compare, Greate) {
	auto first = fixed_point<16>(1.525);
	auto second = fixed_point<16>(1.53);

	ASSERT_GT(second, first);
	ASSERT_GT(1.526, first);
	ASSERT_GT(first, -1.526);
	ASSERT_GT(fixed_point<8>(124), fixed_point<20>(123));
}

TEST(Compare, GreateEqual) {
	auto first = fixed_point<16>(1.525);
	auto second = fixed_point<16>(1.53);

	ASSERT_GE(second, first);
	ASSERT_GE(first, -1.525);
	ASSERT_GE(1.525, first);
	ASSERT_GE(fixed_point<8>(123), fixed_point<20>(123));
}