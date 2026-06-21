/*
 * ## EXERCISE 8: QuantLib — Options and Volatility [9.e]
 *
 * QuantLib's option pricing uses a consistent framework of engines and processes.
 *
 * **Requirements:**
 * 1. Price a **European vanilla call** using:
 *    - `BlackScholesMertonProcess`
 *    - `AnalyticEuropeanEngine` (Black-Scholes analytic)
 *    - `MCEuropeanEngine` (Monte Carlo, 100K paths)
 *    - `FdBlackScholesVanillaEngine` (finite differences)
 * 2. Verify all three engines agree to within MC error
 * 3. Price an **American put** using:
 *    - `FdBlackScholesAmericanEngine` (finite differences)
 *    - `BinomialVanillaEngine<CoxRossRubinstein>` (binomial tree)
 * 4. Compute the **implied volatility** from a market price using
 *    `VanillaOption::impliedVolatility()`
 * 5. Build a QuantLib **volatility surface** using `BlackVarianceSurface`
 *    from a grid of implied vols; price an option using surface interpolation
 * 6. Show how to set the `evaluationDate` and reprice as time passes (theta)
 *
 * **Expected output:**
 * ```
 * === European Call (S=100, K=100, T=1Y, sigma=20%, r=5%) ===
 * Analytic BS:     $10.451
 * MC (100K paths): $10.443 +/- 0.033   diff=0.008  PASS
 * FD (CN):         $10.449              diff=0.002  PASS
 *
 * === American Put (K=100, T=1Y, sigma=30%, r=5%) ===
 * FD engine:       $8.431
 * Binomial (N=200):$8.429               diff=0.002  PASS
 *
 * === Implied Volatility ===
 * Market price: $11.00
 * Implied vol: 21.43%  (> 20% flat -> slight premium)
 *
 * === Theta (change evaluationDate by 1 day) ===
 * Price today:    $10.451
 * Price tomorrow: $10.433
 * 1-day theta:    $-0.018 (= -$6.57/year annualised)  PASS
 * ```
 */

int main() {}
