/** @file calculator_main.cpp
 *  Lab 3: Lists and Polynomial Calculator
 *  COSC-2436 Data Structures
 *
 *  INSTRUCTIONS:
 *  1. Complete the Polynomial class in Polynomial.h
 *  2. Implement the TODO methods below to make the calculator functional
 *
 *  USAGE:
 *  - Interactive mode: ./build/calculator
 *  - File input mode: ./build/calculator < test_input_basic.txt
 */

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <limits>

// Include the List ADT implementations
#include "list_adt.h"
#include "array_list.h"
#include "linked_list.h"

#include "polynomial.h"

// removed namespace std.

class PolynomialCalculator 
{
    private:
        std::map<std::string, Polynomial> polynomials;

        void showHelp() 
        {
            std::cout << "\n=== Polynomial Calculator Commands ===\n";
            std::cout << "POLY <name> <num_terms>      - Create polynomial (then enter terms)\n";
            std::cout << "PRINT <name>                 - Display polynomial\n";
            std::cout << "EVAL <name> <x>              - Evaluate polynomial at x\n";
            std::cout << "ADD <p1> <p2> <result>       - Add two polynomials\n";
            std::cout << "SUB <p1> <p2> <result>       - Subtract polynomials\n";
            std::cout << "MULT <p1> <p2> <result>      - Multiply polynomials\n";
            std::cout << "DERIV <name> <result>        - Compute derivative\n";
            std::cout << "DEGREE <name>                - Show polynomial degree\n";
            std::cout << "LIST                         - List all stored polynomials\n";
            std::cout << "HELP                         - Show this help message\n";
            std::cout << "QUIT                         - Exit calculator\n";
            std::cout << "=====================================\n\n";
        }

        bool polynomialExists(const std::string& name) 
        {
            return polynomials.find(name) != polynomials.end();
        }

        // TODO: Implement this method
        // Read numTerms pairs of (coefficient, exponent) from cin
        // Create a polynomial and store it in the map with the given name
        void createPolynomial(const std::string& name, int numTerms) 
        {
            if (numTerms <= 0)
            {
                std::cout << "cannot have negative number of variables." << std::endl;
                return;
            }
            Polynomial polynomial_function;

            for (int i = 0; i <= numTerms; i++)
            {
                double coefficient;
                int exponent;

                std::cout << "Term " << i << std::endl;
                std::cin >> coefficient >> exponent;

                if (std::cin.fail())
                {
                    std::cout << "Invalid input, numbers only " << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    i--;
                    continue;
                }
                polynomial_function.addTerm(coefficient, exponent);
            }
            
            polynomials[name] = polynomial_function;
            std::cout << "Polynomal: " << name << "created " << polynomial_function.toString() << std::endl;

        }

        // TODO: Implement this method
        // Print the polynomial with the given name
        void printPolynomial(const std::string& name) 
        {

            if (!polynomialExists(name))
            {
                std::cout << "No variables on function " << name << "cannot print function " << std::endl;
                return;
            }
            const Polynomial& polynomial_function = polynomials[name];
            std::cout << name << "=" << polynomial_function.toString() << std::endl;
        }

        // TODO: Implement this method
        // Evaluate the polynomial at the given x value
        void evaluatePolynomial(const std::string& name, double value) 
        {
            if(value == 0.0)
            {
                std::cout << "Value is zero, the result is zero." << std::endl;
            }

            auto polynomial_function = polynomials.find(name);
            if (polynomial_function == polynomials.end())
            {
                std::cout << "Error: Polynomial does not exist " << name << "not found" << std::endl;
                return;
            }
        
            double result = polynomial_function -> second.evaluate(value);
            std::cout << name << "(" << value << ")" << result << std::endl;
        }

        // TODO: Implement this method
        // Add two polynomials and store result
        void addPolynomials(const std::string& name1, const std::string& name2, const std::string& result) 
        {

            if (polynomials.count(name1) == 0)
            {
                std::cout << "Error: Polynomial one " << name1 << " does not exist " << std::endl;
                return;
            }

            if (polynomials.count(name2) == 0)
            {
                std::cout << "Error: Polynomial two " << name2 << " does not exist " << std::endl;
                return;
            }

            if (polynomials.count(result) > 0)
            {
                std::cout << "Overwriting existing polynomial  " << result  << std::endl;
            }

            Polynomial function_result = polynomials[name1] + polynomials[name2];

            polynomials[result] = function_result;

            std::cout << name1 << " (x) = " << polynomials[name1].toString() << std::endl;
            std::cout << name2 << " (x) = " << polynomials[name2].toString() << std::endl;
            std::cout << result << " (x) = " << function_result.toString() << std::endl;

        }

        // TODO: Implement this method
        // Subtract two polynomials and store result
        void subtractPolynomials(const std::string& name1, const std::string& name2, const std::string& result) 
        {
            if (polynomials.count(name1) == 0)
            {
                std::cout << "Error: Polynomial one " << name1 << " does not exist " << std::endl;
                return;
            }

            if (polynomials.count(name2) == 0)
            {
                std::cout << "Error: Polynomial two " << name2 << " does not exist " << std::endl;
                return;
            }

            if (polynomials.count(result) > 0)
            {
                std::cout << "Overwriting existing polynomial  " << result  << std::endl;
            }

            Polynomial function_result = polynomials[name1] - polynomials[name2];

            polynomials[result] = function_result;

            std::cout << name1 << " (x) = " << polynomials[name1].toString() << std::endl;
            std::cout << name2 << " (x) = " << polynomials[name2].toString() << std::endl;
            std::cout << result << " (x) = " << function_result.toString() << std::endl;

        }


