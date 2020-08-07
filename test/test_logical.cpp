#include "pch.h"

TEST(Logical, NOT) {
	ASSERT_TRUE(!fixed_point<10>(0.0));
	ASSERT_FALSE(!fixed_point<10>(.01));
	ASSERT_FALSE(!fixed_point<10>(-.01));
}

TEST(Logical, AND) {
	ASSERT_FALSE(fixed_point<8>(0) && fixed_point<16>(0.1));
	ASSERT_FALSE(fixed_point<8>(0) && 3.1415);
	ASSERT_FALSE(3.1415 && fixed_point<8>(0));

	ASSERT_TRUE(fixed_point<8>(-0.1) && fixed_point<16>(0.1));
	ASSERT_TRUE(fixed_point<8>(-0.1) && 3.1415);
	ASSERT_TRUE(3.1415 && fixed_point<8>(-0.1));
}


TEST(Logical, OR) {
	ASSERT_TRUE(fixed_point<8>(-0.1) || fixed_point<16>(0.1));
	ASSERT_TRUE(fixed_point<8>(0.0) || fixed_point<16>(0.1));
	ASSERT_TRUE(fixed_point<8>(0) || 3.1415);
	ASSERT_TRUE(3.1415 || fixed_point<8>(0));
	
	ASSERT_FALSE(fixed_point<8>(0.0) || fixed_point<16>(0.0));
	ASSERT_FALSE(fixed_point<8>(0.0) || 0.0);
	ASSERT_FALSE(0.0 || fixed_point<8>(0.0));
}