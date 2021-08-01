#pragma once

#include "QuadraticEquation.h"

#include <complex>
#include <ostream>
#include <sstream>

using Complex = std::complex<double>;

class QuadraticEquationSolver {
public:
    explicit QuadraticEquationSolver(const QuadraticEquation& equation);

    void printSolutions(std::ostream& stream);

private:
    void prepareStream();

    void writeTwoSolutions();
    void writeOneSolution();

    void writeTwoComplexSolutions();
    void writeSingleComplexSolution(const Complex& solution);

    const QuadraticEquation& equation;
    const double discriminant;

    std::ostringstream stringBuilder;
};
