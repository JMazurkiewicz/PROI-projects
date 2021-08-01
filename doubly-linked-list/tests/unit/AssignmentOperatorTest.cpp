#include "DoublyLinkedList.h"
#include "Test.h"

namespace {

    void copyAssignmentTest() {
        DoublyLinkedList<int> one{1, 2, 3, 4, 5};
        DoublyLinkedList<int> two{6, 7, 8, 9, 0};
        two = one;

        const auto& refone = one;
        const auto& reftwo = two;

        TEST(refone.getSize() == reftwo.getSize());
        TEST(refone.begin().getNode() == reftwo.begin().getNode());
        TEST(refone[2] == reftwo[2]);
    }

    void moveAssignmentTest() {
        DoublyLinkedList<wchar_t> one(20, L'A');
        DoublyLinkedList<wchar_t> two(10, L'B');
        two = std::move(one);

        TEST(one.getSize() == 0);
        TEST(two.getSize() == 20);
        TEST(two[19] == L'A');
    }

} // namespace

void assignmentOperatorTest() {
    copyAssignmentTest();
    moveAssignmentTest();
}
