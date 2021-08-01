cmake_minimum_required(VERSION 3.10)

project("Quadratic equation")

set(CMAKE_CXX_STANDARD 14)

set(
    SOURCES

    src/Main.cpp
    src/QuadraticEquation.cpp
    src/QuadraticEquationSolver.cpp
)

add_executable(QuadraticEquation ${SOURCES})
target_include_directories(QuadraticEquation PRIVATE src)
