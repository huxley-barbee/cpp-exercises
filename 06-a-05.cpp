/*
 * ## EXERCISE 5: Reader-Writer Locks — `std::shared_mutex` [6.a.ii]
 *
 * **Requirements:**
 * 1. Model a **price table**: `std::unordered_map<std::string, double>` shared between
 *    multiple reader threads (subscribers) and one writer thread (market-data feed)
 * 2. Version A: protect with `std::mutex` — all readers serialise
 * 3. Version B: protect with `std::shared_mutex`:
 *    - Readers use `std::shared_lock<std::shared_mutex>` (concurrent reads allowed)
 *    - Writers use `std::unique_lock<std::shared_mutex>` (exclusive write)
 * 4. Benchmark: 8 reader threads + 1 writer thread, 100K read operations each
 * 5. Show that with a regular mutex, readers queue behind each other unnecessarily
 * 6. Measure and display the speedup from `shared_mutex`
 * 7. Discuss the write-starvation risk: if readers never stop, writers wait forever —
 *    show this scenario and how to mitigate with a write-priority flag
 *
 * **Expected output:**
 * ```
 * === Price Table Benchmark ===
 * 8 readers + 1 writer, 100K reads per reader
 *
 * std::mutex (exclusive):       680ms   reads serialised
 * std::shared_mutex (shared):   145ms   readers concurrent
 *
 * Speedup: 4.7x
 *
 * === shared_lock / unique_lock usage ===
 * Reader: shared_lock lk(sm)   -> concurrent with other readers
 * Writer: unique_lock lk(sm)   -> exclusive, blocks all readers
 *
 * === Write Starvation Demo ===
 * Continuous readers: writer waits 850ms to acquire write lock
 * Fix: use a write-pending flag
 *   if (write_pending) { reader backs off }
 *   -> writer acquires within 5ms
 * ```
 */

int main() {}
