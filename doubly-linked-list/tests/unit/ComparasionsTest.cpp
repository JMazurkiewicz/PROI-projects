#include "DoublyLinkedList.h"
#include "Test.h"

namespace {

    void equalCompareTest() {
        DoublyLinkedList<int> a = {1, 2, 3, 4, 5};
        DoublyLinkedList<int> b = {1, 2, 3, 4, 5};
        DoublyLinkedList<int> c = {1, 2, 3, 4, 6};

        TEST(a == b);
        TEST(b == a);
        TEST((a == c) == false);
        TEST((c == b) == false);
    }

    void notEqualCompareTest() {
        DoublyLinkedList<int> a = {5, 4, 3, 2, 1};
        DoublyLinkedList<int> b = {5, 4, 3, 2, 1};
        DoublyLinkedList<int> c = {6, 4, 3, 2, 1};

        TEST(a != c);
        TEST(c != b);
        TEST((a != b) == false);
        TEST((b != a) == false);
    }

} // namespace

void comparasionsTest() {
    equalCompareTest();
    notEqualCompareTest();
}
