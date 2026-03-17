/*
 * ## EXERCISE 12: STL Algorithms - Advanced Operations [1.b.v]
 * 
 * Write a program with more complex algorithms.
 * 
 * **Requirements:**
 * 1. Create two sorted vectors: {1, 3, 5, 7} and {2, 4, 6, 8}
 * 2. Use std::merge() to combine them
 * 3. Create vector: {1, 2, 2, 3, 3, 3, 4}
 * 4. Use std::unique() to remove consecutive duplicates
 * 5. Use std::partition() to separate even/odd numbers
 * 6. Use std::nth_element() to find median
 * 7. Use std::generate() to fill vector with values
 * 
 * **Expected output format:**
 * ```
 * Vector 1: 1 3 5 7
 * Vector 2: 2 4 6 8
 * After merge: 1 2 3 4 5 6 7 8
 * With duplicates: 1 2 2 3 3 3 4
 * After unique: 1 2 3 4
 * Partition by even (evens first): 2 4 6 8 1 3 5 7
 * Vector for median: 3 1 4 1 5 9 2 6 5
 * After nth_element (median at index 4): [...] 5 [...]
 * Generated sequence (0*2, 1*2, 2*2...): 0 2 4 6 8
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

int gen() {
    static int count = 0;
    count++;
    return count * (count - 1);
}

int main() {
    std::vector<int> one = { 1, 3, 5, 7 };
    std::vector<int> two = { 2, 4, 6, 8 };
    std::vector<int> merged(one.size() + two.size());

    std::cout << "Vector 1: ";
    print(one);

    std::cout << "Vector 2: ";
    print(two);


    std::merge(one.begin(), one.end(), two.begin(), two.end(),
        merged.begin());

    std::cout << "After merge: ";
    print(merged);

    std::vector<int> three = { 1, 2, 2, 3, 3, 3, 4 };
    std::cout << "With duplicates: ";
    print(three);

    std::vector<int>::iterator it = std::unique(three.begin(), three.end());
    three.resize(std::distance(three.begin(), it));

    std::cout << "After unique: ";
    print(three);

    std::partition(merged.begin(), merged.end(),
        [](int a) {
            return (a%2)==0;
        }
    );

    std::cout << "Partition by even numbers (even first): ";
    print(merged);

    std::vector<int> four = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    int middle = -1;
    if (four.size() % 2 == 0) {
        middle = four.size() / 2;
    } else {
        middle = (four.size() / 2) + 1;
    }
    std::nth_element(four.begin(), four.begin() + middle, four.end());

    std::cout << "After nth_element (median at index 4: "
        << four[middle] << std::endl;

    std::vector<int> five(5);
    std::generate(five.begin(), five.end(), gen);

    std::cout << "Generated sequence: ";
    print(five);
}
