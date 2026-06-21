/*
 * ## EXERCISE 22: Putting It Together — Timestamping Pipeline [8.c.iv]
 *
 * Build a complete timestamping pipeline that applies hardware timestamps
 * to all events in the trading system.
 *
 * **Requirements:**
 * 1. Implement a `TimestampEngine`:
 *    - Maintains TSC frequency and drift correction
 *    - Provides `tscToUtcNs(tsc)` conversion
 *    - Locks to GPS/PTP reference every 10 seconds
 * 2. Stamp every event in the pipeline with two timestamps:
 *    - `t_exchange`: exchange-generated timestamp (from the FIX `TransactTime` tag)
 *    - `t_received`: local hardware timestamp at packet receipt
 * 3. Compute **exchange-to-local latency**: `t_received - t_exchange`
 *    (requires clock synchronisation to be meaningful)
 * 4. Detect **timestamp anomalies**: events where `t_exchange > t_received`
 *    (impossible — indicates clock sync error)
 * 5. Implement **latency attribution**:
 *    - Network propagation: `t_received - t_sent_by_exchange`
 *    - Processing: `t_processed - t_received`
 *    - Queue: `t_dequeued - t_enqueued`
 * 6. Produce a latency attribution report for 1M events
 *
 * **Expected output:**
 * ```
 * === Timestamping Pipeline (1M events) ===
 *
 * Clock sync: GPS+PTP locked, offset<10ns
 *
 * Latency Attribution:
 *   Network propagation:  p50=8.2µs   p99=12.1µs
 *   Queue wait:           p50=2.1µs   p99=8.4µs
 *   Processing:           p50=0.1µs   p99=0.3µs
 *   Total (recv to done): p50=10.4µs  p99=20.8µs
 *
 * Timestamp anomalies (t_exchange > t_received):
 *   Count: 0  PASS  (clock sync is good)
 *
 * === Latency heatmap (by time of day) ===
 * 09:30-10:00 (open): p99=45µs  (high volume)
 * 10:00-11:00:        p99=21µs
 * 11:00-14:00:        p99=18µs
 * 14:00-16:00:        p99=22µs
 * 15:55-16:00 (close): p99=38µs  (high volume)
 * ```
 */

int main() {}
