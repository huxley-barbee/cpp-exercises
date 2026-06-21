/*
 * ## EXERCISE 6: Monte Carlo Pricing — European Options [8.d.i]
 *
 * Implement a clean, production-quality MC pricer for European options.
 *
 * **Requirements:**
 * 1. Implement `MCPricer` class with:
 *    - `setUnderlying(S0, sigma, r, q)`
 *    - `price(payoff_fn, T, N_paths, N_steps) -> (mean, stderr)`
 *    - Seed management: reproducible results
 * 2. Price call and put with 1M paths, compare to analytic BS
 * 3. Implement exact GBM simulation (single step): `S_T = S_0 * exp((r-q-0.5*sigma^2)*T + sigma*sqrt(T)*Z)`
 * 4. Implement multi-step Euler-Maruyama and compare bias to exact
 * 5. Show convergence: price error vs `1/sqrt(N)` (standard MC rate)
 * 6. Implement antithetic variates within the pricer
 * 7. Price a **straddle** (call + put) and **strangle** (OTM call + OTM put)
 *
 * **Expected output:**
 * ```
 * === European MC Pricer (S=100, K=100, T=1, sigma=0.2, r=0.05) ===
 *
 * N=100K, exact simulation:
 *   Call:  10.449 +/- 0.033   analytic=10.451  bias=-0.002  PASS
 *   Put:    5.572 +/- 0.023   analytic=5.574   bias=-0.002  PASS
 *
 * Convergence (call price):
 *   N=10K:  error=0.084  (expected 0.033/sqrt(0.1)=0.104)
 *   N=100K: error=0.025
 *   N=1M:   error=0.008  (rate ~N^{-0.5})
 *
 * Antithetic (100K paths):
 *   Call: 10.451 +/- 0.017   3.8x variance reduction
 *
 * Straddle (K=100):  $16.025 +/- 0.040
 * Strangle (K=90/110): $7.648 +/- 0.025
 * ```
 */

int main() {}
