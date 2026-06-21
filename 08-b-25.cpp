/*
 * ## EXERCISE 25: Putting It Together — Multi-Asset Event-Driven Pricer [8.b.iii–iv]
 *
 * Build a complete multi-asset event-driven pricing system that handles
 * equities, rates, and FX simultaneously.
 *
 * **Requirements:**
 * 1. Support three asset classes with separate market data feeds:
 *    - Equities: tick data → spot price + vol surface update
 *    - Rates: swap rates → curve update
 *    - FX: spot FX + forward points → cross-currency curve update
 * 2. Each asset class has its own normalised feed and ring buffer
 * 3. A central `PricingOrchestrator` subscribes to all three feeds:
 *    - Routes updates to the correct pricing engine
 *    - Maintains a `DependencyMap`: which instruments need to be repriced
 *      when a given market data item changes
 * 4. Implement **batch repricing**: accumulate updates for 1ms, then
 *    reprice all affected instruments in one pass (reduces redundant repricing
 *    when multiple ticks arrive for the same underlying)
 * 5. Implement a **pricing heartbeat**: even without market data, reprice
 *    every 100ms due to theta decay
 * 6. Show a cross-asset dependency: an FX option depends on both the FX spot
 *    (from the FX feed) and the domestic/foreign yield curves (from rates feed)
 *
 * **Expected output:**
 * ```
 * === Multi-Asset Event-Driven Pricer ===
 *
 * Feeds active: Equity(5 symbols), Rates(8 tenors), FX(3 pairs)
 *
 * Tick rates:
 *   Equity: 500 ticks/sec (100 per symbol)
 *   Rates:  20 ticks/sec  (2-3 per tenor)
 *   FX:     150 ticks/sec (50 per pair)
 *
 * Batching window: 1ms
 *   Avg updates per batch: 0.67 equity + 0.02 rate + 0.15 FX
 *   Instruments repriced per batch: 3.8 avg (vs 14.2 without batching — 73% reduction)
 *
 * === Cross-asset: EURUSD call ===
 * Dependencies: EURUSD spot, EUR curve, USD curve
 * Trigger: EUR 2Y rate tick
 *   EUR curve updated (2Y tenor)
 *   EURUSD call repriced: $0.0312 -> $0.0314
 *   Total latency: 35µs
 *
 * Theta heartbeat (every 100ms):
 *   All 200 instruments repriced
 *   Time: 8ms (parallel, 4 threads)
 * ```
 */

int main() {}
