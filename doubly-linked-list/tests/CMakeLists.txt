set(SOURCES
    Test.cpp

    unit/AppendingTest.cpp
    unit/AssignmentOperatorTest.cpp
    unit/ComparasionsTest.cpp
    unit/ConstructorTest.cpp
    unit/ErasureTest.cpp
    unit/GrouppingTest.cpp
    unit/InsertionTest.cpp
    unit/IteratorExceptionsTest.cpp
    unit/PoppingFunctionsTest.cpp
    unit/PrintingTest.cpp
    unit/PushingFunctionsTest.cpp
    unit/SwapTest.cpp
)

add_executable(UnitTests ${SOURCES})
target_include_directories(UnitTests PRIVATE ${CMAKE_SOURCE_DIR}/source)
target_include_directories(UnitTests PRIVATE ${CMAKE_SOURCE_DIR}/tests)
