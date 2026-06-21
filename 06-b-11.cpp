/*
 * ## EXERCISE 11: Combining Futures and Thread Pools — Parallel Greeks [6.b.i–ii]
 *
 * Greeks (delta, gamma, vega, theta, rho) are computed by bumping one parameter at a
 * time. They are embarrassingly parallel.
 *
 * **Requirements:**
 * 1. Define a `BlackScholes` pricing function: `double bs(S, K, T, sigma, r)`
 * 2. Define Greeks via finite difference:
 *    - `delta = (bs(S+h) - bs(S-h)) / (2h)`
 *    - `gamma = (bs(S+h) - 2*bs(S) + bs(S-h)) / h^2`
 *    - `vega  = (bs(sigma+h) - bs(sigma-h)) / (2h)`
 *    - `theta = (bs(T-h) - bs(T)) / h`
 *    - `rho   = (bs(r+h) - bs(r-h)) / (2h)`
 * 3. Submit each bump as a separate task to a `ThreadPool`
 * 4. Collect all 9 futures (5 Greeks need up to 9 bs evaluations)
 * 5. Compute and print all Greeks
 * 6. Compare serial (sequential bumps) vs parallel (pool) timing
 * 7. Show that for a single option the overhead dominates, but for 1000 options it wins
 *
 * **Expected output:**
 * ```
 * === Parallel Greeks Calculator ===
 * Option: S=100, K=100, T=1, sigma=0.20, r=0.05
 * Base price: $10.4506
 *
 * Greeks (parallel, 4 threads):
 *   delta:  0.6368
 *   gamma:  0.0188
 *   vega:  37.5240
 *   theta: -6.4140
 *   rho:   53.2325
 *
 * === Timing: 1 option ===
 * Serial:   0.12ms  (sequential bumps)
 * Parallel: 0.38ms  (overhead dominates for single option)
 *
 * === Timing: 1000 options ===
 * Serial:   118ms
 * Parallel:  34ms   speedup 3.5x
 *
 * Pool reuse amortises overhead — always batch work.
 * ```
 */

int main() {}
