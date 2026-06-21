/*
 * ## EXERCISE 12: Greeks — Finite Difference Methods [8.d.iii]
 *
 * Understand the accuracy and stability of numerical Greeks, and when
 * they fail (discontinuous payoffs, near barriers).
 *
 * **Requirements:**
 * 1. Implement three finite-difference Greek estimators:
 *    - **Forward difference**: `(f(x+h) - f(x)) / h` (O(h) error)
 *    - **Central difference**: `(f(x+h) - f(x-h)) / (2h)` (O(h²) error)
 *    - **Complex step**: `Im(f(x + ih)) / h` (O(h²), no cancellation error)
 * 2. For delta, show the optimal bump size: too small → cancellation; too large → truncation
 * 3. Demonstrate failure on a **digital option**: the payoff is discontinuous at K,
 *    so finite-difference delta is wrong unless h is very small
 * 4. Implement **central FD gamma**: `(f(S+h) - 2f(S) + f(S-h)) / h²`
 * 5. Show the gamma "crack" near expiry for an ATM option
 * 6. Demonstrate **cross-gamma** (sensitivity of delta of S1 to S2) for a basket option
 *
 * **Expected output:**
 * ```
 * === FD Greek Accuracy (call, S=100, K=100, T=1, sigma=0.2) ===
 *
 * Delta (analytic = 0.6368):
 *   h=1.0:  Forward=0.6255 (err=1.1e-2)  Central=0.6368 (err=4.2e-7)
 *   h=0.1:  Forward=0.6329 (err=3.9e-3)  Central=0.6368 (err=4.2e-9)
 *   h=0.01: Forward=0.6364 (err=3.9e-4)  Central=0.6368 (err=4.2e-11)
 *   h=1e-7: Forward=0.6368 (err=2.1e-8)  Central=0.6368 (err=1.4e-9)
 *   h=1e-14:Forward=0.5000 (err=0.14)    CANCELLATION!
 *
 * Complex step (h=1e-20): delta=0.636831  error=4.4e-16  (machine precision!)
 *
 * === Digital delta (true = N'(d2)*exp(-rT)/sigma/sqrt(T) = 0.0228) ===
 *   h=1.0:  FD delta=0.0175  (30% error)
 *   h=0.01: FD delta=0.0224  (2% error)
 *   h=0.001:FD delta=0.0227  (0.4% error — slow convergence near discontinuity)
 * ```
 */

int main() {}
