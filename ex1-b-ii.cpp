/*
 * Exercise 1.b.ii — map vs unordered_map
 * Tag: 1.b.ii map vs unordered_map
 *
 * Insert (3,30), (1,10), (2,20) into map and unordered_map and print.
 *
 * Compile with: g++ -std=c++11 ex1-b-ii.cpp
 */

#include <iostream>
#include <map>
#include <unordered_map>

int main() {

    std::map<int, int> map;
    std::unordered_map<int, int> unordered_map;

    map.emplace(3, 30);
    map.emplace(1, 10);
    map.emplace(2, 20);

    unordered_map.emplace(3, 30);
    unordered_map.emplace(1, 10);
    unordered_map.emplace(2, 20);

    for (auto item : map) {
        std::cout << item.first << ": " << item.second << std::endl;
    }

    for (auto item : unordered_map) {
        std::cout << item.first << ": " << item.second << std::endl;
    }

}
