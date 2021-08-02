#include "Test.h"
#include <iomanip>
#include <iostream>

namespace test {
    int status = 0;

    void startTest(void (*test)(), const char* name) {
        std::cout << "TEST: " << name << '\n';
        test();
    }

    void unitTest(std::function<bool()> test, const TestInfo& info) {
        std::cout << std::setw(40) << std::right << info.function << ':';
        std::cout << std::setw(3) << std::left << info.line;
        std::cout << " -> " << std::setw(80) << info.condition << std::flush;

        const bool result = test();
        std::cout << std::setw(7) << std::right
                  << (result ? "passed" : "FAILED") << std::endl;

        if(!result) {
            status = 1;
        }
    }

} // namespace test

int main() {
    std::ios_base::sync_with_stdio(false);
    
    try {
        START_TEST(constructorTest);
        START_TEST(assignmentOperatorTest);
        START_TEST(insertionTest);
        START_TEST(pushingFunctionsTest);
        START_TEST(erasureTest);
        START_TEST(poppingFunctionsTest);
        START_TEST(comparasionsTest);
        START_TEST(swapTest);
        START_TEST(iteratorExceptionsTest);
        START_TEST(appendingTest);
        START_TEST(printingTest);
        START_TEST(grouppingTest);
    } catch(const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << '\n';
        return 1;
    }

    return test::status;
}
