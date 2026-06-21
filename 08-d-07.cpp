/*
 * ## EXERCISE 7: Monte Carlo Pricing — Path-Dependent Options [8.d.i]
 *
 * Path-dependent options require storing the full price path. Implement efficient
 * path generation and payoff evaluation.
 *
 * **Requirements:**
 * 1. Implement a **path generator** that produces `N_paths × N_steps` matrix of stock prices
 * 2. Price the following path-dependent options (all with `S=100, K=100, T=1, sigma=0.2, r=0.05`):
 *    - **Arithmetic Asian call** (average of monthly closes)
 *    - **Geometric Asian call** (has a closed form — use for verification)
 *    - **Lookback call** (pays `S_T - S_min`)
 *    - **Lookback put** (pays `S_max - S_T`)
 *    - **Barrier down-and-out call** (H=90)
 *    - **Shout option** (holder can lock in gain once; pays `max(S_shout - K, S_T - K, 0)`)
 * 3. For the geometric Asian, compare MC to the closed-form price
 * 4. Benchmark: path generation is the bottleneck — profile and optimise
 * 5. Show the effect of N_steps on barrier option price (discretisation error)
 *
 * **Expected output:**
 * ```
 * === Path-Dependent Options (1M paths, 252 steps) ===
 *
 * Option                  Price    Std Err   Notes
 * Arithmetic Asian call   $5.863   $0.012    (lower than vanilla $10.451)
 * Geometric Asian call    $5.401   $0.010    analytic=$5.398  PASS
 * Lookback call (float)   $19.442  $0.025    (always >= vanilla)
 * Lookback put  (float)   $14.573  $0.019
 * DO call H=90            $6.263   $0.018    (closed form: $6.242)
 * Shout call              $13.215  $0.021
 *
 * === Barrier discretisation error ===
 * N_steps=12:  DO price=$6.580  (6% error vs closed form)
 * N_steps=52:  DO price=$6.310  (1.1% error)
 * N_steps=252: DO price=$6.263  (0.3% error)
 * ```
 */

int main() {}
