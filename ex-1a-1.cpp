/**
* =========================================================================
* EXERCISE 1: Variables, Types, and Scope [1.a.i]
* =========================================================================
* 
* Write a program that demonstrates variable scoping rules.
* 
* Requirements:
* 1. Declare a global integer variable 'globalCount' initialized to 100
* 2. Create a function 'outerFunction()' that:
*    - Declares a local int 'outerVar' = 50
*    - Prints "Global: [value], Outer: [value]"
*    - Creates an inner block {} that:
*      * Declares int 'innerVar' = 25
*      * Shadows 'globalCount' with a local variable = 200
*      * Prints "Global (shadowed): [value], Outer: [value], Inner: [value]"
*    - After the block, prints "Back in outer, Global: [value], Outer: [value]"
* 3. In main(), call outerFunction() then print the global variable
* 
* Expected output format:
* Global: 100, Outer: 50
* Global (shadowed): 200, Outer: 50, Inner: 25
* Back in outer, Global: 100, Outer: 50
* Main sees global: 100
*/

#include <iostream>

int globalCount = 100;

void outerFunction() {
    int outerVar = 50;

    std::cout << "Global: " << globalCount << ", Outer: " << outerVar << std::endl;

    {

        int innerVar = 25;
        int globalCount = 200;
        std::cout << "Global (shadowed): " << globalCount << ", Outer: " << outerVar << ", Inner: " << innerVar << std::endl;

    }

    std::cout << "Global: " << globalCount << ", Outer: " << outerVar << std::endl;
}

int main() {
    outerFunction();
    std::cout << "Global: " << globalCount << std::endl;
}
