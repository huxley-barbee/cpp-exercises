/*
 * ## EXERCISE 19: RNGs — Stochastic Process Simulation [8.a.iv]
 *
 * **Requirements:**
 * 1. Simulate the Ornstein-Uhlenbeck process using the exact discretisation
 * 2. Simulate CIR (Cox-Ingersoll-Ross) using the non-central chi-squared exact sampler
 * 3. Simulate Heston using the full-truncation scheme with correlated Brownians
 * 4. For each: verify sample mean and variance match the theoretical stationary distribution
 * 5. Implement correlated Brownian motions using Cholesky decomposition
 * 6. Price a CIR zero-coupon bond via simulation and compare to the analytic formula
 *
 * **Expected output:**
 * ```
 * === Ornstein-Uhlenbeck ===
 * Stationary mean: theoretical=0.0500  sample=0.0501  PASS
 * Stationary var:  theoretical=0.0025  sample=0.0024  PASS
 *
 * === CIR ===
 * Feller condition: 2*kappa*theta > sigma^2  PASS
 * Stationary mean: theoretical=0.0400  sample=0.0401  PASS
 *
 * === Heston ===
 * Option price (MC 1M): $10.443   analytic: $10.451
 *
 * === CIR Bond ===
 * Maturity=1Y: analytic=$0.9612   MC=$0.9610   PASS
 * ```
 */

int main() {}
