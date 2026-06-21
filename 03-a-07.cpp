/*
 * ## EXERCISE 7: constexpr Functions [3.a.v]
 *
 * Write a program demonstrating constexpr for compile-time computation.
 *
 * **Requirements:**
 * 1. Create constexpr function for factorial
 * 2. Show computation at compile time vs runtime
 * 3. Demonstrate constexpr with if constexpr
 * 4. Show constexpr variables
 * 5. Create constexpr class/constructor
 * 6. Use static_assert with constexpr
 *
 * **Expected output format:**
 * ```
 * === constexpr Functions ===
 *
 * constexpr int factorial(int n) {
 *     return n <= 1 ? 1 : n * factorial(n - 1);
 * }
 *
 * Compile-time computation:
 * constexpr int f5 = factorial(5);  // Computed at compile time
 * Value: 120
 *
 * Runtime computation:
 * int n = 5;
 * int f = factorial(n);  // Computed at runtime
 * Value: 120
 *
 * === if constexpr (C++17) ===
 * template<typename T>
 * auto getValue(T t) {
 *     if constexpr (std::is_pointer_v<T>) {
 *         return *t;  // Dereference if pointer
 *     } else {
 *         return t;   // Return as-is if not pointer
 *     }
 * }
 *
 * getValue(42) = 42
 * getValue(&x) = 100 (dereferenced)
 *
 * === constexpr Variables ===
 * constexpr double PI = 3.14159;
 * constexpr double area = PI * 5 * 5;  // Computed at compile time
 * Area of circle (r=5): 78.5398
 *
 * === constexpr Class ===
 * struct Point {
 *     int x, y;
 *     constexpr Point(int x_, int y_) : x(x_), y(y_) {}
 *     constexpr int distance() const { return x*x + y*y; }
 * };
 *
 * constexpr Point p(3, 4);
 * constexpr int d = p.distance();  // Compile-time: 25
 *
 * === static_assert ===
 * static_assert(factorial(5) == 120, "Math broken!");
 * static_assert(sizeof(int) >= 4, "int too small!");
 *
 * All assertions passed at compile time!
 *
 * constexpr moves computation from runtime to compile time!
 * ```
 */

int main() {}
