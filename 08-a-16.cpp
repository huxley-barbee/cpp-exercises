/*
 * ## EXERCISE 16: RNGs — Mersenne Twister and Quality Tests [8.a.iv]
 *
 * **Requirements:**
 * 1. Use `std::mt19937_64` to generate uniform [0,1) and standard normals
 * 2. Implement the Box-Muller transform manually and compare to `std::normal_distribution`
 * 3. Run statistical quality tests on the MT output:
 *    - Chi-squared uniformity test (bin 1M samples into 1000 bins)
 *    - Kolmogorov-Smirnov test for normality
 *    - Lag-1 autocorrelation check
 * 4. Show seed management: same seed -> same sequence
 * 5. Show thread-safe RNG: one `mt19937_64` per thread, seeded distinctly
 *
 * **Expected output:**
 * ```
 * === MT Quality Tests (1M samples) ===
 * Chi-squared (1000 bins): statistic=982.3  p-value=0.66  PASS
 * KS normality test:       D=0.00042         PASS
 * Lag-1 autocorrelation:   0.000041          PASS
 *
 * === Box-Muller vs std::normal_distribution ===
 * Box-Muller:   145ms for 10M samples
 * std::normal:  180ms
 *
 * === Thread-safe RNG ===
 * 4 threads, each mt19937_64 seeded by thread_id XOR global_seed
 * No shared state — lock-free
 * ```
 */

int main() {}
