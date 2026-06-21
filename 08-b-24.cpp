/*
 * ## EXERCISE 24: Putting It Together — Curve-Driven Pricing [8.b.i–ii]
 *
 * Show how yield curve updates propagate through the pricing engine to affect
 * bond and derivative prices.
 *
 * **Requirements:**
 * 1. Maintain a `CurveStore` holding the current zero curve (thread-safe,
 *    updated from market data)
 * 2. Implement a `CurveObserver` interface:
 *    ```cpp
 *    class ICurveObserver {
 *    public:
 *        virtual void onCurveUpdate(const ZeroCurve& newCurve) = 0;
 *    };
 *    ```
 * 3. Register the bond pricer and the swaption pricer as curve observers
 * 4. When a new swap rate arrives on the market data feed:
 *    - Re-bootstrap the curve
 *    - Notify all observers
 *    - Each observer re-prices its instruments
 * 5. Measure the end-to-end latency: swap rate tick → re-bootstrap → bond reprice
 * 6. Show the **dependency graph**: which instruments reprice when which
 *    curve knot changes
 * 7. Implement **selective invalidation**: only reprice instruments that depend
 *    on the changed tenor
 *
 * **Expected output:**
 * ```
 * === Curve-Driven Reprice ===
 *
 * Instruments dependent on 5Y swap rate:
 *   5Y bond (direct)
 *   5Y swaption (vol surface uses 5Y rate as forward)
 *   10Y bond (5Y DF used in discounting)
 *   5Y CDS (hazard rate bootstrap uses 5Y DF)
 *
 * 5Y swap rate changes: 4.18% -> 4.20% (+2bp)
 *
 * t=0µs:    Tick received
 * t=8µs:    Curve re-bootstrapped (5Y and beyond updated)
 * t=12µs:   5Y bond repriced:    $99.12 -> $98.97 (-$0.15)
 * t=14µs:   10Y bond repriced:   $101.42 -> $101.31 (-$0.11)
 * t=18µs:   5Y swaption repriced: $2.45 -> $2.44 (-$0.01)
 * t=22µs:   Risk delta updated
 *
 * Total: 22µs from tick to risk update
 * ```
 */

int main() {}
