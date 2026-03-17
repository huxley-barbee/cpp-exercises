/**
 * ## EXERCISE 3: std::array - Fixed-Size Arrays [1.b.i]
 * 
 * Write a program demonstrating std::array.
 * 
 * **Requirements:**
 * 1. Create std::array<int, 5> initialized with {1, 2, 3, 4, 5}
 * 2. Print size using size()
 * 3. Access with at() (bounds-checked) and [] (unchecked)
 * 4. Use front() and back()
 * 5. Iterate using range-based for loop
 * 6. Demonstrate that size is compile-time constant
 * 7. Try to demonstrate bounds checking with at() using try-catch
 * 
 * **Expected output format:**
 * ```
 * Array size: 5
 * Element at index 2: 3
 * Front: 1, Back: 5
 * All elements: 1 2 3 4 5
 * Trying to access index 10 with at():
 * Exception caught: out_of_range
 * ```
 */ 

#include <array>
#include <iostream>
#include <type_traits>

int main() {

    std::array<int, 5> array = { 1, 2, 3, 4, 5};

    std::cout << "Array size: " << array.size() << std::endl;

    std::cout << "Element at index 2: " << array.at(2) << std::endl;
    std::cout << "Element at index 2: " << array[2] << std::endl;

    std::cout << "Front: " << array.front() << ", Back: "
        << array.back() << std::endl;

    std::cout << "All elements: ";

    for (auto item : array) {
        std::cout << item << " ";
    }

    std::cout << std::endl;

    static_assert(array.size()  == 5, "Array size must be 5");

    try {
        array.at(10);
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: out_of_range" << std::endl;
    }
}
