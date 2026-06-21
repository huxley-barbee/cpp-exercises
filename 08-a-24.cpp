/*
 * ## EXERCISE 24: American Option Pricing by LSMC [8.a.ii–iv]
 *
 * **Requirements:**
 * 1. Implement the Longstaff-Schwartz (LSMC) algorithm for American options:
 *    simulate N paths, work backwards, regress continuation values on basis functions,
 *    exercise when intrinsic value exceeds the regression estimate
 * 2. Use polynomial basis `[1, S, S^2, S^3]`; solve regression with `colPivHouseholderQr`
 * 3. Compare to the CN finite-difference American price
 * 4. Show convergence vs N (paths) and M (time steps)
 * 5. Extend to a Bermudan swaption (exercise at discrete dates)
 *
 * **Expected output:**
 * ```
 * === LSMC American Put ===
 * K=100, T=1, sigma=0.2, r=0.05
 *
 * N=100K, M=50: LSMC=$6.08   CN-FD=$6.07   PASS
 *
 * Convergence (M=50):
 *   N=10K:  $6.04 +/- 0.05
 *   N=500K: $6.07 +/- 0.005
 *
 * === Bermudan Swaption (quarterly, 5Y) ===
 * LSMC: 142bp   CN-FD (1D approx): 138bp
 * ```
 */

int main() {}
