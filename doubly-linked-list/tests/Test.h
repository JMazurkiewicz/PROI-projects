#pragma once

#include <functional>

namespace test {

    struct TestInfo {
        const char* condition;
        const char* function;
        int line;
    };

    void startTest(void (*test)(), const char* name);
    void unitTest(std::function<bool()> test, const TestInfo& info);

} // namespace test

enum ExceptionStatus { EXCEPTION_NOT_THROWN, EXCEPTION_THROWN };

#define START_TEST(testFunction)                                               \
    void(testFunction)();                                                      \
    (::test::startTest((testFunction), (#testFunction)))

#define MAKE_TEST_FUNCTION(testFunction)                                       \
    ([&]() -> bool { return (testFunction); })
#define TEST_INFO(testFunction)                                                \
    (::test::TestInfo{(#testFunction), __func__, __LINE__})
#define TEST(testFunction)                                                     \
    (::test::unitTest(MAKE_TEST_FUNCTION(testFunction),                        \
                      TEST_INFO(testFunction)))
