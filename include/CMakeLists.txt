cmake_minimum_required(VERSION 3.15)
project(fixed_point_lib VERSION 0.0.1)

add_library(${PROJECT_NAME} INTERFACE)
target_sources(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}/fixed_point.hpp
        ${PROJECT_SOURCE_DIR}/operation.hpp
        ${PROJECT_SOURCE_DIR}/arithmetic.hpp
        ${PROJECT_SOURCE_DIR}/bitwise.hpp
        ${PROJECT_SOURCE_DIR}/comparison.hpp
        ${PROJECT_SOURCE_DIR}/logical.hpp
        ${PROJECT_SOURCE_DIR}/make_fixed_point.hpp
        ${PROJECT_SOURCE_DIR}/type_traits.hpp
        ${PROJECT_SOURCE_DIR}/fixed_point
)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_14)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR})