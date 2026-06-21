/*
 * ## EXERCISE 1: Matrix Libraries — Eigen Basics [8.a.i]
 *
 * **Requirements:**
 * 1. Declare `Matrix3d A`, `Vector3d b` using fixed-size Eigen types
 * 2. Fill `A` with a symmetric positive-definite matrix (e.g., a covariance matrix)
 * 3. Solve `Ax = b` using `colPivHouseholderQr().solve(b)`
 * 4. Verify the solution: print `||Ax - b||` (residual norm)
 * 5. Compute `A`'s eigenvalues using `SelfAdjointEigenSolver`
 * 6. Compute the matrix exponential using `A.exp()` (Eigen unsupported)
 * 7. Print `A.determinant()`, `A.trace()`, `A.inverse()`
 * 8. Show fixed-size vs dynamic (`MatrixXd`) and when to use each
 *
 * **Expected output:**
 * ```
 * === Eigen Basics ===
 * A (3x3 covariance):
 *   [4, 2, 0]
 *   [2, 3, 1]
 *   [0, 1, 2]
 *
 * Ax = b solved:
 *   x = [0.3636, 0.5455, 0.2273]
 *   residual ||Ax-b|| = 0.0000 (machine precision)
 *
 * Eigenvalues: [1.1270, 2.4384, 5.4346]
 * Determinant: 12.0000
 * Trace:        9.0000
 * ```
 */

int main() {}