        // TODO: Implement this method
        // Multiply two polynomials and store result
        void multiplyPolynomials(const std::string& name1, const std::string& name2, const std::string& result) 
        {
            if (polynomials.count(name1) == 0)
            {
                std::cout << "Error: Polynomial one " << name1 << " does not exist " << std::endl;
                return;
            }

            if (polynomials.count(name2) == 0)
            {
                std::cout << "Error: Polynomial two " << name2 << " does not exist " << std::endl;
                return;
            }

            if (polynomials.count(result) > 0)
            {
                std::cout << "Overwriting existing polynomial  " << result  << std::endl;
            }

            Polynomial function_result = polynomials[name1] * polynomials[name2];

            polynomials[result] = function_result;

            std::cout << name1 << " (x) = " << polynomials[name1].toString() << std::endl;
            std::cout << name2 << " (x) = " << polynomials[name2].toString() << std::endl;
            std::cout << result << " (x) = " << function_result.toString() << std::endl;

        }

        // TODO: Implement this method
        // Compute derivative of polynomial and store result
        void derivativePolynomial(const std::string& name, const std::string& result) 
        {
            if(!polynomialExists(name))
            {
                std::cout << "No polynomial function to take the derivative. " << std::endl;
                return;
            }

            if (polynomials.count(result) > 0)
            {
                std::cout << "Overwriting existing polynomial  " << result  << std::endl;
            }

            Polynomial function_result = polynomials[name].derivative();
            polynomials[result] = function_result;

            std::cout << name << " (x) = " << polynomials[name].toString() << std::endl;
            std::cout << result << " (x) = " << function_result.toString() << std::endl;

        }

        // TODO: Implement this method
        // Show the degree of the polynomial
        void showDegree(const std::string& name) 
        {
            if(polynomials.find(name) == polynomials.end())
            {
                std::cout << "No polynomial function to take the degree. " << std::endl;
                return;
            }

            int polynomial_degree = polynomials[name].degree();
            
            std::cout << name << " Highest degree of the polynomial is:  " << polynomial_degree << std::endl;

        }

        // TODO: Implement this method
        // List all stored polynomials
        void listPolynomials() 
        {
            if(polynomials.empty())
            {
                std::cout << "No polynomial function to print. " << std::endl;
                return;
            }
            
            std::cout << "\n Stored Polynomial Functions" << std::endl;

            for (const auto& [name, poly] : polynomials)
            {
                std::cout << name << " (x) = " << poly.toString() << std::endl;
            }
            std::cout << " Total variables:  " << polynomials.size() << " polynomial(s)" << std::endl;
        }

    

    public:
        void run() {
            std::cout << "===========================================\n";
            std::cout << "  Polynomial Calculator - COSC 2436 Lab 3  \n";
            std::cout << "===========================================\n";
            std::cout << "Type HELP for list of commands.\n\n";
            std::cout.flush();

            std::string command;
            while (true) {
                std::cout << "> " << std::flush;

                // Check cin state before reading
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                if (!(std::cin >> command)) {
                    break; // End of input
                }

                // Convert command to uppercase for case-insensitive matching
                for (char& c : command) {
                    c = toupper(c);
                }

                try {
                    if (command == "QUIT" || command == "EXIT") {
                        std::cout << "Goodbye!\n";
                        break;
                    }
                    else if (command == "HELP") {
                        showHelp();
                    }
                    else if (command == "LIST") {
                        listPolynomials();
                    }
                    else if (command == "POLY") {
                        std::string name;
                        int numTerms;
                        std::cin >> name >> numTerms;
                        createPolynomial(name, numTerms);
                    }
                    else if (command == "PRINT") {
                        std::string name;
                        std::cin >> name;
                        printPolynomial(name);
                    }
                    else if (command == "EVAL") {
                        std::string name;
                        double x;
                        std::cin >> name >> x;
                        evaluatePolynomial(name, x);
                    }
                    else if (command == "ADD") {
                        std::string name1, name2, result;
                        std::cin >> name1 >> name2 >> result;
                        addPolynomials(name1, name2, result);
                    }
                    else if (command == "SUB") {
                        std::string name1, name2, result;
                        std::cin >> name1 >> name2 >> result;
                        subtractPolynomials(name1, name2, result);
                    }
                    else if (command == "MULT") {
                        std::string name1, name2, result;
                        std::cin >> name1 >> name2 >> result;
                        multiplyPolynomials(name1, name2, result);
                    }
                    else if (command == "DERIV") {
                        std::string name, result;
                        std::cin >> name >> result;
                        derivativePolynomial(name, result);
                    }
                    else if (command == "DEGREE") {
                        std::string name;
                        std::cin >> name;
                        showDegree(name);
                    }
                    else {
                        std::cout << "Unknown command: " << command << "\n";
                        std::cout << "Type HELP for list of commands.\n";
                        // Clear rest of line
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
                catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << "\n";
                    // Clear error state and rest of line
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }
};

int main() {
    PolynomialCalculator calculator;
    calculator.run();
    return 0;
}
