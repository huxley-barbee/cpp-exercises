/*
 * ## EXERCISE 9: Manual Memory Management - Placement New [2.a.iv]
 * 
 * Write a program demonstrating placement new.
 * 
 * **Requirements:**
 * 1. Allocate raw memory buffer with malloc or char array
 * 2. Use placement new to construct object in that memory
 * 3. Manually call destructor (do not use delete)
 * 4. Show constructing multiple objects in pre-allocated buffer
 * 5. Demonstrate proper cleanup sequence
 * 
 * **Expected output format:**
 * ```
 * === Placement New Basics ===
 * Allocating raw memory buffer (100 bytes)
 * Using placement new to construct object at: 0x7ffc...
 * Constructor called
 * Object value: 42
 * 
 * Manually calling destructor
 * Destructor called
 * 
 * Buffer still exists (raw memory)
 * Freeing buffer memory
 * 
 * === Multiple Objects in Buffer ===
 * Constructing 5 objects in pre-allocated buffer
 * Constructed object 0 at offset 0
 * Constructed object 1 at offset 8
 * Constructed object 2 at offset 16
 * Constructed object 3 at offset 24
 * Constructed object 4 at offset 32
 * 
 * Manually destroying all objects...
 * Destroying object 4
 * Destroying object 3
 * Destroying object 2
 * Destroying object 1
 * Destroying object 0
 * 
 * Freeing buffer
 * ```
 */ 

#include <iostream>

class MyClass {
    private:
        int number;

    public:
        MyClass(int n) {
            number = n;
            std::cout << "Constructor called" << std::endl;
            std::cout << "Object value: " << number << std::endl;
        }

        ~MyClass() {
            std::cout << "Destructor called" << std::endl;
        }
};

int main() {


    std::cout << "=== Placement New Basics ===" << std::endl;
    std::cout << "Allocating raw memory buffer (100 bytes)" << std::endl;
    void* buffer = malloc(100);

    std::cout << "Using placement new to construct object at: " << buffer << std::endl;
    MyClass* value = new (buffer) MyClass(42);

    std::cout << "Manually calling destructor" << std::endl;
    value->~MyClass();

    std::cout << "Buffer still exists (raw memory)" << std::endl;
    std::cout << "Freeing buffer memory" << std::endl;
    free(buffer);

    int MAX = 5;
    MyClass* array[MAX];
    std::cout << "=== Multiple Objects in Buffer ===" << std::endl;
    buffer = malloc(MAX * sizeof(MyClass));

    std::cout << "Constructing 5 objects in pre-allocated buffer" << std::endl;

    for (int index = 0; index < MAX; index++) {

        std::cout << "Constructed object " << index << " at offset "
            << (index * sizeof(int)) << std::endl;

        array[index] = new (buffer) MyClass(42+index);

    }

    std::cout << "Manually destroying all objects..." << std::endl;

    for (int index = MAX-1; index >= 0; index--) {
        std::cout << "Destroying object " << index << std::endl;
        array[index]->~MyClass();
    }

    std::cout << "Freeing buffer" << std::endl;
    free(buffer);

}
