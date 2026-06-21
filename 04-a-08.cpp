/*
 * ## EXERCISE 8: Pre-C++11 STL Quirks — Iterators and Algorithms [4.a.v]
 *
 * Write a program using pre-C++11 STL idioms that look foreign to modern eyes.
 *
 * **Requirements:**
 * 1. Use `std::vector<int>::iterator` (written out fully — no `auto`)
 * 2. Use `std::for_each` with a hand-written functor (no lambdas)
 * 3. Use `std::bind1st` / `std::bind2nd` for partial application
 * 4. Use `std::ptr_fun` to adapt a free function for an algorithm
 * 5. Use `std::mem_fun` / `std::mem_fun_ref` to call a member function via algorithm
 * 6. For each, show the C++11 equivalent (lambda / `std::bind` / range-for)
 *
 * **Expected output:**
 * ```
 * === Pre-C++11 Iterator Syntax ===
 * std::vector<int>::iterator it = v.begin();
 * Elements: 1 2 3 4 5
 *
 * === Hand-Written Functor (no lambdas) ===
 * struct Printer { void operator()(int x) { ... } };
 * for_each result: 1 2 3 4 5
 *
 * Modern: for_each(v.begin(), v.end(), [](int x){ ... });
 *
 * === bind2nd ===
 * count_if with bind2nd(greater<int>(), 3): 2  (elements > 3)
 * Modern: count_if(v.begin(), v.end(), [](int x){ return x > 3; });
 *
 * === ptr_fun ===
 * Adapting free function isEven via ptr_fun
 * Even elements: 2 4
 * Modern: use lambda directly
 *
 * === mem_fun_ref ===
 * Calling .empty() on each string via mem_fun_ref
 * Non-empty strings: 3
 * Modern: use lambda [](const string& s){ return !s.empty(); }
 * ```
 */

int main() {}
