/** @file polynomial_tests.cpp
 *  Polynomial Class Unit Tests
 *  COSC-2436 Data Structures
 *  Fall 2025
 *
 *  This file contains comprehensive unit tests for the Polynomial class.
 *  Students can use these tests to verify their Polynomial implementation.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "polynomial.h"

// ============================================================================
// PART 2B: Polynomial Class Tests
// ============================================================================

TEST_CASE("Polynomial - Add Single Term") {
    Polynomial p;
    p.addTerm(3.0, 2);

    p.debugDump();

    CHECK_FALSE(p.isZero());
    CHECK(p.degree() == 2);
    CHECK(p.getCoefficient(2) == doctest::Approx(3.0));
}

TEST_CASE("Polynomial - Like Terms Combined") {
    Polynomial p;
    p.addTerm(3.0, 2);
    p.addTerm(2.0, 2);  // Should combine with previous
    CHECK(p.getCoefficient(2) == doctest::Approx(5.0));
}

TEST_CASE("Polynomial - Terms Cancel to Zero") {
    Polynomial p;
    p.addTerm(5.0, 3);
    p.addTerm(-5.0, 3);  // Should cancel out
    CHECK(p.isZero());
}

TEST_CASE("Polynomial - Multiple Terms") {
    Polynomial p;  // 4x^3 + 3x^2 + 2x + 1
    p.addTerm(4.0, 3);
    p.addTerm(3.0, 2);
    p.addTerm(2.0, 1);
    p.addTerm(1.0, 0);

    CHECK(p.degree() == 3);
    CHECK(p.getCoefficient(3) == doctest::Approx(4.0));
    CHECK(p.getCoefficient(2) == doctest::Approx(3.0));
    CHECK(p.getCoefficient(1) == doctest::Approx(2.0));
    CHECK(p.getCoefficient(0) == doctest::Approx(1.0));
}

TEST_CASE("Polynomial - Evaluation at Zero") {
    Polynomial p;  // 3x^2 + 2x + 1
    p.addTerm(3.0, 2);
    p.addTerm(2.0, 1);
    p.addTerm(1.0, 0);

    CHECK(p.evaluate(0.0) == doctest::Approx(1.0));
}

TEST_CASE("Polynomial - Evaluation at One") {
    Polynomial p;  // 3x^2 + 2x + 1
    p.addTerm(3.0, 2);
    p.addTerm(2.0, 1);
    p.addTerm(1.0, 0);

    CHECK(p.evaluate(1.0) == doctest::Approx(6.0));
}

TEST_CASE("Polynomial - Evaluation at Two") {
    Polynomial p;  // 3x^2 + 2x + 1
    p.addTerm(3.0, 2);
    p.addTerm(2.0, 1);
    p.addTerm(1.0, 0);

    CHECK(p.evaluate(2.0) == doctest::Approx(17.0));
}

TEST_CASE("Polynomial - Evaluation Negative x") {
    Polynomial p;  // x^2 + 2x + 1
    p.addTerm(1.0, 2);
    p.addTerm(2.0, 1);
    p.addTerm(1.0, 0);

    CHECK(p.evaluate(-1.0) == doctest::Approx(0.0));
}

TEST_CASE("Polynomial - Addition Simple") {
    Polynomial p1, p2;
    p1.addTerm(3.0, 2);  // 3x^2
    p1.addTerm(1.0, 0);  // + 1

    p2.addTerm(1.0, 2);  // x^2
    p2.addTerm(1.0, 0);  // + 1

    Polynomial sum = p1 + p2;  // 4x^2 + 2
    CHECK(sum.getCoefficient(2) == doctest::Approx(4.0));
    CHECK(sum.getCoefficient(0) == doctest::Approx(2.0));
}

TEST_CASE("Polynomial - Addition Different Degrees") {
    Polynomial p1, p2;
    p1.addTerm(2.0, 3);  // 2x^3
    p1.addTerm(1.0, 1);  // + x

    p2.addTerm(3.0, 2);  // 3x^2
    p2.addTerm(1.0, 0);  // + 1

    Polynomial sum = p1 + p2;  // 2x^3 + 3x^2 + x + 1
    CHECK(sum.degree() == 3);
    CHECK(sum.getCoefficient(3) == doctest::Approx(2.0));
    CHECK(sum.getCoefficient(2) == doctest::Approx(3.0));
    CHECK(sum.getCoefficient(1) == doctest::Approx(1.0));
    CHECK(sum.getCoefficient(0) == doctest::Approx(1.0));
}

TEST_CASE("Polynomial - Subtraction Simple") {
    Polynomial p1, p2;
    p1.addTerm(5.0, 2);  // 5x^2
    p2.addTerm(2.0, 2);  // 2x^2

    Polynomial diff = p1 - p2;  // 3x^2
    CHECK(diff.getCoefficient(2) == doctest::Approx(3.0));
}

TEST_CASE("Polynomial - Subtraction Result Zero") {
    Polynomial p1, p2;
    p1.addTerm(3.0, 2);  // 3x^2
    p2.addTerm(3.0, 2);  // 3x^2

    Polynomial diff = p1 - p2;  // 0
    CHECK(diff.isZero());
}

TEST_CASE("Polynomial - Subtraction Different Terms") {
    Polynomial p1, p2;
    p1.addTerm(5.0, 3);  // 5x^3
    p1.addTerm(3.0, 1);  // + 3x

    p2.addTerm(2.0, 2);  // 2x^2
    p2.addTerm(1.0, 0);  // + 1

    Polynomial diff = p1 - p2;  // 5x^3 - 2x^2 + 3x - 1
    CHECK(diff.getCoefficient(3) == doctest::Approx(5.0));
    CHECK(diff.getCoefficient(2) == doctest::Approx(-2.0));
    CHECK(diff.getCoefficient(1) == doctest::Approx(3.0));
    CHECK(diff.getCoefficient(0) == doctest::Approx(-1.0));
}

TEST_CASE("Polynomial - Multiplication Simple") {
    Polynomial p1, p2;
    p1.addTerm(2.0, 1);  // 2x
    p2.addTerm(3.0, 1);  // 3x

    Polynomial product = p1 * p2;  // 6x^2
    CHECK(product.degree() == 2);
    CHECK(product.getCoefficient(2) == doctest::Approx(6.0));
}

TEST_CASE("Polynomial - Multiplication Binomials") {
    Polynomial p1, p2;
    p1.addTerm(2.0, 1);  // 2x
    p1.addTerm(1.0, 0);  // + 1

    p2.addTerm(3.0, 1);  // 3x
    p2.addTerm(-1.0, 0); // - 1

    Polynomial product = p1 * p2;  // 6x^2 + x - 1
    CHECK(product.getCoefficient(2) == doctest::Approx(6.0));
    CHECK(product.getCoefficient(1) == doctest::Approx(1.0));
    CHECK(product.getCoefficient(0) == doctest::Approx(-1.0));
}

TEST_CASE("Polynomial - Multiplication Trinomials") {
    Polynomial p1, p2;
    p1.addTerm(1.0, 2);  // x^2
    p1.addTerm(2.0, 1);  // + 2x
    p1.addTerm(1.0, 0);  // + 1

    p2.addTerm(1.0, 1);  // x
    p2.addTerm(1.0, 0);  // + 1

    Polynomial product = p1 * p2;  // x^3 + 3x^2 + 3x + 1
    CHECK(product.degree() == 3);
    CHECK(product.getCoefficient(3) == doctest::Approx(1.0));
    CHECK(product.getCoefficient(2) == doctest::Approx(3.0));
    CHECK(product.getCoefficient(1) == doctest::Approx(3.0));
    CHECK(product.getCoefficient(0) == doctest::Approx(1.0));
}

TEST_CASE("Polynomial - Derivative Linear") {
    Polynomial p;
    p.addTerm(3.0, 1);  // 3x
    p.addTerm(2.0, 0);  // + 2

    Polynomial deriv = p.derivative();  // 3
    CHECK(deriv.degree() == 0);
    CHECK(deriv.getCoefficient(0) == doctest::Approx(3.0));
}

TEST_CASE("Polynomial - Derivative Quadratic") {
    Polynomial p;
    p.addTerm(2.0, 2);  // 2x^2
    p.addTerm(3.0, 1);  // + 3x
    p.addTerm(1.0, 0);  // + 1

    Polynomial deriv = p.derivative();  // 4x + 3
    CHECK(deriv.degree() == 1);
    CHECK(deriv.getCoefficient(1) == doctest::Approx(4.0));
    CHECK(deriv.getCoefficient(0) == doctest::Approx(3.0));
}

TEST_CASE("Polynomial - Derivative Cubic") {
    Polynomial p;  // 3x^3 + 2x^2 + x
    p.addTerm(3.0, 3);
    p.addTerm(2.0, 2);
    p.addTerm(1.0, 1);

    Polynomial deriv = p.derivative();  // 9x^2 + 4x + 1
    CHECK(deriv.getCoefficient(2) == doctest::Approx(9.0));
    CHECK(deriv.getCoefficient(1) == doctest::Approx(4.0));
    CHECK(deriv.getCoefficient(0) == doctest::Approx(1.0));
}

TEST_CASE("Polynomial - Chained Operations") {
    Polynomial p1, p2, p3;
    p1.addTerm(1.0, 1);  // x
    p1.addTerm(1.0, 0);  // + 1

    p2.addTerm(1.0, 1);  // x
    p2.addTerm(-1.0, 0); // - 1

    // (x+1)(x-1) = x^2 - 1
    Polynomial product = p1 * p2;
    CHECK(product.getCoefficient(2) == doctest::Approx(1.0));

    CHECK(product.getCoefficient(1) == doctest::Approx(0.0));
    CHECK(product.getCoefficient(0) == doctest::Approx(-1.0));
}
