/*
 * ## EXERCISE 16: Risk-Neutral Pricing — Change of Measure [8.d.iv]
 *
 * The change of measure (Girsanov's theorem) is the mathematical foundation
 * of risk-neutral pricing. Implement it concretely.
 *
 * **Requirements:**
 * 1. Simulate stock prices under the **physical (real-world) measure P**:
 *    `dS = mu*S*dt + sigma*S*dW_P`, `mu = 0.12`, `sigma = 0.20`
 * 2. Show that the discounted expected stock price under P is not a martingale:
 *    `E_P[S_T * exp(-r*T)] ≠ S_0`
 * 3. Apply the **Girsanov kernel**: `dW_Q = dW_P + theta*dt` where `theta = (mu-r)/sigma`
 *    (the market price of risk)
 * 4. Show that under Q, `dS = r*S*dt + sigma*S*dW_Q` — drift becomes r
 * 5. Verify that under Q, `E_Q[exp(-r*T)*S_T] = S_0` (discounted stock is a martingale)
 * 6. Show the Radon-Nikodym derivative: `dQ/dP = exp(-theta*W_T - 0.5*theta^2*T)`
 * 7. Price a call under P using importance sampling with the RN derivative,
 *    and verify you get the same answer as pricing under Q directly
 *
 * **Expected output:**
 * ```
 * === Change of Measure Demonstration ===
 * mu=0.12, sigma=0.20, r=0.05, T=1, S0=100, N=1M paths
 *
 * Under P (physical measure):
 *   E_P[S_T]:            $112.75  (exp(mu*T)*S0 = $112.75)
 *   E_P[exp(-rT)*S_T]:   $107.36  ≠ S0=100  (NOT a martingale)
 *
 * Under Q (risk-neutral measure, theta = (0.12-0.05)/0.20 = 0.35):
 *   E_Q[S_T]:            $105.13  (= exp(r*T)*S0)
 *   E_Q[exp(-rT)*S_T]:   $100.00  = S0  MARTINGALE VERIFIED
 *
 * Radon-Nikodym pricing:
 *   E_P[exp(-rT)*C(S_T) * dQ/dP] = $10.449  (matches Q pricing: $10.451)  PASS
 * ```
 */

int main() {}
