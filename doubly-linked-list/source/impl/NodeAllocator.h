#pragma once

#include "Node.h"

#include <utility>

namespace impl {
    template<typename ValueT>
    struct NodeAllocator {
        using Node = impl::Node<ValueT>;

        template<typename... Args>
        Node* allocAndConstruct(Args&&... args) {
            return new Node(std::forward<Args>(args)...);
        }

        void destroyAndFree(Node* ptr) {
            delete ptr;
        }
    };
} // namespace impl
