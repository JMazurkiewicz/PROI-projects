#pragma once

class QuadraticEquation {
public:
    explicit QuadraticEquation(double a, double b, double c);

    double getACoefficient() const;
    double getBCoefficient() const;
    double getCCoefficient() const;

    double calculateDiscriminant() const;

private:
    double a, b, c;
};
