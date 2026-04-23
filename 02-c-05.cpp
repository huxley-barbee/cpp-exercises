/*
 * ## EXERCISE 5: Template Specialization - Full [2.c.ii]
 * 
 * Write a program demonstrating full template specialization.
 * 
 * **Requirements:**
 * 1. Create generic template class Storage<T>
 * 2. Specialize for bool (bit packing)
 * 3. Specialize for char* (string handling)
 * 4. Show that specialized version replaces generic entirely
 * 5. Demonstrate when specialization is chosen
 * 
 * **Expected output format:**
 * ```
 * === Generic Template ===
 * Storage<int>: storing integer 42
 * Size: 4 bytes
 * 
 * Storage<double>: storing double 3.14
 * Size: 8 bytes
 * 
 * === Full Specialization for bool ===
 * Storage<bool>: using bit packing optimization
 * Size: 1 byte (packed)
 * Value: true
 * 
 * === Full Specialization for char* ===
 * Storage<char*>: using string handling
 * Size: dynamic
 * Value: "hello world"
 * String length: 11
 * 
 * Specializations provide optimized implementations for specific types!
 * ```
 */

#include <iostream>
#include <string>

template <typename T> class Storage {
    public:
        void store(T thing) {
            std::cout << "Size: " << sizeof(thing) << " bytes\n";
        }

};

template <> class Storage<bool> {
    public:
        void store(bool thing) {
            std::cout << "Size: " << sizeof(thing) << " bytes (packed)\n";
            std::cout << "Value: " << std::boolalpha << thing << "\n";
        }
};

template <> class Storage<std::string> {
    public:
        void store(std::string thing) {
            std::cout << "Size: dynamic\n";
            std::cout << "Value: " << thing << "\n";
            std::cout << "String length: " << thing.size() << "\n";
        }
};

int main() {

    std::cout << "=== Generic Template ===\n";
    std::cout << "Storage<int>: storing integer 42\n";
    Storage<int> intStorage;
    intStorage.store(42);

    std::cout << "\n";

    std::cout << "Storage<double>: storing double 3.14\n";
    Storage<double> doubleStorage;
    doubleStorage.store(3.14);

    std::cout << "\n";

    std::cout << "=== Full Specialization for bool ===\n";
    std::cout << "Storage<bool>: using bit packing optimization\n";
    Storage<bool> boolStorage;
    boolStorage.store(true);

    std::cout << "=== Full Specialization for char* ===\n";
    std::cout << "Storage<char*>: using string handling\n";
    Storage<std::string> stringStorage;
    stringStorage.store("hello world");

    std::cout << "\n";

    std::cout << "Specializations provide optimized implementations for specific types!\n";

}
