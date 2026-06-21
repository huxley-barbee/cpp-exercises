/*
 * ## EXERCISE 15: Optimization — Derivative-Free Methods [8.a.iii]
 *
 * **Requirements:**
 * 1. Implement the Nelder-Mead simplex method
 * 2. Implement a basic differential evolution (DE) algorithm
 * 3. Apply both to calibrate a Heston stochastic volatility model:
 *    parameters `(v0, kappa, theta, sigma_v, rho)` fit to a vol surface
 * 4. Use MC pricing (or analytic Heston) as the inner objective
 * 5. Show DE handles multiple local minima in Heston calibration
 * 6. Compare: LM (fast, local), Nelder-Mead (medium, local), DE (slow, global)
 * 7. Implement basin hopping: Nelder-Mead restarts from random perturbations
 *
 * **Expected output:**
 * ```
 * === Heston Calibration ===
 * True: v0=0.04, kappa=2.0, theta=0.04, sigma_v=0.3, rho=-0.7
 *
 * Nelder-Mead (500 iters): RMSE=0.42%   time=1.2s
 * DE (200 gen, pop=50):    RMSE=0.08%   time=8.5s
 * Basin Hopping (50 rest): RMSE=0.09%   time=4.1s
 *
 * DE finds global minimum; Nelder-Mead can get stuck in local minima.
 * ```
 */

int main() {}
