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

#include <iostream>
#include <vector>

int main() {

    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    std::cout << "Size: " << numbers.size() << ", Capacity: "
        << numbers.capacity() << '\n';

    std::cout << "Element at index 0: " << numbers[0] << '\n';
    std::cout << "Element at index 2 (before): " << numbers.at(2) << '\n';

    numbers[2] = 99;

    std::cout << "Element at index 2 (after): " << numbers.at(2) << '\n';

    numbers.pop_back();

    std::cout << "After pop_back, size(): " << numbers.size() << '\n';

    std::cout << "Elements: ";
    for (auto item : numbers) {
        std::cout << item << " ";
    }
    std::cout << '\n';

    numbers.clear();

    std::cout << "After clear, size: " << numbers.size() << ", empty "
        << std::boolalpha << numbers.empty() << '\n';
}
