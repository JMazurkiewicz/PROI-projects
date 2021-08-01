#include "DoublyLinkedList.h"
#include "Test.h"
#include <complex>
#include <string>

namespace {

    void copyInsertTest() {
        DoublyLinkedList<void*> list;
        list.insert(list.begin(), nullptr);
        list.insert(list.end(), nullptr);

        TEST(list.getSize() == 2);
        TEST(list[0] == nullptr);
    }

    void moveInsertTest() {
        DoublyLinkedList<std::string> list{"hello", "world"};
        std::string toMove = "new";
        list.insert(++list.begin(), std::move(toMove));

        TEST(toMove.size() == 0);
        TEST(list.getSize() == 3);
        TEST(list[1] == "new");
    }

    void emplaceTest() {
        using namespace std::literals;

        DoublyLinkedList<std::complex<double>> list{1.0, 1.0i, -1.0, -1.0i};
        list.emplace(list.begin(), -1.0, -1.0);
        list.emplace(list.end(), 1.0, 1.0);

        TEST(list.getSize() == 6);
        TEST(list[0] == -1.0 - 1.0i);
        TEST(list.back() == 1.0 + 1.0i);
    }

    void copyInsertWithIndexTest() {
        DoublyLinkedList<int*> list;
        list.insert(0, nullptr);
        list.insert(1, nullptr);

        TEST(list.getSize() == 2);
        TEST(list[0] == nullptr);
    }

    void moveInsertWithIndexTest() {
        DoublyLinkedList<std::string> list{"hello", "world"};
        std::string toMove = "new";
        list.insert(1, std::move(toMove));

        TEST(toMove.size() == 0);
        TEST(list.getSize() == 3);
        TEST(list[1] == "new");
    }

    void emplaceWithIndexTest() {
        using namespace std::literals;

        DoublyLinkedList<std::complex<double>> list{1.0, 1.0i, -1.0, -1.0i};
        list.emplace(0, -1.0, -1.0);
        list.emplace(5, 1.0, 1.0);

        TEST(list.getSize() == 6);
        TEST(list.front() == -1.0 - 1.0i);
        TEST(list.back() == 1.0 + 1.0i);
    }

} // namespace

void insertionTest() {
    copyInsertTest();
    moveInsertTest();
    emplaceTest();
    copyInsertWithIndexTest();
    moveInsertWithIndexTest();
    emplaceWithIndexTest();
}
