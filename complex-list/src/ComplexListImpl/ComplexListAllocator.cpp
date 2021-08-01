#include "ComplexListAllocator.h"

ComplexListNode* ComplexListAllocator::allocNode(const Complex& value) {
    return new ComplexListNode(value);
}

void ComplexListAllocator::freeNode(ComplexListNode* node) {
    delete node;
}
