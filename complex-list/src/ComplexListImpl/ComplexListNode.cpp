#include "ComplexListNode.h"

ComplexListNode::ComplexListNode(const Complex& value)
    : next(nullptr)
    , prev(nullptr)
    , value(value) { }

Complex& ComplexListNode::getValue() {
    return value;
}

const Complex& ComplexListNode::getValue() const {
    return value;
}

void ComplexListNode::connectFront(ComplexListNode* nextNode) {
    this->next = nextNode;

    if(nextNode != nullptr) {
        nextNode->prev = this;
    }
}

void ComplexListNode::connectBack(ComplexListNode* prevNode) {
    this->prev = prevNode;

    if(prevNode != nullptr) {
        prevNode->next = this;
    }
}

ComplexListNode* ComplexListNode::getNextNode() {
    return next;
}

ComplexListNode* ComplexListNode::getPrevNode() {
    return prev;
}

const ComplexListNode* ComplexListNode::getNextNode() const {
    return next;
}

const ComplexListNode* ComplexListNode::getPrevNode() const {
    return prev;
}
