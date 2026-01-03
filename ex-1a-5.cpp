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
        << std::endl;
    std::cout << "After modification via reference:" << std::endl;

    reference = 88;

    std::cout << "Original: " << original << ", Reference: " << reference
        << std::endl;

    const int &const_ref = original;
    
    /* this fails with
     * error: cannot assign to variable 'const_ref' with const-qualified
     * type 'const int &'
     */
    //const_ref = 99;

}
