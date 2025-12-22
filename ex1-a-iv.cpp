/*
 * Exercise 4 — Function Overloading
 * Tag: 1.a.iv Functions & overloading
 *
 * Define two overloaded functions named add:
 * - add(int a, int b)
 * - add(double a, double b)
 *
 * Call add(2, 3) and print the result.
 * Call add(2.0, 3.5) and print the result.
 */

#include <iostream>

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    std::cout << add(2, 3) << std::endl;
    std::cout << add(2.0, 3.5) << std::endl;
}
