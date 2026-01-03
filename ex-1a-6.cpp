/**
 * ========================================================================
 * EXERCISE 6: Value vs Reference Semantics [1.a.iii]
 * ===========================================================================
 * 
 * Write a program with three functions to demonstrate parameter passing:
 * - passByValue(int x)
 * - passByPointer(int* x)
 * - passByReference(int& x)
 * 
 * Each function should try to double the parameter.
 * 
 * Requirements:
 * 1. Create int 'num' = 10
 * 2. Call each function with appropriate syntax
 * 3. After each call, print num to show if it changed
 * 4. Explain what happened in comments
 * 
 * Expected output format:
 * Initial value: 10
 * After pass by value: 10 (unchanged)
 * After pass by pointer: 20 (changed)
 * After pass by reference: 40 (changed)
 */ 

#include <iostream>

void passByValue(int x) {
    x *= 2;
}

void passByPointer(int *x) {
    *x *= 2;
}

void passByReference(int& x) {
    x *= 2;
}

int main() {

    int num = 10;

    passByValue(num);
    std::cout << "After pass by value " << num << " (unchanged)"
        << std::endl;

    passByPointer(&num);
    std::cout << "After pass by pointer " << num << " (changed)"
        << std::endl;

    passByReference(num);
    std::cout << "After pass by reference " << num << " (changed)"
        << std::endl;

}
