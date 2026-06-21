/*
 * ## EXERCISE 10: Market Data Dispatch — Tick Data Structures [8.b.iii]
 *
 * Design efficient in-memory structures for high-frequency market data.
 *
 * **Requirements:**
 * 1. Implement a `Tick` struct with:
 *    - Symbol (8-byte fixed-size char array, no heap allocation)
 *    - Bid/ask price as `int64_t` (fixed-point, 8 decimal places)
 *    - Bid/ask size as `int32_t`
 *    - Exchange timestamp as `int64_t` (nanoseconds since epoch)
 *    - Sequence number as `uint64_t`
 *    - Total size: verify `sizeof(Tick) == 64` (one cache line)
 * 2. Implement a `TopOfBook` struct: best bid and ask for a symbol
 * 3. Implement an `OrderBook` (5 levels deep) as a fixed-size array (no `std::map`)
 * 4. Implement `updateTopOfBook(tick)` — O(1) update
 * 5. Implement `midPrice()`, `spread()`, `weightedMid()` (size-weighted)
 * 6. Show memory layout: print `offsetof` for each field
 * 7. Benchmark: 10M tick updates per second with the fixed-size struct vs
 *    a naive `std::map`-based order book
 *
 * **Expected output:**
 * ```
 * === Tick Structure ===
 * sizeof(Tick) = 64 bytes (one cache line)  PASS
 *
 * Field offsets:
 *   symbol[8]:    offset=0
 *   bid_price:    offset=8
 *   ask_price:    offset=16
 *   bid_size:     offset=24
 *   ask_size:     offset=28
 *   timestamp_ns: offset=32
 *   seq_no:       offset=40
 *   padding[16]:  offset=48
 *
 * === Order Book Update Benchmark ===
 * Fixed-size array (5 levels): 10M updates in  82ms (122M/sec)
 * std::map-based book:          10M updates in 910ms (11M/sec)
 * Speedup: 11x
 *
 * mid=$150.030000  spread=$0.010000  wmid=$150.029523
 * ```
 */

int main() {}
