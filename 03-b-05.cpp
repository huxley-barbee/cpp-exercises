/*
 * ## EXERCISE 5: Zero-Cost Abstractions — Range-Based For [3.b.ii]
 *
 * Write a program showing that range-based `for` loops have zero overhead compared with manual iteration.
 *
 * **Requirements:**
 * 1. Sum a large `std::vector<int>` using a raw index loop
 * 2. Sum using an explicit iterator loop
 * 3. Sum using a range-based `for` loop
 * 4. Measure all three
 * 5. Explain why the compiler produces identical assembly
 * 6. Compare readability ratings
 *
 * **Expected output:**
 * ```
 * === Index-Based Loop ===
 * sum = 500000500000
 * Time: ~25ms
 *
 * === Manual Iterator Loop ===
 * sum = 500000500000
 * Time: ~25ms
 *
 * === Range-Based For Loop ===
 * sum = 500000500000
 * Time: ~25ms
 *
 * All three produce identical assembly with -O2!
 *
 * === Readability ===
 * Index-based:   ★★★☆☆
 * Manual iterator: ★★☆☆☆ (verbose)
 * Range-based for: ★★★★★ (clean, expressive)
 *
 * Performance: identical — choose range-based for!
 * ```
 */

int main() {}
