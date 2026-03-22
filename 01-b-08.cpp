/*
 * ## EXERCISE 8: Iterators - Basic Usage [1.b.iv]
 * 
 * Write a program demonstrating different iterator types.
 * 
 * **Requirements:**
 * 1. Create vector with values 1-10
 * 2. Use begin() and end() for forward iteration
 * 3. Use rbegin() and rend() for reverse iteration
 * 4. Demonstrate iterator arithmetic (it + 3)
 * 5. Use std::advance() to move iterator
 * 6. Show const_iterator for read-only access
 * 7. Demonstrate insert() and erase() with iterators
 * 
 * **Expected output format:**
 * ```
 * Forward iteration: 1 2 3 4 5 6 7 8 9 10
 * Reverse iteration: 10 9 8 7 6 5 4 3 2 1
 * Element at begin() + 3: 4
 * After advancing iterator by 5 from begin(): 6
 * Using const_iterator: 1 2 3 4 5 6 7 8 9 10
 * After inserting 99 at position 3: 1 2 3 99 4 5 6 7 8 9 10
 * After erasing element at position 5: 1 2 3 99 4 6 7 8 9 10
 * ```
 */

#include <iostream>
#include <vector>

int main() {

    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::cout << "Forward iteration: ";

    /** 
     * Prefer pre-increment (++it) for iterators.
     * Post-increment creates an unnecessary temporary copy of the iterator.
     */
    /* here it is "iterator" */
    for (auto it = numbers.cbegin(); it != numbers.cend(); ++it) {
        if (it != numbers.cbegin()) {
            std::cout << " ";
        }
        std::cout << *it;
    }
    std::cout << std::endl;

    std::cout << "Reverse iteration: ";
    /* here it is "iterator" */
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        if (it != numbers.rbegin()) {
            std::cout << " ";
        }
        std::cout << *it;
    }
    std::cout << std::endl;

    std::cout << "Element at begin() + 3: " << *(numbers.begin() + 3)
        << std::endl;

    auto it = numbers.begin();
    std::advance(it, 5);
    std::cout << "After advancing by 5 from begin(): " << *it << std::endl;

    std::cout << "Using const_iterator: ";
    /* here it is "item" */
    bool first = true;
    for (const auto& it : numbers) {
        if (!first) {
            std::cout << " " ;
        }
        first = false;
        std::cout << it;
    }
    std::cout << std::endl;

    numbers.insert(numbers.begin()+3, 99);

    std::cout << "After inserting 99 at position 3: ";
    /* here it is "item" */
    first = true;
    for (const auto& it : numbers) {
        if (!first) {
            std::cout << " " ;
        }
        first = false;
        std::cout << it;
    }
    std::cout << std::endl;

    numbers.erase(numbers.begin()+5);

    std::cout << "After erasing element at  position 5: ";
    first = true;
    for (const auto& it : numbers) {
        if (!first) {
            std::cout << " " ;
        }
        first = false;
        std::cout << it;
    }
    std::cout << std::endl;
}
