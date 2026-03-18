/** 
 * ========================================================================
 * EXERCISE 5: References Basics [1.a.ii]
 * ========================================================================
 * 
 * Write a program demonstrating references vs pointers.
 * 
 * Requirements:
 * 1. Create int 'original' = 77
 * 2. Create reference 'ref' to original
 * 3. Print both, showing they're the same
 * 4. Modify through reference (ref = 88)
 * 5. Show original changed
 * 6. Create const reference to prevent modification
 * 7. Demonstrate you cannot reassign a reference (it's an alias, not a pointer)
 * 
 * Expected output format:
 * Original: 77, Reference: 77
 * After modification via reference:
 * Original: 88, Reference: 88
 * Const reference value: 88
 * Reference cannot be reassigned - it's a permanent alias!
 */ 

#include <iostream>

int main() {

    int original = 77;
    int& reference = original;

    std::cout << "Original: " << original << ", Reference: " << reference
        << '\n';
    std::cout << "After modification via reference:" << '\n';

    reference = 88;

    std::cout << "Original: " << original << ", Reference: " << reference
        << '\n';

    const int &const_ref = original;

    std::cout << "Const reference value: " << const_ref << '\n';
    std::cout << "Reference cannot be reassigned - it's a permanent alias!" << '\n';
    
    /* this fails with
     * error: cannot assign to variable 'const_ref' with const-qualified
     * type 'const int &'
     */
    //const_ref = 99;

    int other = 99;
    reference = other;  // Does NOT rebind ref to other — it sets original = 99
    // ref still refers to original, not other
    std::cout << "original: " << original << '\n'; // 99
    std::cout << "&ref == &original: " << (&reference == &original) << '\n'; // 1
}
