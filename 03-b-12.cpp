/*
 * ## EXERCISE 12: Perfect Forwarding and Efficiency [3.b.ii]
 *
 * Write a program demonstrating `std::forward` for zero-cost wrapper functions.
 *
 * **Requirements:**
 * 1. Show copy overhead in a naive wrapper that takes by value
 * 2. Fix with a template wrapper using a universal reference (`T&&`) and `std::forward`
 * 3. Demonstrate the difference when passing lvalues vs rvalues
 * 4. Show perfect forwarding in a variadic factory function
 * 5. Highlight the common mistake of forgetting `std::forward`
 *
 * **Expected output:**
 * ```
 * === Naive Wrapper (BAD) ===
 * template<typename T>
 * void wrapper(T arg) { process(arg); }
 *
 * wrapper(w):          Copy 1 (to wrapper) + Copy 2 (to process) = 2 copies
 * wrapper(Widget()):   Copy 1 (materialise) + Copy 2 (to process) = 2 copies
 *
 * === Perfect Forwarding (GOOD) ===
 * template<typename T>
 * void wrapper(T&& arg) { process(std::forward<T>(arg)); }
 *
 * wrapper(w):          1 copy (lvalue forwarded as lvalue)
 * wrapper(Widget()):   1 move (rvalue forwarded as rvalue)
 * wrapper(std::move(w)): 1 move (rvalue forwarded as rvalue)
 *
 * === Variadic Perfect-Forwarding Factory ===
 * template<typename T, typename... Args>
 * unique_ptr<T> make(Args&&... args) {
 *     return unique_ptr<T>(new T(std::forward<Args>(args)...));
 * }
 *
 * make<Widget>(1, "hello", 3.14) — no extra copies!
 *
 * === Common Mistake ===
 * // WRONG: arg is an lvalue inside the function body
 * template<typename T>
 * void wrapper(T&& arg) { process(arg); }   // Copies even for rvalue!
 *
 * // CORRECT:
 * template<typename T>
 * void wrapper(T&& arg) { process(std::forward<T>(arg)); }
 *
 * === Performance (1 000 000 forwards) ===
 * Naive wrapper (always copies): ~850ms
 * Perfect forwarding (moves):    ~120ms
 * Speedup: ~7x
 *
 * Perfect forwarding = zero-cost generic wrappers!
 * ```
 */

int main() {}
