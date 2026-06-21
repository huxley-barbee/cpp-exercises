/*
 * ## EXERCISE 9: Memory Ordering — The Six Orderings [6.a.iv]
 *
 * **Requirements:**
 * 1. Write a **message-passing** litmus test with `relaxed` stores and loads:
 *    `data=42; flag.store(1, relaxed)` / `while(!flag.load(relaxed)); assert(data==42)`
 *    — show it can fail (data not visible) and explain why
 * 2. Fix with `release`/`acquire` and prove correctness
 * 3. Write a **store-buffer** litmus test (Dekker): two threads each write then read
 *    the other's variable — show `relaxed` allows both reads to see 0 simultaneously,
 *    which `seq_cst` prevents
 * 4. Demonstrate `memory_order_consume` (data-dependency ordering) with a pointer publish
 * 5. Show `std::atomic_thread_fence` as a standalone barrier
 * 6. Write a table showing: ordering, cost, use case, guarantee
 * 7. Demonstrate the trading-system pattern: publish price with `release`,
 *    subscribe with `acquire` — prove the price is always fully written before read
 *
 * **Expected output:**
 * ```
 * === Message Passing (broken with relaxed) ===
 * Ran 1M iterations
 * Failures (data != 42): 3421  <- relaxed allows reordering
 *
 * === Message Passing (fixed with release/acquire) ===
 * Ran 1M iterations
 * Failures: 0  CORRECT
 *
 * === Store Buffer (Dekker) with seq_cst ===
 * Ran 1M iterations
 * Both reads zero: 0  (seq_cst prevents this anomaly)
 *
 * === Memory Ordering Table ===
 * relaxed:   no sync   use: counters, stats
 * consume:   dep-chain use: pointer publish (avoid — broken on some arches)
 * acquire:   load-side use: lock acquisition
 * release:   store-side use: lock release, data publish
 * acq_rel:   both     use: RMW on shared state
 * seq_cst:   total    use: when you need global order (expensive)
 *
 * === Trading Pattern: Price Publish ===
 * Writer: price.store(150.25, release)
 * Reader: double p = price.load(acquire)
 *         assert(p == 150.25 or later value)  PASS always
 * ```
 */

int main() {}
