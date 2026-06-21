/*
 * ## EXERCISE 13: Market Data Dispatch — Ring Buffer and Lock-Free Dispatch [8.b.iii]
 *
 * Market data must flow from network to pricing with minimal latency.
 * Implement a lock-free dispatch path.
 *
 * **Requirements:**
 * 1. Implement a **SPSC ring buffer** for ticks (from section 5.b, now applied
 *    to market data):
 *    - Capacity = power of 2 (e.g., 65536 slots)
 *    - Producer: network thread writes ticks
 *    - Consumer: pricing thread reads ticks
 *    - No mutex — use `std::atomic` with `release`/`acquire` ordering
 * 2. Implement a **MPSC (multi-producer, single-consumer) ring buffer** for
 *    multi-venue feeds converging to one normalisation thread
 * 3. Implement a **fan-out dispatcher**: one market data source, multiple
 *    downstream consumers (risk engine, pricing engine, logger)
 *    using a single producer, multiple SPSC buffers
 * 4. Measure end-to-end latency: time from tick write to tick read
 * 5. Show the **back-pressure mechanism**: if a consumer falls behind,
 *    the buffer fills; implement a drop-oldest policy with a counter
 * 6. Benchmark: throughput comparison — lock-free vs mutex-based queue
 *
 * **Expected output:**
 * ```
 * === Lock-Free Market Data Dispatch ===
 *
 * SPSC ring buffer (capacity=65536 ticks):
 *   Throughput:    48M ticks/sec
 *   Latency p50:   85ns
 *   Latency p99:   142ns
 *   Latency p99.9: 380ns
 *
 * MPSC (4 venues -> 1 normaliser):
 *   Throughput:    39M ticks/sec  (4 producers combined)
 *
 * Fan-out (1 source -> 4 consumers):
 *   Throughput:    41M ticks/sec  (per consumer)
 *
 * Mutex-based queue:
 *   Throughput:    3.2M ticks/sec  (15x slower than SPSC)
 *
 * Back-pressure: buffer full -> 0 drops in 10s at 40M/sec load
 * ```
 */

int main() {}
