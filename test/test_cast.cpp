#include "pch.h"

TEST(Cast, Bool) {
	fixed_point<14> first(0.0);
	ASSERT_EQ(static_cast<bool>(first), false);
	fixed_point<4> second(3252.24);
	ASSERT_EQ(static_cast<bool>(second), true);
}

TEST(Cast, Template) {
	const double PI = 3.14159265358979323846;
	fixed_point<50, int64_t> pi(PI);

	ASSERT_EQ(static_cast<int>(pi), 3);
	ASSERT_FLOAT_EQ(static_cast<float>(pi), static_cast<float>(PI));
	ASSERT_DOUBLE_EQ(static_cast<double>(pi), PI);
}