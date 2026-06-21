/*
 * ## EXERCISE 5: Yield Curves — Multi-Currency and Basis [8.b.i]
 *
 * Trading desks manage curves in multiple currencies with cross-currency basis spreads.
 *
 * **Requirements:**
 * 1. Implement a `CurrencyPair` struct: `{domestic, foreign, spot_fx}`
 * 2. Implement **cross-currency bootstrapping**: derive USD zero rates from
 *    EUR curve + EUR/USD FX forward points:
 *    `df_USD(T) = df_EUR(T) * FX_forward(T) / FX_spot`
 * 3. Implement an **OIS curve** (overnight index swap): bootstrapped from
 *    OIS swap rates, representing near-risk-free rates post-2008
 * 4. Implement a **LIBOR-OIS spread** curve: `LIBOR(T) = OIS(T) + spread(T)`
 * 5. Compute **cross-currency basis** (XCB): the spread added to one leg of a
 *    cross-currency swap to make it fair
 * 6. Show the **discounting vs projection** split: use OIS for discounting,
 *    LIBOR for projecting cash flows (multi-curve framework)
 * 7. Price a EUR/USD cross-currency swap using both curves
 *
 * **Expected output:**
 * ```
 * === Multi-Curve Framework ===
 *
 * OIS curve (risk-free):
 *   1Y: 3.45%  2Y: 3.68%  5Y: 3.95%  10Y: 4.10%
 *
 * LIBOR curve (projection):
 *   1Y: 3.70%  2Y: 3.99%  5Y: 4.27%  10Y: 4.43%
 *
 * LIBOR-OIS spread:
 *   1Y: 25bp  2Y: 31bp  5Y: 32bp  10Y: 33bp
 *
 * === Cross-Currency Swap (EUR pay float, USD receive float, 5Y) ===
 * EUR curve (OIS discount): bootstrapped from EUR OIS + FX fwds
 * USD XCB spread: -22bp  (USD investor pays 22bp less — USD premium)
 * Swap NPV before basis: $0  (by construction)
 * Swap NPV after basis:  $0  (basis absorbed into USD leg)
 * ```
 */

int main() {}
