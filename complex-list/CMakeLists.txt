cmake_minimum_required(VERSION 3.10)

project("Complex list")

set(CMAKE_CXX_STANDARD 14)
enable_testing()

set(
    COMPLEX_LIST_SOURCES

    src/Complex.cpp
    src/ComplexListImpl/ComplexList.cpp
    src/ComplexListImpl/ComplexListAllocator.cpp
    src/ComplexListImpl/ComplexListNode.cpp
)

add_library(ComplexList ${COMPLEX_LIST_SOURCES})
target_include_directories(ComplexList PRIVATE src)

add_executable(ComplexListTests src/Main.cpp)
target_include_directories(ComplexListTests PRIVATE src)
target_link_libraries(ComplexListTests ComplexList)

add_test(NAME UnitTests COMMAND ComplexListTests)
