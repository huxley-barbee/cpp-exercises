/*
 * ## EXERCISE 4: Black-Scholes — Barrier Options [8.d.ii]
 *
 * Barrier options are among the most common exotic derivatives. They have
 * closed-form solutions under BS that require careful case analysis.
 *
 * **Requirements:**
 * 1. Implement the four vanilla barrier types for a **down-and-out call**:
 *    `C_dao = C_vanilla - C_di` where the down-and-in call uses the reflection principle
 * 2. Use the BS barrier formula:
 *    `C_di = S*exp(-qT)*(H/S)^(2*lambda) * N(y) - K*exp(-rT)*(H/S)^(2*lambda-2) * N(y - sigma*sqrt(T))`
 *    where `lambda = (r - q + 0.5*sigma^2) / sigma^2`, `y = log(H^2/(S*K))/(sigma*sqrt(T)) + lambda*sigma*sqrt(T)`
 * 3. Implement all 8 types: {call/put} × {up/down} × {in/out}
 * 4. Verify in-out parity: `C_in + C_out = C_vanilla` for each type
 * 5. Show the **barrier delta discontinuity**: compute delta near the barrier
 *    (the large delta spike that makes these hard to hedge)
 * 6. Price a **double barrier option** (knock out if S touches either barrier)
 *    using the series expansion
 *
 * **Expected output:**
 * ```
 * === Barrier Options (S=100, K=100, T=1, sigma=0.2, r=0.05) ===
 *
 * Barrier H=90 (below current spot):
 *   Vanilla call:         $10.451
 *   Down-and-in call:     $ 4.209
 *   Down-and-out call:    $ 6.242
 *   In + Out check:       $10.451  PASS
 *
 * Barrier H=110 (above current spot):
 *   Up-and-in call:       $ 9.341
 *   Up-and-out call:      $ 1.110
 *   In + Out check:       $10.451  PASS
 *
 * === Barrier delta near H=90 ===
 *   S=91: delta=0.651  S=90: delta=0.921  S=89: delta=-0.134
 *   (large delta spike at barrier — difficult to hedge)
 * ```
 */

int main() {}
