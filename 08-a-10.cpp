/*
 * ## EXERCISE 10: ODE/PDE — Monte Carlo for PDEs (Feynman-Kac) [8.a.ii]
 *
 * **Requirements:**
 * 1. Show the Feynman-Kac connection: price a European option by simulating
 *    `dS = mu*S*dt + sigma*S*dW` and averaging the discounted payoff
 * 2. Implement Euler-Maruyama discretisation of the SDE
 * 3. Compare to exact log-normal simulation:
 *    `S(t+dt) = S(t) * exp((mu-0.5*sigma^2)*dt + sigma*sqrt(dt)*Z)`
 * 4. Show strong and weak convergence of Euler-Maruyama (vary `dt`)
 * 5. Implement the Milstein scheme (stronger strong convergence order)
 * 6. Benchmark: 1M paths, Euler vs Milstein vs exact
 *
 * **Expected output:**
 * ```
 * === Feynman-Kac: European Call via MC ===
 * S0=100, K=100, T=1, sigma=0.2, r=0.05, N=1M paths
 *
 * Analytic:              $10.451
 * Euler-Maruyama dt=0.1: $10.397  bias=-0.054
 * Euler-Maruyama dt=0.01:$10.445  bias=-0.006
 * Exact simulation:      $10.453  bias=+0.002  (sampling error only)
 * Milstein dt=0.1:       $10.448  bias=-0.003
 *
 * Convergence: Euler strong order 0.5   Milstein strong order 1.0
 *
 * === Performance (1M paths) ===
 * Euler (10 steps): 0.8s   Exact (1 step): 0.2s
 * ```
 */

int main() {}
