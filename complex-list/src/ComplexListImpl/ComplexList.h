#pragma once

#include "Complex.h"
#include "ComplexListAllocator.h"
#include <initializer_list>
#include <iosfwd>
#include <stdexcept>
#include <string>

class ComplexList : protected ComplexListAllocator {
public:
    using IndexType = std::size_t;

    ComplexList();
    ComplexList(std::initializer_list<Complex> list);

    ComplexList(const ComplexList& other);
    ComplexList(ComplexList&& other);

    ~ComplexList();
    void clear();

    ComplexList& operator=(const ComplexList& other);
    ComplexList& operator=(ComplexList&& other);

    ComplexList& operator+=(const ComplexList& other);
    ComplexList& operator+=(ComplexList&& other);

private:
    void resetInternalData();

public:
    std::size_t getSize() const;
    bool isEmpty() const;

    Complex& operator[](IndexType index);
    const Complex& operator[](IndexType index) const;

private:
    ComplexListNode* getNodeAt(IndexType index) const;

public:
    void pushBack(const Complex& value);
    void pushFront(const Complex& value);

    void popBack();
    void popFront();

    void erase(IndexType position);
    void insert(IndexType position, const Complex& value);

private:
    ComplexListNode* head;
    ComplexListNode* tail;
    std::size_t size;

public:
    friend ComplexList operator+(const ComplexList& lhs,
                                 const ComplexList& rhs);
    friend ComplexList operator+(ComplexList&& lhs, const ComplexList& rhs);
    friend ComplexList operator+(const ComplexList& lhs, ComplexList&& rhs);

    friend std::ostream& operator<<(std::ostream& stream,
                                    const ComplexList& list);
};
