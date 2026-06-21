/*
 * ## EXERCISE 14: Optimization — Levenberg-Marquardt Curve Fitting [8.a.iii]
 *
 * **Requirements:**
 * 1. Implement the Levenberg-Marquardt (LM) algorithm for nonlinear least squares:
 *    `min_theta ||f(theta)||^2` where `f_i = model(x_i, theta) - y_i`
 * 2. Apply to fit a SABR volatility smile at 7 strikes
 * 3. Compute the Jacobian using finite differences
 * 4. Show the LM update: `(J^T J + lambda I) delta = -J^T f`
 * 5. Compare LM to Gauss-Newton (lambda=0) — show LM is more robust to bad starts
 * 6. Report parameter uncertainty from `Cov(theta) ~ sigma^2 * (J^T J)^{-1}`
 *
 * **Expected output:**
 * ```
 * === SABR Smile Fitting (LM) ===
 * Strikes:   [80, 90, 95, 100, 105, 110, 120]
 * Market IV: [28%, 23%, 21%, 20%, 21%, 22%, 26%]
 *
 * LM Fit (12 iterations):
 *   alpha=0.182, beta=0.700, rho=-0.250, nu=0.450
 *   Final ||f||: 0.0003 (0.03% RMS error)
 *
 * Parameter uncertainties (1-sigma):
 *   alpha: +/-0.008   rho: +/-0.031
 *   beta:  +/-0.043   nu:  +/-0.021
 * ```
 */

int main() {}
