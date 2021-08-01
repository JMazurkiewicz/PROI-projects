#include "DoublyLinkedList.h"
#include "Test.h"

namespace {

    void swapWithEmptyListTest() {
        DoublyLinkedList<int> one;
        DoublyLinkedList<int> two = {1, 2, 3};
        one.swap(two);

        TEST(two.getSize() == 0);
        TEST(one.getSize() == 3);
        TEST(one.front() == 1);
    }

    void regularSwapTest() {
        DoublyLinkedList<int> one = {1, 2, 3};
        DoublyLinkedList<int> two = {4, 5};
        two.swap(one);

        TEST(one.getSize() == 2);
        TEST(two.getSize() == 3);
        TEST(one.back() == 5);
        TEST(two.front() == 1);
    }

    void selfSwapTest() {
        DoublyLinkedList<int> list = {1, 2, 3};
        list.swap(list);

        TEST(list.getSize() == 3);
        TEST(list.front() == 1);
    }

} // namespace

void swapTest() {
    swapWithEmptyListTest();
    regularSwapTest();
    selfSwapTest();
}
