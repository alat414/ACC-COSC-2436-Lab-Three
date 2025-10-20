# Lab 3: Lists and Polynomial Calculator
## COSC-2436 Data Structures
## Fall 2025

**Due Date:** 11/03 11:59 PM
**Points:** 100

---

## Introduction

This lab explores the List Abstract Data Type (ADT) through both theoretical testing and practical application. You will work with both array-based and linked-list implementations, and build a complete polynomial calculator application.

**Learning Objectives:**
1. Understand and test List ADT axioms and operations
2. Apply lists to represent mathematical structures (polynomials)
3. Practice smart pointer usage for automatic memory management
4. Build a complete interactive application using data structures

---

## Submission Requirements

You will submit **TWO files** to Blackboard:

1. **`doctests_main.cpp`** - Completed implementation with all Parts 1-3 finished (includes unit tests)
2. **`calculator_main.cpp`** - Separate standalone calculator program for Part 4

Both files must compile without errors and pass all test cases.

---

## Part 1: List ADT Unit Tests (25 points)

### Overview
The `ArrayList` and `LinkedList` implementations from the textbook have been provided in the starter code. Your task is to write comprehensive unit tests for the List ADT based on the axioms presented in Chapter 8.

### List ADT Axioms (from Carrano Chapter 8)

The List ADT operations must satisfy these fundamental properties:

1. **Axiom 1:** `(new List()).isEmpty()` returns `true`
2. **Axiom 2:** `(new List()).getLength()` returns `0`
3. **Axiom 3:** After `aList.insert(i, item)`, the list length equals old length + 1
4. **Axiom 4:** After `aList.remove(i)`, the list length equals old length - 1
5. **Axiom 5:** After `aList.insert(i, item)`, `aList.getEntry(i)` returns `item`
6. **Axiom 6:** After `aList.clear()`, `isEmpty()` returns `true`

### Requirements

Complete the `testListADT()` function to thoroughly test **all** List ADT operations:

**Essential Test Cases:**
- [ ] Insert at beginning (position 1)
- [ ] Insert at end (position `length + 1`)
- [ ] Insert in middle positions
- [ ] Remove from beginning
- [ ] Remove from end
- [ ] Remove from middle
- [ ] Replace operation at various positions
- [ ] Clear operation
- [ ] Multiple sequential inserts and removes
- [ ] Boundary conditions (empty list, single element, full list for ArrayList)
- [ ] Exception handling (invalid positions)

**Testing Strategy:**
- Each axiom should have explicit test cases
- Test both `ArrayList` and `LinkedList` using the same test function
- Use `CHECK()` assertions for correctness
- Use `CHECK_THROWS()` for exception testing

### Grading Criteria (25 points)

| Criteria | Points |
|----------|--------|
| Tests cover all List ADT axioms | 8 |
| Tests cover all operations (insert, remove, replace, clear) | 8 |
| Tests include boundary conditions and edge cases | 5 |
| Tests verify exception handling | 2 |
| Tests pass for both ArrayList and LinkedList | 2 |

---

## Part 2: Insertion Sort Implementation (15 points)

### Overview
Implement the insertion sort algorithm that works with the List ADT interface.

### Algorithm Description

Insertion sort works like sorting a hand of playing cards:
1. Start with the second element (position 2)
2. Compare it with elements before it
3. Find the correct sorted position for it
4. Insert it in that position
5. Repeat for all remaining elements

**Time Complexity:** O(n²)
**Space Complexity:** O(1)
**Advantage:** Efficient for small lists and partially sorted data

### Requirements

Complete the `insertionSort()` template function:

```cpp
template<typename ItemType>
void insertionSort(ListADT<ItemType> & list) {
    // Your implementation here
}
```

**Implementation Hints:**
- You can only use List ADT operations: `getEntry()`, `insert()`, `remove()`, `getLength()`
- You cannot access internal array or node structure
- Consider removing an element and re-inserting it in the correct position
- The provided unit tests must all pass

### Test Cases Provided

The starter code includes tests for:
- Empty list
- Single element list
- Two element list (sorted and unsorted)
- Three element list (reverse order)
- 32 element random list

All tests must pass for both `ArrayList` and `LinkedList`.

### Grading Criteria (15 points)

