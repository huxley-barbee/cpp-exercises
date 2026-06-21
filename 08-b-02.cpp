/*
 * ## EXERCISE 2: Yield Curves — Bootstrapping from Instruments [8.b.i]
 *
 * Bootstrap a zero curve from market instruments (deposits, futures, swaps).
 *
 * **Requirements:**
 * 1. Define instrument types:
 *    - `DepositRate`: overnight, 1W, 1M, 3M, 6M rates (spot-starting)
 *    - `FuturesRate`: IMM futures (3M tenor, quarterly expiries)
 *    - `SwapRate`: par swap rates at standard tenors 1Y–10Y
 * 2. Implement the bootstrap algorithm:
 *    - Deposits: zero rate = deposit rate (short end)
 *    - Futures: convert price to rate, extract forward DF, chain-multiply
 *    - Swaps: solve `sum(c * df(t_i)) + df(T) = 1` for `df(T)` iteratively
 * 3. Store each instrument's contribution to the curve with its source label
 * 4. Verify self-consistency: re-price each input instrument using the bootstrapped curve —
 *    every instrument must reprice to par (within 0.1bp)
 * 5. Show the **turn-of-year effect**: a small kink at year-end in the overnight curve
 * 6. Compare bootstrapping order (deposits → futures → swaps) vs naive sorting
 *
 * **Expected output:**
 * ```
 * === Curve Bootstrap ===
 * Inputs: 5 deposits, 8 futures, 8 swaps = 21 instruments
 *
 * Bootstrap sequence:
 *   ON:   rate=3.05%  df(1d)=0.999916
 *   1W:   rate=3.10%  df(7d)=0.999405
 *   1M:   rate=3.20%  df(1M)=0.997338
 *   ...
 *   1Y swap: rate=3.70%  df(1Y)=0.963688  (solved from swap equation)
 *   2Y swap: rate=3.95%  df(2Y)=0.924856
 *   ...
 *
 * Self-consistency check (reprice all 21 instruments):
 *   Max error: 0.041bp  PASS (tolerance 0.1bp)
 *
 * Bootstrapped zero rates:
 *   3M: 3.20%  6M: 3.45%  1Y: 3.70%  2Y: 3.99%  5Y: 4.27%  10Y: 4.43%
 * ```
 */

int main() {}
