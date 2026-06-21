/*
 * ## EXERCISE 2: Black-Scholes — Vectorised Implementation [8.d.ii]
 *
 * A production pricer must evaluate thousands of options per millisecond.
 * Vectorise the BS formula using Eigen and compiler intrinsics.
 *
 * **Requirements:**
 * 1. Implement a scalar `bsCall` baseline
 * 2. Implement `bsCallVec(S_vec, K_vec, T_vec, sigma_vec, r, q)` using `Eigen::ArrayXd`
 *    — all arithmetic becomes element-wise, no explicit loop
 * 3. Implement a manual SIMD version using `__m256d` (AVX, 4 doubles at once)
 *    — process the strike array in batches of 4
 * 4. Benchmark all three: 100,000 option evaluations
 * 5. Show the throughput: options/second for each version
 * 6. Verify all three produce identical results (max absolute difference < 1e-12)
 * 7. Discuss: when does SIMD win over Eigen, and when does Eigen win?
 *
 * **Expected output:**
 * ```
 * === Vectorised Black-Scholes (100K options) ===
 *
 * Version         Time    Throughput         vs Scalar
 * Scalar          12.4ms  8.1M ops/sec       1.0x
 * Eigen ArrayXd    3.8ms  26.3M ops/sec      3.2x
 * AVX (__m256d)    2.1ms  47.6M ops/sec      5.9x
 *
 * Max error vs scalar: Eigen=1.4e-15  AVX=1.1e-15  (machine precision)
 *
 * Throughput gate: normCDF (erfc) is the bottleneck — 60% of time.
 * Polynomial approximation of N(x) can give additional 2x speedup.
 * ```
 */

int main() {}
