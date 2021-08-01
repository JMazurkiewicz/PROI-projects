#include "DoublyLinkedList.h"
#include "Test.h"
#include <sstream>

namespace {

    void emptyListPrintingTest() {
        DoublyLinkedList<int> list;
        std::ostringstream stream;
        stream << list;

        TEST(stream.str() == "[]");
    }

    void oneElementListPrinting() {
        DoublyLinkedList<int> list = {123};
        std::ostringstream stream;
        stream << list;

        TEST(stream.str() == "[123]");
    }

    void twoElementListPrinting() {
        DoublyLinkedList<int> list = {123, 456};
        std::ostringstream stream;
        stream << list;

        TEST(stream.str() == "[123, 456]");
    }

    void longListPrinting() {
        DoublyLinkedList<int> list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::ostringstream stream;
        stream << list;

        TEST(stream.str() == "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]");
    }

} // namespace

void printingTest() {
    emptyListPrintingTest();
    oneElementListPrinting();
    twoElementListPrinting();
    longListPrinting();
}
