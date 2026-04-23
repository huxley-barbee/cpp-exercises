/*
 * ## EXERCISE 6: Template Specialization - Partial [2.c.ii]
 * 
 * Write a program demonstrating partial template specialization.
 * 
 * **Requirements:**
 * 1. Create template class Container<T, Allocator>
 * 2. Partially specialize for pointer types Container<T*, Allocator>
 * 3. Partially specialize for const types Container<const T, Allocator>
 * 4. Show ordering of specialization selection
 * 5. Demonstrate that partial specialization only works for classes
 * 
 * **Expected output format:**
 * ```
 * === Primary Template ===
 * Container<int>: regular container
 * Element: 42
 * 
 * === Partial Specialization for Pointers ===
 * Container<int*>: pointer container (special handling)
 * Dereferencing pointer: 42
 * 
 * === Partial Specialization for Const ===
 * Container<const int>: const container (read-only)
 * Value: 100 (cannot modify)
 * 
 * === Specialization Selection Order ===
 * Container<int> -> primary template
 * Container<int*> -> pointer specialization
 * Container<const int> -> const specialization
 * Container<const int*> -> most specialized (pointer + const)
 * 
 * Partial specialization allows patterns, not just single types!
 * ```
 */

#include <iostream>

template <typename T> class Container {
    public:
        void print(T thing) {
            std::cout << "Element: " << thing << "\n";
        }
};

template <typename T> class Container<T*> {
    public:
        void print(T* thing) {
            std::cout << "Deferencing pointer: " << *thing << "\n";
        }
};

template <typename T> class Container<const T> {
    public:
        void print(const T thing) {
            std::cout << "Element: " << thing << " (cannot modify)\n";
            //thing = 101;
        }
};

int main() {

    std::cout << "=== Primary Template ===\n";
    std::cout << "Container<int>: regular container\n";
    Container<int> container;
    container.print(42);

    std::cout << "\n";

    std::cout << "=== Partial Specialization for Pointers ===\n";
    std::cout << "Container<int*>: pointer container (special handling)\n";
    Container<int*> container2;
    int value = 42;
    container2.print(&value);

    std::cout << "\n";

    std::cout << "=== Partial Specialization for Const ===\n";
    std::cout << "Container<const int>: const container (read-only)";
    Container<const int> container3;
    const int val = 47;
    container3.print(val);

    std::cout << "\n";

    std::cout << "=== Specialization Selection Order ===\n";
    std::cout << "Container<int> -> primary template\n";
    std::cout << "Container<int*> -> pointer specialization\n";
    std::cout << "Container<const int> -> const specialization\n";
    std::cout << "Container<const int*> -> most specialized (pointer + const)\n";

    std::cout << "\n";

    std::cout << "Partial specialization allows patterns, not just single types!\n";

}
