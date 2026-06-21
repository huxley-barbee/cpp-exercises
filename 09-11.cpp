/*
 * ## EXERCISE 11: ZeroMQ — Market Data Distribution [9.g]
 *
 * ZeroMQ provides broker-less, asynchronous messaging patterns used throughout
 * trading infrastructure. This exercise builds a complete market data distribution
 * system.
 *
 * **Requirements:**
 * 1. Implement a **market data publisher** using `ZMQ_PUB`:
 *    - Publishes normalised ticks on `tcp://*:5555`
 *    - Topic = 4-byte symbol (e.g., `"AAPL"`)
 *    - Payload = binary `{bid, ask, bid_sz, ask_sz, seq_no}` (32 bytes)
 *    - Publishes at 50,000 ticks/sec
 * 2. Implement a **subscriber** using `ZMQ_SUB`:
 *    - Filter by symbol using `zmq_setsockopt(ZMQ_SUBSCRIBE, "AAPL", 4)`
 *    - Measure **message latency** (publisher timestamp in payload)
 * 3. Implement a **fan-out** pattern: one publisher, 4 subscribers,
 *    each on a different topic filter; verify message isolation
 * 4. Implement a **proxy** using `zmq_proxy` for scalable fan-out:
 *    `XPUB`→`XSUB` proxy between publisher and many subscribers
 * 5. Measure: publish rate, subscribe receive rate, latency distribution
 *
 * **Expected output:**
 * ```
 * === ZeroMQ PUB/SUB Market Data ===
 *
 * Publisher: 50,000 ticks/sec on tcp://*:5555
 *   Topics: AAPL(40%), MSFT(30%), GOOGL(20%), AMZN(10%)
 *
 * Subscriber (AAPL only):
 *   Received: 20,012 ticks/sec  (40% filter pass rate)
 *   Latency p50:  42µs   p99: 95µs  (localhost)
 *
 * Fan-out (4 subscribers):
 *   AAPL sub: 20,012/sec  MSFT sub: 15,006/sec  PASS
 *   Cross-contamination: 0 wrong-symbol ticks  PASS
 *
 * === Proxy (XPUB/XSUB) ===
 * Added 10 more subscribers via proxy
 * Publisher rate unchanged: 50,000/sec  PASS (decoupled)
 * ```
 */

int main() {}
