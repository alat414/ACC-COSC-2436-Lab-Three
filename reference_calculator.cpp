/** @file reference_calculator.cpp
 *  Reference Solution - Complete Calculator Implementation
 *  Lab 3: Lists and Polynomial Calculator
 *  COSC-2436 Data Structures
 *  Fall 2025
 *
 *  This is the instructor's reference solution.
 *  Students should NOT have access to this file.
 */

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

// Include the List ADT implementations
#include "../../ListADT.h"
#include "../../ArrayList.h"
#include "../../LinkedList.h"

// Include reference Polynomial implementation
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

    void createPolynomial(const string& name, int numTerms) {
        Polynomial poly;

        cout << "Enter " << numTerms << " terms (coefficient exponent):\n";
        cout.flush();
        for (int i = 0; i < numTerms; ++i) {
            double coef;
            int exp;
            cin >> coef >> exp;
            poly.addTerm(coef, exp);
        }

        polynomials[name] = poly;
        cout << "Polynomial '" << name << "' created: " << poly.toString() << "\n";
        cout.flush();
    }

    void printPolynomial(const string& name) {
        if (!polynomialExists(name)) {
            cout << "Error: Polynomial '" << name << "' not found.\n";
            return;
        }

        cout << name << " = " << polynomials[name].toString() << "\n";
    }

    void evaluatePolynomial(const string& name, double x) {
        if (!polynomialExists(name)) {
            cout << "Error: Polynomial '" << name << "' not found.\n";
            return;
        }

        double result = polynomials[name].evaluate(x);
        cout << name << "(" << x << ") = " << result << "\n";
    }

    void addPolynomials(const string& name1, const string& name2, const string& result) {
        if (!polynomialExists(name1)) {
            cout << "Error: Polynomial '" << name1 << "' not found.\n";
            return;
        }
        if (!polynomialExists(name2)) {
            cout << "Error: Polynomial '" << name2 << "' not found.\n";
            return;
        }

        Polynomial sum = polynomials[name1] + polynomials[name2];
        polynomials[result] = sum;
        cout << result << " = " << sum.toString() << "\n";
    }

    void subtractPolynomials(const string& name1, const string& name2, const string& result) {
        if (!polynomialExists(name1)) {
            cout << "Error: Polynomial '" << name1 << "' not found.\n";
            return;
        }
        if (!polynomialExists(name2)) {
            cout << "Error: Polynomial '" << name2 << "' not found.\n";
            return;
        }

        Polynomial diff = polynomials[name1] - polynomials[name2];
        polynomials[result] = diff;
        cout << result << " = " << diff.toString() << "\n";
    }

    void multiplyPolynomials(const string& name1, const string& name2, const string& result) {
        if (!polynomialExists(name1)) {
            cout << "Error: Polynomial '" << name1 << "' not found.\n";
            return;
        }
        if (!polynomialExists(name2)) {
            cout << "Error: Polynomial '" << name2 << "' not found.\n";
            return;
        }

        Polynomial product = polynomials[name1] * polynomials[name2];
        polynomials[result] = product;
        cout << result << " = " << product.toString() << "\n";
    }

    void derivativePolynomial(const string& name, const string& result) {
        if (!polynomialExists(name)) {
            cout << "Error: Polynomial '" << name << "' not found.\n";
            return;
        }

        Polynomial deriv = polynomials[name].derivative();
        polynomials[result] = deriv;
        cout << result << " = " << deriv.toString() << "\n";
    }

    void showDegree(const string& name) {
        if (!polynomialExists(name)) {
            cout << "Error: Polynomial '" << name << "' not found.\n";
            return;
        }

        int deg = polynomials[name].degree();
        cout << "degree(" << name << ") = " << deg << "\n";
    }

    void listPolynomials() {
        if (polynomials.empty()) {
            cout << "No polynomials stored.\n";
            return;
        }

        cout << "\nStored polynomials:\n";
        cout << "==================\n";
        for (const auto& pair : polynomials) {
            cout << pair.first << " = " << pair.second.toString() << "\n";
        }
        cout << "\n";
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
