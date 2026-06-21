/*
 * ## EXERCISE 24: Exotic Pricing — Lookback and Cliquet Options [8.d.i–ii]
 *
 * **Requirements:**
 * 1. Implement a **floating-strike lookback call** using closed-form:
 *    `C_lb = S*N(a1) - S_min*exp(-rT)*N(a2) - S*(sigma^2/(2r))*(N(-a1) - exp(-rT)*(S_min/S)^(2r/sigma^2)*N(-a3))`
 * 2. Verify the closed form against MC with 1M paths
 * 3. Implement a **fixed-strike lookback call** (pays `max(S_max - K, 0)`)
 * 4. Implement a **cliquet option**: a series of forward-start options with local floor/cap:
 *    Each period pays `max(min(S_{t+1}/S_t - 1, cap), floor)`
 *    with `cap=5%, floor=0%`, quarterly resets over 2 years
 * 5. Price the cliquet using MC under local volatility and flat volatility
 * 6. Show how the cliquet value depends on the forward skew (sensitivity to vol term structure)
 *
 * **Expected output:**
 * ```
 * === Lookback Options (S=100, T=1, sigma=0.2, r=0.05) ===
 *
 * Floating-strike call (S_min=S0):
 *   Closed form:  $19.845
 *   MC (1M paths): $19.838 +/- 0.038  PASS
 *
 * Fixed-strike call (K=100):
 *   MC (1M paths): $19.442 +/- 0.025
 *
 * === Cliquet Option (cap=5%, floor=0%, quarterly, 2Y) ===
 * Flat vol (20%):    $5.23  per $100 notional
 * Local vol (Heston-generated surface):  $5.61
 * Difference: $0.38 (7.3%) — cliquet is sensitive to forward vol dynamics
 *
 * Vol term structure sensitivity:
 *   Parallel vol +1%:  cliquet +$0.18  (long vega)
 *   Flatter curve:     cliquet +$0.09  (long forward vol)
 * ```
 */

int main() {}
