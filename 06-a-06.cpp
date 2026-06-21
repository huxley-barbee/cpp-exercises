/*
 * ## EXERCISE 6: Reader-Writer Locks — Upgrade Patterns [6.a.ii]
 *
 * Sometimes a thread reads, then conditionally writes — requiring an upgrade from shared
 * to exclusive ownership. `std::shared_mutex` does not support atomic upgrade;
 * this exercise shows the correct patterns.
 *
 * **Requirements:**
 * 1. Show the **non-atomic upgrade pattern**: release shared lock, acquire unique lock,
 *    re-validate condition (state may have changed between the two locks)
 * 2. Write a `LookupOrInsert` function for a `std::map` that uses this pattern:
 *    check under shared lock; if missing, release and re-acquire exclusive, then insert
 * 3. Show the double-checked locking pattern with shared_mutex
 * 4. Implement a `ReadMostlyCache<K,V>` class that wraps `shared_mutex` and provides
 *    a clean `get(key)` / `put(key, value)` interface
 * 5. Benchmark `ReadMostlyCache` under 95% read / 5% write workload
 * 6. Compare with `std::mutex`-protected `std::unordered_map`
 *
 * **Expected output:**
 * ```
 * === Non-Atomic Upgrade ===
 * lookup("AAPL"): shared_lock -> not found -> release
 *                 unique_lock -> re-check -> still missing -> insert
 * lookup("AAPL"): shared_lock -> found: $150.25
 *
 * === Double-Checked Locking ===
 * 1. shared_lock: check cache
 * 2. if missing: release, unique_lock, re-check, insert
 * Re-check is essential: another thread may have inserted between steps 1 and 2
 *
 * === ReadMostlyCache Benchmark (1M ops, 95% read) ===
 * std::mutex wrapper:     520ms
 * ReadMostlyCache:        135ms
 * Speedup: 3.9x
 *
 * === ReadMostlyCache interface ===
 * cache.put("AAPL", 150.25)
 * cache.get("AAPL") -> 150.25
 * cache.get("MSFT") -> std::nullopt
 * ```
 */

int main() {}
