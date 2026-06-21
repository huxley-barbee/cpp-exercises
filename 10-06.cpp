/*
 * ## EXERCISE 6: Diagnose Memory Corruption — Valgrind and Memory Leak Hunting [10.c]
 *
 * Use Valgrind Memcheck to find and fix three categories of leak common in
 * legacy quant code.
 *
 * **Requirements:**
 *
 * **Leak category 1 — Conditional leak** (memory allocated in one branch, not freed in another):
 * ```cpp
 * double* computeGreeks(double S, double K, double T, double sigma) {
 *     double* greeks = new double[5]; // delta, gamma, vega, theta, rho
 *     if (T <= 0) return nullptr;     // BUG: leaks 'greeks' if T<=0
 *     // ... compute greeks ...
 *     return greeks;
 * }
 * ```
 *
 * **Leak category 2 — Exception leak** (memory allocated before a throw):
 * ```cpp
 * void loadCurve(const char* filename) {
 *     double* rates = new double[100];
 *     FILE* f = fopen(filename, "r");
 *     if (!f) throw std::runtime_error("file not found"); // leaks 'rates'
 *     // ... load rates ...
 *     delete[] rates;
 * }
 * ```
 *
 * **Leak category 3 — Ownership confusion** (shared raw pointer, deleted twice):
 * ```cpp
 * double* shared_curve = new double[50];
 * RiskEngine risk(shared_curve);   // stores raw ptr, does NOT delete
 * PricingEngine pricing(shared_curve); // also stores raw ptr
 * // ... at shutdown: both engines delete shared_curve -> double free
 * ```
 *
 * For each: run Valgrind, show the output, fix using RAII.
 *
 * **Expected output:**
 * ```
 * === Valgrind: Conditional Leak ===
 * ==PID== 40 bytes in 1 blocks are definitely lost
 * ==PID==    at 0x...: operator new[](unsigned long)
 * ==PID==    by 0x...: computeGreeks(...)
 * Fix: delete[] greeks before returning nullptr; or use unique_ptr
 *
 * === Valgrind: Exception Leak ===
 * ==PID== 800 bytes in 1 blocks are definitely lost
 * Fix: RAII -> unique_ptr<double[]> rates(new double[100])
 *
 * === Valgrind: Double-Free ===
 * ==PID== Invalid free() / delete / delete[]
 * Fix: std::shared_ptr<double[]> with both engines sharing ownership
 *
 * After all fixes: ERROR SUMMARY: 0 errors  PASS
 * ```
 */

int main() {}
