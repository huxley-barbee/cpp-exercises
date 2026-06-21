/*
 * ## EXERCISE 12: Putting It Together — Thread-Safe Price Cache [6.a.i–iv]
 *
 * Build a `PriceCache` class that would be production-quality in a market-data system.
 *
 * **Requirements:**
 * 1. Internal storage: `std::unordered_map<std::string, double>`
 * 2. Use `std::shared_mutex` for read-heavy access pattern
 * 3. Provide:
 *    - `void update(const std::string& sym, double price)` — exclusive write
 *    - `std::optional<double> get(const std::string& sym) const` — shared read
 *    - `std::unordered_map<std::string, double> snapshot() const` — copy whole map
 * 4. Add a `std::atomic<uint64_t> updateCount_` (no lock needed — separate from map)
 * 5. Add a `std::atomic<uint64_t> readCount_` similarly
 * 6. Implement a `subscribe(callback)` method that stores a list of callbacks and
 *    calls them under a separate `std::mutex` when prices update (fan-out)
 * 7. Write a test: 1 writer thread (100K updates), 8 reader threads (100K reads each),
 *    2 subscriber callbacks — verify no data races, correct counts, correct callbacks
 *
 * **Expected output:**
 * ```
 * === PriceCache Test ===
 * 1 writer, 8 readers, 2 subscribers
 *
 * Writer: 100K updates
 * Reader threads: 800K total reads
 * Subscriber 1: 100K callbacks
 * Subscriber 2: 100K callbacks
 *
 * === Results ===
 * updateCount: 100000  CORRECT
 * readCount:   800000  CORRECT
 * No data races (verified with TSAN)
 *
 * Throughput:
 *   Writes: 1.8M updates/sec
 *   Reads:  5.2M reads/sec  (shared_mutex — readers concurrent)
 * ```
 */

int main() {}
