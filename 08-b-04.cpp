/*
 * ## EXERCISE 4: Yield Curves — Curve Interpolation and Fitting [8.b.i]
 *
 * Build a production-quality curve that is smooth, arbitrage-free, and stable.
 *
 * **Requirements:**
 * 1. Implement and compare three cubic spline variants:
 *    - **Natural cubic spline** (second derivative = 0 at endpoints)
 *    - **Not-a-knot** (third derivative continuous at second and penultimate knots)
 *    - **Monotone cubic spline** (Hyman filter — prevents oscillation)
 * 2. Show that standard cubic spline can produce **negative forward rates**
 *    between knot points — demonstrate with a realistic humped curve
 * 3. Implement the **Hyman monotonicity filter** to constrain the spline
 * 4. Implement **Nelson-Siegel-Svensson** (NSS) parametric fitting:
 *    `r(T) = beta0 + beta1*(1-e^{-T/tau1})/(T/tau1) + beta2*(...) + beta3*(...)`
 * 5. Fit NSS to 15 bootstrapped zero rates using Levenberg-Marquardt
 * 6. Show the NSS decomposition: level (beta0), slope (beta1), two hump terms
 *
 * **Expected output:**
 * ```
 * === Cubic Spline Comparison ===
 * Input: humped curve with peak at 5Y
 *
 * Natural spline:   negative fwd rate at T=3.2Y (-0.12%)  FAIL
 * Not-a-knot:       negative fwd rate at T=3.1Y (-0.08%)  FAIL
 * Monotone (Hyman): all forward rates positive              PASS
 *
 * === NSS Parametric Fit ===
 * Fitted: beta0=4.43, beta1=-1.23, beta2=2.11, beta3=-0.95
 *         tau1=0.92, tau2=3.84
 * RMSE: 0.38bp
 *
 * Decomposition at T=5Y:
 *   Level (beta0):    4.43%
 *   Slope (beta1):   -0.87%
 *   Hump1 (beta2):   +0.51%
 *   Hump2 (beta3):   -0.19%
 *   Total:            3.88%  (matches bootstrapped 3.88%)
 * ```
 */

int main() {}
