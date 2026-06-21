/*
 * ## EXERCISE 7: Profilers — `perf` and `gprof` [7.b.iii]
 *
 * Find the hot path in a pricing loop using Linux `perf` and the traditional `gprof`.
 *
 * **Requirements:**
 *
 * Write `profile_target.cpp` — a realistic but intentionally slow pricing loop:
 * ```cpp
 * // Three functions with different costs
 * double slow_bs(double S, double K, double T, double sigma, double r);
 * double fast_bs(double S, double K, double T, double sigma, double r);
 * double log_result(double price, int id);  // unnecessary string formatting
 *
 * int main() {
 *     for (int i = 0; i < 1000000; ++i) {
 *         double p1 = slow_bs(100, 100, 1, 0.2, 0.05);
 *         double p2 = fast_bs(100, 100, 1, 0.2, 0.05);
 *         double logged = log_result(p1 + p2, i);
 *     }
 * }
 * ```
 *
 * 1. Profile with `gprof`:
 *    - Compile: `g++ -pg -O2 profile_target.cpp -o profile_target`
 *    - Run to produce `gmon.out`
 *    - Analyse: `gprof profile_target gmon.out | head -30`
 * 2. Profile with `perf`:
 *    - `perf record -g ./profile_target`
 *    - `perf report --stdio | head -40`
 * 3. Profile with `perf stat` for hardware counters
 * 4. Identify the hot function and the cache miss rate
 * 5. Fix: replace `slow_bs` with `fast_bs`, remove `log_result` from hot path
 * 6. Show the before/after speedup
 *
 * **Expected output:**
 * ```
 * === gprof flat profile ===
 * %   cumul.  self    calls  name
 * 68.3  4.23s  4.23s  1000000  slow_bs
 * 21.4  5.55s  1.32s  1000000  log_result
 *  9.1  6.11s  0.56s  1000000  fast_bs
 *  1.2  6.18s  0.07s        1  main
 *
 * === perf report ===
 * # Overhead  Command  Symbol
 *     68.12%  profile  [.] slow_bs
 *     21.38%  profile  [.] log_result
 *      9.02%  profile  [.] fast_bs
 *
 * === perf stat ===
 *   6,124,503,211  instructions
 *     412,803,044  cache-misses      (6.74% of cache refs)
 *
 * === After optimisation ===
 * Before: 6.18s
 * After:  0.58s  speedup 10.7x
 * ```
 */

int main() {}
