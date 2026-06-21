/*
 * ## EXERCISE 3: Optimise Loops — Vectorisation and Memory Layout [10.b]
 *
 * The inner loop of a risk engine prices 10,000 options every millisecond.
 * Find and fix the performance bottleneck.
 *
 * **Requirements:**
 *
 * The slow version:
 * ```cpp
 * struct Option {
 *     double S, K, T, sigma, r;
 *     double price;        // computed by price()
 * };
 * std::vector<Option> options;   // Array of Structures (AoS)
 *
 * void priceAll(std::vector<Option>& opts) {
 *     for (auto& o : opts)
 *         o.price = blackScholes(o.S, o.K, o.T, o.sigma, o.r);
 * }
 * ```
 *
 * 1. Profile using `perf stat` to confirm cache misses are the bottleneck
 * 2. Convert from **AoS (Array of Structures)** to **SoA (Structure of Arrays)**:
 *    ```cpp
 *    struct OptionBook {
 *        std::vector<double> S, K, T, sigma, r, price;
 *    };
 *    ```
 * 3. Rewrite `priceAll` for the SoA layout
 * 4. Confirm the compiler auto-vectorises with `-O3 -march=native -fopt-info-vec`
 * 5. Add `__builtin_assume_aligned` or `alignas(32)` hints for AVX
 * 6. Manually SIMD-vectorise the inner loop using `__m256d` (4 doubles at once)
 * 7. Benchmark all versions: AoS, SoA, SoA+auto-vec, SoA+AVX
 *
 * **Expected output:**
 * ```
 * === Loop Optimisation ===
 * Options: 10,000   Reps: 1,000
 *
 * Version          Time      Speedup   Notes
 * AoS (baseline)  12.4ms     1.0x     cache miss rate: 6.7%
 * SoA (layout)     8.1ms     1.5x     cache miss rate: 1.2%
 * SoA + auto-vec   3.9ms     3.2x     vectorised by compiler
 * SoA + AVX        2.1ms     5.9x     manual __m256d
 *
 * Vectorisation confirmation:
 *   priceAll:25: note: loop vectorized  (with -fopt-info-vec)
 *
 * perf stat (AoS):
 *   cache-misses: 412,803   (6.7% of refs)
 * perf stat (SoA+AVX):
 *   cache-misses:  48,921   (0.8% of refs)
 * ```
 */

int main() {}
