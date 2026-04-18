/*
 * ## EXERCISE 1: Function Templates - Basics [2.c.i]
 * 
 * Write a program demonstrating basic function templates.
 * 
 * **Requirements:**
 * 1. Create template function max() that works with any comparable type
 * 2. Test with int, double, and string
 * 3. Show type deduction (no need to specify <T>)
 * 4. Show explicit template instantiation
 * 5. Create template function swap() for any type
 * 6. Demonstrate template argument deduction rules
 * 
 * **Expected output format:**
 * ```
 * === Function Template: max ===
 * Max of 10 and 20: 20
 * Max of 3.14 and 2.71: 3.14
 * Max of "apple" and "banana": banana
 * 
 * Type deduction: compiler infers T = int
 * Explicit instantiation: max<double>(3.14, 2.71) = 3.14
 * 
 * === Function Template: swap ===
 * Before swap: a=5, b=10
 * After swap: a=10, b=5
 * 
 * Before swap: s1="hello", s2="world"
 * After swap: s1="world", s2="hello"
 * 
 * Template argument deduction works automatically!
 * ```
 */

#include <iostream>
#include <string>

template <typename T> T max(T x, T y) {
    if ( x > y ) {
        return x;
    } else {
        return y;
    }
}

template <typename T> const std::string infer(T x);
template <> const std::string infer<int>(int)    { return "int"; }

template <typename T> void swap(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}

int main() {

    std::cout << "=== Function Template: max ===\n";
    std::cout << "Max of 10 and 20: " << max<int>(10, 20) << "\n";
    std::cout << "Max of 3.14 and 2.71: " << max<double>(3.14, 2.71) << "\n";
    std::cout << "Max of \"apple\" and \"banana\": " << max<std::string>("apple", "banana") << "\n";

    std::cout << "\n";

    std::cout << "Type deduction: compiler infers T = : " << infer(47) << "\n";
    std::cout << "Explicit instantiation: max<double>(3.14, 2.71) = " << max<double>(3.41, 2.71) << "\n";

    std::cout << "\n";

    std::cout << "=== Function Template: swap ===\n";
    int a = 5;
    int b = 10;
    std::cout << "Before swap: a=" << a << ", b= " << b << "\n";
    swap<int>(a, b);
    std::cout << "After swap: a=" << a << ", b= " << b << "\n";

    std::string s1 = "hello";
    std::string s2 = "world";

    std::cout << "Before swap: s1=\"" << s1 << "\", s2=\"" << s2 << "\"\n";
    ::swap<std::string>(s1, s2);
    std::cout << "After swap: s1=\"" << s1 << "\", s2=\"" << s2 << "\"\n";

    std::cout << "\n";

    std::cout << "Template argument deduction works automatically!\n";
}
