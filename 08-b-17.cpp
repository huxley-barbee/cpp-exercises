/*
 * ## EXERCISE 17: Event-Driven Architecture — Risk Event Pipeline [8.b.iv]
 *
 * Risk checks must happen in the critical path (pre-trade) and asynchronously
 * (post-trade). Implement both.
 *
 * **Requirements:**
 * 1. Implement **pre-trade risk checks** (synchronous, in the order path):
 *    - Position limit check: `|new_position| <= max_position`
 *    - Notional limit: `price * qty <= max_notional`
 *    - Rate-of-change: reject if same symbol traded > N times in last 1 second
 *    - Each check returns `RiskCheckResult{bool passed, string reason}`
 * 2. Implement a **RiskCheckChain**: checks run in order, first failure stops the chain
 * 3. Implement **post-trade risk** (asynchronous, does not block the order path):
 *    - P&L calculation
 *    - Greeks aggregation
 *    - VaR estimate
 *    - Results published as `RiskEvent` on the async bus
 * 4. Show the latency budget: pre-trade checks must complete in < 5µs
 * 5. Implement a **risk override** mechanism: senior trader can override a failed check
 *    with an audit log entry
 * 6. Benchmark: 100K orders/sec through the full risk pipeline
 *
 * **Expected output:**
 * ```
 * === Pre-Trade Risk Pipeline ===
 *
 * Order: BUY 1000 AAPL @ $150.25
 *   Check 1 PositionLimit:  PASS (pos=500, limit=5000)  0.2µs
 *   Check 2 NotionalLimit:  PASS ($150,250 < $1,000,000) 0.1µs
 *   Check 3 RateLimit:      PASS (3 trades/sec < 10)    0.3µs
 *   Total:                  PASS  0.6µs
 *
 * Order: BUY 10000 AAPL @ $150.25
 *   Check 1 PositionLimit:  FAIL (pos=500+10000=10500 > 5000)  0.2µs
 *   Order REJECTED
 *
 * === Post-Trade Risk (async) ===
 * Fill event received -> risk thread
 *   P&L calc:     0.8µs
 *   Greeks aggr:  2.1µs
 *   VaR update:  12.4µs
 *   Total:        15.3µs  (non-blocking)
 *
 * Throughput: 100K orders/sec with risk: PASS
 * ```
 */

int main() {}
