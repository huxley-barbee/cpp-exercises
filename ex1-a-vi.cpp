/**
 * Exercise 6 — Namespaces and Qualification
 * Tag: 1.a.vi Namespaces
 *
 * Define two namespaces:
 * - namespace A containing int value = 1
 * - namespace B containing int value = 2
 *
 * Print A::value on one line.
 * Print B::value on the next line.
 */

#include <iostream>

namespace A {
    int value = 1;
}

namespace B {
    int value = 2;
}

int main() {
    std::cout << A::value << std::endl;
    std::cout << B::value << std::endl;
}
