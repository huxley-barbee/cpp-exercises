/*
 * ## EXERCISE 11: Optimization — Newton's Method and Root Finding [8.a.iii]
 *
 * **Requirements:**
 * 1. Implement Newton's method for scalar root finding: `f(x) = 0`
 * 2. Apply to find the implied volatility from a Black-Scholes call price
 * 3. Implement Brent's method as a robust fallback (no derivative needed)
 * 4. Compare convergence: Newton (quadratic), bisection (linear), Brent (superlinear)
 * 5. Show Newton's failure: derivative near zero or poor initial guess
 * 6. Implement Halley's method (cubic convergence) using the second derivative
 * 7. Benchmark: 10,000 implied vol calculations using each method
 *
 * **Expected output:**
 * ```
 * === Implied Volatility Solver ===
 * Market price: $10.45  True IV: 0.2000
 *
 * Newton:    converged in 4 iterations
 * Brent:     converged in 8 iterations
 * Halley:    converged in 3 iterations  (cubic convergence)
 * Bisection: converged in 42 iterations
 *
 * === Benchmark (10K IV calcs) ===
 * Newton:  18ms  (avg 3.1 iter)
 * Halley:  16ms  (avg 2.3 iter)
 * Brent:   28ms  (avg 5.2 iter)
 * ```
 */

int main() {}
