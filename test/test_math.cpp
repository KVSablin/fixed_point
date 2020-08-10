#include "pch.h"

TEST(Math, Abs) {
	ASSERT_EQ(abs(fixed_point<16>(-1.25)), 1.25);
	ASSERT_EQ(abs(fixed_point<16>(0.1)), 0.1);
}

TEST(Math, Sqrt) {
	ASSERT_EQ(sqrt(fixed_point<11>(121.0)), 11.);
	ASSERT_THROW(sqrt(fixed_point<11>(-1.0)), std::invalid_argument);
}

TEST(Math, Pow) {
	ASSERT_EQ(pow(fixed_point<8>(4.0), -2), 0.0625);
	ASSERT_EQ(pow(fixed_point<8>(2.0), 0), 1.0);
	ASSERT_EQ(pow(fixed_point<8>(2.0), 2), 4.0);
	ASSERT_EQ(pow(fixed_point<8>(7.5), 3), 421.875);
}