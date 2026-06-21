/*
 * ## EXERCISE 25: Pricing Under Jump Processes [8.d.i–iv]
 *
 * **Requirements:**
 * 1. Implement the **Merton jump-diffusion** model:
 *    `dS/S = (r - lambda*k_bar)*dt + sigma*dW + (J-1)*dN`
 *    where `N(t)` is a Poisson process with intensity `lambda`,
 *    `J = exp(mu_J + sigma_J * Z)` is the jump size
 * 2. MC simulation: at each step, draw `n ~ Poisson(lambda*dt)` jumps,
 *    apply compound log-normal jumps
 * 3. Price a European call under Merton and compare to BS
 * 4. Show that jump diffusion produces **heavier tails** and **steeper short-term skew**
 * 5. Implement the **Merton analytic formula**:
 *    `C_Merton = sum_{n=0}^{inf} exp(-lambda'*T)*(lambda'*T)^n/n! * BS(S, K, T, sigma_n, r_n)`
 *    where `sigma_n^2 = sigma^2 + n*sigma_J^2/T`, `r_n = r - lambda*k_bar + n*log(1+k_bar)/T`
 * 6. Verify MC against analytic formula
 * 7. Show that jumps cannot be hedged by delta — compute the **unhedgeable jump risk**
 *
 * **Expected output:**
 * ```
 * === Merton Jump-Diffusion ===
 * sigma=0.15, lambda=0.3, mu_J=-0.1, sigma_J=0.15, r=0.05
 *
 * European call (K=100, T=1):
 *   BS (no jumps):      $7.965
 *   Merton analytic:    $9.183  (higher — jump risk premium)
 *   Merton MC (1M):     $9.175 +/- 0.029  PASS
 *
 * === Short-term Skew (T=1M) ===
 * Strike  BS IV   Merton IV  Difference
 *   90%    20.0%   28.1%     +8.1%   (jumps cause steep short-term skew)
 *  100%    20.0%   22.3%     +2.3%
 *  110%    20.0%   17.4%     -2.6%
 *
 * === Unhedgeable Jump Risk ===
 * Delta-hedged portfolio at T=0:
 *   BS expected P&L: 0
 *   With jumps, P&L variance = lambda*T*E[(J*S*Delta - J*S*1_{S>K})^2]
 *   Residual P&L std dev: $1.24 (cannot be hedged with stock alone)
 * ```
 */

int main() {}
