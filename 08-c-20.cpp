/*
 * ## EXERCISE 20: Putting It Together — Order Gateway Under Load [8.c.ii–iv]
 *
 * Test the order gateway at realistic trading volumes and measure the
 * full order round-trip latency.
 *
 * **Requirements:**
 * 1. Implement a **simulated exchange** that:
 *    - Accepts FIX NewOrderSingle messages
 *    - ACKs immediately (with configurable delay: 10-50µs)
 *    - Fills 80% of orders, rejects 20%
 *    - Sends fill messages asynchronously
 * 2. Connect the order gateway to the simulated exchange
 * 3. Send 100,000 orders at 10,000 orders/sec for 10 seconds
 * 4. Measure **round-trip latency** (submit to ACK, submit to fill)
 * 5. Detect and report any **order leaks** (submitted but never ACK'd or rejected)
 * 6. Implement a **kill switch**: if `error_rate > 5%` in the last 100 orders,
 *    cancel all open orders and halt trading
 * 7. Show throughput degradation under high load vs moderate load
 *
 * **Expected output:**
 * ```
 * === Order Gateway Load Test ===
 * Rate: 10,000 orders/sec for 10 seconds
 *
 * Results:
 *   Total submitted:  100,000
 *   ACK'd:             80,000  (80%)
 *   Rejected:          20,000  (20%)
 *   Order leaks:            0  PASS
 *
 * Latency (submit to ACK):
 *   p50: 18µs   p99: 45µs   max: 120µs
 *
 * Latency (submit to fill):
 *   p50: 42µs   p99: 95µs   max: 310µs
 *
 * Throughput at 10K/sec: 100% of orders processed
 * Throughput at 50K/sec: throttle kicks in, 100% at 10K/sec paced
 *
 * Kill switch test:
 *   Injected 10% error rate at t=7s
 *   Kill switch fired at t=7.008s (8ms after threshold)
 *   Open orders cancelled: 12  PASS
 * ```
 */

int main() {}
