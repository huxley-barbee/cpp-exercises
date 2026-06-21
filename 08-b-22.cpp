/*
 * ## EXERCISE 22: Putting It Together — Real-Time Pricing Pipeline [8.b.ii–iv]
 *
 * Build a complete real-time pricing pipeline from market data to risk.
 *
 * **Requirements:**
 * 1. **Market data layer**: SPSC ring buffer receiving normalised ticks (Exercise 13)
 * 2. **Curve update**: when a rate tick arrives, update the relevant yield curve;
 *    propagate the change to all dependent pricers
 * 3. **Pricing trigger**: when spot or vol ticks arrive for a symbol, trigger
 *    re-pricing of all instruments on that underlying
 * 4. **Event bus**: publish `PriceUpdatedEvent` for each repriced instrument
 * 5. **Risk aggregation**: consume `PriceUpdatedEvent` and update the risk engine:
 *    - Update position P&L
 *    - Recompute portfolio delta (sum of individual deltas)
 * 6. **Latency measurement**: time from tick arrival to risk update completion
 * 7. Show the full pipeline with 1000 instruments, 100 ticks/sec per symbol
 *
 * **Expected output:**
 * ```
 * === Real-Time Pricing Pipeline ===
 *
 * Architecture:
 *   [Tick Feed] -> [SPSC Buffer] -> [Normaliser] -> [Curve/Vol Update]
 *                                                         |
 *                                               [Pricing Trigger]
 *                                                         |
 *                                               [Event Bus: PriceUpdated]
 *                                                         |
 *                                               [Risk Aggregation]
 *
 * Workload: 1000 instruments, 5 underlyings, 100 ticks/sec each
 *
 * Latency (tick-to-risk):
 *   p50:  185µs
 *   p99:  420µs
 *   p99.9: 1.2ms
 *
 * Throughput: 500 reprices/sec (100 ticks * 5 instruments per underlying)
 * Risk updates: 500/sec, P&L always within 1 tick of current
 *
 * Memory: 0 heap allocations in steady-state (all pre-allocated)
 * ```
 */

int main() {}
