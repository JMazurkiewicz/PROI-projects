#include "DoublyLinkedList.h"
#include "Test.h"
#include <string>

namespace {

    void pushBackTest() {
        DoublyLinkedList<char> chars;
        for(char c = 'a'; c <= 'z'; ++c) {
            chars.pushBack(c);
        }

        TEST(chars.getSize() == 26);
        TEST(chars[8] == 'a' + 8);
        TEST(chars.back() == 'z');
    }

    void pushFrontTest() {
        DoublyLinkedList<wchar_t> wideChars;
        for(wchar_t c = L'0'; c <= L'9'; ++c) {
            wideChars.pushFront(c);
        }

        TEST(wideChars.getSize() == 10);
        TEST(wideChars.front() == L'9');
        TEST(wideChars.back() == L'0');
    }

    void movingPushBackTest() {
        DoublyLinkedList<std::string> strings;
        std::string toMove[3] = {"move", "this", "array"};
        for(std::string& e : toMove) {
            strings.pushBack(std::move(e));
        }

        TEST(strings.getSize() == 3);
        TEST(toMove[0].empty() && toMove[1].empty() && toMove[2].empty());
        TEST(strings.back() == "array");
    }

    void movingPushFrontTest() {
        DoublyLinkedList<std::wstring> wideStrings;
        std::wstring toMove[3] = {L"move", L"this", L"array"};
        for(std::wstring& e : toMove) {
            wideStrings.pushBack(std::move(e));
        }

        TEST(wideStrings.getSize() == 3);
        TEST(toMove[0].empty() && toMove[1].empty() && toMove[2].empty());
        TEST(wideStrings.back() == L"array");
    }

    void emplaceBackTest() {
        DoublyLinkedList<std::u16string> u16strings;
        u16strings.emplaceBack(10, u'0');
        u16strings.emplaceBack(u"some text", 0, 4);

        TEST(u16strings.getSize() == 2);
        TEST(u16strings.front() == u"0000000000");
        TEST(u16strings.back() == u"some");
    }

    void emplaceFrontTest() {
        DoublyLinkedList<std::u32string> u32strings;
        u32strings.emplaceFront(10, U'O');
        u32strings.emplaceFront(U"more text", 5, 4);

        TEST(u32strings.getSize() == 2);
        TEST(u32strings.front() == U"text");
        TEST(u32strings.back() == U"OOOOOOOOOO");
    }

} // namespace

void pushingFunctionsTest() {
    pushBackTest();
    pushFrontTest();
    movingPushBackTest();
    movingPushFrontTest();
    emplaceBackTest();
    emplaceFrontTest();
}
