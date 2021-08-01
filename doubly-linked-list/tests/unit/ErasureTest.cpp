#include "DoublyLinkedList.h"
#include "Test.h"
#include <string>

namespace {

    void eraseTest() {
        DoublyLinkedList<std::string> test{"short", "int", "long"};
        test.erase(++test.begin());

        TEST(test.getSize() == 2);
        TEST(test.front() == "short");
        TEST(test.back() == "long");
    }

    void eraseWithIndexTest() {
        DoublyLinkedList<std::wstring> test{L"sin", L"cos", L"tan"};
        test.erase(1);

        TEST(test.getSize() == 2);
        TEST(test.front() == L"sin");
        TEST(test.back() == L"tan");
    }

} // namespace

void erasureTest() {
    eraseTest();
    eraseWithIndexTest();
}
