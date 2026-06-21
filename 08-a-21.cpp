/*
 * ## EXERCISE 21: Monte Carlo Greeks [8.a.iv]
 *
 * **Requirements:**
 * 1. Compute MC Greeks using three methods: bump-and-reprice, pathwise (IPA),
 *    and likelihood ratio (score function)
 * 2. For a European call, implement:
 *    - Pathwise delta: `E[e^{-rT} * 1_{S_T>K} * S_T/S_0]`
 *    - LR delta: `E[payoff * Z / (S0*sigma*sqrt(T))]`
 * 3. Compare variance of each estimator (1M paths)
 * 4. Apply pathwise delta to an Asian call: derive the estimator
 * 5. Show LR vega: `E[payoff * (Z^2-1)/sigma - Z*sqrt(T)]`
 * 6. Describe AAD: how it computes all Greeks in one backward pass at ~3x pricing cost
 *
 * **Expected output:**
 * ```
 * === MC Greeks (European Call, 1M paths) ===
 * Method           Delta   Std Error   Time
 * Bump-and-reprice 0.6370  0.0003      0.24s
 * Pathwise (IPA)   0.6368  0.0001      0.12s  (3x lower variance)
 * Likelihood ratio 0.6369  0.0012      0.12s
 *
 * === Asian Call Pathwise Delta ===
 * MC Delta: 0.5821 +/- 0.0001
 *
 * === AAD Concept ===
 * Forward pass stores computational tape.
 * Backward pass computes all sensitivities at O(1) * forward cost.
 * ```
 */

int main() {}
