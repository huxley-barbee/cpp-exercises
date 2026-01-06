/*
 * ## EXERCISE 1: Stack vs Heap Allocation [2.a.i]
 * 
 * Write a program demonstrating the differences between stack and heap allocation.
 * **Requirements:**
 * 1. Allocate an integer on the stack
 * 2. Allocate an integer on the heap using new
 * 3. Print addresses of both variables
 * 4. Show that stack variables are automatically destroyed
 * 5. Show that heap variables require manual deletion
 * 6. Create an array on stack (fixed size) and heap (dynamic size)
 * 7. Compare memory addresses to show stack grows down, heap grows up
 * 
 * **Expected output format:**
 * ```
 * Stack variable address: 0x7ffc... (higher address)
 * Stack variable value: 42
 * Heap variable address: 0x55... (lower address)
 * Heap variable value: 100
 * 
 * Stack array: [1, 2, 3, 4, 5]
 * Stack array address: 0x7ffc...
 * 
 * Heap array: [10, 20, 30, 40, 50]
 * Heap array address: 0x55...
 * 
 * Cleaning up heap memory...
 * Stack variables automatically destroyed at end of scope
 * ```
 */ 

#include <iostream>

int main() {

    int* stack_addr;
    int* heap_addr;

    {
        int stack_value = 42;
        stack_addr = &stack_value;
        int* heap_value = new int;
        heap_addr = heap_value;
        *heap_value = 100;

        std::cout << "Stack variable address: " << &stack_value << std::endl;
        std::cout << "Stack variable value: " << stack_value << std::endl;
        std::cout << "Heap variable address: " << heap_value << std::endl;
        std::cout << "Heap variable value: " << *heap_value << std::endl;

        delete heap_value;
    }

    int stack[] = { 1, 2, 3, 4, 5 };
    int* heap = new int[]{ 10, 20, 30, 40, 50 };

    std::cout << "Stack array: [";
    for (const auto item : stack) {
        std::cout << item << " ";
    }
    std::cout << "]" << std::endl;;
    std::cout << "Stack array address: ";
    for (int index = 0; index < 5; index++) {
        std::cout << "0x" << &stack[index] << " ";
    }
    std::cout << "]" << std::endl;;

    std::cout << "Heap array: [";
    for (int index = 0; index < 5; index++) {
        std::cout << "0x" << heap+index << " ";
    }
    std::cout << "]" << std::endl;;

    std::cout << "Cleaning up heap memory..." << std::endl;
    delete[] heap;

    std::cout << "Stack variables automatically destroyed at end of scope"
        << std::endl;

}
