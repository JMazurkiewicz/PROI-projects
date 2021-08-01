#include "DoublyLinkedList.h"
#include "Test.h"

#include <utility>

namespace {

    void simpleConstructorGrouppingTest() {
        DoublyLinkedList<int> list1 = {1, 2, 3, 4};
        DoublyLinkedList<int> list2 = list1;

        const auto& reflist1 = list1;
        const auto& reflist2 = list2;

        TEST(&reflist1.front() == &reflist2.front());
        TEST(&reflist1.back() == &reflist2.back());
    }

    void tripleConstructorGrouppingTest() {
        DoublyLinkedList<int> list1 = {1, 2, 3, 4};
        DoublyLinkedList<int> list2 = list1;
        DoublyLinkedList<int> list3 = list2;

        const auto& reflist1 = list1;
        const auto& reflist2 = list2;
        const auto& reflist3 = list3;

        TEST(&reflist1.front() == &reflist2.front());
        TEST(&reflist2.front() == &reflist3.front());
    }

    void simpleAssignmentGrouppingTest() {
        DoublyLinkedList<long> list1 = {1, 2, 3, 4};
        DoublyLinkedList<long> list2;
        list2 = list1;

        const auto& reflist1 = list1;
        const auto& reflist2 = list2;

        TEST(&reflist1.front() == &reflist2.front());
        TEST(&reflist1.back() == &reflist2.back());
    }

    void tripleAssignmentGrouppingTest() {
        DoublyLinkedList<int> list1 = {1, 2, 3, 4};
        DoublyLinkedList<int> list2;
        DoublyLinkedList<int> list3;
        list2 = list1;
        list3 = list2;

        const auto& reflist1 = list1;
        const auto& reflist2 = list2;
        const auto& reflist3 = list3;

        TEST(&reflist1.front() == &reflist2.front());
        TEST(&reflist2.front() == &reflist3.front());
    }

    void changingGroupTest() {
        DoublyLinkedList<int> list1 = {1, 2, 3};
        DoublyLinkedList<int> list2;
        list2 = list1;
        list2 += DoublyLinkedList<int>{4};

        TEST(list2.getSize() == list1.getSize() + 1);
        TEST(&list2.front() != &list1.front());
    }

    void movingGroupTest() {
        DoublyLinkedList<int> list1 = {1, 2, 3};
        DoublyLinkedList<int> list2 = list1;
        DoublyLinkedList<int> list3 = std::move(list2);

        const auto& reflist1 = list1;
        const auto& reflist3 = list3;

        TEST(list1.isEmpty() == false);
        TEST(list2.isEmpty() == true);
        TEST(&reflist1.front() == &reflist3.front());
    }

    void appendMovingGroupTest() {
        DoublyLinkedList<int> list1 = {1, 2, 3};
        DoublyLinkedList<int> list2 = list1;
        DoublyLinkedList<int> list3 = {0};
        list3 += std::move(list2);

        TEST(list1.getSize() == 3);
        TEST(list2.getSize() == 0);
        TEST(list3.getSize() == 4);
    }

} // namespace

void grouppingTest() {
    simpleConstructorGrouppingTest();
    tripleConstructorGrouppingTest();
    simpleAssignmentGrouppingTest();
    tripleAssignmentGrouppingTest();
    changingGroupTest();
    movingGroupTest();
    appendMovingGroupTest();
}
