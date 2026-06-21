/*
 * ## EXERCISE 17: RNGs — Quasi-Random (Low-Discrepancy) Sequences [8.a.iv]
 *
 * **Requirements:**
 * 1. Implement a Sobol sequence generator for dimensions 1-8 (or use an existing one)
 * 2. Compare Sobol to pseudo-random MC for integrating `exp(-||x||^2/2)` in 4D
 *    (exact answer: `(2*pi)^2 = 39.478`)
 * 3. Show convergence rates: pseudo-MC at `N^{-0.5}`, quasi-MC much faster
 * 4. Apply quasi-MC to price an arithmetic Asian option
 * 5. Implement scrambled Sobol for unbiased estimation
 * 6. Show the star discrepancy of pseudo vs quasi sequences in 2D visually
 *
 * **Expected output:**
 * ```
 * === Quasi-MC vs Pseudo-MC (4D integral, true=39.4784) ===
 * N=1000:   Pseudo: error=0.27   Sobol: error=0.01  (20x better)
 * N=10000:  Pseudo: error=0.01   Sobol: error=0.001 (10x better)
 *
 * === Asian Option (1M paths) ===
 * Pseudo-MC: $7.823 +/- 0.042
 * Sobol:     $7.821 +/- 0.008  (5x lower std error)
 * ```
 */

int main() {}
