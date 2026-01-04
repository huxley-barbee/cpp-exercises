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

void print(std::vector<int> vector) {

    for (const auto& item : vector) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

}

int main() {
    std::vector<int> vector = { 1, 2, 3, 4, 5 };

    std::cout << "Original: ";
    print(vector);

    std::transform(vector.begin(), vector.end(), vector.begin(),
        [](int a) {
            return a * a;
        }
    );

    std::cout << "After transform (square): ";
    print(vector);

    std::cout << "Using for_each to print: ";
    std::for_each(vector.begin(), vector.end(), 
        [](int a) {
            std::cout << a << " ";
        }
    );
    std::cout << std::endl;;

    std::vector<int> second(vector.size());

    std::copy_if(vector.begin(), vector.end(), second.begin(),
            [](int a) {
                return (a % 2) == 0;
            }
    );

    std::cout << "Even numbers only: ";
    print(second);

    std::cout << "Sum using accumulate: "
        << std::accumulate(vector.begin(), vector.end(), 0) << std::endl;

    auto odds = std::remove_if(vector.begin(), vector.end(),
        [](int a) {
            return (a % 2) != 0;
        }
    );
    vector.erase(odds, vector.end());

    std::cout << "After removing odds: ";
    print(vector);

}
