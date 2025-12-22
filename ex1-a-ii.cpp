/*
* Exercise 2 — Pointer and Reference Mutation
* Tag: 1.a.ii Pointers and references
*
* Create an int value initialized to 7. Create:
* - a pointer to value
* - a reference to value
*
* Increment the value by 1 using the pointer.
* Print the value.

* Increment the value by 1 using the reference.
* Print the value.
*/

#include <iostream>

int main() {
    int value = 7;
    int *pointer = &value;

    /* This should not compile. */
//    int& references;

    int& reference = value;

    (*pointer)++;
    std::cout << value << std::endl;

    reference++;
    std::cout << value << std::endl;

}
