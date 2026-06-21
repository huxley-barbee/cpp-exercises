/*
 * ## EXERCISE 3: auto Type Deduction [3.a.ii]
 *
 * Write a program demonstrating auto type deduction rules.
 *
 * **Requirements:**
 * 1. Show auto deduces type from initializer
 * 2. Demonstrate auto with references (auto vs auto&)
 * 3. Show auto with const (auto vs const auto)
 * 4. Use auto with structured bindings (C++17)
 * 5. Show auto with function return types
 * 6. Demonstrate decltype(auto)
 *
 * **Expected output format:**
 * ```
 * === auto Type Deduction ===
 *
 * int x = 5;
 * auto a = x;        // Type: int (copy)
 * auto& b = x;       // Type: int& (reference)
 * const auto c = x;  // Type: const int
 * auto& d = c;       // Type: const int& (const preserved)
 *
 * After modifying b: x = 10 (reference modifies original)
 * After trying to modify a: x = 10 (copy doesn't affect original)
 *
 * === auto with Containers ===
 * std::vector<int> vec = {1, 2, 3};
 * auto it = vec.begin();  // Type: std::vector<int>::iterator
 * for (auto val : vec)    // Type: int (copy)
 * for (auto& val : vec)   // Type: int& (reference)
 * for (const auto& val : vec)  // Type: const int& (const reference)
 *
 * === Structured Bindings (C++17) ===
 * std::map<std::string, int> map = {{"one", 1}, {"two", 2}};
 * for (const auto& [key, value] : map) {
 *     // key: const std::string&, value: const int&
 *     one: 1
 *     two: 2
 * }
 *
 * === decltype(auto) ===
 * int& func() { return x; }
 * auto a = func();         // Type: int (copy)
 * decltype(auto) b = func();  // Type: int& (preserves reference)
 *
 * auto makes code cleaner while maintaining type safety!
 * ```
 */

int main() {}
