/**
 * Exercise 1.b.iv — Iterators
 * Tag: 1.b.iv Iterators
 *
 * Use iterators to increment each element in a vector {1,2,3,4}.
 *
 * Compile with: g++ -std=c++11 ex1-b-iv.cpp
 */

#include <iostream>
#include <vector>

int main() {

    std::vector<int> vector = {1, 2, 3, 4};

    for (auto it = vector.begin(); it != vector.end(); ++it) {
        (*it)++;
    }

    for (auto item : vector) {
        std::cout << item << std::endl;
    }
}
