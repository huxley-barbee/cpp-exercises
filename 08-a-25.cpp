/*
 * ## EXERCISE 25: Parallel Monte Carlo [8.a.iv]
 *
 * **Requirements:**
 * 1. Parallelise the European option MC pricer using `std::thread` / thread pool
 * 2. Each thread has its own `mt19937_64` seeded by `global_seed XOR thread_id`
 * 3. Benchmark: 100M paths on 1, 2, 4, 8 threads — show near-linear scaling
 * 4. Implement a parallel portfolio VaR: 1000 positions, each priced under 10K scenarios
 * 5. Show that parallel Sobol requires scrambling to avoid correlating thread sequences
 * 6. Report parallel efficiency at each thread count
 *
 * **Expected output:**
 * ```
 * === Parallel MC Scaling (100M paths, European Call) ===
 * Threads  Time   Speedup  Efficiency
 * 1        8.2s   1.0x     100%
 * 2        4.2s   2.0x      99%
 * 4        2.1s   3.9x      98%
 * 8        1.1s   7.5x      94%
 *
 * === Parallel Portfolio VaR (1000 pos, 10K scenarios) ===
 * 1 thread:   45s
 * 8 threads:   6.1s   speedup 7.4x
 *
 * Parallel Sobol: each thread uses a scrambled Sobol instance.
 * KS test confirms no correlation between threads' sequences.
 * ```
 */

int main() {}
