/*
 * ## EXERCISE 17: Risk-Neutral Pricing — The Fundamental Theorem [8.d.iv]
 *
 * Implement the two forms of the Fundamental Theorem of Asset Pricing (FTAP)
 * concretely in code.
 *
 * **Requirements:**
 * 1. Build a 3-state, 2-asset model and verify the **First FTAP**:
 *    no arbitrage ⟺ there exists a risk-neutral measure Q
 * 2. Build an **arbitrage-free incomplete market** (more states than assets)
 *    and show multiple Q measures exist
 * 3. Show the **Second FTAP**: the market is complete ⟺ Q is unique
 * 4. Implement pricing of a contingent claim in an incomplete market using
 *    the **superreplication** (min/max pricing bounds)
 * 5. Implement **Arrow-Debreu prices** (state prices) from the Q measure:
 *    `psi_i = q_i / (1+r)` for each state `i`
 * 6. Price 5 different derivatives using Arrow-Debreu prices directly
 * 7. Verify the Arrow-Debreu prices reproduce the initial asset prices
 *
 * **Expected output:**
 * ```
 * === First FTAP: No-Arbitrage Check ===
 * 2 assets, 3 states: S1=(110,100,90), S2=(115,100,85)
 * S1_0=100, S2_0=100, r=5%
 *
 * Solving for Q: 0.35*u + 0.40*m + 0.25*d = 1
 *                Q exists, all positive => no arbitrage  PASS
 *
 * === Arrow-Debreu Prices ===
 * State  Q_prob   AD_price
 * Up     0.350    0.3333
 * Mid    0.400    0.3810
 * Down   0.250    0.2381
 *
 * AD prices sum: 0.9524 = 1/(1+r) = 0.9524  PASS
 *
 * === Derivative Pricing via AD Prices ===
 * Call (K=100): 0.3333*10 + 0.3810*0 + 0.2381*0 = $3.333
 * Put  (K=100): 0.3333*0  + 0.3810*0 + 0.2381*15 = $3.571
 * Straddle:     $3.333 + $3.571 = $6.905
 * ```
 */

int main() {}
