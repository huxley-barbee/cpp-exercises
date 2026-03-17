/*
 * ## EXERCISE 5: Smart Pointers - unique_ptr Basics [2.a.iii]
 * 
 * Write a program demonstrating std::unique_ptr.
 * 
 * **Requirements:**
 * 1. Create unique_ptr to an integer
 * 2. Show automatic cleanup (no delete needed)
 * 3. Demonstrate move semantics (transfer ownership)
 * 4. Show that copying is not allowed (compile error if attempted)
 * 5. Use unique_ptr with arrays
 * 6. Return unique_ptr from function
 * 7. Use make_unique (C++14)
 * 
 * **Expected output format:**
 * ```
 * Creating unique_ptr to integer
 * Value: 42
 * Address: 0x55...
 * 
 * Transferring ownership via move
 * Original ptr is now null: true
 * New ptr value: 42
 * 
 * unique_ptr with array:
 * Array elements: 1 2 3 4 5
 * 
 * unique_ptr returned from factory function
 * Created object value: 100
 * 
 * Automatic cleanup - no delete needed!
 * All unique_ptrs destroyed automatically
 * ```
 */ 

#include <iostream>
#include <memory>

std::unique_ptr<int> pointer_factory() {
    return std::make_unique<int>(100);
}

int main() {

    std::cout << "Creating unique_ptr to integer" << std::endl;
    auto pointer1 = std::make_unique<int>(42);

    std::cout << "Value: " << *pointer1 << std::endl;
    std::cout << "Address: " << pointer1 << std::endl;

    std::cout << std::endl;

    std::cout << "Transferring ownership via move" << std::endl;
    std::unique_ptr<int> pointer2;
    pointer2 = std::move(pointer1);
    if ( pointer1 == NULL ) {
        std::cout << "Original ptr is now null: true" << std::endl;
    }
    std::cout << "New ptr value: " << *pointer2 << std::endl;

    std::cout << std::endl;

    std::cout << "unique_ptr with array:" << std::endl;
    auto pointer3 = std::make_unique<int[]>(5);
    for (int index = 0; index < 5; index++) {
        pointer3[index] = index + 1;
    }

    std::cout << "Array elements:";
    for (int index = 0; index < 5; index++) {
        std::cout << " " << pointer3[index];
    }
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "unique_ptr returned from factory functoin" << std::endl;
    std::cout << "Created object value: " << *pointer_factory()
        << std::endl;;

    std::cout << std::endl;

    std::cout << "All unique_ptrs destroyed automatically" << std::endl;
}
