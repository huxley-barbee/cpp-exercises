/*
 * ## EXERCISE 2: Memory Layout and Scope [2.a.i]
 * 
 * Write a program demonstrating variable lifetime and scope.
 * 
 * **Requirements:**
 * 1. Create a function that allocates local (stack) variables
 * 2. Show these variables are destroyed when function returns
 * 3. Create nested scopes and show variable shadowing
 * 4. Demonstrate that pointers can outlive the data they point to (dangling pointer)
 * 5. Show proper heap allocation that persists across function calls
 * 
 * **Expected output format:**
 * ```
 * Entering outerFunction()
 *   Local variable x: 10
 *   Entering inner scope
 *     Inner variable y: 20
 *     Shadowed x: 30
 *   Exiting inner scope (y destroyed)
 *   Back to outer x: 10
 * Exiting outerFunction() (x destroyed)
 * 
 * Heap allocation persists across function calls
 * Heap value from function: 999
 * Properly cleaned up
 * 
 * WARNING: Dangling pointer example (commented out - would crash)
 * ```
 */ 

#include <iostream>

void outerFunction() {

    std::cout << "Entering outerFunction()" << std::endl;

    int x = 10;

    std::cout << "Local variable x: " << x << std::endl;

    {
        std::cout << "Entering inner scope" << std::endl;

        int y = 20;
        int x = 30;

        std::cout << "Inner variable y: " << y << std::endl;
        std::cout << "Shadowed x: " << x << std::endl;

        std::cout << "Exiting inner scope (y destroyed)" << std::endl;

    }

    std::cout << "Back to the outer x: " << x << std::endl;

    std::cout << "Exiting outerFunction() (x destroyed)" << std::endl;
}

int* heapFunction() {
    return new int(999);
}

int main() {

    outerFunction();

    std::cout << "\nHeap allocation persists across function calls" << std::endl;

    int *heap_value = heapFunction();

    std::cout << "Heap value from function: " << *heap_value << std::endl;

    delete heap_value;
    std::cout << "Properly cleaned up" << std::endl;

    std::cout << "\nWARNING: Dangling pointer example (commented out - would crash)"
        << std::endl;
    // std::cout << "Heap value from function: " << *heap_value << std::endl;

}
