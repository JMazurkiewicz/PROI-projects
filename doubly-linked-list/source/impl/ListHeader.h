#pragma once

#include "NodeBase.h"

#include <cstddef>

namespace impl {
    struct ListHeader : NodeBase {
        ListHeader()
            : size{0} { }

        void reset() override {
            NodeBase::reset();
            size = 0;
        }

        std::size_t size;
    };
} // namespace impl
