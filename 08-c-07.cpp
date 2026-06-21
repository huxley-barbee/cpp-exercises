/*
 * ## EXERCISE 7: Order Gateways — Rate Limiting and Throttling [8.c.ii]
 *
 * Exchanges impose strict message rate limits. Exceeding them results in
 * disconnection. Implement a correct, low-latency throttle.
 *
 * **Requirements:**
 * 1. Implement a **token bucket throttle**:
 *    - `max_rate`: maximum messages per second
 *    - `burst`: maximum instantaneous burst
 *    - `tryConsume(n)`: returns true if `n` tokens available, atomically deducts
 *    - Use `std::atomic<int64_t>` for token count and last-refill timestamp
 *    - No mutex — all operations must be lock-free
 * 2. Implement a **sliding window counter**:
 *    - Track message timestamps in a circular buffer
 *    - `count(window_ms)`: count messages in the last `window_ms` milliseconds
 * 3. Implement a **rate limiter** that combines both: token bucket for burst,
 *    sliding window for sustained rate
 * 4. Show the throttle in action: send 1000 messages with a 100/sec limit —
 *    the throttle paces them correctly
 * 5. Benchmark: `tryConsume` latency (target < 50ns)
 * 6. Show the fail-open vs fail-closed policy: what happens when the exchange
 *    connection drops while messages are queued
 *
 * **Expected output:**
 * ```
 * === Token Bucket Throttle ===
 * Config: 100 msg/sec, burst=20
 *
 * t=0ms:   20 messages sent immediately (burst consumed)
 * t=10ms:  1 message sent (1 token refilled at 100/sec)
 * t=100ms: 10 messages sent (10 tokens refilled)
 * t=200ms: 10 messages sent
 *
 * Total in 1 second: 100 messages  CORRECT
 *
 * tryConsume latency: 18ns  PASS (<50ns target)
 *
 * Fail-closed: queue drains when connection is lost
 *   Queued: 45 messages  Drained: 45  Sent: 0  PASS
 * ```
 */

int main() {}
