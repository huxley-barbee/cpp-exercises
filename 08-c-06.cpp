/*
 * ## EXERCISE 6: Order Gateways — Order State Machine [8.c.ii]
 *
 * An order gateway must track the exact state of every live order and handle
 * exchange responses correctly.
 *
 * **Requirements:**
 * 1. Implement `OrderState` as an enum:
 *    `PENDING_NEW, LIVE, PENDING_CANCEL, PENDING_REPLACE, PARTIALLY_FILLED,
 *     FILLED, CANCELLED, REJECTED, EXPIRED`
 * 2. Implement `OrderGateway::Order` struct:
 *    - `uint64_t client_order_id`
 *    - `uint64_t exchange_order_id` (assigned on ACK)
 *    - `OrderState state`
 *    - `int64_t  price` (fixed-point)
 *    - `int32_t  qty, filled_qty, remaining_qty`
 *    - `char     symbol[8]`
 *    - `int64_t  submit_ts_ns, ack_ts_ns, fill_ts_ns`
 * 3. Implement valid state transitions as a compile-time table:
 *    `constexpr bool valid[NUM_STATES][NUM_EVENTS]`
 * 4. Implement `processAck()`, `processFill()`, `processCancel()`,
 *    `processReject()` — each updates state and timestamps
 * 5. Compute **order latency metrics**: `ack_latency = ack_ts - submit_ts`,
 *    `fill_latency = fill_ts - submit_ts`
 * 6. Implement an `OrderBook` (blotter): `std::array<Order, MAX_ORDERS>`
 *    with O(1) lookup by `client_order_id` via a hash map
 * 7. Show the full lifecycle of 5 orders with latency measurements
 *
 * **Expected output:**
 * ```
 * === Order Gateway State Machine ===
 *
 * Order 001: BUY 100 AAPL @ $150.25
 *   [PENDING_NEW] submitted t=0ns
 *   [LIVE]        ack       t=18,420ns  ack_latency=18.4µs
 *   [PART_FILLED] fill 40   t=45,100ns
 *   [FILLED]      fill 60   t=72,800ns  fill_latency=72.8µs
 *
 * Order 002: SELL 50 MSFT @ $300.00
 *   [PENDING_NEW] submitted t=0ns
 *   [REJECTED]    reason=price_outside_limits  t=4,200ns
 *
 * Invalid transition test:
 *   FILLED -> processAck(): INVALID  exception thrown  PASS
 *
 * === Latency stats (1000 orders) ===
 * Ack latency:  p50=18µs  p99=45µs  max=120µs
 * Fill latency: p50=45µs  p99=95µs  max=280µs
 * ```
 */

int main() {}
