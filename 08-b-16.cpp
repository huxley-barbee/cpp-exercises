/*
 * ## EXERCISE 16: Event-Driven Architecture — Order Lifecycle Events [8.b.iv]
 *
 * Model the complete lifecycle of an order as a sequence of events.
 *
 * **Requirements:**
 * 1. Define the order state machine with events:
 *    `NEW -> PENDING_ACK -> ACKNOWLEDGED -> PARTIALLY_FILLED -> FILLED`
 *    `NEW -> PENDING_ACK -> REJECTED`
 *    `ACKNOWLEDGED -> PENDING_CANCEL -> CANCELLED`
 * 2. Implement `OrderStateMachine` that:
 *    - Transitions state on each incoming event
 *    - Throws `InvalidTransition` if an illegal event arrives
 *    - Calls registered callbacks on each transition
 * 3. Implement `OrderBook` (the internal blotter, not the market order book):
 *    - Stores all live orders indexed by `order_id`
 *    - Updates position when fills arrive
 *    - Thread-safe: order updates and fill events come from different threads
 * 4. Publish lifecycle events to the async bus from Exercise 15
 * 5. Implement a **fill reconciliation** check: simulated exchange fills
 *    vs internal fill records — detect any discrepancy
 * 6. Show the full lifecycle of 5 orders: new → ack → partial fill → fill
 *
 * **Expected output:**
 * ```
 * === Order Lifecycle ===
 *
 * Order 001: BUY 100 AAPL @ $150.25 LIMIT
 *   t=0ms:   NEW          (submitted)
 *   t=2ms:   ACK          (exchange confirmed)
 *   t=15ms:  PARTIAL_FILL qty=40 @ $150.25
 *   t=38ms:  PARTIAL_FILL qty=35 @ $150.25
 *   t=52ms:  FILLED       qty=25 @ $150.24  (total 100)
 *   Position: +100 AAPL @ avg $150.249
 *
 * Order 002: SELL 50 MSFT @ $300.00 LIMIT
 *   t=0ms:   NEW
 *   t=3ms:   REJECTED     (reason: price outside circuit breaker)
 *
 * === Fill Reconciliation ===
 * Exchange fills: 247  Internal fills: 247  PASS
 * Position check: AAPL=+100, MSFT=0  PASS
 * ```
 */

int main() {}
