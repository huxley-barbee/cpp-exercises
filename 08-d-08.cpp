/*
 * ## EXERCISE 8: Monte Carlo Pricing — Multi-Asset Options [8.d.i]
 *
 * Multi-asset options require correlated Brownian motions. Use the Cholesky
 * decomposition from section 8.a.
 *
 * **Requirements:**
 * 1. Generate correlated stock paths using Cholesky decomposition of a
 *    correlation matrix
 * 2. Price the following multi-asset options:
 *    - **Best-of call**: `max(max(S1_T, S2_T) - K, 0)`
 *    - **Worst-of call**: `max(min(S1_T, S2_T) - K, 0)`
 *    - **Basket call**: `max(w1*S1_T + w2*S2_T - K, 0)` (equal weights)
 *    - **Spread option**: `max(S1_T - S2_T - K, 0)` (Margrabe formula as check)
 *    - **Rainbow call** on 3 assets: `max(max(S1,S2,S3) - K, 0)`
 * 3. For the spread option, compare to Margrabe's formula
 * 4. Show how increasing correlation ρ from -0.9 to +0.9 affects basket vs spread prices
 * 5. Implement a **quanto option**: underlying in JPY, payoff in USD at fixed FX rate
 *
 * **Expected output:**
 * ```
 * === Multi-Asset Options (S1=S2=100, K=100, T=1, sigma=0.2, r=0.05) ===
 *
 * rho=0.5:
 *   Best-of call:    $20.842  +/- 0.033
 *   Worst-of call:   $  0.060  +/- 0.002
 *   Basket call:     $  7.612  +/- 0.018  (lower vol basket)
 *   Spread (K=0):    $12.388  +/- 0.026  Margrabe=$12.390  PASS
 *
 * Correlation effect on basket call price:
 *   rho=-0.9:  $2.41    rho=0.0: $7.61    rho=+0.9: $10.03
 *
 * === Quanto call (S in JPY, payoff in USD) ===
 * Quanto adjustment: sigma_FX=0.10, rho_SQ=-0.30
 * Effective rate: r_adj = r - rho*sigma_S*sigma_FX = 0.05+0.006 = 0.056
 * Quanto call: $10.566  vs domestic call: $10.451
 * ```
 */

int main() {}
