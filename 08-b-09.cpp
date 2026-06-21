/*
 * ## EXERCISE 9: Pricing Engines — Parallel Pricing [8.b.ii]
 *
 * A book of 10,000 positions must be re-priced in under 100ms for end-of-day.
 * Implement a parallel pricing engine.
 *
 * **Requirements:**
 * 1. Implement `ParallelPricingEngine` wrapping a thread pool (from section 6.b):
 *    - `submitBatch(requests) -> vector<future<PricingResult>>`
 *    - Configurable number of worker threads
 *    - Per-thread market data snapshot (avoid contention)
 * 2. Implement **work partitioning**: group instruments by type so each thread
 *    gets a balanced mix (avoid all slow MC jobs going to one thread)
 * 3. Implement **priority pricing**: option positions priced before bond positions
 * 4. Show scaling: price 10,000 instruments on 1, 2, 4, 8 threads
 * 5. Handle exceptions: if one instrument fails to price, the rest continue;
 *    report failures at the end
 * 6. Implement a **pricing run** with timing: start → distribute → collect → aggregate
 *
 * **Expected output:**
 * ```
 * === Parallel Pricing Engine ===
 * Book: 10,000 positions
 *   8,000 vanilla options (BS, ~0.02ms each)
 *   1,500 American options (Binomial, ~1.2ms each)
 *     500 exotics (MC, ~40ms each)
 *
 * Threads  Time    Speedup  Efficiency
 * 1        28.4s   1.0x     100%
 * 2        14.3s   2.0x      99%
 * 4         7.2s   3.9x      98%
 * 8         3.7s   7.7x      96%
 *
 * Failures: 0 / 10,000
 * Pricing run breakdown:
 *   Distribution:  2ms
 *   Execution:  3,695ms
 *   Collection:    5ms
 *   Total:       3,702ms
 * ```
 */

int main() {}
