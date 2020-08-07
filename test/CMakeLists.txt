
add_executable(fp_test main.cpp)
target_sources(fp_test
    PRIVATE
        test_construct.cpp
        test_arithmetic.cpp
        test_bitwise.cpp
        test_comparison.cpp
        test_logical.cpp
        test_math.cpp
        pch.h
)

target_link_libraries(fp_test
    PRIVATE
        fixed_point_lib
        gtest
)

target_include_directories(fp_test PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_test(
    NAME fp_test
    COMMAND test
)
