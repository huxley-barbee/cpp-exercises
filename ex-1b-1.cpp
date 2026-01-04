/*
 * ## EXERCISE 1: std::vector - Basic Operations [1.b.i]
 * 
 * Write a program that demonstrates vector fundamentals.
 * 
 * **Requirements:**
 * 1. Create an empty vector of integers
 * 2. Add elements: 10, 20, 30, 40, 50 using push_back()
 * 3. Print size and capacity
 * 4. Access elements using [] and at()
 * 5. Modify element at index 2
 * 6. Remove last element with pop_back()
 * 7. Iterate and print all elements
 * 8. Clear the vector and verify it's empty
 * 
 * **Expected output format:**
 * ```
 * After adding 5 elements:
 * Size: 5, Capacity: [implementation-dependent, typically 8]
 * Element at index 0: 10
 * Element at index 2 (before): 30
 * Element at index 2 (after): 99
 * After pop_back, size: 4
 * Elements: 10 20 99 40
 * After clear, size: 0, empty: true
 * ```
 */ 

#include <array>
#include <iostream>
#include <vector>

int main() {

    std::vector<int> vector(0);

    vector.push_back(10);
    vector.push_back(20);
    vector.push_back(30);
    vector.push_back(40);
    vector.push_back(50);

    std::cout << "Size: " << vector.size() << ", Capacity: "
        << vector.capacity() << std::endl;

    std::cout << "Element at index 0: " << vector[0] << std::endl;
    std::cout << "Element at index 2: " << vector.at(2) << std::endl;

    vector[2] = 99;

    std::cout << "Element at index 2: " << vector.at(2) << std::endl;

    vector.pop_back();

    std::cout << "After pop_back, size(): " << vector.size() << std::endl;

    std::cout << "Elements: ";
    for (auto item : vector) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    vector.clear();

    std::cout << "After clear, size: " << vector.size() << ", empty "
        << vector.empty() << std::endl;
}
