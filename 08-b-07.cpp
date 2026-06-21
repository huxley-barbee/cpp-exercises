/*
 * ## EXERCISE 7: Pricing Engines — Model Parameters and Market Data [8.b.ii]
 *
 * A pricing engine must cleanly separate market data (live, changing) from
 * model parameters (calibrated, semi-static).
 *
 * **Requirements:**
 * 1. Implement a `MarketData` class:
 *    - Stores spot prices, vol surfaces (as `std::map<std::pair<double,double>, double>`),
 *      yield curves, dividend yields
 *    - Thread-safe reads via `std::shared_mutex`
 *    - Atomic snapshot: `MarketData::snapshot()` returns a consistent copy
 * 2. Implement a `ModelParameters` class (Heston, SABR, LV params):
 *    - Immutable after calibration (const members or `std::shared_ptr<const Params>`)
 *    - Serialisable to JSON-like string for audit logging
 * 3. Implement a `PricingContext` that bundles market data + model parameters:
 *    the engine only sees the context, never global state
 * 4. Show the hot-swap pattern: replace `ModelParameters` atomically while
 *    the pricing engine is live (using `std::atomic<std::shared_ptr<const Params>>`)
 * 5. Benchmark: pricing with and without a lock (atomic shared_ptr vs mutex)
 *
 * **Expected output:**
 * ```
 * === Market Data and Model Parameters ===
 *
 * MarketData snapshot (thread-safe):
 *   SPX spot: $4,782.50
 *   ATM vol (1Y): 18.5%
 *   OIS rate (5Y): 3.95%
 *   Updated: 2024-01-15 10:23:45.123
 *
 * ModelParameters (Heston):
 *   v0=0.0400, kappa=2.000, theta=0.0400, sigma_v=0.300, rho=-0.700
 *   Calibrated: 2024-01-15 09:58:12  RMSE=0.03%
 *
 * === Hot-swap benchmark ===
 * Writer: update ModelParameters every 10ms
 * Readers: 8 threads pricing continuously
 *
 * Read throughput (mutex):       2.1M prices/sec
 * Read throughput (atomic sptr): 4.8M prices/sec  2.3x faster
 * Zero pricing interruptions during hot-swap: PASS
 * ```
 */

int main() {}
