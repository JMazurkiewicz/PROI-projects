#pragma once

#include <iosfwd>

using Real = double;

class Complex {
public:
    Complex(Real real = 0.0, Real imag = 0.0);

    Real getRealPart() const;
    Real getImagPart() const;

    void setRealPart(Real newValue);
    void setImagPart(Real newValue);

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);

private:
    Real real;
    Real imag;
};

Complex operator+(const Complex& value);
Complex operator-(const Complex& value);

Complex operator+(const Complex& left, const Complex& right);
Complex operator-(const Complex& left, const Complex& right);

bool operator==(const Complex& left, const Complex& right);
bool operator!=(const Complex& left, const Complex& right);

Complex operator""_i(long double value);
Complex operator""_i(unsigned long long value);

std::ostream& operator<<(std::ostream& stream, const Complex& value);
