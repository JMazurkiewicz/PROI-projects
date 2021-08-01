#include "QuadraticEquationSolver.h"

#include <cmath>
#include <iomanip>

QuadraticEquationSolver::QuadraticEquationSolver(
    const QuadraticEquation& equation)
    : equation(equation)
    , discriminant(equation.calculateDiscriminant()) {
    prepareStream();

    if(discriminant > 0) {
        writeTwoSolutions();
    } else if(discriminant == 0) {
        writeOneSolution();
    } else {
        writeTwoComplexSolutions();
    }
}

void QuadraticEquationSolver::printSolutions(std::ostream& stream) {
    stream << stringBuilder.str() << '\n';
}

void QuadraticEquationSolver::prepareStream() {
    stringBuilder << std::fixed;
    stringBuilder << std::setprecision(4);
}

void QuadraticEquationSolver::writeTwoSolutions() {
    const double discriminantSqrt = std::sqrt(discriminant);
    const double denominator = 2 * equation.getACoefficient();

    const double solution1 =
        (-equation.getBCoefficient() + discriminantSqrt) / denominator;
    const double solution2 =
        (-equation.getBCoefficient() - discriminantSqrt) / denominator;

    stringBuilder << "x = " << solution1 << " or x = " << solution2;
}

void QuadraticEquationSolver::writeOneSolution() {
    const double solution =
        -equation.getBCoefficient() / (2 * equation.getACoefficient());
    stringBuilder << "x = " << solution;
}

void QuadraticEquationSolver::writeTwoComplexSolutions() {
    const Complex discriminantSqrt = std::sqrt(Complex{discriminant, 0.0});
    const double denominator = 2 * equation.getACoefficient();

    const Complex solution1 =
        (-equation.getBCoefficient() + discriminantSqrt) / denominator;
    const Complex solution2 =
        (-equation.getBCoefficient() - discriminantSqrt) / denominator;

    stringBuilder << "No real solutions: ";
    writeSingleComplexSolution(solution1);
    stringBuilder << " or ";
    writeSingleComplexSolution(solution2);
}

void QuadraticEquationSolver::writeSingleComplexSolution(
    const Complex& solution) {
    stringBuilder << "x = ";

    if(solution.real() != 0) {
        stringBuilder << solution.real() << std::showpos;
    }

    stringBuilder << solution.imag() << 'i';
    stringBuilder << std::noshowpos;
}
