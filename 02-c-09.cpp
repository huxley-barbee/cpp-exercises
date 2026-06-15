/*
 * ## EXERCISE 9: Concepts (C++20) [2.c.iv]
 * 
 * Write a program demonstrating C++20 concepts.
 * 
 * **Requirements:**
 * 1. Define Addable concept (has operator+)
 * 2. Define Container concept (has begin/end/size)
 * 3. Use concepts to constrain template parameters
 * 4. Show requires clause syntax
 * 5. Compare with SFINAE approach
 * 6. Demonstrate better error messages
 * 
 * **Expected output format:**
 * ```
 * === C++20 Concepts ===
 * 
 * Concept: Addable
 * template<typename T>
 * concept Addable = requires(T a, T b) {
 *     { a + b } -> std::same_as<T>;
 * };
 * 
 * add(5, 10) = 15 (int satisfies Addable)
 * add(3.14, 2.71) = 5.85 (double satisfies Addable)
 * 
 * Concept: Container
 * template<typename T>
 * concept Container = requires(T c) {
 *     { c.begin() };
 *     { c.end() };
 *     { c.size() } -> std::same_as<size_t>;
 * };
 * 
 * processContainer(vector<int>): size = 5 (satisfies Container)
 * processContainer(list<string>): size = 3 (satisfies Container)
 * 
 * === Better Error Messages ===
 * With SFINAE: cryptic template substitution errors
 * With Concepts: "int does not satisfy Container concept"
 * 
 * === Comparison ===
 * SFINAE: requires(enable_if, decltype, complex syntax)
 * Concepts: readable, named constraints
 * ```
 */

#include <iostream>
#include <string>
#include <type_traits>
#include <list>
#include <vector>

template<typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};

template<Addable T>
T add(T a, T b) {
    return a + b;
}

template<typename U>
concept Container = requires(U c) {
    { c.begin() };
    { c.end() };
    { c.size() } -> std::same_as<size_t>;
};

/**
 * If we used SFINAE, it would be this.
 * template <typename U>
 * std::enable_if_t<has_size_method<T>::value, void>
 * size_t getSize(const T& thing) {
 *      return thing.size();
 * }
 *
 * And the error output would be inscrutable.
 */

template<Container U>
size_t processContainer(const U& c) {
    return c.size();
}

int main() {

    std::cout << "=== C++20 Concepts ===\n";
    std::cout << "\n";

    std::cout <<
        R"EOF(Concept: Addable
template<typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};
)EOF";

    std::cout << "add(5, 10) = " << add (5, 10) << " (int satisfies Addable)\n";
    std::cout << "add(3.14, 2.71) = " << add (3.14, 2.71) << " (double satisfies Addable)\n";

    std::cout << "\n";

    std::cout <<
        R"EOF(Concept: Container
template<typename T>
concept Container = requires(T c) {
    { c.begin() };
    { c.end() };
    { c.size() } -> std::same_as<size_t>;
};
)EOF";

    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    std::list<std::string> strings = { "lorem", "ipsum", "dolor" };

    std::cout << "processContainer(vector<int>): size = " << processContainer(numbers) << " (satisfies Container)\n";
    std::cout << "processContainer(list<string>): size = " << processContainer(strings) << " (satisfies Container)\n";

    std::cout <<
        R"EOF(=== Better Error Messages ===
With SFINAE: cryptic template substitution errors
With Concepts: "int does not satisfy Container concept"

=== Comparison ===
SFINAE: requires(enable_if, decltype, complex syntax)
Concepts: readable, named constraints
)EOF";

}
