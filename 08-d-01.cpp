/*
 * ## EXERCISE 1: Black-Scholes — Analytic Formula from First Principles [8.d.ii]
 *
 * Derive and implement the Black-Scholes formula without using any library functions
 * beyond `std::log`, `std::exp`, `std::sqrt`, and `std::erfc`.
 *
 * **Requirements:**
 * 1. Implement `normCDF(x)` using `std::erfc`: `N(x) = 0.5 * erfc(-x / sqrt(2))`
 * 2. Implement `normPDF(x)` = `exp(-x^2/2) / sqrt(2*pi)`
 * 3. Implement `bsCall(S, K, T, sigma, r, q)` where `q` is the continuous dividend yield
 * 4. Implement `bsPut` using put-call parity: `P = C - S*exp(-q*T) + K*exp(-r*T)`
 * 5. Verify put-call parity numerically for 10 different (S, K) pairs
 * 6. Implement the **forward price** form: `F = S*exp((r-q)*T)`, express d1/d2 in terms of F
 * 7. Identify the four degenerate cases: `T=0`, `sigma=0`, `K=0`, `S=0` — handle all gracefully
 * 8. Print a 5×5 price grid: S ∈ {80,90,100,110,120}, K ∈ {90,95,100,105,110}
 *
 * **Expected output:**
 * ```
 * === Black-Scholes Call Prices (T=1, sigma=0.2, r=0.05, q=0) ===
 *
 *         K=90     K=95    K=100   K=105   K=110
 * S= 80:  3.355    2.009    1.161    0.647    0.348
 * S= 90: 10.074    6.876    4.526    2.875    1.764
 * S=100: 19.099   14.231   10.451    7.474    5.193
 * S=110: 29.362   23.414   18.286   13.990   10.462
 * S=120: 40.231   33.549   27.440   21.992   17.263
 *
 * Put-call parity check (10 pairs): max error = 2.84e-14  PASS
 *
 * Degenerate cases:
 *   T=0, S=100, K=100: C=0.000 (expired ATM)
 *   T=0, S=110, K=100: C=10.000 (expired ITM)
 *   sigma=0, S=100, K=90, r=0.05: C=14.757 (deterministic)
 * ```
 */

int main() {}
