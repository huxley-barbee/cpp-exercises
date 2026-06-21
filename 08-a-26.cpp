/*
 * ## EXERCISE 26: Comprehensive Integration [All of 8.a]
 *
 * Build a **complete numerical pricing and risk system** integrating all four
 * topics: matrix libraries (Eigen), PDE solvers, optimisers, and RNGs.
 *
 * **System**: prices and risk-manages a portfolio of 10 vanilla options.
 *
 * **Requirements:**
 *
 * 1. **Data layer**: generate a synthetic Heston vol surface (5 maturities x 7 strikes)
 * 2. **Calibration** (8.a.iii + 8.a.iv):
 *    - DE global search, then LM polish
 *    - Verify calibrated parameters match the true values
 * 3. **Pricing** (8.a.ii + 8.a.iv):
 *    - Price each option with both Crank-Nicolson FD and MC with antithetic variates
 *    - Verify they agree within 3 standard errors of the MC estimate
 * 4. **Greeks** (8.a.ii + 8.a.iii):
 *    - FD Greeks directly from the PDE grid (delta, gamma, theta)
 *    - MC pathwise delta; LR vega
 * 5. **Risk** (8.a.i + 8.a.iv):
 *    - Build portfolio covariance matrix using Cholesky-correlated MC paths
 *    - Compute 1-day 99% VaR using parallel MC (Exercise 25)
 *    - Decompose VaR by risk factor using PCA (Exercise 4)
 * 6. **Report**: print a complete risk report with position-level and portfolio-level
 *    Greeks, VaR, CVaR, and calibration quality metrics
 *
 * **Expected output:**
 * ```
 * === Integrated Pricing and Risk System ===
 *
 * Step 1: Heston surface (5x7 = 35 vol quotes) generated.
 *
 * Step 2: Calibration
 *   DE (200 gen) + LM polish: RMSE=0.03%  time=4.3s
 *   Params: v0=0.0400 kappa=2.000 theta=0.0400 sigma_v=0.300 rho=-0.700
 *
 * Step 3: Pricing (10 options)
 *   Option  K    T     CN-FD   MC(100K)  Diff(sigma)
 *   1      90   0.5  $13.21   $13.19     0.4
 *   2     100   0.5  $ 7.11   $ 7.10     0.2
 *   ...
 *   All within 3 sigma of MC estimate.
 *
 * Step 4: Portfolio Greeks
 *   Delta: +3.82   Gamma: +0.19   Vega: +48.3   Theta: -12.4/day
 *
 * Step 5: Risk
 *   VaR(1d, 99%):  -$4,230
 *   CVaR(1d, 99%): -$5,810
 *   PCA decomposition:
 *     Vol risk (vega):   50%
 *     Spot risk (delta): 43%
 *     Other:              7%
 *
 * System Audit:
 *   Matrix library: Eigen (covariance, Cholesky, regression, SVD)
 *   PDE solver:     Crank-Nicolson + Thomas algorithm
 *   Optimiser:      DE + LM
 *   RNG:            mt19937_64 + antithetic + scrambled Sobol
 *   Parallelism:    8-thread pool (95% efficiency)
 *   Total runtime:  12.3s  (serial equivalent: ~80s)
 * ```
 */

int main() {}