| Criteria | Points |
|----------|--------|
| Algorithm correctly sorts all test cases | 10 |
| Works with both ArrayList and LinkedList | 3 |
| Uses only List ADT interface (no direct access to internals) | 2 |

---

## Part 3: Polynomial Class Implementation (30 points)

### Overview
Implement a `Polynomial` class that uses a `LinkedList<Term>` to represent polynomials as sorted lists of terms.

### Mathematical Background

**Polynomial Representation:**
- A polynomial is a sum of terms: `a_n*x^n + a_(n-1)*x^(n-1) + ... + a_1*x + a_0`
- Each term has a coefficient (a_i) and an exponent (i)
- Example: `3x² + 2x + 1` has terms `[(3,2), (2,1), (1,0)]`

**Storage Strategy:**
- Store terms in a linked list sorted by exponent (descending order)
- Skip terms with coefficient of 0
- Combine like terms (same exponent)

### Required Methods

#### Core Operations
```cpp
void addTerm(double coefficient, int exponent)
```
- Add a term to the polynomial
- If term with same exponent exists, add coefficients
- Maintain sorted order (descending by exponent)
- Remove term if resulting coefficient is 0

```cpp
double evaluate(double x) const
```
- Compute polynomial value at given x
- Example: For `3x² + 2x + 1`, `evaluate(2)` returns `17`

```cpp
int degree() const
```
- Return highest exponent in polynomial
- Return `-1` for zero polynomial

#### Arithmetic Operations
```cpp
Polynomial operator+(const Polynomial& other) const
Polynomial operator-(const Polynomial& other) const
Polynomial operator*(const Polynomial& other) const
```

**Addition Example:**
```
(3x² + 2x + 1) + (x² - x + 5) = 4x² + x + 6
```

**Multiplication Example:**
```
(2x + 3) * (x - 1) = 2x² + x - 3
```

#### Calculus Operations
```cpp
Polynomial derivative() const
```
- Compute derivative using power rule: `d/dx(ax^n) = n*a*x^(n-1)`
- Example: `d/dx(3x² + 2x + 1) = 6x + 2`

#### Utility Methods
```cpp
string toString() const
```
- Return human-readable string representation
- Format: `"3x^2 + 2x + 1"` or `"5x^3 - 2x + 7"`
- Handle special cases: negative coefficients, exponent 0 (constant), exponent 1 (linear)

```cpp
bool isZero() const
double getCoefficient(int exponent) const
```

### Implementation Requirements

1. **Use the Term struct provided:**
```cpp
struct Term {
    double coefficient;
    int exponent;
    // Comparison operators provided
};
```

2. **Use LinkedList<Term> for storage:**
   - Do NOT use arrays or vectors
   - Maintain sorted order (descending by exponent)

3. **Complete all helper functions:**
   - `findTermPosition()` - Find position of term with given exponent
   - `insertTermSorted()` - Insert term maintaining sorted order

4. **Write comprehensive unit tests:**
   - Complete the test cases in the starter code
   - Test all operations with various polynomials
   - Test edge cases: zero polynomial, constant polynomial, single term

### Grading Criteria (30 points)

| Criteria | Points |
|----------|--------|
| `addTerm()` correctly maintains sorted list | 4 |
| `evaluate()` computes correct values | 3 |
| `degree()` returns correct value | 2 |
| Addition operator works correctly | 4 |
| Subtraction operator works correctly | 3 |
| Multiplication operator works correctly | 5 |
| Derivative operation works correctly | 4 |
| `toString()` formats output correctly | 3 |
| Comprehensive unit tests written and passing | 2 |

### Testing

**All existing unit tests must still pass:**
- Part 1: List ADT tests
- Part 2: Insertion sort tests
- Part 3: Polynomial tests (if using LinkedList)

This demonstrates that the refactoring maintains correctness while improving safety.

### Grading Criteria (15 points)

| Criteria | Points |
|----------|--------|
| Node class uses shared_ptr for next pointer | 3 |
| LinkedList uses shared_ptr for headPtr | 3 |
| All manual delete calls removed | 3 |
| Destructor and clear() simplified | 2 |
| All existing unit tests still pass | 4 |

---

## Part 4: Interactive Polynomial Calculator (15 points)

