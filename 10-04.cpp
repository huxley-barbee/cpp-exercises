/*
 * ## EXERCISE 4: Optimise Loops — Branch Prediction and Algorithmic Improvements [10.b]
 *
 * A market-making algorithm applies per-tick transformations with conditional
 * logic. Eliminate branches and improve the algorithm.
 *
 * **Requirements:**
 * 1. **Branch elimination**: replace `if (price > threshold) adjust(price)`
 *    with a branchless equivalent using multiplication by a 0/1 mask
 * 2. **Loop unrolling**: manually unroll a simple sum-of-prices loop by 4 and
 *    compare to the compiler-unrolled version
 * 3. **Precomputation**: in the Black-Scholes inner loop, precompute
 *    `log(S/K)`, `sqrt(T)`, `sigma*sqrtT` outside the K-loop when
 *    pricing at multiple strikes
 * 4. **SIMD horizontal sum**: implement `hsum_256(__m256d v)` to efficiently
 *    sum 4 doubles in a `__m256d` register
 * 5. Show the speedup for a realistic mid-price smoothing loop applied to
 *    1M ticks with and without these optimisations
 * 6. Profile with `perf record -g` + flame graph to confirm the hot instruction
 *
 * **Expected output:**
 * ```
 * === Branch Elimination ===
 * Branchy version:    850ns for 1000 conditionals (branch mispred: 48%)
 * Branchless version: 210ns for 1000 conditionals (no branch)
 * Speedup: 4.0x
 *
 * === Precomputation (price at 9 strikes, same S/T) ===
 * Without precompute: 9 x log(S/K) + 9 x sqrt(T) = 18 slow ops
 * With precompute:    1 x log(S)   + 1 x sqrt(T) = 2 slow ops
 * Speedup: 6.2x  (9 strikes)
 *
 * === Mid-price smoothing (1M ticks) ===
 * Naive loop with branch: 3.8ms
 * Branchless + SIMD:      0.7ms
 * Speedup: 5.4x
 * ```
 */

int main() {}
