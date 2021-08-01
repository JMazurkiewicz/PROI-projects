#include "QuadraticEquation.h"

#include <stdexcept>

QuadraticEquation::QuadraticEquation(double a, double b, double c)
    : a(a)
    , b(b)
    , c(c) {
    if(a == 0) {
        throw std::logic_error{"\'a\' coefficient cannot be equal to zero"};
    }
}

double QuadraticEquation::getACoefficient() const {
    return a;
}

double QuadraticEquation::getBCoefficient() const {
    return b;
}

double QuadraticEquation::getCCoefficient() const {
    return c;
}

double QuadraticEquation::calculateDiscriminant() const {
    return getBCoefficient() * getBCoefficient() -
           4 * getACoefficient() * getCCoefficient();
}
