#pragma once

#include "InvalidIteratorException.h"
#include "Iterator.h"
#include "Node.h"

#include <iterator>

namespace impl {
    template<typename ValueT>
    class ConstIterator {
    public:
        using ValueType = ValueT;
        using Pointer = const ValueType*;
        using Reference = const ValueType&;
        using Node = impl::Node<ValueType>;
        using MutableIterator = impl::Iterator<ValueType>;

        using difference_type = std::ptrdiff_t;
        using value_type = ValueType;
        using pointer = Pointer;
        using reference = Reference;
        using iterator_category = std::bidirectional_iterator_tag;

        ConstIterator()
            : ConstIterator(nullptr) { }

        ConstIterator(const MutableIterator& other)
            : ConstIterator(other.getNode()) { }

        explicit ConstIterator(NodeBase* node)
            : node{node} { }

        ConstIterator& operator++() {
            if(node == nullptr) {
                throw InvalidIteratorException{INCREMENTING_NULL_ITERATOR};
            }

            node = node->getNextNode();
            return *this;
        }

        ConstIterator operator++(int) {
            ConstIterator copy = *this;
            ++*this;
            return copy;
        }

        ConstIterator& operator--() {
            if(node == nullptr) {
                throw InvalidIteratorException{DECREMENTING_NULL_ITERATOR};
            }

            node = node->getPrevNode();
            return *this;
        }

        ConstIterator operator--(int) {
            ConstIterator copy = *this;
            --*this;
            return copy;
        }

        Reference operator*() const {
            const Node* const node = dynamic_cast<const Node*>(this->node);

            if(node == nullptr) {
                throw InvalidIteratorException{DEREFERENCING_INVALID_ITERATOR};
            } else {
                return node->getValue();
            }
        }

        Pointer operator->() const {
            return std::addressof(**this);
        }

        NodeBase* getNode() const {
            return node;
        }

    private:
        NodeBase* node;

    public:
        friend bool operator==(const ConstIterator& left,
                               const ConstIterator& right) {
            return left.getNode() == right.getNode();
        }

        friend bool operator!=(const ConstIterator& left,
                               const ConstIterator& right) {
            return !(left == right);
        }
    };
} // namespace impl
