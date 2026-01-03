/*
* ===========================================================================
* EXERCISE 3: Pointers - Basic Operations [1.a.ii]
* ===========================================================================
* 
* Write a program demonstrating pointer fundamentals.
* 
* Requirements:
* 1. Declare int 'value' = 42
* 2. Create pointer 'ptr' pointing to 'value'
* 3. Print: value, address of value, ptr, *ptr
* 4. Modify value through pointer (*ptr = 100)
* 5. Print value again to show change
* 6. Create nullptr pointer, check if it's null before dereferencing
* 
* Expected output format:
* Value: 42
* Address of value: 0x[address]
* Pointer holds: 0x[address]
* Dereferenced pointer: 42
* After modification through pointer
* Value: 100
* Nullptr check: Pointer is null, safe!
*/

#include <iostream>

int main() {

    int value = 42;
    int *pointer = &value;

    std::cout << "Value: " << value << std::endl;
    std::cout << "Address of value: " << &value << std::endl;
    std::cout << "Pointer holds: " << pointer << std::endl;
    std::cout << "Dereferenced pointer: " << *pointer << std::endl;
    *pointer = 100;
    std::cout << "Value: " << value << std::endl;

    void *null_pointer = NULL;
    if (!null_pointer) {
        std::cout << "Nullptr check: Pointer is null, safe!" << std::endl;
    }
}
