/*
 * ## EXERCISE 4: Eigen — Linear Algebra for Portfolio Optimisation [9.b]
 *
 * Eigen is the backbone of quantitative portfolio analytics. This exercise
 * covers the operations that appear daily in a risk system.
 *
 * **Requirements:**
 * 1. Build a 5×5 sample covariance matrix from a 5×252 matrix of daily returns
 * 2. Compute the **minimum variance portfolio** weights:
 *    `w = (Sigma^{-1} * 1) / (1^T * Sigma^{-1} * 1)`
 * 3. Compute the **Sharpe-optimal (tangency) portfolio** weights given
 *    excess returns `mu`:
 *    `w = (Sigma^{-1} * mu) / (1^T * Sigma^{-1} * mu)`
 * 4. Verify: `sum(w) = 1` for both portfolios
 * 5. Compute portfolio volatility: `vol = sqrt(w^T * Sigma * w) * sqrt(252)`
 * 6. Compute the **risk contributions** (Euler decomposition):
 *    `RC_i = w_i * (Sigma * w)_i / (w^T * Sigma * w)`
 * 7. Show `Sigma.llt().solve(b)` is faster than `Sigma.inverse() * b`
 *
 * **Expected output:**
 * ```
 * === Portfolio Optimisation (5 assets) ===
 *
 * Covariance matrix (annualised):
 *   [0.0423  0.0187  ...]
 *   ...
 *
 * Minimum variance portfolio:
 *   Weights: [0.121, 0.083, 0.214, 0.312, 0.270]
 *   sum(w) = 1.000  PASS
 *   Portfolio vol: 11.4% annualised
 *
 * Tangency portfolio (rf=3%):
 *   Weights: [0.085, 0.142, 0.231, 0.298, 0.244]
 *   Portfolio vol: 14.2%  Sharpe: 0.71
 *
 * Risk contributions:
 *   Asset 0:  8.3%   Asset 1: 12.1%   Asset 2: 23.4%
 *   Asset 3: 32.1%   Asset 4: 24.1%
 *   Sum: 100%  PASS
 *
 * Cholesky solve vs matrix inverse:
 *   llt().solve(): 0.8ms  (100 reps)
 *   inverse()*b:   2.3ms  (100 reps)
 *   Cholesky 2.9x faster  PASS
 * ```
 */

int main() {}
