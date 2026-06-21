/*
 * ## EXERCISE 5: Lambda Expressions - Basics [3.a.iv]
 *
 * Write a program demonstrating lambda expressions.
 *
 * **Requirements:**
 * 1. Create simple lambda with no captures
 * 2. Show lambda with captures by value [=]
 * 3. Show lambda with captures by reference [&]
 * 4. Demonstrate explicit captures [x, &y]
 * 5. Show lambda return type deduction
 * 6. Use lambda with STL algorithms
 *
 * **Expected output format:**
 * ```
 * === Lambda Basics ===
 *
 * Simple lambda (no captures):
 * auto sum = [](int a, int b) { return a + b; };
 * sum(3, 4) = 7
 *
 * === Capture by Value ===
 * int x = 10;
 * auto lambda = [x]() { return x * 2; };
 * Result: 20
 * Original x unchanged: 10
 *
 * === Capture by Reference ===
 * int y = 5;
 * auto lambda = [&y]() { y *= 2; };
 * After lambda: y = 10
 *
 * === Mixed Captures ===
 * int a = 1, b = 2;
 * auto lambda = [a, &b]() {
 *     b = a + b;  // Can modify b (reference)
 *     // a = 10;  // ERROR: a is const (captured by value)
 * };
 * After lambda: a = 1, b = 3
 *
 * === Lambda with STL ===
 * std::vector<int> v{5, 2, 8, 1, 9};
 * std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
 * Sorted descending: [9, 8, 5, 2, 1]
 *
 * int threshold = 5;
 * auto count = std::count_if(v.begin(), v.end(),
 *     [threshold](int x) { return x > threshold; });
 * Elements > 5: 2
 *
 * Lambdas enable inline function objects!
 * ```
 */

int main() {}
