/*
 * ## EXERCISE 23: Calibration Pipeline [8.a.iii–iv]
 *
 * **Requirements:**
 * 1. Generate a synthetic Heston implied vol surface with known parameters
 * 2. Build the objective: sum of squared differences between model and market vols
 * 3. Use the Heston characteristic function for fast pricing
 * 4. Run a two-stage calibration: DE for global search, then LM for polish
 * 5. Add regularisation to prevent overfitting
 * 6. Perform a parameter stability test: re-calibrate on 5 perturbed surfaces
 *
 * **Expected output:**
 * ```
 * === Heston Calibration Pipeline ===
 * True: v0=0.04, kappa=2.0, theta=0.04, sigma_v=0.30, rho=-0.70
 *
 * DE (200 gen): RMSE=0.15%   time=4.2s
 * LM polish:    RMSE=0.03%   time=0.1s
 * Calibrated: v0=0.0400, kappa=2.000, theta=0.0400, sigma_v=0.300, rho=-0.700
 *
 * === Stability (5 perturbed surfaces) ===
 * v0:  mean=0.0401  std=0.0003
 * rho: mean=-0.701  std=0.012
 * ```
 */

int main() {}
