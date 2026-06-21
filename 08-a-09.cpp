/*
 * ## EXERCISE 9: ODE/PDE — Heat Equation and ADI Methods [8.a.ii]
 *
 * **Requirements:**
 * 1. Solve the 2D heat equation on a unit square:
 *    `du/dt = kappa*(d^2u/dx^2 + d^2u/dy^2)`
 *    Initial condition: `u(x,y,0) = sin(pi*x)*sin(pi*y)`
 * 2. Implement the ADI (Alternating Direction Implicit) scheme (Peaceman-Rachford)
 * 3. Compare ADI to naive 2D explicit scheme for stability and performance
 * 4. Use the exact solution `u(x,y,t) = exp(-2*pi^2*kappa*t)*sin(pi*x)*sin(pi*y)`
 * 5. Show operator splitting: each ADI half-step solves a 1D tridiagonal problem
 * 6. State how ADI extends to two-asset Black-Scholes
 *
 * **Expected output:**
 * ```
 * === 2D Heat Equation (50x50 grid) ===
 * kappa=0.1, T=0.5
 *
 * ADI      (N_t=50 steps):   error=4.2e-6
 * Explicit (N_t=5000 steps): error=1.1e-5
 *
 * ADI is 100x faster for the same spatial resolution.
 *
 * Operator splitting: each half-step is O(N) tridiagonal solve.
 * Full 2D implicit would require O(N^2) system — infeasible for large grids.
 * ```
 */

int main() {}
