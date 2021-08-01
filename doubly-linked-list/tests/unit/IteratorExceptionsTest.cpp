#include "DoublyLinkedList.h"
#include "Test.h"

namespace {

    void nullIteratorDereferenceTest() {
        try {
            DoublyLinkedList<int>::Iterator it;
            *it = 5;

        } catch(InvalidIteratorException& except) {
            TEST(EXCEPTION_THROWN);
            TEST(except.getCode() == DEREFERENCING_INVALID_ITERATOR);
            return;
        }

        TEST(EXCEPTION_NOT_THROWN);
    }

    void nullConstIteratorDereferenceTest() {
        try {
            DoublyLinkedList<float>::ConstIterator it;
            *it;

        } catch(InvalidIteratorException& except) {
            TEST(EXCEPTION_THROWN);
            TEST(except.getCode() == DEREFERENCING_INVALID_ITERATOR);
            return;
        }

        TEST(EXCEPTION_NOT_THROWN);
    }

    void endIteratorDereferenceTest() {
        try {
            DoublyLinkedList<int> list(5);
            DoublyLinkedList<int>::Iterator it = list.end();
            *it = 5;

        } catch(InvalidIteratorException& except) {
            TEST(EXCEPTION_THROWN);
            TEST(except.getCode() == DEREFERENCING_INVALID_ITERATOR);
            return;
        }

        TEST(EXCEPTION_NOT_THROWN);
    }

    void endConstIteratorDereferenceTest() {
        try {
            DoublyLinkedList<int> list(5);
            DoublyLinkedList<int>::ConstIterator it = list.end();
            *it;

        } catch(InvalidIteratorException& except) {
            TEST(EXCEPTION_THROWN);
            TEST(except.getCode() == DEREFERENCING_INVALID_ITERATOR);
            return;
        }

        TEST(EXCEPTION_NOT_THROWN);
    }

    void nullIteratorIncrementationTest() {
        try {
            DoublyLinkedList<int>::Iterator it;
            ++it;

        } catch(InvalidIteratorException& except) {
            TEST(EXCEPTION_THROWN);
            TEST(except.getCode() == INCREMENTING_NULL_ITERATOR);
            return;
        }

        TEST(EXCEPTION_NOT_THROWN);
    }

    void nullConstIteratorIncrementationTest() {
        try {
            DoublyLinkedList<int>::ConstIterator it;
            ++it;

        } catch(InvalidIteratorException& except) {
            TEST(EXCEPTION_THROWN);
            TEST(except.getCode() == INCREMENTING_NULL_ITERATOR);
            return;
        }

        TEST(EXCEPTION_NOT_THROWN);
    }

    void nullIteratorDecrementationTest() {
        try {
            DoublyLinkedList<int>::Iterator it;
            --it;

        } catch(InvalidIteratorException& except) {
            TEST(EXCEPTION_THROWN);
            TEST(except.getCode() == DECREMENTING_NULL_ITERATOR);
            return;
        }

        TEST(EXCEPTION_NOT_THROWN);
    }

    void nullConstIteratorDecrementationTest() {
        try {
            DoublyLinkedList<int>::ConstIterator it;
            --it;

        } catch(InvalidIteratorException& except) {
            TEST(EXCEPTION_THROWN);
            TEST(except.getCode() == DECREMENTING_NULL_ITERATOR);
            return;
        }

        TEST(EXCEPTION_NOT_THROWN);
    }

} // namespace

void iteratorExceptionsTest() {
    nullIteratorDereferenceTest();
    nullConstIteratorDereferenceTest();
    endIteratorDereferenceTest();
    endConstIteratorDereferenceTest();

    nullIteratorIncrementationTest();
    nullConstIteratorIncrementationTest();
    nullIteratorDecrementationTest();
    nullConstIteratorDecrementationTest();
}
