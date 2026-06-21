/*
 * ## EXERCISE 14: Greeks — Automatic Differentiation (AAD) [8.d.iii]
 *
 * Adjoint Algorithmic Differentiation computes all sensitivities in a single
 * backward pass — the same cost as one pricing.
 *
 * **Requirements:**
 * 1. Implement a simple **dual number** class `Dual<T>` that carries value and derivative:
 *    - Overload `+`, `-`, `*`, `/`, `exp`, `log`, `sqrt`, `max`, `erfc`
 * 2. Use `Dual<double>` to compute the BS delta by evaluating `bsCall<Dual<double>>`
 *    with `S = Dual(S0, 1.0)` — the derivative flows through automatically
 * 3. Extend to a **tape-based AAD**: record operations in a forward pass, then
 *    replay in reverse to get all sensitivities simultaneously
 * 4. Show that for `n` inputs and 1 output, forward mode costs `O(n)` and
 *    reverse mode (AAD) costs `O(1)` — independent of `n`
 * 5. Apply AAD to compute all 5 first-order Greeks simultaneously in one pass
 * 6. Compare to bump-and-reprice: AAD at ~2x pricing cost, bump at ~2*n pricing cost
 *
 * **Expected output:**
 * ```
 * === Dual Number AAD ===
 *
 * bsCall with Dual<double> (S=Dual(100,1), all others scalar):
 *   Price:  $10.451
 *   Delta:   0.6368  (= d(price)/d(S0))  PASS
 *
 * === Tape-based AAD (all 5 Greeks, 1 backward pass) ===
 * Forward:  price=$10.451
 * Backward:
 *   dC/dS=0.6368  dC/dsigma=37.524  dC/dr=53.232  dC/dT=-6.414  dC/dq=-60.025
 * All Greeks in 2.3x pricing cost.
 *
 * Bump-and-reprice: 10x pricing cost (2 bumps x 5 parameters).
 * AAD speedup: 4.3x vs bump-and-reprice for 5 Greeks.
 * For 50 Greeks: AAD still ~2x pricing; bump-and-reprice ~100x pricing.
 * ```
 */

int main() {}
