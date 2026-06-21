/*
 * ## EXERCISE 4: Uniform Initialization [3.a.iii]
 *
 * Write a program demonstrating uniform initialization syntax.
 *
 * **Requirements:**
 * 1. Show initialization with {} for built-in types
 * 2. Demonstrate aggregate initialization
 * 3. Show initialization of containers
 * 4. Demonstrate initializer_list
 * 5. Show narrowing conversion prevention
 * 6. Compare with old-style initialization
 *
 * **Expected output format:**
 * ```
 * === Uniform Initialization ===
 *
 * Built-in types:
 * int x{5};           // Uniform init
 * int y = 5;          // Traditional init
 * int z(5);           // Direct init
 *
 * === Aggregate Initialization ===
 * struct Point { int x; int y; };
 * Point p1{10, 20};   // Uniform init
 * Point p2 = {10, 20};  // Also works
 *
 * === Container Initialization ===
 * std::vector<int> v1{1, 2, 3, 4, 5};
 * std::map<std::string, int> m{{"one", 1}, {"two", 2}};
 *
 * === Narrowing Prevention ===
 * int x = 1000;
 * // char c{x};  // ERROR: narrowing conversion
 * char c = x;    // OK (but data loss)
 *
 * Uniform initialization prevents accidental narrowing!
 *
 * === Most Vexing Parse ===
 * Widget w1();    // Function declaration (not what you want!)
 * Widget w2{};    // Object initialization (what you want)
 *
 * Uniform initialization solves most vexing parse!
 * ```
 */

int main() {}
