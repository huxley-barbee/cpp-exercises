/*
 * ## EXERCISE 19: Putting It Together — Complete Option Pricing Library [8.d.i–iv]
 *
 * Build a clean, well-structured option pricing library combining all topics.
 *
 * **Requirements:**
 *
 * Design an `OptionPricer` class hierarchy:
 * 1. Base: `IPricer` with `virtual Result price(const Option&, const Market&) = 0`
 * 2. `BSPricer` — analytic Black-Scholes for European options
 * 3. `MCPricer` — Monte Carlo for any payoff
 * 4. `FDPricer` — Crank-Nicolson finite difference
 * 5. `BinomialPricer` — CRR binomial tree
 *
 * `Option` struct:
 * ```cpp
 * struct Option {
 *     enum Type { CALL, PUT };
 *     enum Style { EUROPEAN, AMERICAN, ASIAN, BARRIER };
 *     Type type; Style style;
 *     double K, T, H;  // strike, maturity, barrier
 * };
 *
 * struct Market {
 *     double S, sigma, r, q;
 * };
 * ```
 *
 * Test the library:
 * - European call: all 4 pricers agree to within MC error
 * - American put: MC (LSMC), FD, Binomial agree; BS gives wrong answer
 * - Asian call: MC only; verify with geometric Asian closed form
 * - Down-and-out call: MC + BS analytic agree
 *
 * **Expected output:**
 * ```
 * === Option Pricing Library Test ===
 *
 * European Call (S=100, K=100, T=1, sigma=0.2, r=0.05):
 *   BS:        $10.451
 *   MC:        $10.449 +/- 0.033   diff=0.002  PASS
 *   FD (CN):   $10.449              diff=0.002  PASS
 *   Binomial:  $10.449              diff=0.002  PASS
 *
 * American Put (K=100, T=1, sigma=0.3, r=0.05):
 *   BS (Euro): $7.970   (WRONG for American)
 *   MC (LSMC): $8.435 +/- 0.012
 *   FD (CN):   $8.431               diff=0.004  PASS
 *   Binomial:  $8.432               diff=0.001  PASS
 *
 * Asian Call (K=100, T=1, sigma=0.2, r=0.05):
 *   MC:        $5.863 +/- 0.012
 *   Closed (geo): $5.398  (geometric, not arithmetic — lower bound)
 *
 * Down-and-Out Call (H=90):
 *   BS analytic: $6.242
 *   MC:          $6.263 +/- 0.018  diff=0.021  PASS
 * ```
 */

int main() {}
