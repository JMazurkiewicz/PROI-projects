#pragma once

#include "ComplexListNode.h"

class ComplexListAllocator {
public:
    ComplexListNode* allocNode(const Complex& value);
    void freeNode(ComplexListNode* node);
};
