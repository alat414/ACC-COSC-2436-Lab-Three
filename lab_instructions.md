# Lab 3: Lists and Polynomial Calculator

**COSC-2436 Data Structures - Fall 2025**

## Overview

This lab has three parts:
1. Write unit tests for the List ADT
2. Implement a Polynomial class using LinkedList
3. Build an interactive polynomial calculator

## Files Provided

- `list_adt.h` - List ADT interface
- `array_list.h` - Array-based list implementation (complete)
- `linked_list.h` - Linked list implementation (complete)
- `polynomial.h` - Polynomial class template (you complete this)
- `list_tests.cpp` - List ADT test file (you complete this)
- `polynomial_tests.cpp` - Polynomial tests (provided for verification)
- `calculator_main.cpp` - Calculator application (you complete this)
- `doctest.h` - Testing framework

## Build & Run

```bash
# Build all targets
cmake -B build -S .
cmake --build build

# Run list tests
./build/list_tests

# Run polynomial tests
./build/polynomial_tests

# Run calculator
./build/calculator
```

---

## Part 1: List ADT Unit Tests (30 points)

**File:** `list_tests.cpp`

Complete the `testListADT()` function to test all List operations. Your tests must work for both `ArrayList` and `LinkedList`.

### Required Tests

Test each operation from `list_adt.h`:
- `isEmpty()` - Test on empty and non-empty lists
- `getLength()` - Verify count after insert/remove
- `insert()` - Test at beginning, middle, end; verify return value
- `remove()` - Test at beginning, middle, end; verify return value
- `clear()` - Verify list is empty after clear
- `getEntry()` - Test valid positions; verify exceptions for invalid positions
- `replace()` - Test valid positions; verify exceptions for invalid positions

### List ADT Axioms

Your tests should verify these fundamental properties:
1. New list is empty: `(new List()).isEmpty() == true`
2. New list has length 0: `(new List()).getLength() == 0`
3. After insert: length increases by 1
4. After remove: length decreases by 1
5. After insert at position i: `getEntry(i)` returns inserted item
6. After clear: `isEmpty() == true`

### Tips

- Use `CHECK()` for assertions
- Use `CHECK_THROWS()` for exception testing
- Test boundary conditions (empty list, full ArrayList)
- The same tests should pass for both ArrayList and LinkedList

---

## Part 2: Polynomial Implementation (40 points)

**File:** `polynomial.h`

Implement a `Polynomial` class that represents polynomials using a `LinkedList<Term>`.

### Step 1: Define Term Structure

```cpp
struct Term {
    double coefficient;
    int exponent;

    Term(double coef = 0.0, int exp = 0)
        : coefficient(coef), exponent(exp) {}
};
```

### Step 2: Complete Polynomial Class

Implement all methods marked `TODO`:

**Core Operations:**
- `addTerm(coefficient, exponent)` - Add/combine terms; maintain descending order by exponent
- `evaluate(x)` - Calculate polynomial value at x
- `degree()` - Return highest exponent (-1 for zero polynomial)
- `getCoefficient(exponent)` - Return coefficient for given exponent
- `isZero()` - Check if polynomial has no terms
- `toString()` - Format as "3x^2 + 2x - 1"

**Arithmetic Operators:**
- `operator+` - Add two polynomials
- `operator-` - Subtract two polynomials
- `operator*` - Multiply two polynomials

**Calculus:**
- `derivative()` - Return derivative polynomial

### Implementation Requirements

1. **Store terms in descending order by exponent** (highest first)
2. **Automatically exclude zero coefficients** - don't store terms with coefficient 0.0
3. **Automatically combine like terms** - if adding term with existing exponent, add coefficients
4. **Remove terms that become zero** - if combination results in 0.0, remove the term
5. **Use LinkedList<Term> for storage** - do not use arrays or vectors

### String Formatting Rules

- Zero polynomial: `"0"`
- Omit coefficient 1: `"x^2"` not `"1x^2"` (except constant term)
- Omit exponent 1: `"2x"` not `"2x^1"`
- Omit `x^0` for constants: `"5"` not `"5x^0"`
- Use proper signs: `"3x^2 - 2x + 1"` not `"3x^2 + -2x + 1"`

### Testing Your Implementation

Run the provided tests to verify your implementation:

```bash
./build/polynomial_tests
```

All tests must pass before proceeding to Part 3.

---

## Part 3: Calculator Implementation (30 points)

**File:** `calculator_main.cpp`

Complete the `PolynomialCalculator` class methods to create an interactive calculator.

### Methods to Implement

1. `createPolynomial(name, numTerms)` - Read coefficient/exponent pairs, create polynomial
2. `printPolynomial(name)` - Display polynomial using `toString()`
3. `evaluatePolynomial(name, x)` - Evaluate and print result
4. `addPolynomials(name1, name2, result)` - Use `operator+`
5. `subtractPolynomials(name1, name2, result)` - Use `operator-`
6. `multiplyPolynomials(name1, name2, result)` - Use `operator*`
7. `derivativePolynomial(name, result)` - Use `derivative()`
8. `showDegree(name)` - Print polynomial degree
9. `listPolynomials()` - Print all stored polynomials

### Example Session

```
> POLY p1 3
Enter 3 terms (coefficient exponent):
3 2
2 1
1 0
Polynomial 'p1' created: 3x^2 + 2x + 1

> POLY p2 2
Enter 2 terms (coefficient exponent):
1 2
-1 0
Polynomial 'p2' created: x^2 - 1

> ADD p1 p2 sum
sum = 4x^2 + 2x

> MULT p1 p2 product
product = 3x^4 + 2x^3 - 2x^2 - 2x - 1

> DERIV p1 dp1
dp1 = 6x + 2

> EVAL p1 2
p1(2) = 17

> LIST
Stored polynomials:
==================
p1 = 3x^2 + 2x + 1
p2 = x^2 - 1
sum = 4x^2 + 2x
product = 3x^4 + 2x^3 - 2x^2 - 2x - 1
dp1 = 6x + 2

> QUIT
Goodbye!
```

### Tips

- Check if polynomials exist before using them
- Store results in the map using `polynomials[name] = result`
- Print error messages for missing polynomials
- The reference implementation is in `reference_calculator.cpp` (for instructor use)

---

## Submission

Submit **three files** to Blackboard:

1. `list_tests.cpp` - Completed List ADT tests
2. `polynomial.h` - Completed Polynomial implementation
3. `calculator_main.cpp` - Completed calculator implementation

All files must compile without errors and pass all tests.

---

## Grading Rubric

| Part | Points | Criteria |
|------|--------|----------|
| Part 1 | 30 | Complete List ADT tests, all axioms verified |
| Part 2 | 40 | Polynomial implementation passes all tests |
| Part 3 | 30 | Calculator implements all commands correctly |
| **Total** | **100** | |

### Deductions

- Does not compile: -50 points
- Incorrect output format: -5 points per issue
- Missing error checking: -5 points per issue
