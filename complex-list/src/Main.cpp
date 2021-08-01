#include "ComplexList.h"

#include <iostream>
#include <utility>

int status = 0;

void CheckCondition(const char* what, int line, bool cond) {
    std::cout << "test \"" << what << "\" at " << line;
    if(!cond) {
        std::cout << " failed";
        status = 1;
    } else {
        std::cout << " passed";
    }
    std::cout << std::endl;
}

#define ASSERT(cond) (CheckCondition((#cond), __LINE__, (cond)))

class Test {
public:
    static void run() {
        defaultCtorTest();
        listCtorTest();
        copyCtorTest();
        moveCtorTest();
        clearTest();
        copyAssignmentTest();
        moveAssignmentTest();
        addAndCopyAssignTest();
        addAndMoveAssignTest();
        pushBackTest();
        pushFrontTest();
        popBackTest();
        popFrontTest();
        eraseTest();
        insertTest();
        printTest();
    }

private:
    static void defaultCtorTest() {
        ComplexList list;
        ASSERT(list.getSize() == 0);
        ASSERT(list.isEmpty());
    }

    static void listCtorTest() {
        ComplexList list = {1, 2, 3};
        ASSERT(list.getSize() == 3);
        ASSERT(list[0] == 1);
        ASSERT(list[1] == 2);
        ASSERT(list[2] == 3);
    }

    static void copyCtorTest() {
        ComplexList list1 = {1, 2, 3};
        ComplexList list2 = list1;
        ASSERT(list1[0] == 1 && list2[0] == 1);
        ASSERT(list1[1] == 2 && list2[1] == 2);
        ASSERT(list1[2] == 3 && list2[2] == 3);
        ASSERT(list2.getSize() == 3);
    }

    static void moveCtorTest() {
        ComplexList list1 = {1_i, 2_i, 3_i};
        ComplexList list2 = std::move(list1);
        ASSERT(list2[2] == 3_i);
        ASSERT(list2.getSize() == 3);
        ASSERT(list1.getSize() == 0);
    }

    static void clearTest() {
        ComplexList list = {1 + 1_i, 2 + 2_i, 3 + 3_i};
        list.clear();
        ASSERT(list.getSize() == 0);
        ASSERT(list.isEmpty());
    }

    static void copyAssignmentTest() {
        ComplexList list1 = {1, 2, 3};
        ComplexList list2;
        list2 = list1;
        ASSERT(list2[2] == 3);
        ASSERT(list2.getSize() == 3);
    }

    static void moveAssignmentTest() {
        ComplexList list1 = {1, 2, 3};
        ComplexList list2;
        list2 = std::move(list1);
        ASSERT(list2[2] == 3);
        ASSERT(list2.getSize() == 3);
        ASSERT(list1.getSize() == 0);
    }

    static void addAndCopyAssignTest() {
        ComplexList list1 = {1, 2, 3};
        ComplexList list2 = {4, 5, 6};
        list1 += list2;
        ASSERT(list1.getSize() == 6);
        ASSERT(list1[4] == 5);
        ASSERT(list2.getSize() == 3);
        ASSERT(list2[0] == 4);
    }

    static void addAndMoveAssignTest() {
        ComplexList list1 = {1, 2, 3};
        ComplexList list2 = {4, 5, 6};
        list1 += std::move(list2);
        ASSERT(list1.getSize() == 6);
        ASSERT(list1[4] == 5);
        ASSERT(list2.getSize() == 0);
    }

    static void pushBackTest() {
        ComplexList list;
        list.pushBack(1);
        ASSERT(list.getSize() == 1);
        list.pushBack(1_i);
        ASSERT(list.getSize() == 2);
        ASSERT(list[1] == 1_i);
    }

    static void pushFrontTest() {
        ComplexList list;
        list.pushFront(1);
        ASSERT(list.getSize() == 1);
        list.pushFront(1_i);
        ASSERT(list.getSize() == 2);
        ASSERT(list[1] == 1);
    }

    static void popBackTest() {
        ComplexList list{1, 2, 3, 4};
        list.popBack();
        ASSERT(list.getSize() == 3);
        list.popBack();
        ASSERT(list.getSize() == 2);
        ASSERT(list[1] == 2);
    }

    static void popFrontTest() {
        ComplexList list{1, 2, 3, 4};
        list.popFront();
        ASSERT(list.getSize() == 3);
        list.popFront();
        ASSERT(list.getSize() == 2);
        ASSERT(list[1] == 4);
    }

    static void eraseTest() {
        ComplexList list{1, 2, 3, 4, 5};
        list.erase(1);
        ASSERT(list.getSize() == 4);
        ASSERT(list[1] == 3);
        list.erase(2);
        ASSERT(list.getSize() == 3);
        ASSERT(list[2] == 5);
    }

    static void insertTest() {
        ComplexList list;
        list.insert(0, 1);
        ASSERT(list.getSize() == 1);
        list.insert(0, 1_i);
        ASSERT(list.getSize() == 2);
        ASSERT(list[0] == 1_i);
    }

    static void printTest() {
        ComplexList list;
        for(int i = 0; i < 100; ++i) {
            list.pushFront(
                Complex{static_cast<Real>(i), static_cast<Real>(99 - i)});
        }
        ASSERT(list.getSize() == 100);
        ASSERT(list[50] == 49 + 50_i);
        list.pushFront(0);
        std::cout << list << '\n';
    }
};

int main() {
    try {
        Test::run();
    } catch(std::exception& e) {
        std::cerr << "Unexpected exception...\n";
        std::cerr << "what(): " << e.what() << '\n';
        status = 1;
    }

    return status;
}
