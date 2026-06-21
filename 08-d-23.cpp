/*
 * ## EXERCISE 23: Full Greeks Surface [8.d.iii]
 *
 * Compute and visualise the complete Greeks surface across (S, sigma) space.
 *
 * **Requirements:**
 * 1. Compute a 20×20 grid of all 5 first-order Greeks as `Eigen::MatrixXd`
 *    - S ∈ [60, 140], sigma ∈ [0.05, 0.50]
 * 2. Find the (S, sigma) that maximises gamma — show it is near ATM, short maturity
 * 3. Find the ridge of maximum vega — show it is ATM, any maturity
 * 4. Show that **delta** transitions from 0→1 faster with high sigma (fatter tails)
 * 5. Implement the **vega-gamma relationship**:
 *    `Vega = 0.5 * S^2 * T * Gamma` — verify on the grid
 * 6. Show the **Black-Scholes PDE** is satisfied on the grid:
 *    `Theta + 0.5*sigma^2*S^2*Gamma + r*S*Delta - r*V = 0`
 *    Verify this holds for every (S, sigma) point (up to numerical precision)
 *
 * **Expected output:**
 * ```
 * === Greeks Surface (K=100, T=1, r=0.05) ===
 *
 * Maximum Gamma: S=100, sigma=0.05  gamma=0.0795  (ATM, low vol => sharp peak)
 *
 * Maximum Vega:  S=100 (ATM)  at any sigma  vega increases with S*sqrt(T)
 *
 * Delta contours (sigma=0.20):
 *   S=80: delta=0.274  S=90: delta=0.448  S=100: delta=0.637
 *   S=110: delta=0.789  S=120: delta=0.893
 *
 * === Vega-Gamma Relationship ===
 * Vega = 0.5 * S^2 * T * Gamma  (verify for all 400 grid points)
 * Max error: 2.8e-12  PASS
 *
 * === Black-Scholes PDE Check ===
 * Max |Theta + 0.5*sigma^2*S^2*Gamma + r*S*Delta - r*V| = 4.1e-11  PASS
 * ```
 */

int main() {}
