/*
 * ## EXERCISE 4: Matrix Libraries — SVD and PCA [8.a.i]
 *
 * **Requirements:**
 * 1. Generate a synthetic return matrix: 50 assets, 500 daily returns, with
 *    known factor structure (3 latent factors + idiosyncratic noise)
 * 2. Compute SVD using `JacobiSVD` with `ComputeThinU` and `ComputeThinV`
 * 3. Compute proportion of variance explained by each singular value
 * 4. Truncate to 3 principal components and reconstruct; measure Frobenius error
 * 5. Use the first PC as a "market factor" — show its correlation with an
 *    equal-weight portfolio
 * 6. Implement a minimum-variance portfolio using the PCA-reduced covariance matrix
 *
 * **Expected output:**
 * ```
 * === PCA on Return Matrix (50 assets, 500 obs) ===
 * Singular values (top 5): [42.1, 18.3, 12.7, 3.1, 2.9]
 *
 * Variance explained:
 *   PC1: 52.3%   PC2: 22.1%   PC3: 10.6%
 *   Top 3: 85.0%
 *
 * Reconstruction error (3 PCs): ||R - R_hat||_F = 4.21
 * PC1 correlation with EW portfolio: 0.94
 * Min-variance portfolio vol: 8.2% annualised
 * ```
 */

int main() {}