### Overview
Create a **separate** standalone program (`calculator_main.cpp`) that implements an interactive polynomial calculator using your `Polynomial` class.

### Program Requirements

#### Input Format
The calculator should read commands from standard input (keyboard or file redirection).

**Polynomial Input:**
```
POLY <name> <num_terms>
<coefficient1> <exponent1>
<coefficient2> <exponent2>
...
```

**Example:**
```
POLY p1 3
3.0 2
2.0 1
1.0 0
```
Creates polynomial `p1 = 3x² + 2x + 1`

#### Supported Commands

| Command | Format | Description | Example |
|---------|--------|-------------|---------|
| POLY | `POLY <name> <n>` | Define new polynomial | `POLY p1 3` |
| PRINT | `PRINT <name>` | Display polynomial | `PRINT p1` |
| EVAL | `EVAL <name> <x>` | Evaluate at x | `EVAL p1 2.0` |
| ADD | `ADD <name1> <name2> <result>` | result = name1 + name2 | `ADD p1 p2 p3` |
| SUB | `SUB <name1> <name2> <result>` | result = name1 - name2 | `SUB p1 p2 p3` |
| MULT | `MULT <name1> <name2> <result>` | result = name1 * name2 | `MULT p1 p2 p3` |
| DERIV | `DERIV <name> <result>` | result = derivative | `DERIV p1 dp1` |
| DEGREE | `DEGREE <name>` | Show degree | `DEGREE p1` |
| HELP | `HELP` | Show command list | `HELP` |
| QUIT | `QUIT` | Exit program | `QUIT` |

#### Example Session

```
Welcome to Polynomial Calculator!
Type HELP for command list.

> POLY p1 3
> 3 2
> 2 1
> 1 0
Polynomial p1 created: 3x^2 + 2x + 1

> POLY p2 2
> 1 1
> -1 0
Polynomial p2 created: x - 1

> MULT p1 p2 p3
Result p3: 3x^3 + 2x^2 - x - 1

> EVAL p3 2
p3(2.0) = 37.0

> DERIV p3 dp3
Derivative dp3: 9x^2 + 4x - 1

> PRINT dp3
9x^2 + 4x - 1

> QUIT
Goodbye!
```

### Implementation Requirements

1. **Use a map to store polynomials:**
```cpp
#include <map>
#include <string>

std::map<std::string, Polynomial> polynomials;
```

2. **Command processing:**
   - Read commands in a loop until QUIT
   - Parse command and arguments
   - Execute appropriate operation
   - Handle errors gracefully (undefined polynomials, invalid input)

3. **User interface:**
   - Display clear prompts
   - Show helpful error messages
   - Format output nicely

4. **File I/O bonus (optional +5 points):**
   - Add `LOAD <filename>` to read commands from file
   - Add `SAVE <name> <filename>` to save polynomial to file

### Program Structure

```cpp
#include <iostream>
#include <map>
#include <string>
#include <sstream>

// Include your Polynomial class and List implementations here
// (Copy from doctests_main.cpp)

int main() {
    std::map<std::string, Polynomial> polynomials;
    std::string command;

    std::cout << "Welcome to Polynomial Calculator!\n";
    std::cout << "Type HELP for command list.\n\n";

    while (true) {
        std::cout << "> ";
        std::cin >> command;

        if (command == "QUIT") {
            break;
        } else if (command == "POLY") {
            // Handle POLY command
        } else if (command == "PRINT") {
            // Handle PRINT command
        }
        // ... more commands
    }

    std::cout << "Goodbye!\n";
    return 0;
}
```

### Expected Output
- All unit tests should pass with green checkmarks
- Calculator should handle all commands correctly

---

## Resources

### Textbook References
- **Chapter 8:** Lists (ADT specification and axioms)
- **Chapter 9:** List Implementations (ArrayList and LinkedList)
- **Chapter 11:** Sorting Algorithms (insertion sort)
- **C++ Interlude 4:** Smart Pointers

### Online Resources
- [Insertion Sort Visualization](https://visualgo.net/en/sorting)
- [Polynomial Operations](https://www.khanacademy.org/math/algebra/polynomial-arithmetic)
- [doctest Documentation](https://github.com/doctest/doctest)

