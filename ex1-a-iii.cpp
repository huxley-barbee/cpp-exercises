/*
 * Exercise 3 — Value vs Reference Semantics
 * Tag: 1.a.iii Value vs reference semantics
 *
 * Write two functions:
 * - increment_by_value(int x)
 * - increment_by_reference(int& x)
 *
 * Initialize an int n = 10.
 * Call increment_by_value(n), then print n.
 * Call increment_by_reference(n), then print n.
 */

#include <iostream>

void increment_by_value(int value) {
    value++;
}

void increment_by_reference(int& reference) {
    reference++;
}

int main() {
    int n = 10;

    increment_by_value(n);
    std::cout << n << std::endl;

    increment_by_reference(n);
    std::cout << n << std::endl;
}

