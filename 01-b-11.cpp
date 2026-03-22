/*
 * ## EXERCISE 11: STL Algorithms - Transformation [1.b.v]
 * 
 * Write a program using transformation algorithms.
 * 
 * **Requirements:**
 * 1. Create vector: {1, 2, 3, 4, 5}
 * 2. Use std::transform() to square each element (in-place)
 * 3. Use std::for_each() to print elements
 * 4. Create second vector for even numbers only using std::copy_if()
 * 5. Use std::accumulate() to sum all elements
 * 6. Use std::remove_if() to remove odd numbers (then erase)
 * 
 * **Expected output format:**
 * ```
 * Original: 1 2 3 4 5
 * After transform (square): 1 4 9 16 25
 * Using for_each to print: 1 4 9 16 25
 * Even numbers only: 4 16
 * Sum using accumulate: 46
 * After removing odds: 4 16
 * ```
 */ 

#include <iostream>
#include <numeric>
#include <vector>

void print(const std::vector<int>& numbers) {

    bool first = true;
    for (const auto& item : numbers) {
        if (!first) {
            std::cout << " ";
        }
        first = false;
        std::cout << item;
    }
    std::cout << std::endl;

}

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    std::cout << "Original: ";
    print(numbers);

    std::transform(numbers.begin(), numbers.end(), numbers.begin(),
        [](int a) {
            return a * a;
        }
    );

    std::cout << "After transform (square): ";
    print(numbers);

    std::cout << "Using for_each to print: ";
    std::for_each(numbers.begin(), numbers.end(), 
        [first = true](int a) mutable{
            if (!first) {
                std::cout << " ";
            }
            first = false;
            std::cout << a;
        }
    );
    std::cout << std::endl;

    std::vector<int> second;

    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(second),
            [](int a) {
                return (a % 2) == 0;
            }
    );

    std::cout << "Even numbers only: ";
    print(second);

    std::cout << "Sum using accumulate: "
        << std::accumulate(numbers.begin(), numbers.end(), 0) << std::endl;

    auto odds = std::remove_if(numbers.begin(), numbers.end(),
        [](int a) {
            return (a % 2) != 0;
        }
    );
    numbers.erase(odds, numbers.end());

    std::cout << "After removing odds: ";
    print(numbers);

}
