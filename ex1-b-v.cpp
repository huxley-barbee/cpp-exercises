/**
 * Exercise 1.b.v — STL Algorithms
 * Tag: 1.b.v STL algorithms
 *
 * Use one STL algorithm to sum {1,2,3,4,5}.
 */

#include <array>
#include <iostream>
#include <numeric>

int main() {

    std::array<int, 5> array = { 1, 2, 3, 4, 5 };

    int sum = std::accumulate(array.begin(), array.end(), 0);

    std::cout << sum << std::endl;
}
