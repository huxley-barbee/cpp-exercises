/*
 * ## EXERCISE 12: Comprehensive Diagnostics — Bug Hunt [7.b.i–iv]
 *
 * A legacy `PortfolioValuation` module has three bugs. Use the full diagnostics
 * toolkit to find and fix all three.
 *
 * **Requirements:**
 *
 * ```cpp
 * // portfolio_valuation.cpp — contains 3 bugs
 * #include <cstring>
 * #include <cmath>
 * #include <cstdio>
 *
 * struct Position { char symbol[8]; int qty; double price; };
 *
 * class PortfolioValuation {
 *     Position* positions_;
 *     int count_;
 *     double* weights_;
 *
 * public:
 *     PortfolioValuation(int maxPositions)
 *         : count_(0) {
 *         positions_ = new Position[maxPositions];
 *         weights_   = new double[maxPositions];
 *         // BUG 1: weights_ is not initialised — uninitialised read later
 *     }
 *
 *     void addPosition(const char* sym, int qty, double price) {
 *         Position& p = positions_[count_++];
 *         strncpy(p.symbol, sym, 8);
 *         // BUG 2: if sym is exactly 8 chars, no null terminator written
 *         p.qty   = qty;
 *         p.price = price;
 *     }
 *
 *     double computeWeightedReturn(double* returns, int n) {
 *         double total = 0.0;
 *         for (int i = 0; i < n; ++i)
 *             total += weights_[i] * returns[i]; // reads uninitialised weights_
 *         return total;
 *     }
 *
 *     ~PortfolioValuation() {
 *         delete[] positions_;
 *         // BUG 3: weights_ is never deleted — memory leak
 *     }
 * };
 * ```
 *
 * 1. Run under Valgrind — show it catches bugs 1 and 3
 * 2. Run under ASAN — show it catches bugs 1 and 2
 * 3. Run under UBSAN — show any additional issues
 * 4. Use gdb to manually inspect the uninitialised memory
 * 5. Fix all three bugs and show clean runs under all three tools
 * 6. Write two regression tests that would catch these bugs in future
 *
 * **Expected output:**
 * ```
 * === Valgrind output ===
 * ==PID== Conditional jump depends on uninitialised value  (Bug 1)
 * ==PID== definitely lost: 800 bytes in 1 blocks           (Bug 3)
 *
 * === ASAN output ===
 * ERROR: AddressSanitizer: use-of-uninitialized-value         (Bug 1)
 * (Bug 2 may require a string comparison to manifest)
 *
 * === After fixes ===
 * Valgrind: 0 errors, 0 leaks
 * ASAN:     0 errors
 * Tests:    2/2 passed
 * ```
 */

int main() {}
