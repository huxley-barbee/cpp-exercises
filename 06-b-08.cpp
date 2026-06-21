/*
 * ## EXERCISE 8: Thread Pool — Parallel Algorithms [6.b.ii]
 *
 * Use a thread pool to parallelise common quant workloads.
 *
 * **Requirements:**
 * 1. Implement `parallelFor(pool, begin, end, f)` that splits the range into chunks,
 *    submits one task per chunk to the pool, and waits for all to complete
 * 2. Use it to parallelise a Monte Carlo option pricer:
 *    - 1M paths, split into chunks of 10K
 *    - Each chunk simulates paths and returns a partial sum
 *    - Main thread averages the partial sums
 * 3. Implement `parallelTransform(pool, input, output, f)` for Greek calculation
 * 4. Compare serial vs parallel for 1M paths on 4 and 8 threads
 * 5. Show the overhead crossover: parallelFor is slower than serial for < ~1000 work units
 *    due to task-submission overhead
 * 6. Demonstrate `std::reduce` with execution policy as the standard library equivalent
 *
 * **Expected output:**
 * ```
 * === Monte Carlo Option Pricer ===
 * 1M paths, S=100, K=100, T=1, sigma=0.2, r=0.05
 *
 * Serial (1 thread):       3200ms  price=$10.45
 * Parallel (4 threads):     850ms  price=$10.45  speedup 3.8x
 * Parallel (8 threads):     460ms  price=$10.45  speedup 6.9x
 *
 * === parallelFor overhead crossover ===
 * Tasks=10    (trivial work): serial=0.1ms, parallel=2.1ms  <- parallel SLOWER
 * Tasks=100   (light work):   serial=0.8ms, parallel=1.2ms
 * Tasks=1000  (medium work):  serial=8ms,   parallel=3ms    <- parallel wins
 * Tasks=10000 (heavy work):   serial=80ms,  parallel=22ms
 *
 * Crossover: ~500 tasks of this weight
 *
 * === std::reduce (parallel execution policy) ===
 * std::reduce(std::execution::par, prices.begin(), prices.end()):
 *   Result: $1044.52  time: 12ms
 *   (Standard library uses OS thread pool internally)
 * ```
 */

int main() {}
