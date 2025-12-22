/*
 * Exercise 5 — Const Correctness
 * Tag: 1.a.v const correctness
 *
 * Declare a const int x initialized to 42.
 * Bind a const reference to x.
 * Print the value through the reference.
 */

#include <iostream>

int main() {
    const int x = 42;

    /* Fails. Can't reference a const int without a const. */
    // int& reference = x;

    const int& reference = x;

    /* Fails. Cannot modify const. */
    // x = 43;
    // reference = 43;

    std::cout << reference << std::endl;

}
