/*
 * ## EXERCISE 1: Yield Curves — Zero Curve Representation [8.b.i]
 *
 * Design and implement the foundational data structure for a zero-coupon yield curve.
 *
 * **Requirements:**
 * 1. Implement a `ZeroCurve` class that stores (tenor, zero rate) pairs
 * 2. Support the following day-count conventions as an enum:
 *    `ACT_365`, `ACT_360`, `ACT_ACT`, `THIRTY_360`
 * 3. Implement `df(T)` — discount factor: `exp(-r(T) * T)`
 * 4. Implement `forwardRate(T1, T2)` — continuously compounded instantaneous forward:
 *    `f(T1,T2) = (r(T2)*T2 - r(T1)*T1) / (T2 - T1)`
 * 5. Implement three interpolation methods (selectable at construction):
 *    - **Linear on zero rates**
 *    - **Linear on log-discount factors** (the industry standard)
 *    - **Cubic spline on zero rates**
 * 6. Store the curve as `std::vector<std::pair<double,double>>` sorted by tenor
 * 7. Verify that `df(0) = 1.0` and that forward rates are positive for an upward-sloping curve
 * 8. Print a curve report: tenors, zero rates, discount factors, 1Y forward rates
 *
 * **Expected output:**
 * ```
 * === Zero Curve Report ===
 * Tenors: [0.25, 0.5, 1, 2, 3, 5, 7, 10]
 * Rates:  [3.20, 3.45, 3.70, 3.95, 4.05, 4.18, 4.25, 4.30]%
 *
 * Tenor   ZeroRate   DiscFactor   Fwd(T,T+1Y)
 * 0.25    3.200%     0.99202      3.632%
 * 0.50    3.450%     0.98293      3.819%
 * 1.00    3.700%     0.96369      4.095%
 * 2.00    3.950%     0.92486      4.198%
 * 3.00    4.050%     0.88692      4.243%
 * 5.00    4.180%     0.81218      4.353%
 * 7.00    4.250%     0.74321      4.390%
 * 10.00   4.300%     0.65177       —
 *
 * df(0) = 1.000000  PASS
 * All forward rates positive: PASS
 * ```
 */

int main() {}
