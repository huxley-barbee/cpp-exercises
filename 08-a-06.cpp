/*
 * ## EXERCISE 6: ODE/PDE — Euler and Runge-Kutta Methods [8.a.ii]
 *
 * **Requirements:**
 * 1. Solve `dS/dt = mu * S`, `S(0) = 100`, `mu = 0.10`, `T = 1.0`
 * 2. Implement Forward Euler, RK2 (Heun), RK4
 * 3. Compare to exact solution `S(T) = S0 * exp(mu*T)` at `h = 0.1`
 * 4. Show convergence: halve step size 6 times, confirm orders 1, 2, 4 from slopes
 * 5. Implement the Lorenz attractor using RK4
 * 6. Show sensitivity to initial conditions: perturb `x0` by 1e-8, compare at t=20
 *
 * **Expected output:**
 * ```
 * === GBM ODE (S(1) exact = 110.5171) ===
 * h=0.1:
 *   Euler: error=5.5e-2   RK2: error=2.4e-4   RK4: error=3.1e-8
 *
 * Convergence order:
 *   Euler: 1.00   RK2: 2.00   RK4: 4.00
 *
 * === Lorenz (RK4, dt=0.01, T=20) ===
 * Trajectory 1: x(20) =  8.723
 * Trajectory 2: x(20) = -4.218  (diverged from 1e-8 perturbation)
 * ```
 */

int main() {}
