#pragma once

#include "ListHeader.h"
#include "NodeAllocator.h"
#include "NodeBase.h"
#include <type_traits>

namespace impl {
    template<typename ValueT>
    class ListImpl : private NodeAllocator<ValueT> {
    public:
        using ValueType = ValueT;
        using Node = typename impl::NodeAllocator<ValueType>::Node;
        using SizeType = std::size_t;

    private:
        ListHeader header;

    public:
        ListImpl() = default;

        ListImpl(const ListImpl& other) {
            copyAppendFrom(other);
        }

        template<typename InputIt>
        explicit ListImpl(InputIt first, InputIt last) {
            for(; first != last; ++first) {
                emplace(getHeader(), *first);
            }
        }

        ~ListImpl() {
            clear();
        }

        void clear() {
            for(NodeBase* node = getHead(); node != getHeader();) {
                NodeBase* const nextNode = node->getNextNode();
                this->destroyAndFree(dynamic_cast<Node*>(node));
                node = nextNode;
            }
        }

        ListImpl& operator=(const ListImpl& other) = delete;

        void copyAppendFrom(const ListImpl& other) {
            NodeBase* const head = other.getHead();
            NodeBase* const tail = other.getTail();

            for(NodeBase* node = head; true; node = node->getNextNode()) {
                emplace(getHeader(), static_cast<Node*>(node)->getValue());

                if(node == tail) {
                    break;
                }
            }
        }

        void moveAppendFrom(ListImpl&& other) {
            other.getHead()->hookFront(this->getTail());
            other.getTail()->hookFront(this->getHeader());
            header.size += other.getSize();

            other.getHeader()->reset();
        }

        template<typename... Args>
        void emplace(NodeBase* nextNode, Args&&... args) {
            Node* const newNode =
                this->allocAndConstruct(std::forward<Args>(args)...);
            newNode->hookBefore(nextNode);
            ++header.size;
        }

        void erase(NodeBase* node) {
            node->unhook();
            this->destroyAndFree(static_cast<Node*>(node));
            --header.size;
        }

        NodeBase* getHead() const {
            return header.getNextNode();
        }

        NodeBase* getTail() const {
            return header.getPrevNode();
        }

        NodeBase* getHeader() {
            return &header;
        }

        const NodeBase* getHeader() const {
            return &header;
        }

        SizeType getSize() const {
            return header.size;
        }
    };
} // namespace impl
