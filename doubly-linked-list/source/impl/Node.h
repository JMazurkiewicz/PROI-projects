#pragma once

#include "NodeBase.h"

#include <utility>

namespace impl {
    template<typename ValueT>
    class Node : public NodeBase {
    public:
        using ValueType = ValueT;

        template<typename... Args>
        Node(Args&&... args)
            : NodeBase()
            , value(std::forward<Args>(args)...) { }

        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;

        ValueType& getValue() {
            return value;
        }

        const ValueType& getValue() const {
            return value;
        }

    private:
        ValueType value;
    };
} // namespace impl
