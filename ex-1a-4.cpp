/**
 * ========================================================================
 * EXERCISE 4: Pointers - Array Relationship [1.a.ii]
 * ========================================================================
 * 
 * Write a program showing pointer arithmetic with arrays.
 * 
 * Requirements:
 * 1. Create int array: {10, 20, 30, 40, 50}
 * 2. Use pointer to traverse array without subscript operator
 * 3. Print each element using pointer arithmetic (ptr + i) and dereference
 * 4. Show that array name decays to pointer: print arr and &arr[0]
 * 5. Calculate array size using pointer arithmetic: &arr[5] - &arr[0]
 * 
 * Expected output format:
 * Element 0: 10 (address: 0x[addr])
 * Element 1: 20 (address: 0x[addr])
 * Element 2: 30 (address: 0x[addr])
 * Element 3: 40 (address: 0x[addr])
 * Element 4: 50 (address: 0x[addr])
 * Array address: 0x[addr]
 * First element address: 0x[addr]
 * Array size via pointers: 5
 * 
 */ 

#include <iostream>

int main() {

    int array[] = { 10, 20, 30, 40, 50 };

    int *pointer = array;

    for (int index = 0; index < 5; index++) {
        std::cout << "Element " << index << ": " << *(pointer+index)
            << " (address: 0x" << pointer+index << ")" << std::endl;
    }

    std::cout << "Array address: 0x" << array << std::endl;
    std::cout << "First element address: " << &array[0] << std::endl;
    std::cout << "Array size via pointers: " <<&array[5] - &array[0]
        << std::endl;
}
