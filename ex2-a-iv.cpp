/**
 * Exercise 2.a.iv — Manual Memory Management
 * Tag: 2.a.iv manual memory management
 * 
 * Allocate an array of three ints {1,2,3} on the heap.
 * Print them space-separated on one line.
 * Deallocate the array correctly.
 *
 * Compile with g++ -std=c++11 ex2-a-iv.cpp
 */

#include <iostream>

int main() {
    int* array = new int[]{1, 2, 3};

    // int max = 3;
    // constexpr gives us compile-time checks
    constexpr int size = 3;


    for (int index = 0; index < max; index++) {

        if (index > 0) {
            std::cout << " ";
        }

        std::cout << *(array+index);
    }

    std::cout << std::endl;

    delete[] array;

}
