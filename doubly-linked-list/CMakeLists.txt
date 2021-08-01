cmake_minimum_required(VERSION 3.10)

project("Doubly linked list")

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(tests)
add_subdirectory(example)

enable_testing()
add_test(NAME UnitTests COMMAND UnitTests)
