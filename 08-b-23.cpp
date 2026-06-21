/*
 * ## EXERCISE 23: Putting It Together — Order Management System [8.b.iv]
 *
 * Build a minimal but complete order management system (OMS) using the
 * event-driven patterns from this module.
 *
 * **Requirements:**
 * 1. **Order Entry**: accept orders via a REQ/REP ZeroMQ socket (Exercise 19)
 * 2. **Risk Pre-Check**: run the risk pipeline from Exercise 17 synchronously
 * 3. **Order Routing**: route to exchange simulator via a PUSH socket
 * 4. **Fill Handling**: receive fills from exchange simulator via a PULL socket;
 *    publish `FillEvent` on the async bus
 * 5. **Position Management**: maintain real-time positions per symbol, updated
 *    on each fill
 * 6. **OMS State Machine**: use the order lifecycle from Exercise 16
 * 7. Show a full round-trip: client sends order → OMS checks risk → routes to
 *    exchange → fill received → position updated → confirmation sent to client
 * 8. Measure round-trip latency from order submission to position update
 *
 * **Expected output:**
 * ```
 * === OMS Round-Trip ===
 *
 * t=0µs:    Client submits BUY 100 AAPL @ $150.25
 * t=1µs:    Risk pre-check: PASS (0.6µs)
 * t=2µs:    Order routed to exchange
 * t=18µs:   Exchange ACK received
 * t=45µs:   Fill: 100 @ $150.24 (price improvement!)
 * t=46µs:   FillEvent published on async bus
 * t=48µs:   Position updated: AAPL +100
 * t=49µs:   Confirmation sent to client
 *
 * Total OMS round-trip: 49µs
 *
 * Throughput: 18,000 orders/sec (single-threaded OMS)
 * Risk check: 0.6µs avg
 * Exchange RTT: 43µs (simulated)
 * ```
 */

int main() {}
