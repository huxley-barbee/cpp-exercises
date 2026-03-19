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
    // x is a local copy; the original variable is unaffected
    x *= 2;
}

void passByPointer(int* x) {
    // dereferences the pointer to modify the value at that memory address
    *x *= 2;
}

void passByReference(int& x) {
    // x is an alias for the original variable; modifies it directly
    x *= 2;
}

int main() {

    int num = 10;
    std::cout << "Initial value: " << num << '\n'; // add this

    passByValue(num);
    std::cout << "After pass by value " << num << " (unchanged)"
        << '\n';

    passByPointer(&num);
    std::cout << "After pass by pointer " << num << " (changed)"
        << '\n';

    passByReference(num);
    std::cout << "After pass by reference " << num << " (changed)"
        << '\n';

}
