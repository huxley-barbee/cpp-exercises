/*
 * ## EXERCISE 22: Monte Carlo — Variance Reduction for Exotics [8.d.i]
 *
 * Apply advanced variance reduction to path-dependent and multi-asset options.
 *
 * **Requirements:**
 * 1. Price an arithmetic Asian call using:
 *    - Plain MC
 *    - Geometric Asian control variate (geometric Asian has a known analytic price)
 *    - Stratified sampling on the final stock price
 *    - Quasi-MC with scrambled Sobol sequences (12 dimensions for monthly steps)
 * 2. Price a basket call (2 assets) using:
 *    - Plain MC
 *    - Geometric basket as control variate
 * 3. Price a down-and-out barrier call using:
 *    - Plain MC (high variance near barrier)
 *    - Brownian bridge interpolation to get exact crossing probabilities
 * 4. For each option, report: price, std error, variance reduction factor, time
 * 5. Combine quasi-MC + control variate — show the combined reduction
 *
 * **Expected output:**
 * ```
 * === Asian Call Variance Reduction (1M paths, K=100, T=1, sigma=0.2) ===
 *
 * Method              Price    Std Err   VR Factor  Time
 * Plain MC            $5.863   0.0117    1.0x       0.8s
 * Geo CV              $5.864   0.0011   112x        0.9s
 * Stratified          $5.862   0.0062    3.6x       1.0s
 * Sobol (12D)         $5.863   0.0019   38.0x       0.7s
 * Sobol + Geo CV      $5.863   0.0004  855x!        0.8s
 *
 * === Barrier Call VR (H=90) ===
 * Plain MC:             $6.263   0.018    1.0x
 * Brownian bridge:      $6.244   0.006    9.0x
 * (BB gives exact crossing prob within each interval)
 * ```
 */

int main() {}
