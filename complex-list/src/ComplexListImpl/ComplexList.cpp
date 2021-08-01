#include "ComplexList.h"
#include "SimpleMath.h"
#include <iomanip>
#include <ostream>

ComplexList::ComplexList()
    : head(nullptr)
    , tail(nullptr)
    , size(0) { }

ComplexList::ComplexList(std::initializer_list<Complex> list)
    : ComplexList() {
    for(auto&& value : list) {
        pushBack(value);
    }
}

ComplexList::ComplexList(const ComplexList& other)
    : ComplexList() {
    *this += other;
}

ComplexList::ComplexList(ComplexList&& other)
    : ComplexList() {
    *this += std::move(other);
}

ComplexList::~ComplexList() {
    clear();
}

void ComplexList::clear() {
    for(ComplexListNode* node = head; node != nullptr;) {
        ComplexListNode* const nextNode = node->getNextNode();
        freeNode(node);
        node = nextNode;
    }

    resetInternalData();
}

ComplexList& ComplexList::operator=(const ComplexList& other) {
    if(this != &other) {
        clear();
        *this += other;
    }

    return *this;
}

ComplexList& ComplexList::operator=(ComplexList&& other) {
    if(this != &other) {
        clear();
        *this += std::move(other);
    }

    return *this;
}

ComplexList& ComplexList::operator+=(const ComplexList& other) {
    ComplexListNode* const otherHead = other.head;
    ComplexListNode* const otherTail = other.tail;

    for(ComplexListNode* node = otherHead;; node = node->getNextNode()) {
        pushBack(node->getValue());
        if(node == otherTail) {
            break;
        }
    }

    return *this;
}

ComplexList& ComplexList::operator+=(ComplexList&& other) {
    if(this != &other && !other.isEmpty()) {
        other.head->connectBack(this->tail);

        tail = other.tail;
        if(isEmpty()) {
            head = other.head;
        }
        size += other.getSize();

        other.resetInternalData();
    }

    return *this;
}

void ComplexList::resetInternalData() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

std::size_t ComplexList::getSize() const {
    return size;
}

bool ComplexList::isEmpty() const {
    return getSize() == 0;
}

Complex& ComplexList::operator[](IndexType index) {
    return getNodeAt(index)->getValue();
}

const Complex& ComplexList::operator[](IndexType index) const {
    return getNodeAt(index)->getValue();
}

ComplexListNode* ComplexList::getNodeAt(IndexType index) const {
    if(index >= getSize()) {
        throw std::out_of_range{"invalid index: " + std::to_string(index)};
    }

    ComplexListNode* node = head;
    while(index--) {
        node = node->getNextNode();
    }

    return node;
}

void ComplexList::pushBack(const Complex& value) {
    ComplexListNode* const newNode = allocNode(value);
    newNode->connectBack(tail);

    tail = newNode;
    if(isEmpty()) {
        head = newNode;
    }

    ++size;
}

void ComplexList::pushFront(const Complex& value) {
    ComplexListNode* const newNode = allocNode(value);
    newNode->connectFront(head);

    head = newNode;
    if(isEmpty()) {
        tail = newNode;
    }

    ++size;
}

void ComplexList::popBack() {
    erase(getSize() - 1);
}

void ComplexList::popFront() {
    erase(0);
}

void ComplexList::erase(IndexType position) {
    ComplexListNode* const toDelete = getNodeAt(position);

    if(position == 0) {
        head = toDelete->getNextNode();
        head->connectBack(nullptr);
    } else if(position == getSize() - 1) {
        tail = toDelete->getPrevNode();
        tail->connectFront(nullptr);
    } else {
        toDelete->getPrevNode()->connectFront(toDelete->getNextNode());
    }

    freeNode(toDelete);
    --size;
}

void ComplexList::insert(IndexType position, const Complex& value) {
    if(position == 0) {
        pushFront(value);
    } else if(position == getSize()) {
        pushBack(value);
    } else {
        ComplexListNode* const newNode = allocNode(value);
        ComplexListNode* const nextToInserted = getNodeAt(position);

        nextToInserted->getPrevNode()->connectFront(newNode);
        nextToInserted->connectBack(newNode);

        ++size;
    }
}

ComplexList operator+(const ComplexList& lhs, const ComplexList& rhs) {
    return ComplexList{lhs} += rhs;
}

ComplexList operator+(ComplexList&& lhs, const ComplexList& rhs) {
    return ComplexList{std::move(lhs)} += rhs;
}

ComplexList operator+(const ComplexList& lhs, ComplexList&& rhs) {
    return ComplexList{lhs} += std::move(rhs);
}

std::ostream& operator<<(std::ostream& stream, const ComplexList& list) {
    const std::streamsize width = intLength(list.getSize());
    ComplexList::IndexType index = 1;

    for(ComplexListNode* node = list.head; node != nullptr;
        node = node->getNextNode()) {
        stream << std::setw(width) << index << ") ";
        stream << node->getValue() << '\n';
        ++index;
    }

    return stream;
}
