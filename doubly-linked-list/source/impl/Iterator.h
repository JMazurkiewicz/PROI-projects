#pragma once

#include "InvalidIteratorException.h"
#include "Node.h"

#include <iterator>

namespace impl {
    template<typename ValueT>
    class Iterator {
    public:
        using ValueType = ValueT;
        using Pointer = ValueType*;
        using Reference = ValueType&;
        using Node = impl::Node<ValueType>;

        using difference_type = std::ptrdiff_t;
        using value_type = ValueType;
        using pointer = Pointer;
        using reference = Reference;
        using iterator_category = std::bidirectional_iterator_tag;

        Iterator()
            : Iterator(nullptr) { }

        explicit Iterator(NodeBase* node)
            : node{node} { }

        Iterator& operator++() {
            if(node == nullptr) {
                throw InvalidIteratorException{INCREMENTING_NULL_ITERATOR};
            }

            node = node->getNextNode();
            return *this;
        }

        Iterator operator++(int) {
            Iterator copy = *this;
            ++*this;
            return copy;
        }

        Iterator& operator--() {
            if(node == nullptr) {
                throw InvalidIteratorException{DECREMENTING_NULL_ITERATOR};
            }

            node = node->getPrevNode();
            return *this;
        }

        Iterator operator--(int) {
            Iterator copy = *this;
            --*this;
            return copy;
        }

        Reference operator*() const {
            Node* const node = dynamic_cast<Node*>(this->node);

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
        friend bool operator==(const Iterator& left, const Iterator& right) {
            return left.getNode() == right.getNode();
        }

        friend bool operator!=(const Iterator& left, const Iterator& right) {
            return !(left == right);
        }
    };
} // namespace impl
