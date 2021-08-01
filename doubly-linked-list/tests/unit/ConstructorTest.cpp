#include "DoublyLinkedList.h"
#include "Test.h"
#include <vector>

namespace {

    void defaultConstructorTest() {
        DoublyLinkedList<int> list;

        TEST(list.getSize() == 0);
        TEST(list.isEmpty());
        TEST(list.begin() == list.end());
    }

    void listConstructorTest() {
        DoublyLinkedList<float> list{1.2F, 2, 4, 6, 8, 1, 4, 6};

        TEST(list.getSize() == 8);
        TEST(list[4] == 8);
        TEST(list[1] == 2);
    }

    void valueConstructorTest() {
        DoublyLinkedList<char> list(26, 'A');

        TEST(list.getSize() == 26);
        TEST(list[0] == 'A');
    }

    void copyConstructorTest() {
        DoublyLinkedList<double> one{0.0, 1, 2, 3, 4, 5, 6, 7};
        DoublyLinkedList<double> two(one);

        const auto& refone = one;
        const auto& reftwo = two;

        TEST(one.getSize() == two.getSize());
        TEST(refone[0] == reftwo[0]);
        TEST(refone[6] == reftwo[6]);
        TEST(refone.begin().getNode() == reftwo.begin().getNode());
    }

    void moveConstructorTest() {
        DoublyLinkedList<void*> one(3, nullptr);
        void* firstNode = one.begin().getNode();
        DoublyLinkedList<void*> two = std::move(one);

        TEST(one.getSize() == 0);
        TEST(two.getSize() == 3);
        TEST(firstNode == two.begin().getNode());
    }

    void iteratorConstructorTest() {
        std::vector<int> vector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        DoublyLinkedList<long> list(vector.begin(), vector.end());

        TEST(list.getSize() == 10);
        TEST(list.front() == 0);
        TEST(list.back() == 9);
    }

} // namespace

void constructorTest() {
    defaultConstructorTest();
    listConstructorTest();
    valueConstructorTest();
    copyConstructorTest();
    moveConstructorTest();
    iteratorConstructorTest();
}
