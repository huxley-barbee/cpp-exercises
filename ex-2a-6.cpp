/*
 * ## EXERCISE 6: Smart Pointers - shared_ptr and weak_ptr [2.a.iii]
 * 
 * Write a program demonstrating std::shared_ptr and std::weak_ptr.
 * 
 * **Requirements:**
 * 1. Create shared_ptr and show reference counting
 * 2. Create multiple shared_ptrs pointing to same object
 * 3. Show use_count() changes as shared_ptrs are created/destroyed
 * 4. Demonstrate weak_ptr (doesn't increase ref count)
 * 5. Show weak_ptr.lock() to safely access object
 * 6. Demonstrate weak_ptr becoming expired
 * 
 * **Expected output format:**
 * ```
 * Creating shared_ptr
 * Value: 42, use_count: 1
 * 
 * Creating second shared_ptr (copy)
 * Value: 42, use_count: 2
 * 
 * Creating third shared_ptr
 * Value: 42, use_count: 3
 * 
 * Creating weak_ptr (doesn't increase count)
 * use_count still: 3
 * weak_ptr expired: false
 * 
 * Locking weak_ptr to access value: 42
 * 
 * Destroying shared_ptrs...
 * After destroying one, use_count: 2
 * After destroying another, use_count: 1
 * After destroying last, object deleted
 * 
 * weak_ptr now expired: true
 * Attempting to lock expired weak_ptr: null
 * ```
 */ 

#include <iostream>
#include <memory>

int main() {

    std::cout << "Creating sahred_ptr" << std::endl;

    std::shared_ptr <int> shared1 = std::make_shared<int>(42);
    std::cout << "Value: " << *shared1 << ", use_count: "
        << shared1.use_count() << std::endl;

    std::cout << "Creating second shared_ptr (copy)" << std::endl;
    std::shared_ptr<int> shared2 = shared1;
    std::cout << "Value: " << *shared2 << ", use_count: "
        << shared2.use_count() << std::endl;

    std::cout << "Creating third shared_ptr (copy)" << std::endl;
    std::shared_ptr<int> shared3 = shared1;
    std::cout << "Value: " << *shared3 << ", use_count: "
        << shared3.use_count() << std::endl;

    std::cout << "Creating weak_ptr (doesn't increase cont)" << std::endl;
    std::weak_ptr<int> weak1 = shared1;
    std::cout << "use_count still: " << weak1.use_count() << std::endl;
    if ( !weak1.expired() ) {
        std::cout << "weak_ptr expired: false" << std::endl;
    }

    if ( auto shared_from_lock = weak1.lock() ) {
        std::cout << "Locking weak_ptr to access value : "
            << *shared_from_lock << std::endl;
    }

    std::cout << "Destroying shared ptrs..." << std::endl;
    shared3.reset();
    std::cout << "After destroying one, use_count: " << shared1.use_count()
        << std::endl;
    shared2.reset();
    std::cout << "After destroying another, use_count: "
        << shared1.use_count() << std::endl;
    shared1.reset();
    std::cout << "After destroying last, object deleted." << std::endl;

    std::cout << "weak_ptr now expired: " << weak1.expired()
        << std::endl;

    auto attempt = weak1.lock();
    std::cout << "Attempting to lock expired weak_ptr: " << attempt
        << std::endl;

}
