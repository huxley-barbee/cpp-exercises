/*
 * ## EXERCISE 10: STL Algorithms - Searching and Sorting [1.b.v]
 * 
 * Write a program using common STL algorithms.
 * 
 * **Requirements:**
 * 1. Create vector: {5, 2, 8, 1, 9, 3, 7}
 * 2. Use std::sort() to sort it
 * 3. Use std::find() to search for value 8
 * 4. Use std::binary_search() on sorted vector
 * 5. Use std::count() to count occurrences
 * 6. Use std::min_element() and std::max_element()
 * 7. Use std::reverse() to reverse the vector
 * 
 * **Expected output format:**
 * ```
 * Original: 5 2 8 1 9 3 7
 * After sort: 1 2 3 5 7 8 9
 * Finding 8: found at index 5
 * Binary search for 5: found
 * Binary search for 4: not found
 * Count of 2: 1
 * Min element: 1
 * Max element: 9
 * After reverse: 9 8 7 5 3 2 1
 * ```
 */ 

#include <iostream>
#include <vector>
#include <algorithm>

void print(const std::vector<int>& numbers) {

    for (const auto& item : numbers) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

}

int main() {
    std::vector<int> numbers = { 5, 2, 8, 1, 9, 3, 7 };

    std::cout << "Original: ";
    print(numbers);

    std::sort(numbers.begin(), numbers.end());
    std::cout << "After sort: ";
    print(numbers);

    /**
     * Objects/containers → const& to avoid expensive copies
     * Iterators, pointers, simple scalars → pass/store by value
     */
    auto firstEight = std::find(numbers.begin(), numbers.end(), 8);
    if (firstEight != numbers.end()) {
        std::cout << "Finding 8: found at index "
            << std::distance(numbers.begin(), firstEight) << std::endl;
    } else {
        std::cout << "Eight not found" << std::endl;
    }

    if (std::binary_search(numbers.begin(), numbers.end(), 5)) {
        std::cout << "Binar search for 5: found" << std::endl;
    }

    if (!std::binary_search(numbers.begin(), numbers.end(), 4)) {
        std::cout << "Binar search for 4: not found" << std::endl;
    }

    std::cout << "Count of 2: "
        << std::count(numbers.begin(), numbers.end(), 2) << std::endl;

    std::cout << "Min element: "
        << *std::min_element(numbers.begin(), numbers.end()) << std::endl;
    std::cout << "Max element: "
        << *std::max_element(numbers.begin(), numbers.end()) << std::endl;

    std::reverse(numbers.begin(), numbers.end());
    std::cout << "After reverse: ";
    print(numbers);
}
