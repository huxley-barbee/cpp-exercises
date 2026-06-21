/*
 * ## EXERCISE 3: Yield Curves — Curve Sensitivities (DV01 and Key Rate Durations) [8.b.i]
 *
 * Compute the sensitivity of a bond portfolio to yield curve movements.
 *
 * **Requirements:**
 * 1. Implement a `FixedRateBond` pricer using the zero curve:
 *    `P = sum(c * df(t_i)) + df(T)` where `c` is the coupon
 * 2. Compute **DV01** (dollar value of a basis point):
 *    `DV01 = -(P(r+1bp) - P(r-1bp)) / 2`
 *    where the entire curve is shifted by 1bp
 * 3. Compute **key rate durations (KRD)**: sensitivity to a 1bp move at each
 *    curve knot, holding all other knots fixed
 * 4. Compute **modified duration** and **convexity** analytically
 * 5. Verify: `DV01 ≈ Duration * Price / 10000`
 * 6. Implement a **duration-matched hedge**: find the notional of a 5Y bond
 *    that neutralises the DV01 of a 10Y bond
 * 7. Show the **PV01 ladder**: for a portfolio of 5 bonds, print the KRD
 *    contribution at each tenor
 *
 * **Expected output:**
 * ```
 * === Bond Sensitivities (10Y 4.5% coupon bond, face=$1M) ===
 *
 * Price:              $101,423
 * Modified Duration:   7.84 years
 * Convexity:          74.2
 * DV01:              $795/bp
 * Duration * P/10000: $795  PASS
 *
 * Key Rate Durations:
 *   2Y KRD: $  42/bp
 *   3Y KRD: $  68/bp
 *   5Y KRD: $ 183/bp
 *   7Y KRD: $ 224/bp
 *  10Y KRD: $ 278/bp
 *   Sum:    $ 795/bp = DV01  PASS
 *
 * === Duration-Matched Hedge ===
 * 10Y bond DV01: $795/bp
 * 5Y bond DV01:  $488/bp
 * Hedge ratio: Short $1.629M 5Y bond to neutralise 10Y DV01
 * ```
 */

int main() {}
