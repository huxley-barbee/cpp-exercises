/*
 * ## EXERCISE 15: Risk-Neutral Pricing — Replication and No-Arbitrage [8.d.iv]
 *
 * Build the risk-neutral pricing framework from first principles on a binomial tree.
 *
 * **Requirements:**
 * 1. Implement a **one-step binomial tree** and price a call option by replication
 * 2. Show that the risk-neutral probability `q = (exp(r*dt) - d) / (u - d)`
 *    does not depend on investor risk preferences (risk-neutral argument)
 * 3. Implement a general **N-step binomial tree** (CRR parametrisation:
 *    `u = exp(sigma*sqrt(dt))`, `d = 1/u`)
 * 4. Price European call and put — show convergence to BS as N → ∞
 * 5. Price an **American put** on the binomial tree using backward induction
 *    with early exercise check at each node
 * 6. Implement the **Greeks from the tree**: delta = (Vu - Vd) / (Su - Sd) at t=0
 * 7. Show **put-call parity** holds on the tree for European options
 *
 * **Expected output:**
 * ```
 * === One-Step Binomial Replication ===
 * S=100, K=100, u=1.1, d=0.9, r=5%, T=1
 *   Risk-neutral q: 0.7564
 *   Replication portfolio: Delta=0.250, Bond=-$21.81
 *   Option price: $3.193  (replication matches risk-neutral pricing: PASS)
 *
 * === N-Step Tree Convergence to BS ===
 * N=10:   call=$10.248  error=0.203
 * N=50:   call=$10.421  error=0.030
 * N=100:  call=$10.436  error=0.015
 * N=1000: call=$10.449  error=0.002
 *
 * BS analytic: $10.451
 *
 * === American Put (K=100, T=1, sigma=0.2, r=0.05) ===
 * N=1000: American put=$6.085  European put=$5.574  EE premium=$0.511
 * ```
 */

int main() {}
