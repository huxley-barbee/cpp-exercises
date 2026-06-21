/*
 * ## EXERCISE 2: Market Data Handlers — Order Book Maintenance [8.c.i]
 *
 * The order book is the core in-memory data structure updated on every market
 * data message. It must be updated in nanoseconds.
 *
 * **Requirements:**
 * 1. Implement a **price-level order book** using two sorted fixed-size arrays:
 *    - `PriceLevel bids_[MAX_LEVELS]` and `PriceLevel asks_[MAX_LEVELS]`
 *    - `PriceLevel` = `{int64_t price; int32_t qty; uint32_t count}`
 *    - `MAX_LEVELS = 10` (top-10 book; sufficient for most use cases)
 *    - Arrays kept sorted: bids descending, asks ascending
 * 2. Implement `addOrder(side, price, qty)`, `deleteOrder(side, price, qty)`,
 *    `modifyOrder(side, old_price, new_price, old_qty, new_qty)`
 * 3. Implement `bestBid()`, `bestAsk()`, `midPrice()`, `spread()` — all O(1)
 * 4. Implement `O(N)` insertion maintaining sort order
 * 5. Test with a realistic sequence of 1M add/delete/modify messages
 * 6. Benchmark: order book update latency (target < 100ns per update)
 * 7. Show the **memory layout**: entire top-10 book fits in 3 cache lines
 * 8. Implement a `BookSnapshot` that copies the current state atomically for
 *    a risk engine reader (using a seqlock)
 *
 * **Expected output:**
 * ```
 * === Price-Level Order Book ===
 * Memory: bids_[10] + asks_[10] = 240 bytes (< 4 cache lines)
 *
 * After 1M add/delete/modify:
 *   Best bid: $150.25 (qty=500, count=3)
 *   Best ask: $150.26 (qty=300, count=2)
 *   Spread:   $0.01
 *   Mid:      $150.255
 *
 * Update benchmark (1M operations):
 *   addOrder:    42ns avg
 *   deleteOrder: 38ns avg
 *   modifyOrder: 61ns avg  (delete + insert)
 *
 * BookSnapshot (seqlock read, no mutex):
 *   Read time: 28ns  Version consistent: PASS
 * ```
 */

int main() {}
