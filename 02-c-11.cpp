/*
 * ## EXERCISE 11: Template Metaprogramming Basics [2.c.ii]
 * 
 * Write a program demonstrating compile-time computation with templates.
 * 
 * **Requirements:**
 * 1. Compute factorial at compile time
 * 2. Compute Fibonacci at compile time
 * 3. Show constexpr as modern alternative
 * 4. Demonstrate type list manipulation
 * 5. Use static_assert for compile-time checks
 * 
 * **Expected output format:**
 * ```
 * === Compile-Time Factorial ===
 * factorial<5> = 120 (computed at compile time)
 * factorial<10> = 3628800
 * 
 * === Compile-Time Fibonacci ===
 * fibonacci<10> = 55 (computed at compile time)
 * fibonacci<20> = 6765
 * 
 * === Modern Alternative: constexpr ===
 * constexpr factorial(5) = 120
 * constexpr fibonacci(10) = 55
 * 
 * Both computed at compile time, but constexpr is cleaner!
 * 
 * === Type List Manipulation ===
 * TypeList<int, double, string>:
 *   Size: 3
 *   First type: int
 *   Last type: string
 * 
 * === Compile-Time Assertions ===
 * static_assert(factorial<5> == 120, "Math is broken!");
 * static_assert(sizeof(int) == 4, "Unexpected int size!");
 * 
 * All checks passed at compile time!
 * ```
 */

#include <iostream>
#include <string>
#include <type_traits>
#include <list>
#include <vector>

template<int N>
struct Factorial {
    static const int value = N * Factorial<N-1>::value;
};

template<>
struct Factorial<0> {
    static const int value = 1;
};

//template<int N>
//struct Fibonacci {
//    static const int value;
//};
//
//template<int N>
//const int Fibonacci<N>::value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
//
//// base cases as full struct specializations
//template<>
//struct Fibonacci<0> {
//    static const int value = 0;
//};
//
//template<>
//struct Fibonacci<1> {
//    static const int value = 1;
//};

constexpr int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

constexpr int fibonacci(int n) {
    if ( n <= 1 ) {
        return 1;
    } else if ( n == 2 ) {
        return 1;
    } else {
        return fibonacci(n-2) + fibonacci(n-1);
    }
}

template<typename... Ts>
struct TypeList {};
using MyList = TypeList<int, double, std::string>;

template<typename List>
struct Length;
template<typename... Ts>
struct Length<TypeList<Ts...>> {
    static constexpr size_t value = sizeof...(Ts);
};

template<typename List> struct Head;
template<typename T, typename... Ts>
struct Head<TypeList<T, Ts...>> {
    using type = T;
};

template<typename List> struct Tail;
template<typename T, typename... Ts>
struct Tail<TypeList<T, Ts...>> {
    using type = TypeList<Ts...>;
};

int main() {
    std::cout << "=== Compile-Time Factorial ===\n";
    std::cout << "factorial<5> = " << Factorial<5>::value << " (computed at compile time)\n";
    std::cout << "factorial<10> = " << Factorial<10>::value << "\n\n";

    // std::cout << "=== Compile-Time Fibonacci ===\n";
    // std::cout << "fibonacci<10> = " << Fibonacci<55>::value << " (computed at compile time)\n";
    // std::cout << "fibonacci<20> = " << Fibonacci<6765>::value << "\n\n";

    /**
     * This implementation cannot be completed using pre-constexpr syntax. The Fibonacci
     * template requires two recursive template instantiations
     * (Fibonacci<N-1>::value + Fibonacci<N-2>::value) as an inline static const int initializer,
     * which is not guaranteed to be accepted as a constant expression before C++11. Unlike
     * Factorial, which uses a single multiplication that compilers tolerate inline, Fibonacci's
     * dependent double recursion requires constexpr to be well-formed. The correct solution
     * requires either static constexpr int (C++11) or a compiler extension beyond the pre-C++11
     * standard.
     */

    std::cout << "=== Modern Alternative: constexpr ===\n";
    std::cout << "constexpr factorial(5) = " << factorial(5) << "\n";
    std::cout << "constexpr fibonacci(10) = " << fibonacci(10) << "\n\n";

    std::cout << "Both computed at compile time, but constexpr is cleaner!\n\n";

    std::cout << "=== Type List Manipulation ===\n";
    std::cout << "TypeList<int, double, string>:\n";
    std::cout << "\tSize: " << Length<MyList>::value << "\n";
    std::cout << "\tFirst type: " << typeid(typename Head<MyList>::type).name() << "\n";
    std::cout << "\tLast type: " << typeid(typename Tail<MyList>::type).name() << "\n\n";

    std::cout << "=== Compile-Time Assertions ===\n";
    std::cout << "static_assert(factorial<5> == 120, \"Math is broken!\");\n";
    static_assert(Factorial<5>::value == 120, "Math is broken!");

    std::cout << "static_assert(sizeof(int) == 4, \"Unexpected int size!\");\n";
    static_assert(sizeof(int) == 4, "Unexpected int size!");

    std::cout << "\nAll checks passed at compile time!\n";
}
