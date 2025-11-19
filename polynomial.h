/** @file Polynomial.h
 *  Polynomial Implementation Template
 *  Lab 3: Lists and Polynomial Calculator
 *  COSC-2436 Data Structures
 *
 *  TODO: Complete this Polynomial class implementation
 *  This file provides a starting structure for your Polynomial class.
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "linked_list.h"
#include <string>
#include <sstream>
#include <cmath>

// TODO: Define your Term structure
// Suggested structure:
// struct Term {
//     double coefficient;
//     int exponent;
//
//     Term(double coef = 0.0, int exp = 0)
//         : coefficient(coef), exponent(exp) {}
// };

struct Term
{
    double coefficient;
    int exponent;

    Term(double coefficient = 0.0, int exponent= 0)
    : coefficient(coefficient), exponent(exponent)
    {}
};
/**
 * @brief Polynomial class that stores terms in a LinkedList
 *
 * Implementation Requirements:
 * - Store terms in descending order by exponent (highest degree first)
 * - Automatically exclude terms with zero coefficients
 * - Automatically combine like terms (same exponent)
 * - Support arithmetic operations: +, -, *
 * - Support evaluation at a given x value
 * - Support derivative computation
 */
class Polynomial 
{
private:
    // TODO: Declare your data member(s)
    // Hint: Use LinkedList<Term> to store the polynomial terms
    // Example: LinkedList<Term> terms;
    LinkedList<Term> terms;


public:
    // Compiler-generated special members work fine since LinkedList handles its own copying
    Polynomial() = default;
    ~Polynomial() = default;
    Polynomial(const Polynomial& other) = default;
    Polynomial& operator=(const Polynomial& other) = default;

    /**
     * @brief Add a term to the polynomial
     * @param coefficient The coefficient of the term
     * @param exponent The exponent of the term (must be non-negative)
     *
     * Implementation hints:
     * - Ignore terms with coefficient of 0.0
     * - If term with same exponent exists, combine coefficients
     * - Maintain terms in descending order by exponent
     * - If combined coefficient becomes 0.0, remove the term
     */
    void addTerm(double coefficient, int exponent) 
    {
        // TODO: Implement addTerm
        // Steps:
        // 1. Check if coefficient is zero - if so, return
        // 2. Search for existing term with same exponent
        // 3. If found, add coefficients
        // 4. If not found, insert in correct position (descending order)
        // 5. If resulting coefficient is zero, remove the term

        if (coefficient <= 0)
        {
            return;
        }
        Term newTerm(coefficient, exponent);

        if(terms.isEmpty())
        {
            terms.insert(0,newTerm);
            return;
        }

        for (int i = 0; i < terms.getLength(); i++)
        {
            Term currentTerm = terms.getEntry(i);

            if (currentTerm.exponent == exponent)
            {
                double newCoefficient = currentTerm.coefficient + coefficient;

                if(newCoefficient == 0.0)
                {
                    terms.remove(i);
                }
                else
                {
                    terms.replace(i, Term(newCoefficient,exponent));
                }
                return;
            }
            if(exponent > currentTerm.exponent)
            {
                terms.insert(i, newTerm);
                return;
            }
        }
        terms.insert(terms.getLength(), newTerm);
    }

    /**
     * @brief Evaluate the polynomial at a given value of x
     * @param x The value at which to evaluate
     * @return The result of evaluating the polynomial at x
     *
     * Hint: Use Horner's method or simply sum each term: coef * x^exp
     */
    double evaluate(double x) const 
    {
        // TODO: Implement evaluate

        if (terms.isEmpty())
        {
            return 0.0;
        }
        double result;

        int currentExponent = terms.getEntry(0).exponent;

        for (int i = 0; i < terms.getLength(); i++)
        {
            Term item_term = terms.getEntry(i);
            while(currentExponent > item_term.exponent)
            {
                result *= x;
                currentExponent--;
            }

            result += item_term.coefficient;
            if (currentExponent > 0)
            {
                result *= x;
                currentExponent--;
            }

        }
        while(currentExponent > 0)
        {
            result *= x;
            currentExponent--;
        }

        return result;  // Placeholder
    }

