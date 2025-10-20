/** @file calculator_main.cpp
 *  Part 4: Interactive Polynomial Calculator
 *  Lab 3: Lists and Polynomial Calculator
 *  COSC-2436 Data Structures
 *  Fall 2025
 *
 *  INSTRUCTIONS:
 *  1. Complete the Polynomial class in Polynomial.h (Part 2B)
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

#include "Polynomial.h"

using namespace std;

class PolynomialCalculator {
private:
    map<string, Polynomial> polynomials;

    void showHelp() {
        cout << "\n=== Polynomial Calculator Commands ===\n";
        cout << "POLY <name> <num_terms>      - Create polynomial (then enter terms)\n";
        cout << "PRINT <name>                 - Display polynomial\n";
        cout << "EVAL <name> <x>              - Evaluate polynomial at x\n";
        cout << "ADD <p1> <p2> <result>       - Add two polynomials\n";
        cout << "SUB <p1> <p2> <result>       - Subtract polynomials\n";
        cout << "MULT <p1> <p2> <result>      - Multiply polynomials\n";
        cout << "DERIV <name> <result>        - Compute derivative\n";
        cout << "DEGREE <name>                - Show polynomial degree\n";
        cout << "LIST                         - List all stored polynomials\n";
        cout << "HELP                         - Show this help message\n";
        cout << "QUIT                         - Exit calculator\n";
        cout << "=====================================\n\n";
    }

    bool polynomialExists(const string& name) {
        return polynomials.find(name) != polynomials.end();
    }

    // TODO: Implement this method
    // Read numTerms pairs of (coefficient, exponent) from cin
    // Create a polynomial and store it in the map with the given name
    void createPolynomial(const string& name, int numTerms) {
        cout << "TODO: Implement createPolynomial\n";
        // Hint: Create a Polynomial object, read terms in a loop,
        //       add each term to the polynomial, store in map
    }

    // TODO: Implement this method
    // Print the polynomial with the given name
    void printPolynomial(const string& name) {
        cout << "TODO: Implement printPolynomial\n";
        // Hint: Check if polynomial exists, then use toString()
    }

    // TODO: Implement this method
    // Evaluate the polynomial at the given x value
    void evaluatePolynomial(const string& name, double x) {
        cout << "TODO: Implement evaluatePolynomial\n";
        // Hint: Check if polynomial exists, call evaluate(x), print result
    }

    // TODO: Implement this method
    // Add two polynomials and store result
    void addPolynomials(const string& name1, const string& name2, const string& result) {
        cout << "TODO: Implement addPolynomials\n";
        // Hint: Check both polynomials exist, use operator+, store result
    }

    // TODO: Implement this method
    // Subtract two polynomials and store result
    void subtractPolynomials(const string& name1, const string& name2, const string& result) {
        cout << "TODO: Implement subtractPolynomials\n";
        // Hint: Check both polynomials exist, use operator-, store result
    }

    // TODO: Implement this method
    // Multiply two polynomials and store result
    void multiplyPolynomials(const string& name1, const string& name2, const string& result) {
        cout << "TODO: Implement multiplyPolynomials\n";
        // Hint: Check both polynomials exist, use operator*, store result
    }

    // TODO: Implement this method
    // Compute derivative of polynomial and store result
    void derivativePolynomial(const string& name, const string& result) {
        cout << "TODO: Implement derivativePolynomial\n";
        // Hint: Check polynomial exists, call derivative(), store result
    }

    // TODO: Implement this method
    // Show the degree of the polynomial
    void showDegree(const string& name) {
        cout << "TODO: Implement showDegree\n";
        // Hint: Check polynomial exists, call degree(), print result
    }

    // TODO: Implement this method
    // List all stored polynomials
    void listPolynomials() {
        cout << "TODO: Implement listPolynomials\n";
        // Hint: Iterate through map, print each polynomial with its name
    }

public:
    void run() {
        cout << "===========================================\n";
        cout << "  Polynomial Calculator - COSC 2436 Lab 3  \n";
        cout << "===========================================\n";
        cout << "Type HELP for list of commands.\n\n";
        cout.flush();

        string command;
        while (true) {
            cout << "> " << flush;

            // Check cin state before reading
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (!(cin >> command)) {
                break; // End of input
            }

            // Convert command to uppercase for case-insensitive matching
            for (char& c : command) {
                c = toupper(c);
            }

            try {
                if (command == "QUIT" || command == "EXIT") {
                    cout << "Goodbye!\n";
                    break;
                }
                else if (command == "HELP") {
                    showHelp();
                }
                else if (command == "LIST") {
                    listPolynomials();
                }
                else if (command == "POLY") {
                    string name;
                    int numTerms;
                    cin >> name >> numTerms;
                    createPolynomial(name, numTerms);
                }
                else if (command == "PRINT") {
                    string name;
                    cin >> name;
                    printPolynomial(name);
                }
                else if (command == "EVAL") {
                    string name;
                    double x;
                    cin >> name >> x;
                    evaluatePolynomial(name, x);
                }
                else if (command == "ADD") {
                    string name1, name2, result;
                    cin >> name1 >> name2 >> result;
                    addPolynomials(name1, name2, result);
                }
                else if (command == "SUB") {
                    string name1, name2, result;
                    cin >> name1 >> name2 >> result;
                    subtractPolynomials(name1, name2, result);
                }
                else if (command == "MULT") {
                    string name1, name2, result;
                    cin >> name1 >> name2 >> result;
                    multiplyPolynomials(name1, name2, result);
                }
                else if (command == "DERIV") {
                    string name, result;
                    cin >> name >> result;
                    derivativePolynomial(name, result);
                }
                else if (command == "DEGREE") {
                    string name;
                    cin >> name;
                    showDegree(name);
                }
                else {
                    cout << "Unknown command: " << command << "\n";
                    cout << "Type HELP for list of commands.\n";
                    // Clear rest of line
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << "\n";
                // Clear error state and rest of line
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
};

int main() {
    PolynomialCalculator calculator;
    calculator.run();
    return 0;
}
