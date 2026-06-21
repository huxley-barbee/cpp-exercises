/*
 * ## EXERCISE 4: Market Data Handlers — Statistics and Monitoring [8.c.i]
 *
 * Every production feed handler must publish its own health metrics so
 * operations teams can detect problems without reading source code.
 *
 * **Requirements:**
 * 1. Implement a `FeedStats` struct using only atomic integers:
 *    ```cpp
 *    struct FeedStats {
 *        std::atomic<uint64_t> messages_received;
 *        std::atomic<uint64_t> messages_rejected;
 *        std::atomic<uint64_t> sequence_gaps;
 *        std::atomic<uint64_t> bytes_received;
 *        std::atomic<int64_t>  last_rx_timestamp_ns;
 *        std::atomic<int64_t>  max_gap_ns;     // max inter-message gap
 *        std::atomic<int64_t>  latency_p99_ns; // approximate
 *    };
 *    ```
 * 2. Implement a **running percentile estimator** (P-Square algorithm or
 *    simple reservoir sampling) for latency without storing all samples
 * 3. Implement a **rate counter**: messages per second, computed as a
 *    rolling 1-second window using a circular buffer of per-tick timestamps
 * 4. Implement a **watchdog**: if `last_rx_timestamp_ns` is more than 5 seconds
 *    old, fire a `StaleDataAlert`
 * 5. Publish stats via a `/stats` endpoint (simulated: print to stdout every second)
 * 6. Show the stats output for a 10-second simulated run
 *
 * **Expected output:**
 * ```
 * === Feed Handler Stats (10 second run) ===
 *
 * t=1s:  msg/sec=12,345  bytes/sec=1.8MB  gaps=0  rejected=2  latency_p99=145ns
 * t=2s:  msg/sec=12,180  bytes/sec=1.8MB  gaps=0  rejected=1  latency_p99=138ns
 * t=3s:  msg/sec=11,950  bytes/sec=1.7MB  gaps=1  rejected=3  latency_p99=162ns
 * ...
 * t=10s: msg/sec=12,210  bytes/sec=1.8MB  gaps=1  rejected=18 latency_p99=148ns
 *
 * Summary:
 *   Total messages:    122,340
 *   Total gaps:              1
 *   Max inter-msg gap: 2,840µs  (at t=3.241s)
 *   Availability:         99.9992%
 *   Watchdog: no stale data alerts
 * ```
 */

int main() {}
