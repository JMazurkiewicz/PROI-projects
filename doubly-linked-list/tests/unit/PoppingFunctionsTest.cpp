#include "DoublyLinkedList.h"
#include "Test.h"

namespace {

    void popBackTest() {
        DoublyLinkedList<int> list = {0, 1, 2, 3, 4, 5, 6};
        list.popBack();
        list.popBack();

        TEST(list.getSize() == 5);
        TEST(list.back() == 4);
    }

    void popFrontTest() {
        DoublyLinkedList<char> list = {'a', 'b', 'c', 'd', 'e'};
        list.popFront();
        list.popFront();
        list.popFront();

        TEST(list.getSize() == 2);
        TEST(list.front() == 'd');
    }

} // namespace

void poppingFunctionsTest() {
    popBackTest();
    popFrontTest();
}
