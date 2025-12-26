/**
 * Exercise 2.a.iii — Smart Pointers
 * Tag: 2.a.iii smart pointers
 * 
 * Create a std::unique_ptr initialized to 42. Print the value.
 * Move ownership to another unique_ptr and print the value again.
 */

#include <iostream>
#include <memory>

int main() {

    /**
     * Modern C++ guidance is very explicit:
     * “Do not use new directly unless you are implementing
     * a low-level abstraction.”
     */
    // std::unique_ptr<int> pointer1(new int(42));
    auto pointer1 = std::make_unique<int>(42);

    std::unique_ptr<int> pointer2;

    std::cout << *pointer1 << std::endl;

    /* This segfaults. */
    // std::cout << *pointer2 << std::endl;

    pointer2 = std::move(pointer1);

    /* This segfaults. */
    // std::cout << *pointer1 << std::endl;
    std::cout << *pointer2 << std::endl;

}
