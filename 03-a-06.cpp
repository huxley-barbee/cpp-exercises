/*
 * ## EXERCISE 6: Lambda Expressions - Advanced [3.a.iv]
 *
 * Write a program demonstrating advanced lambda features.
 *
 * **Requirements:**
 * 1. Show mutable lambda
 * 2. Demonstrate generic lambda (C++14)
 * 3. Show init capture (C++14)
 * 4. Use lambda as function return value
 * 5. Show recursive lambda
 * 6. Demonstrate lambda with trailing return type
 *
 * **Expected output format:**
 * ```
 * === Mutable Lambda ===
 * int x = 0;
 * auto counter = [x]() mutable { return ++x; };
 * First call: 1
 * Second call: 2
 * Third call: 3
 * Original x unchanged: 0
 *
 * === Generic Lambda (C++14) ===
 * auto print = [](auto x) { std::cout << x << std::endl; };
 * print(42);          // int
 * print(3.14);        // double
 * print("hello");     // const char*
 *
 * === Init Capture (C++14) ===
 * auto ptr = std::make_unique<int>(42);
 * auto lambda = [p = std::move(ptr)]() { return *p; };
 * Result: 42
 * Original ptr is null: true
 *
 * === Lambda as Return Value ===
 * auto makeAdder(int n) {
 *     return [n](int x) { return x + n; };
 * }
 * auto add5 = makeAdder(5);
 * add5(10) = 15
 *
 * === Recursive Lambda ===
 * auto factorial = [](int n) {
 *     auto impl = [](int n, auto& self) -> int {
 *         return n <= 1 ? 1 : n * self(n - 1, self);
 *     };
 *     return impl(n, impl);
 * };
 * factorial(5) = 120
 *
 * === Trailing Return Type ===
 * auto lambda = [](int x) -> double { return x / 2.0; };
 * lambda(5) = 2.5
 *
 * Advanced lambdas enable powerful functional programming!
 * ```
 */

int main() {}
