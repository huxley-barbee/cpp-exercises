/*
 * ## EXERCISE 8: ODE/PDE — Crank-Nicolson for Black-Scholes [8.a.ii]
 *
 * **Requirements:**
 * 1. Implement the Crank-Nicolson (implicit) scheme for the Black-Scholes PDE
 * 2. At each time step, solve a tridiagonal system `A * V_new = B * V_old`
 * 3. Use the Thomas algorithm (tridiagonal solver) for O(N) solve time
 * 4. Show CN with 50 time steps achieves better accuracy than explicit with 5000 steps
 * 5. Extend to an American put: apply the early-exercise condition at each step
 * 6. Benchmark: CN vs explicit for a 1000-step spatial grid
 *
 * **Expected output:**
 * ```
 * === Crank-Nicolson vs Explicit ===
 * N_t=50,   N_S=200, CN:        price=$10.451   error=0.001
 * N_t=5000, N_S=200, Explicit:  price=$10.449   error=0.002
 * CN achieves better accuracy with 100x fewer time steps!
 *
 * === American Put (K=100, T=1, sigma=0.3, r=0.05) ===
 * European put: $7.97   American put (CN): $8.43
 * Early exercise premium: $0.46
 *
 * === Benchmark (N_S=1000) ===
 * Explicit (N_t=500000): 8.2s
 * CN       (N_t=100):    0.04s   speedup 205x
 * ```
 */

int main() {}
