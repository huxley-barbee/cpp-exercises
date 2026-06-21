/*
 * ## EXERCISE 19: Putting It Together — Low-Latency Tick Processing [8.c.i–iv]
 *
 * Combine market data handling, timestamping, and logging into a single
 * measurable tick-processing pipeline.
 *
 * **Requirements:**
 * 1. Implement the full path from raw byte receipt to downstream publish:
 *    ```
 *    [UDP socket recv] -> [PacketBuffer pool] -> [ITCH parser]
 *    -> [OrderBook update] -> [NBBO compute] -> [Timestamp]
 *    -> [Binary log entry] -> [SPSC to pricing engine]
 *    ```
 * 2. Pre-allocate **all** data structures at startup — zero heap allocation
 *    during processing
 * 3. Use **CPU affinity** (`pthread_setaffinity_np`) to pin the receive thread
 *    to core 2 and the processing thread to core 3
 * 4. Use **SCHED_FIFO** with priority 50 for the hot path threads
 * 5. Measure the end-to-end latency from `recvmsg()` return to SPSC push
 * 6. Show a latency histogram (8 buckets: <50ns, <100ns, <200ns, ..., >1ms)
 * 7. Profile: where is the time spent? (parse vs book update vs timestamp vs log)
 *
 * **Expected output:**
 * ```
 * === Tick Processing Pipeline ===
 *
 * Pre-allocated:
 *   PacketBuffer pool:  256 * 1536 bytes = 384KB
 *   OrderBooks:         500 symbols * 240 bytes = 120KB
 *   Log queue:          65536 * 128 bytes = 8MB
 *   Total pre-alloc:    ~8.5MB  heap allocs during processing: 0
 *
 * CPU affinity: recv=core2  process=core3  logger=core4
 * Thread priority: SCHED_FIFO priority=50
 *
 * === Latency histogram (1M ticks) ===
 *   < 50ns:  12.4%
 *   < 100ns: 52.1%
 *   < 200ns: 28.3%
 *   < 500ns:  6.8%
 *   <   1µs:  0.3%
 *   >   1µs:  0.1%  (OS jitter)
 *
 * p50=88ns  p99=342ns  p99.9=780ns
 *
 * Time budget breakdown:
 *   recvmsg:        18ns
 *   ITCH parse:     12ns
 *   OrderBook upd:  42ns
 *   Timestamp:       9ns
 *   Binary log:     16ns
 *   SPSC push:      15ns
 *   Total:         112ns median
 * ```
 */

int main() {}
