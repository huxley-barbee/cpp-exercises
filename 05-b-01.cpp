/*
 * ## EXERCISE 1: Branch Prediction — Sorted vs Unsorted [5.b.i]
 *
 * The canonical branch-prediction demonstration: summing elements above a threshold in a
 * sorted vs unsorted array.
 *
 * **Requirements:**
 * 1. Allocate an array of 10 million `int`s filled with random values in [0, 255]
 * 2. Measure the time to sum all elements greater than 128 on the **unsorted** array
 * 3. Sort the array, then repeat the measurement
 * 4. Explain why sorted is faster: once the branch crosses the threshold the CPU predicts
 *    "always taken" or "always not taken" — mispredictions fall to near zero
 * 5. Use `perf stat -e branch-misses` (document expected output in a comment)
 * 6. Show the branchless alternative using a conditional move (`cmov`) pattern:
 *    `sum += (val > 128) ? val : 0` vs `sum += val & -(val > 128)`
 * 7. Measure the branchless version — it may beat sorted because it eliminates the branch
 *    entirely at the cost of an extra arithmetic op
 *
 * **Expected output:**
 * ```
 * === Branch Prediction: Sorted vs Unsorted ===
 * Array: 10M random ints in [0,255]
 *
 * Unsorted sum (>128): result=961330150  time=68ms
 *   Branch mispredictions: ~50%  (random data = coin flip)
 *
 * Sorted sum (>128):   result=961330150  time=18ms
 *   Branch mispredictions: ~0%  (CPU learns the pattern)
 *   Speedup: 3.8x
 *
 * Branchless (cmov):   result=961330150  time=14ms
 *   No branch at all — conditional move in one cycle
 *   Speedup vs unsorted: 4.9x
 *
 * Rule: sort data before processing, or use branchless arithmetic
 *       in hot loops with unpredictable conditions.
 * ```
 */

int main() {}
