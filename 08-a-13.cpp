/*
 * ## EXERCISE 13: Optimization — Constrained Optimization [8.a.iii]
 *
 * **Requirements:**
 * 1. Implement projected gradient descent for box-constrained problems
 * 2. Solve the Markowitz mean-variance portfolio problem:
 *    minimise `w^T Sigma w` s.t. `w^T mu = mu_target`, `sum(w)=1`, `w >= 0`
 * 3. Implement a simple active-set method for the portfolio problem
 * 4. Trace the efficient frontier: solve for 50 target returns
 * 5. Show the two-fund separation theorem
 * 6. Add a cardinality constraint (at most K non-zero weights) using a greedy
 *    heuristic and compare to the unconstrained frontier
 *
 * **Expected output:**
 * ```
 * === Markowitz Portfolio (10 assets) ===
 * Min variance portfolio:
 *   Return: 9.2%   Vol: 11.4%   Sharpe: 0.54
 *
 * Efficient frontier (50 points):
 *   Min vol:    11.4% at return 9.2%
 *   Max Sharpe: vol=14.2%, return=13.1%, Sharpe=0.71
 *   Max return: vol=18.3%, return=15.0%
 *
 * Cardinality K=3: Sharpe=0.68 (vs 0.71 unconstrained, -4%)
 * ```
 */

int main() {}
