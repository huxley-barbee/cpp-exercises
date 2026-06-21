/*
 * ## EXERCISE 12: Optimization — Gradient Descent and Variants [8.a.iii]
 *
 * **Requirements:**
 * 1. Implement gradient descent with a fixed learning rate
 * 2. Implement momentum (heavy-ball method)
 * 3. Implement Adam (adaptive moment estimation)
 * 4. Apply all three to minimise the Rosenbrock function:
 *    `f(x,y) = (1-x)^2 + 100*(y-x^2)^2`
 * 5. Apply Adam to fit a Nelson-Siegel yield curve to observed bond yields
 * 6. Show convergence: `log(f(x_k) - f*)` vs iteration count
 * 7. Show that fixed learning rate diverges if too large; demonstrate a schedule
 *
 * **Expected output:**
 * ```
 * === Rosenbrock minimisation ===
 * Gradient Descent (lr=0.001): iter 10000: f=0.0042
 * Momentum         (lr=0.001): iter 2000:  f=0.0001
 * Adam             (lr=0.01):  iter 500:   f=1.2e-8  CONVERGED
 *
 * === Nelson-Siegel Yield Curve Fit (Adam) ===
 * Observed: 3M=3.2%, 6M=3.5%, 1Y=3.8%, 2Y=4.0%, 5Y=4.2%, 10Y=4.3%
 * Fitted beta0=4.31, beta1=-1.11, beta2=0.52, tau=1.82
 * RMSE: 0.008%
 * ```
 */

int main() {}
