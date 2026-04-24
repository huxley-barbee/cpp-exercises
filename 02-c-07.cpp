/*
 * ## EXERCISE 7: SFINAE Basics [2.c.iii]
 * 
 * Write a program demonstrating SFINAE (Substitution Failure Is Not An Error).
 * 
 * **Requirements:**
 * 1. Create two overloads: one for integral types, one for floating types
 * 2. Use std::enable_if to enable/disable based on type traits
 * 3. Show that failed substitution removes function from overload set
 * 4. Demonstrate with std::is_integral, std::is_floating_point
 * 5. Show SFINAE in action with different types
 * 
 * **Expected output format:**
 * ```
 * === SFINAE Demo ===
 * 
 * Calling process(42):
 * Processing integral type: 42
 * Type category: integral
 * 
 * Calling process(3.14):
 * Processing floating-point type: 3.14
 * Type category: floating-point
 * 
 * Calling process("hello"):
 * Compiler error: no matching function (both overloads SFINAE'd out)
 * 
 * === How SFINAE Works ===
 * 1. Compiler tries to substitute int into enable_if<is_floating_point<int>>
 * 2. Substitution fails (int is not floating-point)
 * 3. This is NOT an error - just removes this overload
 * 4. Compiler tries other overload with enable_if<is_integral<int>>
 * 5. Success! This overload is used
 * 
 * SFINAE enables compile-time function selection!
 * ```
 */

#include <iostream>
#include <type_traits>

template<typename T> std::enable_if_t<std::is_integral<T>::value, void>
process(T thing)
{
    std::cout << "Processing integral type: " << thing << "\n";
    std::cout << "Type category: integral\n";
}

template<typename T> std::enable_if_t<std::is_floating_point<T>::value, void>
process(T thing)
{
    std::cout << "Processing floating-point type: " << thing << "\n";
    std::cout << "Type category: floating-point\n";
}

int main() {

    std::cout << "=== SFINAE Demo ===\n";
    std::cout << "\n";

    std::cout << "Calling process(42):\n";
    process(42);
    std::cout << "\n";

    std::cout << "Calling process(3.14):\n";
    process(3.14);
    std::cout << "\n";

    std::cout << "Calling process(\"hello\"):\n";
    //process("hello");
    std::cout << "Compiler error: no matching function (both overloads SFINAE'd out)\n";

    std::cout <<
        R"EOF(=== How SFINAE Works ===
1. Compiler tries to substitute int into enable_if<is_floating_point<int>>
2. Substitution fails (int is not floating-point)
3. This is NOT an error - just removes this overload
4. Compiler tries other overload with enable_if<is_integral<int>>
5. Success! This overload is used

SFINAE enables compile-time function selection!
)EOF";


}
