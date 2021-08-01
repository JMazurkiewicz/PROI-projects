#pragma once

#include "Complex.h"

class ComplexListNode {
public:
    explicit ComplexListNode(const Complex& value);

    Complex& getValue();
    const Complex& getValue() const;

    void connectFront(ComplexListNode* nextNode);
    void connectBack(ComplexListNode* prevNode);

    ComplexListNode* getNextNode();
    ComplexListNode* getPrevNode();

    const ComplexListNode* getNextNode() const;
    const ComplexListNode* getPrevNode() const;

private:
    ComplexListNode* next;
    ComplexListNode* prev;

    Complex value;
};
