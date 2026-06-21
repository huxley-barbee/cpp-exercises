/*
 * ## EXERCISE 20: Finite Difference Greeks [8.a.ii–iii]
 *
 * **Requirements:**
 * 1. Build a full Crank-Nicolson FD option pricing engine
 * 2. Compute delta and gamma directly from the spatial FD grid (first and second derivatives)
 * 3. Compute theta from the temporal derivative of the grid
 * 4. Compute vega and rho by re-solving with bumped parameters
 * 5. Compare all Greeks to analytic Black-Scholes values
 * 6. Show that FD delta and gamma are more accurate than bump-and-reprice
 *    (no finite-difference noise in the bump)
 *
 * **Expected output:**
 * ```
 * === FD Greeks (K=100, T=1, S=100, sigma=0.2, r=0.05) ===
 *
 *          FD Value   BS Analytic   Error
 * Price:   $10.449    $10.451       0.002
 * Delta:    0.6368     0.6368      <0.0001
 * Gamma:    0.0188     0.0188      <0.0001
 * Theta:   -6.414     -6.414        0.001
 * Vega:    37.524     37.524        0.010
 * Rho:     53.233     53.233        0.008
 *
 * FD delta/gamma have NO bumping noise vs bump-and-reprice.
 * ```
 */

int main() {}
