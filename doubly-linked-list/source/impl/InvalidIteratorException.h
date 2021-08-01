#pragma once

#include <stdexcept>

enum InvalidIteratorErrorCode {
    INCREMENTING_NULL_ITERATOR,
    DECREMENTING_NULL_ITERATOR,
    DEREFERENCING_INVALID_ITERATOR
};

class InvalidIteratorException : public std::runtime_error {
public:
    explicit InvalidIteratorException(InvalidIteratorErrorCode code)
        : runtime_error(makeWhat(code))
        , code{code} { }

    InvalidIteratorErrorCode getCode() const {
        return code;
    }

private:
    InvalidIteratorErrorCode code;

    static const char* makeWhat(InvalidIteratorErrorCode code) {
        switch(code) {
        case INCREMENTING_NULL_ITERATOR:
            return "incrementing null interator";

        case DECREMENTING_NULL_ITERATOR:
            return "decrementing null iterator";

        case DEREFERENCING_INVALID_ITERATOR:
            return "dereferencing invalid iterator";

        default:
            return "unknown error";
        }
    }
};
