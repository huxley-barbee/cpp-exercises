/*
 * Exercise 1.b.i — vector vs array
 * Tag: 1.b.i vector, array
 *
 * Create a std::array and a std::vector, modify the second element
 * to 20, and print both.
 */

#include <array>
#include <iostream>
#include <vector>

int main() {

    /* std::array is a container class in the C++ Standard Library
     * introduced in C++11
     */
    std::array<int, 2> array = {};

    /* std::vector is a container class in the C++ Standard Library
     * that implements a dynamic array
     */
    std::vector<int> vector(2);

    array[1] = 20;
    vector[1] = 20;

    std::cout << array[1] << std::endl;
    std::cout << vector[1] << std::endl;

}
