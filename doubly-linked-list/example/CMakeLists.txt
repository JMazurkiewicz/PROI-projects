cmake_minimum_required(VERSION 3.10)

add_executable(Statistics Statistics.cpp)
target_include_directories(Statistics PRIVATE ${CMAKE_SOURCE_DIR}/source)
