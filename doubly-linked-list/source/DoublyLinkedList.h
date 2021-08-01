#pragma once

#include <algorithm>
#include <initializer_list>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <utility>

#include "impl/ConstIterator.h"
#include "impl/Iterator.h"
#include "impl/ListImpl.h"
#include "impl/ListPrinter.h"
#include "impl/Node.h"
#include "impl/NodeAllocator.h"

template<typename ValueT>
class DoublyLinkedList {
public:
    using ValueType = ValueT;
    using Reference = ValueType&;
    using ConstReference = const ValueType&;
    using Iterator = impl::Iterator<ValueType>;
    using ConstIterator = impl::ConstIterator<ValueType>;
    using ReverseIterator = std::reverse_iterator<Iterator>;
    using ConstReverseIterator = std::reverse_iterator<ConstIterator>;
    using SizeType = std::size_t;

private:
    using NodeBase = ::impl::NodeBase;
    using Node = ::impl::Node<ValueType>;
    using NodeAllocator = ::impl::NodeAllocator<ValueType>;
    using ListImpl = ::impl::ListImpl<ValueType>;

    template<typename... Args>
    static std::shared_ptr<ListImpl> makeImpl(Args&&... args) {
        return std::make_shared<ListImpl>(std::forward<Args>(args)...);
    }

    std::shared_ptr<ListImpl> impl;

    void useUniqueImpl() {
        const long useCount = impl.use_count();

        if(useCount > 1) {
            impl = makeImpl(*impl);
        } else if(useCount == 0) {
            impl = makeImpl();
        }
    }

public:
    DoublyLinkedList()
        : impl{makeImpl()} { }

    DoublyLinkedList(const DoublyLinkedList& other)
        : impl{other.impl} { }

    DoublyLinkedList(DoublyLinkedList&& other)
        : impl{std::move(other.impl)} {
        other.useUniqueImpl();
    }

    template<typename InputIt>
    explicit DoublyLinkedList(InputIt first, InputIt last)
        : impl{makeImpl(first, last)} { }

    DoublyLinkedList(std::initializer_list<ValueType> list)
        : DoublyLinkedList(list.begin(), list.end()) { }

    explicit DoublyLinkedList(SizeType count,
                              const ValueType& value = ValueType{}) {
        useUniqueImpl();
        while(count--) {
            pushBack(value);
        }
    }

    void clear() {
        if(impl.use_count() != 1) {
            impl = makeImpl();
        } else {
            impl->clear();
        }
    }

    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if(this != &other) {
            this->impl = other.impl;
        }
        return *this;
    }

    DoublyLinkedList& operator=(DoublyLinkedList&& other) {
        if(this != &other) {
            this->impl = std::move(other.impl);
            other.useUniqueImpl();
        }
        return *this;
    }

    DoublyLinkedList& operator+=(const DoublyLinkedList& other) {
        if(!other.isEmpty()) {
            useUniqueImpl();
            impl->copyAppendFrom(*other.impl);
        }

        return *this;
    }

    DoublyLinkedList& operator+=(DoublyLinkedList&& other) {
        if(this != &other && !other.isEmpty()) {
            useUniqueImpl();
            other.useUniqueImpl();
            impl->moveAppendFrom(std::move(*other.impl));
        }

        return *this;
    }

    void swap(DoublyLinkedList& other) {
        impl.swap(other.impl);
    }

    SizeType getSize() const {
        return impl->getSize();
    }

    bool isEmpty() const {
        return getSize() == 0;
    }

    void pushBack(const ValueType& value) {
        emplace(end(), value);
    }

    void pushBack(ValueType&& value) {
        emplace(end(), std::move(value));
    }

    template<typename... Args>
    void emplaceBack(Args&&... args) {
        emplace(end(), std::forward<Args>(args)...);
    }

    void pushFront(const ValueType& value) {
        emplace(begin(), value);
    }

    void pushFront(ValueType&& value) {
        emplace(begin(), std::move(value));
    }

    template<typename... Args>
    void emplaceFront(Args&&... args) {
        emplace(begin(), std::forward<Args>(args)...);
    }

    void popBack() {
        erase(ConstIterator{impl->getTail()});
    }

    void popFront() {
        erase(begin());
    }

    void insert(ConstIterator position, const ValueType& value) {
        emplace(position, value);
    }

    void insert(ConstIterator position, ValueType&& value) {
        emplace(position, std::move(value));
    }

    template<typename... Args>
    void emplace(ConstIterator position, Args&&... args) {
        useUniqueImpl();
        impl->emplace(position.getNode(), std::forward<Args>(args)...);
    }

    void erase(ConstIterator position) {
        useUniqueImpl();
        impl->erase(position.getNode());
    }

