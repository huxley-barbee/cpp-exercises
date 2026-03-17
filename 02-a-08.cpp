/*
 * ## EXERCISE 8: Manual Memory Management - new/delete [2.a.iv]
 * 
 * Write a program demonstrating manual memory management with new/delete.
 * 
 * **Requirements:**
 * 1. Allocate single object with new
 * 2. Allocate array with new[]
 * 3. Properly delete with delete and delete[]
 * 4. Demonstrate memory leak (forget to delete)
 * 5. Show double-delete problem (undefined behavior - comment out)
 * 6. Demonstrate proper null-check before delete
 * 
 * **Expected output format:**
 * ```
 * === Single Object ===
 * Allocating single integer with new
 * Value: 42
 * Deleting single object
 * 
 * === Array ===
 * Allocating array with new[]
 * Array: [1, 2, 3, 4, 5]
 * Deleting array with delete[]
 * 
 * === Memory Leak Example ===
 * Allocating but not deleting (MEMORY LEAK)
 * Pointer value: 100
 * (Memory leaked - never deleted)
 * 
 * === Safe Delete Pattern ===
 * Pointer is valid, deleting
 * Pointer is now null, safe to delete again (does nothing)
 * 
 * WARNING: Double-delete would crash (commented out)
 * WARNING: Mismatched new[]/delete would corrupt memory (commented out)
 * ```
 */

#include <iostream>

int main() {

    std::cout << "=== Single Object ===" << std::endl;
    std::cout << "Allocating single integer with new" << std::endl;

    int* value = new int(42);
    std::cout << "Value: " << *value << std::endl;

    std::cout << "Deleting single object" << std::endl;
    delete value;

    std::cout << "=== Array ===" << std::endl;
    std::cout << "Allocating array with new[]" << std::endl;
    int* array = new int[]{1, 2, 3, 4, 5};

    std::cout << "Array: [";
    for (int index = 0; index < 5; index++) {
        if (index > 0) {
            std::cout << ", ";
        }
        std::cout << *(array+index);
    }
    std::cout << "]" << std::endl;

    std::cout << "Deleting array with delete[]" << std::endl;
    delete[] array;

    std::cout << "=== Memory Leak Example ===" << std::endl;
    std::cout << "Allocating but not deleting (MEMORY LEAK)" << std::endl;

    int* value2 = new int(100);
    std::cout << "Pointer Value: " << *value2 << std::endl;
    std::cout << "(Memory leaked - never deleted)" << std::endl;

    std::cout << "=== Safe Delete Pattern ===" << std::endl;
    int* value3 = new int(47);
    if (value3) {
        std::cout << "Pointer is valid, deleting" << std::endl;
        delete value3;
        /*
         * line below segfaults
        delete value3;
        */
    }
}
