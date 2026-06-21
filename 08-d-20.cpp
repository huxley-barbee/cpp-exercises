/*
 * ## EXERCISE 20: Portfolio Greeks and Risk Management [8.d.iii]
 *
 * Aggregate Greeks across a portfolio and implement standard risk management
 * reports.
 *
 * **Requirements:**
 * 1. Build a portfolio of 10 options (calls and puts, various K, T, sigma)
 * 2. Aggregate **dollar Greeks** (DV01, dollar delta, dollar gamma, dollar vega)
 * 3. Implement a **P&L explain** formula:
 *    `dV ≈ Delta*dS + 0.5*Gamma*dS² + Vega*dsigma + Theta*dt`
 * 4. Simulate a 1-day P&L using the P&L explain vs full repricing;
 *    compare the two (the difference is P&L unexplained / higher-order effects)
 * 5. Implement **vega bucketing**: vega per maturity bucket [0-1M, 1-3M, 3-6M, 6-12M, 1-2Y, 2Y+]
 * 6. Compute the **DV01 curve** (sensitivity to 1bp move at each yield curve knot)
 * 7. Show the **speed** (dGamma/dS) and **colour** (dGamma/dt) for the portfolio
 *
 * **Expected output:**
 * ```
 * === Portfolio Greeks (10 options) ===
 *
 * Position  Type  K    T     Delta  Gamma   Vega    Theta
 * 1         Call  95   0.25   0.71   0.038   9.4    -18.4
 * 2         Put   100  0.25  -0.44   0.040   9.9    -19.5
 * ...
 * TOTAL            —    —    +1.82   0.301  141.3  -284.2
 *
 * Dollar Greeks (notional $1M per position):
 *   $Delta:  +$18,200    $Gamma: +$3,010/1%
 *   $Vega:  +$14,130/1%  $Theta: -$28,420/day
 *
 * === P&L Explain (1-day move: dS=+$2, dsigma=-0.5%) ===
 * Delta P&L:   +$36,400
 * Gamma P&L:   +$1,204
 * Vega P&L:    -$7,065
 * Theta P&L:   -$28,420
 * Total explain: +$2,119
 *
 * Full reprice:  +$2,342
 * Unexplained:    +$223  (higher-order cross-gamma effects)
 * ```
 */

int main() {}
