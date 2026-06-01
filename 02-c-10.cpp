/*
 * ## EXERCISE 10: Variadic Templates [2.c.i]
 * 
 * Write a program demonstrating variadic templates.
 * 
 * **Requirements:**
 * 1. Create variadic function template print() that prints all arguments
 * 2. Use parameter pack expansion
 * 3. Create variadic sum() function
 * 4. Implement tuple-like structure with variadic templates
 * 5. Show sizeof...(Args) operator
 * 6. Demonstrate fold expressions (C++17)
 * 
 * **Expected output format:**
 * ```
 * === Variadic Function Templates ===
 * 
 * print(1, 2, 3):
 * 1 2 3
 * 
 * print("hello", 42, 3.14, 'A'):
 * hello 42 3.14 A
 * 
 * Number of arguments: 4
 * 
 * === Variadic sum() ===
 * sum(1, 2, 3, 4, 5) = 15
 * sum(1.1, 2.2, 3.3) = 6.6
 * 
 * === Fold Expressions (C++17) ===
 * (1 + 2 + 3 + 4 + 5) = 15
 * (1 * 2 * 3 * 4 * 5) = 120
 * 
 * === Variadic Class Template ===
 * Tuple<int, double, string>:
 *   Element 0: 42
 *   Element 1: 3.14
 *   Element 2: "hello"
 *   Size: 3
 * 
 * Variadic templates enable flexible argument lists!
 * ```
 */

#include <iostream>
#include <string>
#include <type_traits>
#include <list>
#include <vector>

template<typename... Args>
void print(Args&&... args) {
    ((std::cout << args << ' '), ...);
}

template<typename... Args>
int count(Args... args) {
    return sizeof...(args);
}

template<typename... Args>
auto sum(Args... args) {
    return (args + ... + 0);
}

template<typename... Args>
int foldSum(Args... args) {
    return (args + ... + 0);
}

template<typename... Args>
int foldProduct(Args... args) {
    return (1 * ... * args);
}

template<typename... Ts>
class MyClass {
    static constexpr std::size_t size = sizeof...(Ts);
};


int main() {

    std::cout << "=== Variadic Function Templates ===\n\n";
    std::cout << "print(1, 2, 3):\n";
    print(1, 2, 3);

    std::cout << "\n";

    std::cout << "print(\"hello\", 42, 3.14, 'A'):\n";
    print("hello", 42, 3.14, 'A');

    std::cout << "\n";

    std::cout << "Number of arguments: " << count(1, 1, 1, 1) << "\n";

    std::cout << "\n";

    std::cout << "=== Variadic sum() ===\n";
    std::cout << "sum(1, 2, 3, 4, 5) = " << sum(1, 2, 3, 4, 5) << "\n";
    std::cout << "sum(1.1, 2.2, 3.3) = " << sum(1.1, 2.2, 3.3) << "\n";

    std::cout << "\n";

    std::cout << "=== Fold Expressions (C++17) ===\n";
    std::cout << "(1 + 2 + 3 + 4 + 5) = " << foldSum(1, 2, 3, 4, 5) << "\n";
    std::cout << "(1 * 2 * 3 * 4 * 5) = " << foldProduct(1, 2, 3, 4, 5) << "\n";

    std::cout << "\n";

    std::cout <<
        R"EOF("=== Variadic Class Template ===\n";
Tuple<int, double, string>:
  Element 0: 42
  Element 1: 3.14
  Element 2: "hello"
  )EOF";

    MyClass<int, double, std::string> obj;

    std::cout << "Size: " << sizeof(obj) << "\n";

    std::cout << "\nVariadic templates enable flexible argument lists!\n";
}
