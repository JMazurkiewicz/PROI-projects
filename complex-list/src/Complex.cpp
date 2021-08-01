#include "Complex.h"

#include <ostream>

Complex::Complex(Real real, Real imag)
    : real(real)
    , imag(imag) { }

Real Complex::getRealPart() const {
    return real;
}

Real Complex::getImagPart() const {
    return imag;
}

void Complex::setRealPart(Real newValue) {
    real = newValue;
}

void Complex::setImagPart(Real newValue) {
    imag = newValue;
}

Complex& Complex::operator+=(const Complex& other) {
    real += other.real;
    imag += other.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    real -= other.real;
    imag -= other.imag;
    return *this;
}

Complex operator+(const Complex& value) {
    return value;
}

Complex operator-(const Complex& value) {
    return Complex{-value.getRealPart(), -value.getImagPart()};
}

Complex operator+(const Complex& left, const Complex& right) {
    return Complex{left} += right;
}

Complex operator-(const Complex& left, const Complex& right) {
    return Complex{left} -= right;
}

bool operator==(const Complex& left, const Complex& right) {
    return (left.getRealPart() == right.getRealPart()) &&
           (left.getImagPart() == right.getImagPart());
}

bool operator!=(const Complex& left, const Complex& right) {
    return !(left == right);
}

Complex operator""_i(long double value) {
    return Complex{0.0, static_cast<Real>(value)};
}

Complex operator""_i(unsigned long long value) {
    return Complex{0.0, static_cast<Real>(value)};
}

std::ostream& operator<<(std::ostream& stream, const Complex& value) {
    const auto showposFlag = stream.flags() & std::ios_base::showpos;

    if(value.getRealPart() != 0 || value.getImagPart() == 0) {
        stream << value.getRealPart() << std::showpos;
    }

    if(value.getImagPart() != 0) {
        stream << value.getImagPart() << 'i';
    }

    if(showposFlag == 0) {
        stream << std::noshowpos;
    }

    return stream;
}