private:
    Iterator getIteratorAt(SizeType position) {
        return std::next(begin(), position);
    }

    ConstIterator getIteratorAt(SizeType position) const {
        return std::next(begin(), position);
    }

public:
    Reference operator[](SizeType index) {
        useUniqueImpl();
        return *getIteratorAt(index);
    }

    ConstReference operator[](SizeType index) const {
        return *getIteratorAt(index);
    }

    void erase(SizeType position) {
        erase(getIteratorAt(position));
    }

    void insert(SizeType position, const ValueType& value) {
        emplace(getIteratorAt(position), value);
    }

    void insert(SizeType position, ValueType&& value) {
        emplace(getIteratorAt(position), std::move(value));
    }

    template<typename... Args>
    void emplace(SizeType position, Args&&... args) {
        emplace(getIteratorAt(position), std::forward<Args>(args)...);
    }

public:
    Reference front() {
        useUniqueImpl();
        return *begin();
    }

    ConstReference front() const {
        return *begin();
    }

    Reference back() {
        useUniqueImpl();
        return *Iterator{impl->getTail()};
    }

    ConstReference back() const {
        return *ConstIterator{impl->getTail()};
    }

    Iterator begin() {
        useUniqueImpl();
        return Iterator{impl->getHead()};
    }

    ConstIterator begin() const {
        return ConstIterator{impl->getHead()};
    }

    ConstIterator cbegin() const {
        return begin();
    }

    Iterator end() {
        useUniqueImpl();
        return Iterator{impl->getHeader()};
    }

    ConstIterator end() const {
        return ConstIterator{impl->getHeader()};
    }

    ConstIterator cend() const {
        return end();
    }

    ReverseIterator rbegin() {
        return ReverseIterator{end()};
    }

    ConstReverseIterator rbegin() const {
        return ConstReverseIterator{end()};
    }

    ConstReverseIterator crbegin() const {
        return ConstReverseIterator{cend()};
    }

    ReverseIterator rend() {
        return ReverseIterator{begin()};
    }

    ConstReverseIterator rend() const {
        return ReverseIterator{begin()};
    }

    ConstReverseIterator crend() const {
        return ReverseIterator{rbegin()};
    }
};

template<typename T>
bool operator==(const DoublyLinkedList<T>& left,
                const DoublyLinkedList<T>& right) {
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

template<typename T>
bool operator!=(const DoublyLinkedList<T>& left,
                const DoublyLinkedList<T>& right) {
    return !(left == right);
}

template<typename T>
DoublyLinkedList<T> operator+(const DoublyLinkedList<T>& left,
                              const DoublyLinkedList<T>& right) {
    return DoublyLinkedList<T>{left} += right;
}

template<typename T>
DoublyLinkedList<T> operator+(const DoublyLinkedList<T>& left,
                              DoublyLinkedList<T>&& right) {
    return DoublyLinkedList<T>{left} += std::move(right);
}

template<typename T>
DoublyLinkedList<T> operator+(DoublyLinkedList<T>&& left,
                              const DoublyLinkedList<T>& right) {
    return DoublyLinkedList<T>{std::move(left)} += right;
}

template<typename T>
DoublyLinkedList<T> operator+(DoublyLinkedList<T>&& left,
                              DoublyLinkedList<T>&& right) {
    return DoublyLinkedList<T>{std::move(left)} += std::move(right);
}

template<typename CharT, typename Traits, typename T>
std::basic_ostream<CharT, Traits>&
    operator<<(std::basic_ostream<CharT, Traits>& stream,
               const DoublyLinkedList<T>& list) {
    printList(stream, list.cbegin(), list.cend());
    return stream;
}

template<typename T>
void swap(DoublyLinkedList<T>& left, DoublyLinkedList<T>& right) {
    left.swap(right);
}
