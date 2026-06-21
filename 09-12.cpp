/*
 * ## EXERCISE 12: ZeroMQ — Request/Reply and Pipeline Patterns [9.g]
 *
 * Beyond pub/sub, ZeroMQ's REQ/REP and PUSH/PULL patterns are used for
 * RPC-style interfaces and work distribution in trading systems.
 *
 * **Requirements:**
 * 1. Implement a **VaR calculation service** using REQ/REP:
 *    - Client sends: `{portfolio_id, confidence, horizon_days}` (binary)
 *    - Server responds: `{var, cvar, timestamp}` (binary)
 *    - Use `zmq::socket_t` C++ binding (`zmq.hpp`)
 * 2. Implement a **non-blocking REQ/REP** using `DONTWAIT` and poll:
 *    - Client sends multiple requests without waiting
 *    - Uses `zmq_poll` to detect when a reply is ready
 * 3. Implement a **parallel risk engine** using PUSH/PULL:
 *    - Risk manager pushes scenario batches to workers
 *    - N worker threads each pull and price a batch
 *    - Results collected by a PULL socket on the risk manager
 * 4. Show message serialisation: binary struct layout with fixed-size fields
 * 5. Measure: REQ/REP round-trip latency; PUSH/PULL throughput
 * 6. Show graceful shutdown: `LINGER=0` socket close without blocking
 *
 * **Expected output:**
 * ```
 * === VaR Service (REQ/REP) ===
 * Client request: {portfolio_id="SPX_BOOK", confidence=0.99, horizon=1}
 * Server reply:   {var=1234567.0, cvar=1654321.0, ts=1705312345123456789}
 *
 * REQ/REP round-trip: p50=42µs  p99=95µs  (localhost)
 *
 * === Non-blocking REQ/REP ===
 * Sent 10 requests, processing...
 * Replies received via zmq_poll: 10/10  PASS
 *
 * === Parallel Risk (PUSH/PULL, 4 workers) ===
 * Pushed 1000 scenario batches (250 per worker)
 * All workers completed, results collected: 1000/1000  PASS
 * Throughput: 24,500 scenarios/sec
 *
 * Shutdown with LINGER=0: immediate close, no blocking  PASS
 * ```
 */

int main() {}
