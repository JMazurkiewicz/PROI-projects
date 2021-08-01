#pragma once

#include "ConstIterator.h"
#include <ostream>

namespace impl {
    template<typename CharT, typename Traits, typename T>
    void printList(std::basic_ostream<CharT, Traits>& stream,
                   ConstIterator<T> first, ConstIterator<T> last) {
        stream << '[';

        if(first != last) {
            stream << *first;
            while(++first != last) {
                stream << ", " << *first;
            }
        }

        stream << ']';
    }
} // namespace impl
