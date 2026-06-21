/*
 * ## EXERCISE 5: Black-Scholes — Implied Volatility Surface [8.d.ii]
 *
 * Build a complete implied volatility surface from market prices and analyse
 * its properties.
 *
 * **Requirements:**
 * 1. Generate a synthetic market: 6 maturities × 9 strikes, prices from a
 *    known Heston model (use a simplified MC)
 * 2. Invert to implied vols using Newton's method (from section 8.a.11)
 * 3. Build the IV surface as an `Eigen::MatrixXd`
 * 4. Compute the **volatility smile** slope (skew) and curvature at each maturity
 * 5. Verify **calendar spread arbitrage**: `C(T2) >= C(T1)` for `T2 > T1` at same K
 * 6. Verify **butterfly arbitrage** (convexity in K): `C(K-dK) - 2*C(K) + C(K+dK) >= 0`
 * 7. Fit a **SVI (Stochastic Volatility Inspired)** parametric smile at each maturity:
 *    `w(k) = a + b*(rho*(k-m) + sqrt((k-m)^2 + sigma^2))`
 *    where `k = log(K/F)` and `w = sigma_imp^2 * T`
 * 8. Interpolate the surface using bilinear interpolation
 *
 * **Expected output:**
 * ```
 * === Implied Volatility Surface ===
 * Maturities: [1M, 3M, 6M, 1Y, 2Y, 5Y]
 * Strikes:    [70%, 80%, 90%, 95%, ATM, 105%, 110%, 120%, 130%]
 *
 * Sample IVs (%):
 *        K=80%  K=90%  K=ATM  K=110% K=120%
 * T=1M:  28.1   24.3   20.0   22.1   25.4
 * T=3M:  26.4   22.8   20.0   21.2   23.5
 * T=1Y:  24.1   21.5   20.0   20.7   21.8
 * T=5Y:  22.0   20.8   20.0   20.4   21.0
 *
 * Skew (d_IV/d_k at ATM):
 *   T=1M: -0.43  T=3M: -0.38  T=1Y: -0.23  T=5Y: -0.12
 *
 * Calendar spread check: PASS (no arbitrage)
 * Butterfly check:       PASS (convex in K)
 * ```
 */

int main() {}
