/*
 * ## EXERCISE 13: Comprehensive Integration [All of 6.a]
 *
 * Build a **multi-threaded order book** that exercises every concept from section 6.a.
 *
 * **Requirements:**
 *
 * The order book has three concurrent actors:
 * - **Feed handler thread**: receives price updates, writes to a lock-free SPSC queue
 * - **Book thread**: reads from the SPSC queue, maintains bid/ask maps under a
 *   `shared_mutex`, publishes best bid/ask atomically
 * - **Risk thread**: reads best bid/ask continuously under shared lock, computes VaR
 *
 * **Specific requirements:**
 * 1. `Tick` POD struct: `symbol[8]`, `price (double)`, `qty (int32)`, `side (char)`
 * 2. SPSC queue between feed handler and book thread (from Exercise 8)
 * 3. `OrderBook` class:
 *    - `std::map<double, int, std::greater<>>` bids (price descending)
 *    - `std::map<double, int>` asks (price ascending)
 *    - `std::shared_mutex` for book access
 *    - `std::atomic<double>` bestBid, bestAsk (lock-free fast path for risk thread)
 * 4. Feed handler publishes 1M ticks
 * 5. Risk thread reads bestBid/bestAsk 1M times using `acquire` load
 * 6. Measure: total throughput, P99 tick-to-bestBid latency
 * 7. Add a `std::stop_token` to each thread for clean shutdown
 * 8. Conclude with a **synchronisation audit** listing every primitive used and why
 *
 * **Expected output:**
 * ```
 * === Multi-Threaded Order Book ===
 *
 * === Setup ===
 * Feed handler -> SPSC queue -> Book thread
 *                               |-> bestBid (atomic)
 *                               |-> bestAsk (atomic)
 * Risk thread reads bestBid/bestAsk continuously
 *
 * === Run: 1M ticks ===
 * Feed handler: published 1000000 ticks
 * Book thread:  processed 1000000 ticks
 * Risk thread:  read bestBid 1000000 times
 *
 * === Performance ===
 * Total time:         2.1s
 * Feed throughput:    476K ticks/sec
 * Risk reads:         476K reads/sec
 * P99 tick->bestBid:  ~280ns
 *
 * === Synchronisation Audit ===
 * SPSC queue:         std::atomic indices (release/acquire) — feed->book, no lock
 * bestBid/bestAsk:    std::atomic<double> (release store, acquire load) — book->risk
 * Order book maps:    std::shared_mutex — book writes (unique), risk reads (shared)
 * Thread shutdown:    std::stop_token — cooperative cancellation
 * Feed->book sync:    SPSC release/acquire — happens-before guaranteed
 * Book->risk sync:    atomic release/acquire — price always fully written before read
 * ```
 */

int main() {}
