/*
 * ## EXERCISE 2: Function Templates - Multiple Type Parameters [2.c.i]
 * 
 * Write a program with function templates using multiple type parameters.
 * 
 * **Requirements:**
 * 1. Create template function pair() with two different type parameters
 * 2. Create template function convert() that converts T1 to T2
 * 3. Show that type parameters can be independent
 * 4. Demonstrate partial type specification
 * 5. Use auto return type deduction (C++14)
 * 
 * **Expected output format:**
 * ```
 * === Multiple Type Parameters ===
 * Creating pair: (42, "hello")
 * Type 1: int, value: 42
 * Type 2: string, value: hello
 * 
 * Converting int to double: 42 -> 42.0
 * Converting double to int: 3.14 -> 3
 * Converting string to int: "123" -> 123
 * 
 * === Auto Return Type ===
 * add(5, 10) = 15 (deduced return type)
 * multiply(3.5, 2.0) = 7.0 (deduced return type)
 * 
 * Multiple type parameters allow flexible template functions!
 * ```
 */ 

#include <iostream>
#include <string>
#include <typeinfo>

template <typename T, typename U> auto
    makePair(const T& one, const U& two) {
    return std::make_pair(one, two);
}

template <typename T, typename U> U convert(const T& x) {
    return static_cast<U>(x);
}

template<> int convert<std::string, int>(const std::string& s) {
    return std::stoi(s);
}

template <typename T, typename U> auto add(T one, U two) {
    return one + two;
}

template <typename T, typename U> auto multiply(T one, U two) {
    return one * two;
}

int main() {

    std::cout << "=== Multiple Type Parameters ===\n";
    std::cout << "Creating pair: (42, \"hello\")\n";
    std::pair<int, std::string> pair = makePair<int>(42, "hello");
    std::cout << "Type 1: int, value: " << pair.first << "\n";
    std::cout << "Type 2: string, value: " << pair.second << "\n";

    std::cout << "\n";

    std::cout << "Converting int to double: 42 -> ";
    std::cout << std::showpoint << convert<int, double>(42);
    std::cout << "\n";

    std::cout << "Converting double to int: 3.14 -> ";
    std::cout << convert<double, int>(3.14);
    std::cout << "\n";

    std::cout << "Converting string to int: \"123\" -> ";
    std::cout << convert<std::string, int>("123");
    std::cout << "\n";

    std::cout << "\n";

    std::cout << "=== Auto Return Type ===\n";
    std::cout << "add(5, 10) = " << add(5, 10)
        << " (deduced return type)\n";
    std::cout << "multiply(3.5, 2.0) = " << std::showpoint << multiply(3.5, 2.0)
        << " (deduced return type)\n";

    std::cout << "Multiple type parameters allow flexible template functions!\n";

}
