/*
 * ## EXERCISE 21: Volatility Models — Local Volatility [8.d.ii–iv]
 *
 * The Dupire local volatility model is the unique complete model consistent
 * with any given European option surface.
 *
 * **Requirements:**
 * 1. Generate a synthetic IV surface using Heston MC (6 maturities × 9 strikes)
 * 2. Implement **Dupire's formula** to extract the local vol surface:
 *    `sigma_loc^2(K,T) = (dC/dT + (r-q)*K*dC/dK + q*C) / (0.5*K^2*dC^2/dK^2)`
 *    using finite differences on the price surface
 * 3. Implement a **local volatility MC pricer**: at each step, look up
 *    `sigma_loc(S_t, t)` from a bilinear-interpolated grid
 * 4. Verify that local vol MC reprices the input European options exactly
 * 5. Price a **forward-start option** under local vol and compare to Black-Scholes
 * 6. Show that local vol skew is approximately twice the implied vol skew
 * 7. Implement **Andreasen-Huge** single-step interpolation as a faster alternative
 *
 * **Expected output:**
 * ```
 * === Local Volatility Surface ===
 * Extracted sigma_loc(S,T) from Heston IV surface
 *
 * Sample local vols (T=1):
 *   S=80:  28.4%  S=90:  22.1%  S=100: 20.0%  S=110: 19.3%  S=120: 20.8%
 *
 * Note: Local vol skew ≈ 2 × implied vol skew  (Dupire's formula)
 *
 * === Local Vol MC Repricing ===
 * Option      Market IV   LV MC price   BS(MktIV)   Error
 * ATM T=1Y    20.0%       $10.449       $10.451     0.002  PASS
 * 25d put T=1Y 21.5%       $6.248        $6.251     0.003  PASS
 *
 * === Forward-Start Option (set in 6M, maturity 1Y) ===
 * LV MC:    $4.821  (captures vol smile, forward vol smile differs from spot)
 * BS (flat): $5.023  (overestimates: flat vol ignores skew dynamics)
 * ```
 */

int main() {}
