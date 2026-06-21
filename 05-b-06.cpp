/*
 * ## EXERCISE 6: Cache-Aware Programming — Cache-Oblivious Algorithms [5.b.ii]
 *
 * Matrix multiplication is the textbook example of cache-blocking. Implement naïve and
 * blocked versions and measure the difference.
 *
 * **Requirements:**
 * 1. Allocate two 512×512 `double` matrices A and B
 * 2. Version A: naïve triple-loop matrix multiply `C[i][j] += A[i][k] * B[k][j]`
 *    (inner loop accesses B column-wise — terrible for cache)
 * 3. Version B: transpose B first, then multiply — B is accessed row-wise
 * 4. Version C: cache-blocked multiply with tile size 32 or 64
 * 5. Measure all three and show the speedup
 * 6. Explain why B's column access causes cache thrashing in version A
 * 7. Show how blocking fits a tile into L1/L2 cache
 * 8. Extend: show the same principle applies to a 2D market-data grid (prices × time)
 *
 * **Expected output:**
 * ```
 * === Matrix Multiply 512x512 doubles ===
 *
 * Version A (naïve, column B access):     3200ms
 * Version B (transpose B, row access):     420ms   speedup 7.6x
 * Version C (cache-blocked, tile=64):      380ms   speedup 8.4x
 *
 * Cache analysis:
 *   Naïve:    B[k][j] stride = 512*8 = 4096 bytes per j-step
 *             Cache miss on every B access (512 >> L1 cache)
 *   Transposed: B_T[j][k] stride = 8 bytes — sequential
 *   Blocked:    tile fits in L1, reuse ratio high
 *
 * Rule: ensure inner loops access memory sequentially.
 *       When not possible, transpose or block the data.
 * ```
 */

int main() {}
