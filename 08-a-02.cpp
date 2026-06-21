/*
 * ## EXERCISE 2: Matrix Libraries — Dense Linear Algebra [8.a.i]
 *
 * **Requirements:**
 * 1. Implement a covariance matrix estimator:
 *    given an `N x M` matrix of returns (N assets, M observations),
 *    compute the sample covariance matrix `Sigma = (R - mean) * (R - mean)^T / (M-1)`
 * 2. Decompose `Sigma` with Cholesky (`llt()`) — use the factor `L` to draw
 *    correlated Gaussian samples
 * 3. Compute the condition number of `Sigma` (ratio of largest to smallest eigenvalue)
 * 4. Show that an ill-conditioned covariance (near-singular) causes numerical issues
 *    and apply Tikhonov regularisation: `Sigma_reg = Sigma + lambda * I`
 * 5. Benchmark: 100x100 Cholesky vs LU decomposition (1000 repetitions)
 *
 * **Expected output:**
 * ```
 * === Covariance Matrix ===
 * 5 assets, 252 observations
 * Cholesky factor L: (lower triangular)
 * Condition number: 12.4
 * Regularised (lambda=1e-6): condition number 11.9
 *
 * === Benchmark (100x100, 1000 reps) ===
 * Cholesky: 8ms
 * LU:       12ms
 * Cholesky 1.5x faster for SPD matrices
 * ```
 */

int main() {}
