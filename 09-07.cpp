/*
 * ## EXERCISE 7: QuantLib — Yield Curve and Bond Pricing [9.e]
 *
 * QuantLib is the industry-standard open-source library for financial
 * instrument pricing. This exercise uses its yield curve and bond machinery.
 *
 * **Requirements:**
 * 1. Build a QuantLib `YieldTermStructure` from a set of deposit and swap rates:
 *    - Use `DepositRateHelper` for short-end instruments
 *    - Use `SwapRateHelper` for long-end instruments
 *    - Bootstrap with `PiecewiseYieldCurve<Discount, LogLinear>`
 * 2. Price a **fixed-rate bond**:
 *    - Use `FixedRateBond` with `UnitedStates(NYSE)` calendar
 *    - Compute `cleanPrice`, `dirtyPrice`, `yield`, `duration`, `convexity`
 * 3. Price a **floating-rate bond** (FRN):
 *    - Use `FloatingRateBond` with USD-LIBOR index
 *    - Show that at issuance, clean price ≈ 100
 * 4. Compute the **Z-spread** of a bond: the constant spread to add to the
 *    benchmark curve that makes the model price equal to the market price
 * 5. Use `QuantLib::Settings::instance().evaluationDate()` for date-dependent pricing
 *
 * **Expected output:**
 * ```
 * === QuantLib Yield Curve Bootstrap ===
 * Instruments: 3 deposits + 5 swaps
 * Bootstrapped zero rates:
 *   6M: 3.45%  1Y: 3.70%  2Y: 3.95%  5Y: 4.18%  10Y: 4.30%
 *
 * === Fixed-Rate Bond (5% coupon, 10Y, semi-annual) ===
 * Settlement: 2024-01-17
 * Clean price:  101.423
 * Dirty price:  101.623 (includes accrued: 0.200)
 * Yield:         4.832%
 * Modified duration: 7.84
 * Convexity:    74.2
 *
 * === Z-Spread ===
 * Market price: 101.00 (cheaper than model)
 * Z-spread:     28.4bp (compensation for credit/liquidity)
 *
 * === Floating-Rate Bond ===
 * At issuance clean price: 99.982 ≈ 100  PASS
 * ```
 */

int main() {}
