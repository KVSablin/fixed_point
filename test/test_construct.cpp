#include "pch.h"

// Test Pow2
static_assert(pow2<int8_t, 0>::result == 1, "pow2 test - #FAILED");
static_assert(pow2<float, 1>::result == 2., "pow2 test - #FAILED");
static_assert(pow2<int16_t, 3>::result == 8, "pow2 test - #FAILED");
static_assert(pow2<double, 10>::result == 1024., "pow2 test - #FAILED");
static_assert(pow2<int32_t, 20>::result == 1048576, "pow2 test - #FAILED");
static_assert(pow2<long double, 50>::result == 1125899906842624, "pow2 test - #FAILED");
static_assert(pow2<int64_t, 60>::result == 1152921504606846976, "pow2 test - #FAILED");


#define SS(message) static_assert(false, ##message)

TEST(Construct, Default) {
	fixed_point<16> x;
	ASSERT_EQ(x, 0);
}

TEST(Construct, RealType) {
	fixed_point<15> x(1.5);
	ASSERT_EQ(x.value(), 49152);
}

TEST(Construct, Copy) {
	auto left = fixed_point<10>(0.);
	auto right = fixed_point<10>(543.9);
	left = right;
	ASSERT_EQ(left, 543.9);
}

TEST(Construct, CopyOtherFixedPoint) {
	auto left = fixed_point<16, uint32_t>(0);
	auto right = fixed_point<10, uint16_t>(87.65);
	left = right;
	ASSERT_EQ(left, right);
}

TEST(CopyAssignment, FixedPoint) {
	auto left = fixed_point<16>(0);
	left = static_cast<fixed_point<16>>(123.45);
	ASSERT_EQ(left, fixed_point<16>(123.45));
}

TEST(CopyAssignment, RealType) {
	auto left = fixed_point<16, uint32_t>(0);
	left = 3.1415;
	ASSERT_EQ(left, 3.1415);
}

TEST(CopyAssignment, OtherFixedPoint) {
	auto left = fixed_point<16, uint32_t>(0);
	auto right = fixed_point<10, uint16_t>(87.65);
	left = right;
	ASSERT_EQ(left, right);
}