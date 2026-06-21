/*
 * ## EXERCISE 10: Monte Carlo Pricing — Stochastic Volatility [8.d.i]
 *
 * Implement MC pricing under stochastic volatility models.
 *
 * **Requirements:**
 * 1. Implement the **Heston model** using the full-truncation Euler scheme:
 *    ```
 *    dS = r*S*dt + sqrt(v)*S*dW1
 *    dv = kappa*(theta-v)*dt + sigma_v*sqrt(v)*dW2
 *    corr(dW1,dW2) = rho
 *    ```
 * 2. Price a vanilla call and compare to the Heston characteristic function price
 * 3. Implement **SABR MC**: simulate under the SABR dynamics
 *    ```
 *    dF = sigma*F^beta*dW1
 *    dsigma = nu*sigma*dW2,  corr = rho
 *    ```
 * 4. Compare Heston and SABR MC prices for an ATM option
 * 5. Show the **vol-of-vol effect**: price a straddle under Heston with
 *    `sigma_v = 0.1, 0.3, 0.5` — higher vol-of-vol increases the straddle value
 * 6. Implement the **Andersen QE scheme** as a more accurate Heston discretisation
 *
 * **Expected output:**
 * ```
 * === Heston MC (v0=0.04, kappa=2, theta=0.04, sigma_v=0.3, rho=-0.7) ===
 * N=1M paths, 100 steps
 *
 * Call (K=100, T=1):
 *   Full-truncation Euler: $10.387  +/- 0.010
 *   Andersen QE scheme:    $10.443  +/- 0.009
 *   Characteristic fn:     $10.451  (benchmark)
 *
 * === Vol-of-vol effect on straddle ===
 * sigma_v=0.1: straddle=$16.031  (near BS)
 * sigma_v=0.3: straddle=$16.288
 * sigma_v=0.5: straddle=$16.741  (higher vol-of-vol => fatter tails => costlier straddle)
 * ```
 */

int main() {}
