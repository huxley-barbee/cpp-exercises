/*
 * ## EXERCISE 7: ODE/PDE — Black-Scholes PDE by Explicit Finite Differences [8.a.ii]
 *
 * **Requirements:**
 * 1. Solve the Black-Scholes PDE for a European call using explicit Euler in time.
 *    Terminal condition: `V(S,T) = max(S-K, 0)`
 * 2. Parameters: `S_max=300, K=100, T=1, sigma=0.2, r=0.05`
 * 3. Grid: `N_S=200` asset steps, `N_t=5000` time steps
 * 4. Compare to the Black-Scholes analytic formula
 * 5. Show the stability condition and demonstrate an unstable run (`dt` too large)
 * 6. Implement the boundary conditions: `V(0,t)=0`, `V(S_max,t)=S_max-K*exp(-r*(T-t))`
 *
 * **Expected output:**
 * ```
 * === Black-Scholes PDE (Explicit FD) ===
 * Results at S=100 (ATM):
 *   Analytic BS: $10.451
 *   Explicit FD: $10.449   error=0.002
 *
 * === Stability ===
 * Stable   (dt=2e-4): price=$10.449   PASS
 * Unstable (dt=1e-3): price=NaN/blowup  FAIL (CFL violated)
 *
 * CFL condition: dt <= dS^2 / (sigma^2 * S_max^2) = 1.25e-4
 * ```
 */

int main() {}
