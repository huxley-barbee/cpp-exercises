/*
 * ## EXERCISE 2: std::vector - Memory and Performance [1.b.i]
 * 
 * Write a program exploring vector memory behavior.
 * 
 * **Requirements:**
 * 1. Create vector with initial capacity using reserve(10)
 * 2. Print capacity
 * 3. Add 5 elements, print capacity after each (should not reallocate)
 * 4. Add 10 more elements, observe capacity changes
 * 5. Use shrink_to_fit() to reduce capacity
 * 6. Demonstrate the difference between size() and capacity()
 * 
 * **Expected output format:**
 * ```
 * Initial capacity after reserve(10): 10
 * After adding element 1, capacity: 10
 * After adding element 2, capacity: 10
 * After adding element 3, capacity: 10
 * After adding element 4, capacity: 10
 * After adding element 5, capacity: 10
 * After adding 10 more elements:
 * Size: 15, Capacity: 20 (or similar - grown)
 * After shrink_to_fit:
 * Size: 15, Capacity: 15
 * ```
 */ 

#include <iostream>
#include <vector>

int main() {

    std::vector<int> vector(0);

    vector.reserve(10);

    std::cout << "Initial capacity after reserve(10): " << vector.capacity()
        << std::endl;

    for (int index = 0; index < 5; index++) {
        vector.push_back(15);
        std::cout << "After adding element " << index+1 << ", capacity: "
            << vector.capacity() << std::endl;
    }

    for (int index = 0; index < 10; index++) {
        vector.push_back(47);
    }

    std::cout << "After adding 10 more elements" << std::endl;

    std::cout << "Size: " << vector.size() << ", Capacity: "
        << vector.capacity() << std::endl;

    vector.shrink_to_fit();

    std::cout << "After shrink to fit" << std::endl;
    std::cout << "Size: " << vector.size() << ", Capacity: "
        << vector.capacity() << std::endl;

}
