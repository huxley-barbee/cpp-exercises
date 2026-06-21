/*
 * ## EXERCISE 5: Matrix Libraries — Kronecker Products and Tensor Operations [8.a.i]
 *
 * **Requirements:**
 * 1. Implement `kroneckerProduct(A, B)` manually and verify against Eigen's version
 * 2. Use Kronecker products to build a 2D finite-difference Laplacian:
 *    `L_2D = L_1D ⊗ I + I ⊗ L_1D` (for a 10x10 grid -> 100x100 matrix)
 * 3. Implement matrix-vector products using `Map` to reshape vectors as matrices,
 *    avoiding explicit Kronecker product for large grids
 * 4. Benchmark: explicit Kronecker vs Map-based reshape for N=50 grid
 *
 * **Expected output:**
 * ```
 * === Kronecker Product (2x2) ===
 * A⊗B (4x4):
 *   [ 0  5  0 10]
 *   [ 6  7 12 14]
 *   [ 0 15  0 20]
 *   [18 21 24 28]
 *
 * === 2D Laplacian (10x10 grid -> 100x100) ===
 * Non-zeros: 460   Solve residual: 1.2e-14
 *
 * === Benchmark (50x50 grid) ===
 * Explicit Kronecker: 145ms
 * Map reshape:         12ms   speedup 12x
 * ```
 */

int main() {}
