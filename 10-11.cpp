/*
 * ## EXERCISE 11: Pricing & Risk Architecture — System Design [10.f]
 *
 * Design a complete pricing and risk system architecture on paper (as C++
 * structs and interfaces) before writing a single line of implementation.
 *
 * **Requirements:**
 *
 * Design a system that:
 * - Prices a portfolio of 10,000 instruments (bonds, vanilla options, Asian options)
 * - Computes real-time Greeks and P&L
 * - Runs VaR/CVaR via Monte Carlo (10,000 scenarios)
 * - Publishes results over a message bus
 * - Handles market data updates in < 1ms
 *
 * Produce the following design artefacts:
 * 1. **Component diagram** (ASCII): show the major components and their
 *    data flow (market data → pricing → risk → reporting)
 * 2. **Interface definitions** (C++ headers only, no implementation):
 *    `IMarketDataSource`, `IPricingEngine`, `IRiskEngine`, `IResultPublisher`
 * 3. **Data model**: define `Instrument`, `MarketSnapshot`, `PricingResult`,
 *    `RiskReport` as C++ structs
 * 4. **Threading model**: which threads own which components, how data flows
 *    between threads (ring buffers, futures, events)
 * 5. **Latency budget**: allocate the 1ms budget across all stages
 * 6. **Failure modes**: what happens if the market data feed dies? If a pricer
 *    throws? If the VaR engine is too slow?
 *
 * **Expected output:**
 * ```
 * === Component Diagram ===
 *
 * [Market Data Feed] -> [SPSC Ring Buffer]
 *                               |
 *                     [Normalisation Thread]
 *                               |
 *                     [Curve/Vol Update]     [Pricing Cache]
 *                               |                   |
 *                     [Pricing Trigger] <----------->
 *                               |
 *                     [Parallel Pricing]  (thread pool, 8 workers)
 *                               |
 *                     [Greeks Aggregator]
 *                               |
 *               +---------------+----------------+
 *               |                                |
 *    [Real-time Risk]                    [VaR Engine]
 *    (incremental update)         (batch MC, 10K scenarios)
 *               |                                |
 *               +---------------+----------------+
 *                               |
 *                     [Result Publisher]
 *                          ZeroMQ PUB
 *
 * === Latency Budget (1ms total) ===
 * Market data receive:      50µs
 * Curve update:             80µs
 * Pricing (fast path):     200µs
 * Greeks aggregation:       50µs
 * Risk update:             100µs
 * Publish:                  20µs
 * Total:                   500µs  (2x margin)
 * ```
 */

int main() {}
