#include "QuadraticEquation.h"
#include "QuadraticEquationSolver.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std::string_literals;

class Program {
private:
    enum ArgsIndices : std::size_t {
        PATH,
        ACOEFF,
        BCOEFF,
        CCOEFF,
        ERROR_CODE,
    };

    enum ErrorCode {
        MEMORY_LEAK = 'M',
        SEGMENTATION_FAULT = 'S',
    };

    static constexpr std::size_t MIN_ARG_COUNT = 4;
    static constexpr std::size_t ARG_ERROR_COUNT = 5;

public:
    void mainfn(std::vector<std::string>& args) {
        if(args.size() < MIN_ARG_COUNT) {
            throw std::runtime_error{"Invalid amount of program arguments "
                                     "(expected three floating point values)"};
        } else {
            QuadraticEquation equation = makeEquation(args);
            QuadraticEquationSolver solver(equation);
            solver.printSolutions(std::cout);

            if(args.size() == ARG_ERROR_COUNT) {
                makeError(args[ERROR_CODE]);
            }
        }
    }

private:
    QuadraticEquation makeEquation(const std::vector<std::string>& args) const {
        try {
            const double aCoefficient = std::stod(args[ACOEFF]);
            const double bCoefficient = std::stod(args[BCOEFF]);
            const double cCoefficient = std::stod(args[CCOEFF]);

            return QuadraticEquation{aCoefficient, bCoefficient, cCoefficient};
        } catch(std::invalid_argument& e) {
            throw std::invalid_argument{"Invalid program input ("s + e.what() +
                                        ')'};
        }
    }

    void makeError(const std::string& errorCode) {
        const char errorSymbol = errorCode.front();

        switch(errorSymbol) {
        case MEMORY_LEAK:
            new int[1'000'000];
            break;

        case SEGMENTATION_FAULT:
            *static_cast<volatile int*>(nullptr) = 0;
            break;
        }
    }
};

int main(int argc, char* argv[]) {
    try {
        Program program;
        std::vector<std::string> args(argv, argv + argc);
        program.mainfn(args);

    } catch(std::exception& e) {
        std::cerr << "Fatal error: \"" << e.what() << "\"\n";
    }
}
