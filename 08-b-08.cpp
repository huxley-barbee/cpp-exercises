/*
 * ## EXERCISE 8: Pricing Engines — Caching and Memoisation [8.b.ii]
 *
 * Pricing the same instrument twice with unchanged market data is wasteful.
 * Implement a smart pricing cache.
 *
 * **Requirements:**
 * 1. Implement a `PricingCache` with:
 *    - Key: `(instrument_id, market_data_hash, model_params_hash)`
 *    - Value: `PricingResult` with a timestamp
 *    - Eviction: LRU (Least Recently Used) with a configurable max size
 *    - Thread-safe: concurrent reads, exclusive writes
 * 2. Implement a `market_data_hash()` function using `std::hash` and XOR-folding
 * 3. Implement cache invalidation: when market data changes, invalidate all
 *    entries derived from that data
 * 4. Show the cache hit rate in a realistic workload:
 *    100 instruments, market data updated every 100ms, prices queried every 1ms
 * 5. Implement a **dirty flag** mechanism: mark cached prices as stale when
 *    relevant market data changes, re-price lazily on next query
 * 6. Benchmark: pricing with and without cache for a 100-instrument book
 *
 * **Expected output:**
 * ```
 * === Pricing Cache (LRU, max 500 entries) ===
 *
 * Workload: 100 instruments, data update every 100ms, query every 1ms
 *
 * Cache statistics (10 seconds):
 *   Total queries:   10,000
 *   Cache hits:      9,812  (98.1%)
 *   Cache misses:      188  (1.9%)
 *   Evictions:           0
 *
 * Without cache: 10,000 * 0.42ms = 4,200ms
 * With cache:     188 * 0.42ms + 9,812 * 0.001ms = 89ms
 * Speedup: 47x
 *
 * Dirty flag test:
 *   Market data updated -> 100 entries marked stale
 *   Next query triggers reprice -> cache refreshed
 *   Price correctness: PASS
 * ```
 */

int main() {}
