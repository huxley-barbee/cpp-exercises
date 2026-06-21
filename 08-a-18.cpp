/*
 * ## EXERCISE 18: RNGs — Variance Reduction Techniques [8.a.iv]
 *
 * **Requirements:**
 * 1. Price a European call using plain MC, then apply:
 *    - Antithetic variates: pair each path `Z` with `-Z`
 *    - Control variates: use the underlying as a control
 *    - Importance sampling: shift mean toward the money
 *    - Stratified sampling: divide [0,1] into equal strata
 * 2. For each method report: price estimate, standard error, variance reduction factor
 * 3. Combine antithetic + control variates
 * 4. Apply importance sampling to price a deep OTM call (K=150) where plain MC is noisy
 * 5. Implement moment matching: scale paths so sample mean and variance match theory
 *
 * **Expected output:**
 * ```
 * === Variance Reduction (European Call, 100K paths) ===
 * Method            Price   Std Err  VR Factor
 * Plain MC          10.443  0.033     1.0x
 * Antithetic        10.450  0.017     3.8x
 * Control variate   10.451  0.008    17.0x
 * Stratified        10.449  0.012     7.6x
 * Antithetic+CV     10.451  0.006    30.2x
 *
 * === Deep OTM Call (K=150, analytic=$0.0422) ===
 * Plain MC: $0.039 +/- 0.018  (45% relative error)
 * IS shift: $0.042 +/- 0.001  (2.4% relative error, VR=324x)
 * ```
 */

int main() {}