    /**
     * @brief Get the degree of the polynomial
     * @return The highest exponent, or -1 if polynomial is zero
     */
    int degree() const {
        // TODO: Implement degree
        // Hint: If list is empty, return -1
        //       Otherwise, return exponent of first term (highest degree)
        
        if (terms.isEmpty())
        {
            return -1;
        }
        int highestDegreeVariable = terms.getEntry(0).exponent;

        for (int i = 0; i < terms.getLength(); i++)
        {
            int currentExponent = terms.getEntry(i).exponent;
            if (currentExponent > highestDegreeVariable)
            {
                highestDegreeVariable = currentExponent;
            }
        }    
        return highestDegreeVariable;  // Placeholder
    }

    /**
     * @brief Get the coefficient of a term with given exponent
     * @param exponent The exponent to query
     * @return The coefficient, or 0.0 if term doesn't exist
     */
    double getCoefficient(int exponent) const {
        // TODO: Implement getCoefficient
        if (terms.isEmpty())
        {
            return 0.0;
        }

        for (int i = 0; i < terms.getLength(); i++)
        {
            Term currentTerm = terms.getEntry(i);

            if (currentTerm.exponent == exponent)
            {
                return currentTerm.exponent;
            }
        }
        
        return 0.0;  // Placeholder
    }

    /**
     * @brief Check if polynomial is the zero polynomial
     * @return true if no terms exist
     */
    bool isZero() const 
    {
        // TODO: Implement isZero

        if (terms.isEmpty())
        {
            return true;  // Placeholder
        }

        for (int i = 0; i < terms.getLength(); i++)
        {
            if(terms.getEntry(i).coefficient != 0.0)
            {
                return false;
            }
        }
        return true;
        
    }

    /**
     * @brief Convert polynomial to string representation
     * @return String like "3x^2 + 2x - 1" or "0" for zero polynomial
     *
     * Formatting requirements:
     * - Terms in descending order by exponent
     * - Use "+" for positive terms (except first), "-" for negative
     * - Omit coefficient of 1 (except for constant term): "x^2" not "1x^2"
     * - Omit exponent of 1: "2x" not "2x^1"
     * - Omit "x^0" for constant: "5" not "5x^0"
     * - Special case: return "0" for zero polynomial
     */
    std::string toString() const {
        // TODO: Implement toString
        return "0";  // Placeholder
    }

    /**
     * @brief Compute the derivative of this polynomial
     * @return A new polynomial representing d/dx of this polynomial
     *
     * Hint: Derivative of ax^n is (n*a)x^(n-1)
     *       Derivative of constant is 0
     */
    Polynomial derivative() const {
        // TODO: Implement derivative
        // For each term: coef*x^exp -> (exp*coef)*x^(exp-1)
        return Polynomial();  // Placeholder
    }

    /**
     * @brief Add two polynomials using + operator
     * @param other The polynomial to add
     * @return A new polynomial representing this + other
     */
    Polynomial operator+(const Polynomial& other) const {
        // TODO: Implement operator+
        return Polynomial();  // Placeholder
    }

    /**
     * @brief Subtract two polynomials using - operator
     * @param other The polynomial to subtract
     * @return A new polynomial representing this - other
     */
    Polynomial operator-(const Polynomial& other) const {
        // TODO: Implement operator-
        return Polynomial();  // Placeholder
    }

    /**
     * @brief Multiply two polynomials using * operator
     * @param other The polynomial to multiply
     * @return A new polynomial representing this * other
     *
     * Hint: Multiply each term in this by each term in other
     *       (a*x^m) * (b*x^n) = (a*b)*x^(m+n)
     */
    Polynomial operator*(const Polynomial& other) const {
        // TODO: Implement operator*
        return Polynomial();  // Placeholder
    }
};

#endif // POLYNOMIAL_H
