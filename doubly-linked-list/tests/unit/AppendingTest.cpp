#include "DoublyLinkedList.h"
#include "Test.h"

namespace {

    void copyAppendTest() {
        DoublyLinkedList<int> one = {0, 1, 2, 3, 4};
        DoublyLinkedList<int> two = {5, 6, 7, 8, 9};
        one += two;

        TEST(one.getSize() == 10);
        TEST(two.getSize() == 5);
        TEST(one.back() == 9);
        TEST(two.front() == 5);
    }

    void moveAppendTest() {
        DoublyLinkedList<int> one = {0, 1, 2, 3, 4};
        DoublyLinkedList<int> two = {5, 6, 7, 8, 9};
        one += std::move(two);

        TEST(one.getSize() == 10);
        TEST(two.getSize() == 0);
        TEST(one.back() == 9);
    }

    void selfCopyAppendTest() {
        DoublyLinkedList<int> list = {1, 2, 3};
        list += list;

        TEST(list.getSize() == 6);
        TEST(list.back() == 3);
        TEST(list[3] == 1);
    }

    void selfMoveAppendTest() {
        DoublyLinkedList<int> list = {1, 2, 3};
        list += std::move(list);

        TEST(list.getSize() == 3);
        TEST(list.back() == 3);
        TEST(list.front() == 1);
    }

} // namespace

void appendingTest() {
    copyAppendTest();
    moveAppendTest();
    selfCopyAppendTest();
    selfMoveAppendTest();
}
