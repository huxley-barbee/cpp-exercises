/**
 * Exercise 2.a.i — Stack vs Heap
 * Tag: 2.a.i stack vs heap
 *
 * Create an int on the stack initialized to 5. Create an int on the
 * heap initialized to 10. Print both values on separate lines. Delete
 * heap memory explicitly.
 */

#include <iostream>

int main() {
    int stack_var = 5;
    int *heap_var = new int(10);

    std::cout << stack_var << std::endl;
    std::cout << *heap_var << std::endl;
}
