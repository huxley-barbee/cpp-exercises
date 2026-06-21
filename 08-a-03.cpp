/*
 * ## EXERCISE 3: Matrix Libraries — Sparse Matrices [8.a.i]
 *
 * **Requirements:**
 * 1. Build a sparse tridiagonal matrix `T` (NxN, N=1000) representing a
 *    finite-difference discretisation: `T[i,i]=2, T[i,i+-1]=-1`
 * 2. Use `Eigen::SparseMatrix<double>` with `setFromTriplets()`
 * 3. Solve `Tx = b` using `SimplicialLLT` (sparse Cholesky)
 * 4. Also solve with `SparseLU` and `BiCGSTAB` (iterative)
 * 5. Compare: dense vs sparse storage (memory and solve time) for N=1000 and N=10000
 * 6. Show `T.nonZeros()` vs `T.rows() * T.cols()`
 * 7. Print a small (10x10) version to show the sparsity pattern
 *
 * **Expected output:**
 * ```
 * === Sparse Tridiagonal (N=1000) ===
 * Dense storage:  8.0 MB
 * Sparse storage: 0.024 MB
 * Compression: 333x
 *
 * Solve time (N=1000):
 *   SimplicialLLT: 2ms
 *   SparseLU:      3ms
 *   BiCGSTAB:      5ms
 *
 * Sparsity (10x10):
 *   [ 2 -1  .  .  .  .  .  .  .  .]
 *   [-1  2 -1  .  .  .  .  .  .  .]
 * ```
 */

int main() {}
