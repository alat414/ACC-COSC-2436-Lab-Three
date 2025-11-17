cmake_minimum_required(VERSION 3.10)
project(lab3_lists)

set(CMAKE_CXX_STANDARD 17)

# Everything in the directory that you want visible/associated with each target
set(HEADERS
        array_list.h
        linked_list.h
        list_adt.h
        polynomial.h
        doctest.h
)

# --- Executables (each includes all headers so edits show up in IDEs and CMake traces) ---
add_executable(calculator
        calculator_main.cpp
        ${HEADERS}
)

add_executable(list_tests
        list_tests.cpp
        ${HEADERS}
)

add_executable(polynomial_tests
        polynomial_tests.cpp
        ${HEADERS}
)
