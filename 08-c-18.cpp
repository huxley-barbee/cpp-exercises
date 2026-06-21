/*
 * ## EXERCISE 18: Low-Latency Logging — Async Logger Thread [8.c.v]
 *
 * The logger thread must drain the log queue fast enough that the producer
 * (trading thread) never blocks.
 *
 * **Requirements:**
 * 1. Implement `LoggerThread`:
 *    - Owns an `SPSCQueue<LogEntry, 65536>` (8MB)
 *    - Wakes up when entries are available (spinning for < 100µs, then
 *      sleeping with `futex_wait` to save CPU)
 *    - Batches writes: accumulate up to 64 entries, then `writev` to disk
 *    - Uses `O_DIRECT | O_SYNC` for durability (or `fsync` periodically)
 * 2. Implement a **backpressure indicator**: if the queue is > 80% full,
 *    set a flag that the trading thread can check
 * 3. Implement **queue overflow handling**: if the queue is full, the
 *    trading thread drops the log entry (never blocks) and increments
 *    a `dropped_count` counter
 * 4. Show the throughput: messages per second the logger thread can sustain
 * 5. Implement **log flushing on shutdown**: drain the queue completely
 *    before exiting
 * 6. Measure: worst-case latency of the trading thread's `log()` call
 *    when the logger thread is busy writing to disk
 *
 * **Expected output:**
 * ```
 * === Logger Thread Performance ===
 *
 * Queue: 65536 entries, 8MB
 * Batch size: 64 entries per writev call
 *
 * Logger throughput: 4.2M entries/sec
 *   (writev batch: 64 * 128 bytes = 8KB per syscall)
 *
 * Trading thread log() latency:
 *   p50:  28ns  (queue enqueue only)
 *   p99:  48ns
 *   p99.9: 65ns
 *   max:   82ns  (never blocks — drop policy)
 *
 * Backpressure: queue at 85% -> flag set, 0 drops in test
 * Overflow: queue full -> entry dropped, dropped_count=0 in test
 *
 * Shutdown drain: 4,821 queued entries flushed in 1.1ms  PASS
 * ```
 */

int main() {}
