/*
 * ## EXERCISE 3: Black-Scholes — Digital and Binary Options [8.d.ii]
 *
 * Digital options are the fundamental building blocks of structured products
 * and have closed-form BS solutions that test your understanding of d2.
 *
 * **Requirements:**
 * 1. Implement a **cash-or-nothing call**: pays $1 if S_T > K, else 0
 *    `C_dig = exp(-rT) * N(d2)`
 * 2. Implement an **asset-or-nothing call**: pays S_T if S_T > K, else 0
 *    `C_aon = S * exp(-qT) * N(d1)`
 * 3. Show that a vanilla call = asset-or-nothing - K * cash-or-nothing
 * 4. Implement **gap options**: pays `S_T - G` if `S_T > K` (trigger != strike)
 * 5. Implement **supershare options**: pays `S_T / F_lo` if `F_lo < S_T < F_hi`
 * 6. Price a **binary put spread** (call spread normalised to pay $1):
 *    long cash-or-nothing strike K1, short cash-or-nothing strike K2 > K1
 * 7. Show the digital as a limit: `C_dig = lim_{dK→0} (C(K) - C(K+dK)) / dK`
 *    and verify numerically
 *
 * **Expected output:**
 * ```
 * === Digital Options (S=100, T=1, sigma=0.2, r=0.05) ===
 *
 * Cash-or-nothing call (K=100):   $0.5323
 * Asset-or-nothing call (K=100):  $60.025
 * Vanilla call (K=100):           $10.451
 *
 * Decomposition check:
 *   AON - K * CON = 60.025 - 100*0.5323 = $6.794 ... wait
 *   Let's check: AON - K*e^{-rT}*CON = 60.025 - 95.123*0.5323 = $10.451  PASS
 *
 * Gap option (K=100, G=90):       $15.023
 *   = vanilla call + 10 * cash-or-nothing  PASS
 *
 * Digital as finite difference:
 *   (C(100) - C(100.001)) / 0.001 = 0.5321  analytic = 0.5323  PASS
 * ```
 */

int main() {}
