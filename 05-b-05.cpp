/*
 * ## EXERCISE 5: Cache-Aware Programming — Data Structure Layout [5.b.ii]
 *
 * How you lay out structs determines whether hot fields fit in one cache line or span several.
 *
 * **Requirements:**
 * 1. Define a `OrderBookEntry` with fields: `price (double)`, `qty (int32)`,
 *    `orderId (int64)`, `flags (uint8)`, `symbol (char[8])`, `timestamp (int64)`
 * 2. Version A: fields in declaration order — measure the size and padding
 * 3. Version B: reorder fields to minimise padding (largest alignment first)
 * 4. Version C: split into "hot" fields (price, qty — read every tick) and "cold" fields
 *    (orderId, timestamp, symbol — read only on fill), place hot fields in a separate struct
 * 5. Benchmark: iterate 10M entries summing only `price` — measure cache-line waste
 * 6. Show `offsetof` for each version
 * 7. Demonstrate `__attribute__((packed))` — when it helps and when it hurts (alignment faults)
 * 8. Show the cache-line occupancy calculation: hot fields / cache-line size
 *
 * **Expected output:**
 * ```
 * === OrderBookEntry Layout ===
 *
 * Version A (declaration order):
 *   sizeof: 48 bytes  (12 bytes padding wasted)
 *   offsetof(price):     0
 *   offsetof(qty):       8
 *   offsetof(orderId):  16
 *   offsetof(flags):    24
 *   offsetof(symbol):   25
 *   offsetof(timestamp):40   <- 7 bytes padding before!
 *
 * Version B (sorted by alignment):
 *   sizeof: 40 bytes  (4 bytes padding)
 *   offsetof(timestamp):  0
 *   offsetof(orderId):    8
 *   offsetof(price):     16
 *   offsetof(qty):       24
 *   offsetof(symbol):    28
 *   offsetof(flags):     36
 *
 * Version C (hot/cold split):
 *   HotEntry  sizeof: 16 bytes  (price + qty, 1 cache line per 4 entries)
 *   ColdEntry sizeof: 32 bytes
 *
 * === Benchmark: sum price across 10M entries ===
 * Version A: 42ms   (48 bytes/entry, 1.3 entries per cache line)
 * Version B: 38ms   (40 bytes/entry, 1.6 entries per cache line)
 * Version C: 22ms   (16 bytes/entry, 4 hot entries per cache line)
 * Speedup C vs A: 1.9x
 * ```
 */

int main() {}
