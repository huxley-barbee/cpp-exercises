/*
 * ## EXERCISE 11: Greeks — Analytic Formulas [8.d.iii]
 *
 * Implement all five first-order and the key second-order Greeks analytically.
 *
 * **Requirements:**
 * 1. Implement the full set of BS Greeks:
 *    - **Delta**: `∂C/∂S = exp(-qT)*N(d1)` (call); `exp(-qT)*(N(d1)-1)` (put)
 *    - **Gamma**: `∂²C/∂S² = exp(-qT)*N'(d1) / (S*sigma*sqrt(T))`
 *    - **Vega**: `∂C/∂sigma = S*exp(-qT)*N'(d1)*sqrt(T)`
 *    - **Theta**: `∂C/∂t = -S*exp(-qT)*N'(d1)*sigma/(2*sqrt(T)) - r*K*exp(-rT)*N(d2) + q*S*exp(-qT)*N(d1)`
 *    - **Rho**: `∂C/∂r = K*T*exp(-rT)*N(d2)` (call)
 *    - **Vanna**: `∂²C/∂S∂sigma = -exp(-qT)*N'(d1)*d2/sigma`
 *    - **Volga**: `∂²C/∂sigma² = S*exp(-qT)*N'(d1)*sqrt(T)*d1*d2/sigma`
 * 2. Verify by finite differences (bump-and-reprice) for all Greeks
 * 3. Print a full Greek report for a 5-option portfolio
 * 4. Show **theta decay**: plot theta as a function of S for calls and puts
 *
 * **Expected output:**
 * ```
 * === Full Greek Report (S=100, K=100, T=1, sigma=0.2, r=0.05, q=0) ===
 *
 * Greek       Analytic    FD (bump)    Error
 * Price       $10.451     —            —
 * Delta        0.6368      0.6368      3.2e-6
 * Gamma        0.0188      0.0188      2.1e-7
 * Vega        37.524      37.524       4.8e-5
 * Theta       -6.414      -6.414       1.2e-5
 * Rho         53.232      53.233       8.7e-4
 * Vanna       -0.1061     -0.1062      1.5e-5
 * Volga        1.2488      1.2491      4.3e-5
 *
 * === Theta decay (call, sigma=0.2) ===
 * S= 80: theta=-3.10  S= 90: theta=-5.12  S=100: theta=-6.41
 * S=110: theta=-6.84  S=120: theta=-6.62
 * Max theta at-the-money (as expected for ATM options).
 * ```
 */

int main() {}
