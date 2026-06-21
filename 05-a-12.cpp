/*
 * ## EXERCISE 12: CPU Cache Hierarchy — Prefetching and Branch Prediction [5.a.iv]
 *
 * Modern CPUs prefetch data speculatively. Help or hinder the prefetcher to see the effect.
 *
 * **Requirements:**
 * 1. Sequential access: sum an array forwards — prefetcher predicts next access perfectly
 * 2. Stride access: sum every 16th element — stride larger than cache line, prefetcher struggles
 * 3. Random access: shuffle indices first, then gather — worst case for prefetcher
 * 4. Measure all three and show the latency difference
 * 5. Demonstrate `__builtin_prefetch(ptr, 0, 3)` to manually prefetch in a streaming loop
 * 6. Show branch prediction: a loop with a perfectly predictable branch (alternating) vs
 *    random branch — measure the misprediction penalty
 * 7. Use `likely` / `unlikely` hints (`__builtin_expect`) to guide branch prediction in
 *    a hot error-check path
 * 8. State the relevance: order-book tick processing, risk calculation loops
 *
 * **Expected output:**
 * ```
 * === Access Pattern Benchmark (64MB array) ===
 *
 * Pattern          Time      Effective Bandwidth   Notes
 * Sequential       4.2ms     15.2 GB/s             prefetcher works perfectly
 * Stride-16        18.0ms    3.6 GB/s              strides miss prefetcher
 * Random           250ms     0.26 GB/s             one cache miss per access
 *
 * === Manual Prefetch ===
 * Without prefetch: 4.2ms
 * With __builtin_prefetch (16 elements ahead): 3.1ms
 * Speedup: 26%
 *
 * === Branch Prediction ===
 * Predictable branch (always true): 12ms
 * Random branch (50% misprediction): 48ms
 * Misprediction penalty: ~15 cycles per miss
 *
 * === likely / unlikely ===
 * Hot path: if (__builtin_expect(orderValid, 1)) { ... }
 *   -> compiler places valid-order code inline (no branch)
 * Error path: if (__builtin_expect(error, 0)) { ... }
 *   -> compiler moves error handling out-of-line
 *
 * === Trading Relevance ===
 * Tick loop: access price array sequentially — prefetcher helps
 * Risk calc: SoA layout + sequential access = maximum prefetch efficiency
 * Order validation: unlikely(invalid) -> error path out of line
 * ```
 */

int main() {}
