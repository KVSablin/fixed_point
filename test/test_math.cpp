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
	
}
