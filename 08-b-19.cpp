/*
 * ## EXERCISE 19: Message Buses — ZeroMQ Patterns [8.b.v]
 *
 * ZeroMQ provides low-latency message passing between system components.
 * Implement the core patterns used in trading systems.
 *
 * **Requirements:**
 * 1. Implement the **PUB/SUB** pattern:
 *    - Publisher: market data server publishing tick updates on `tcp://*:5555`
 *    - Subscriber: pricing engine subscribing to specific symbols
 *    - Show topic filtering: subscriber only receives ticks for `AAPL` and `MSFT`
 * 2. Implement the **PUSH/PULL** (pipeline) pattern:
 *    - Pusher: order router pushing orders to a worker pool
 *    - Pullers: N worker threads pulling and processing orders
 *    - Show load balancing: ZeroMQ distributes round-robin to workers
 * 3. Implement the **REQ/REP** pattern:
 *    - Client: risk system requesting portfolio VaR
 *    - Server: VaR engine computing and replying
 * 4. Implement the **DEALER/ROUTER** pattern for async request/reply:
 *    - Multiple clients, single server, non-blocking
 * 5. Show message serialisation using a simple binary format (no Protobuf dependency)
 * 6. Measure latency: round-trip time for REQ/REP on localhost
 *
 * **Expected output:**
 * ```
 * === ZeroMQ Patterns ===
 *
 * PUB/SUB:
 *   Publisher: pushing 100K ticks/sec on port 5555
 *   Subscriber (AAPL+MSFT filter): receiving 40K ticks/sec
 *   Topic filter latency: 0ns (kernel-level filtering)
 *
 * PUSH/PULL (4 workers):
 *   Push rate: 50K orders/sec
 *   Per-worker: ~12.5K orders/sec (load balanced)
 *
 * REQ/REP:
 *   Request: "VaR for portfolio=SPX_BOOK"
 *   Reply:   "VaR=$1,234,567"
 *   RTT p50:  42µs  p99: 95µs  (localhost)
 *
 * DEALER/ROUTER (async):
 *   10 concurrent requests outstanding
 *   All replies matched to correct client: PASS
 * ```
 */

int main() {}
