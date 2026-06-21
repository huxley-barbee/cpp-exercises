/*
 * ## EXERCISE 13: Greeks — Pathwise (IPA) and Likelihood Ratio [8.d.iii]
 *
 * The two main Monte Carlo Greek methods: pathwise differentiation and the
 * likelihood ratio method. Each has different applicability and variance properties.
 *
 * **Requirements:**
 * 1. Implement **pathwise delta** for a European call:
 *    `delta = E[exp(-rT) * 1_{S_T > K} * S_T / S_0]`
 * 2. Implement **pathwise vega**:
 *    `vega = E[exp(-rT) * 1_{S_T > K} * S_T * (Z*sqrt(T) - sigma*T)]`
 *    where `Z` is the standard normal draw
 * 3. Implement **LR (score function) delta**:
 *    `delta = E[payoff * Z / (S0 * sigma * sqrt(T))]`
 * 4. Compare variance: pathwise vs LR for delta (1M paths)
 * 5. Apply pathwise delta to a **knockout barrier call** — show it fails
 *    (payoff is discontinuous, IPA does not apply)
 * 6. Apply LR delta to the knockout barrier — show it works
 * 7. Implement **pathwise Asian delta**:
 *    `delta = E[exp(-rT) * 1_{avg > K} * avg_derivative]` where
 *    `avg_derivative = (1/N)*sum(S_t_i / S_0)`
 *
 * **Expected output:**
 * ```
 * === MC Greeks (European Call, 1M paths) ===
 *
 *               Estimate   Std Error   Time
 * Analytic       0.6368     —          0ms
 * Pathwise IPA   0.6368     0.0001     0.12s  (3x lower var than LR)
 * LR delta       0.6370     0.0004     0.12s
 * Bump+reprice   0.6370     0.0003     0.24s  (2 MC runs)
 *
 * === Knockout Barrier Delta (H=90) ===
 * Pathwise IPA: 0.4823  (WRONG — payoff discontinuous at barrier)
 * LR method:    0.5831  (correct — score function handles discontinuity)
 * FD bumped MC: 0.5836  (correct but high variance, 2x cost)
 *
 * === Asian Call Pathwise Delta ===
 * Estimator: E[exp(-rT) * 1_{avg>K} * (1/M)*sum(S_ti/S0)]
 * Delta: 0.4721 +/- 0.0001
 * ```
 */

int main() {}
