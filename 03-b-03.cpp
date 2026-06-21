/*
 * ## EXERCISE 3: Zero-Cost Abstractions — Inline Functions [3.b.ii]
 *
 * Write a program demonstrating zero-cost abstractions with inline and `constexpr` functions.
 *
 * **Requirements:**
 * 1. Show function-call overhead for a non-inline function
 * 2. Demonstrate that an equivalent `inline` function eliminates the call
 * 3. Use `constexpr` for compile-time evaluation
 * 4. Measure performance: raw arithmetic vs abstracted call
 * 5. Show the compiler (`-O2`) auto-inlines even non-inline functions
 * 6. Summarise the zero-overhead principle
 *
 * **Expected output:**
 * ```
 * === Non-Inline Function Call ===
 * add(3, 4) = 7
 * (Compiler emits a real function call — ~5-10 cycles overhead)
 *
 * === Inline Function (Zero-Cost) ===
 * add_inline(3, 4) = 7
 * (Compiler substitutes body directly — 0 call overhead)
 *
 * === constexpr (Compile-Time) ===
 * constexpr square(5) = 25
 * Runtime cost: 0 cycles — value baked into binary
 *
 * === Performance Comparison (1 000 000 iterations) ===
 * Non-inline add: ~25ms
 * Inline add:     ~2ms
 * Speedup:        ~12x
 *
 * With -O2 (compiler auto-inlines):
 * Non-inline:     ~2ms
 * Inline:         ~2ms
 * Result:         Zero-cost abstraction confirmed!
 *
 * === Zero-Overhead Abstractions ===
 * ✓ inline functions
 * ✓ constexpr
 * ✓ Templates (monomorphised at compile time)
 * ✓ unique_ptr (no extra indirection)
 * ✓ Range-based for loops
 *
 * "Zero overhead principle" — Bjarne Stroustrup
 * ```
 */

int main() {}
