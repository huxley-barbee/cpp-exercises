/*
 * ## EXERCISE 7: Macros — Compile-Time Polymorphism and Guards [4.a.iv]
 *
 * Write a program showing how C++98 used macros for things that templates and `inline` now handle better.
 *
 * **Requirements:**
 * 1. Implement a `MAX(a, b)` macro and show the classic double-evaluation bug
 * 2. Implement a `STATIC_ASSERT(cond, msg)` macro (pre-C++11 trick using `typedef`)
 * 3. Implement an include guard using `#ifndef / #define / #endif`
 * 4. Implement a `DISALLOW_COPY(ClassName)` macro (private copy ctor + assignment)
 * 5. Show the `#ifdef DEBUG` pattern for conditional compilation
 * 6. For each, show the modern C++11 equivalent
 *
 * **Expected output:**
 * ```
 * === MAX Macro Bug ===
 * int a = 3, b = 5;
 * MAX(a, b) = 5  (correct here)
 *
 * int x = 3;
 * MAX(++x, 5) = ?
 * Expected: max(4, 5) = 5
 * Actual:   x incremented TWICE — x = 5, result = 6  (BUG!)
 *
 * Modern fix: template<typename T> T max(T a, T b) { return a > b ? a : b; }
 *
 * === STATIC_ASSERT Macro (pre-C++11) ===
 * STATIC_ASSERT(sizeof(int) == 4, int_must_be_4_bytes)
 * Trick: typedef char assertion_failed[(cond) ? 1 : -1]
 * Cryptic error if condition false.
 *
 * Modern fix: static_assert(sizeof(int) == 4, "int must be 4 bytes");
 *
 * === DISALLOW_COPY Macro ===
 * class NoCopy {
 *     DISALLOW_COPY(NoCopy);  // expands to private copy ctor + assignment
 * };
 * // NoCopy a; NoCopy b = a;  // compile error
 *
 * Modern fix: = delete
 *
 * === #ifdef DEBUG ===
 * Compiled with DEBUG: extra checks enabled
 * Without DEBUG: checks stripped from binary
 *
 * Modern fix: if constexpr or compiler optimises away dead branches
 * ```
 */

int main() {}
