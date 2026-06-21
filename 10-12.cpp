/*
 * ## EXERCISE 12: Pricing & Risk Architecture — Greeks Aggregation Engine [10.f]
 *
 * Implement the Greeks aggregation engine — the component that takes
 * per-instrument Greeks and produces book-level sensitivities.
 *
 * **Requirements:**
 * 1. Define a `Greeks` struct:
 *    ```cpp
 *    struct Greeks {
 *        double delta, gamma, vega, theta, rho;
 *        double vanna, volga;   // second-order cross-Greeks
 *        double dv01;           // for rate products
 *    };
 *    ```
 * 2. Implement `GreeksAggregator`:
 *    - `update(instrument_id, Greeks)` — O(1), called per pricing result
 *    - `bookGreeks()` — returns the sum of all instrument Greeks
 *    - `greeksByBucket(tenor_bucket)` — vega by maturity bucket
 *    - `topContributors(n, greek)` — top-N instruments by |delta|, |vega|, etc.
 * 3. Implement **dollar Greeks** (normalise to notional):
 *    - Dollar delta: `delta * spot * notional`
 *    - Dollar gamma: `0.5 * gamma * spot^2 * notional` (per 1% move)
 *    - Dollar vega: `vega * notional` (per 1% vol move)
 * 4. Implement **P&L explain** (1-day):
 *    `dPnL = delta*dS + 0.5*gamma*dS^2 + vega*dvol + theta*dt`
 * 5. Thread-safety: pricing threads write Greeks, risk thread reads them;
 *    use a double-buffer (ping-pong) for zero-contention reads
 *
 * **Expected output:**
 * ```
 * === Greeks Aggregation (100 instruments) ===
 *
 * Book Greeks:
 *   Delta:  +3.821   Gamma: +0.194/1%S
 *   Vega:  +48.3/1%vol  Theta: -12.4/day
 *
 * Dollar Greeks (notional $10M):
 *   $Delta:  +$382,100
 *   $Gamma:  +$19,400/1%S move
 *   $Vega:   +$4,830/1%vol move
 *
 * Top-3 delta contributors:
 *   #1 AAPL_CALL  delta=0.637  $delta=$63,700
 *   #2 MSFT_CALL  delta=0.521  $delta=$52,100
 *   #3 GOOGL_PUT  delta=-0.412 $delta=-$41,200
 *
 * P&L Explain (dS=+1%, dvol=-0.5vol%):
 *   Delta P&L:  +$38,210
 *   Gamma P&L:  +$1,940
 *   Vega P&L:   -$2,415
 *   Theta P&L:  -$1,240
 *   Total:      +$36,495
 *
 * Double-buffer: read latency=0ns (no lock)  PASS
 * ```
 */

int main() {}
