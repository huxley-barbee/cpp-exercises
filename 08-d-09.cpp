/*
 * ## EXERCISE 9: Monte Carlo Pricing — Interest Rate Products [8.d.i]
 *
 * Extend MC pricing to interest rate derivatives using short-rate models.
 *
 * **Requirements:**
 * 1. Simulate the Vasicek short-rate model: `dr = kappa*(theta-r)*dt + sigma*dW`
 *    using the exact discretisation
 * 2. Price a **zero-coupon bond** `P(0,T) = E[exp(-integral r dt)]` via MC;
 *    compare to analytic formula `P(0,T) = exp(A(T) - B(T)*r0)`
 * 3. Price a **European bond option**: `max(P(T, T+tau) - K, 0)` via MC
 * 4. Simulate the **CIR** model and price the same bond option
 * 5. Implement a simple **LIBOR market model** (LMM / BGM) for a 5Y swap:
 *    evolve 10 LIBOR rates under the spot measure
 * 6. Price an **interest rate cap** (sum of caplets) under LMM and compare
 *    to Black's formula for each caplet
 *
 * **Expected output:**
 * ```
 * === Vasicek Model (r0=0.04, kappa=0.5, theta=0.05, sigma=0.01) ===
 *
 * ZCB P(0,5): analytic=0.7985   MC=0.7983 +/- 0.0004  PASS
 *
 * Bond option (T=1, tau=4, K=0.75):
 *   MC price: $0.0142 +/- 0.0002
 *
 * === LMM Cap Pricing (notional=$1M, K=4%) ===
 * Tenor  Caplet(LMM)  Caplet(Black)  Error
 * 1Y->2Y   $2,840       $2,835       0.2%
 * 2Y->3Y   $3,120       $3,115       0.2%
 * ...
 * Total cap: $24,350 (LMM)  vs  $24,310 (Black's)  1.7bp diff
 * ```
 */

int main() {}
