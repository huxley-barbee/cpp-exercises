/*
 * ## EXERCISE 11: Incremental Modernisation — Extracting and Testing a Pure Core [7.a.iv]
 *
 * The safest refactoring of all: identify the pure mathematical core of a legacy
 * function, extract it, and test it independently.
 *
 * **Requirements:**
 *
 * The legacy function mixes computation with I/O and global state:
 * ```cpp
 * double LegacyRiskEngine::computeVaR(const char* portfolio_id) {
 *     // Load from database (I/O)
 *     Position* positions = g_db.loadPositions(portfolio_id);
 *     int n = g_db.positionCount(portfolio_id);
 *
 *     // Fetch prices (network I/O)
 *     double* prices = new double[n];
 *     for (int i = 0; i < n; i++)
 *         prices[i] = g_feed.getPrice(positions[i].symbol);
 *
 *     // The pure computation (what we actually care about)
 *     double sum_sq = 0.0;
 *     for (int i = 0; i < n; i++)
 *         sum_sq += positions[i].qty * positions[i].qty
 *                   * prices[i] * prices[i] * g_config.volatility;
 *     double var = sqrt(sum_sq) * 1.645;  // 95% VaR
 *
 *     delete[] prices;
 *     g_logger.log("VaR for %s: %.2f", portfolio_id, var);
 *     return var;
 * }
 * ```
 *
 * 1. Identify and extract the pure core into a free function:
 *    `double computeVaR(const Position* pos, const double* prices, int n, double vol)`
 * 2. Write comprehensive tests for the pure function — no mocks needed
 * 3. Rewrite `LegacyRiskEngine::computeVaR` to call the pure function (behaviour unchanged)
 * 4. Show the test coverage the pure function now has vs the original zero coverage
 * 5. Demonstrate the **Humble Object** pattern: all testable logic in the pure core,
 *    the legacy wrapper just orchestrates I/O
 *
 * **Expected output:**
 * ```
 * === Pure Core Extraction ===
 *
 * Extracted: double computeVaR(const Position* pos,
 *                               const double* prices,
 *                               int n, double vol)
 *
 * Tests for pure function (no I/O, no mocks):
 * [PASS] single_position_var
 * [PASS] zero_quantity
 * [PASS] multi_position_var
 * [PASS] high_volatility
 * [PASS] var_scales_with_sqrt_n  (diversification)
 * 5/5 tests passed
 *
 * LegacyRiskEngine::computeVaR now delegates to pure function.
 * Behaviour unchanged (characterisation tests still pass).
 *
 * Coverage before extraction: 0% (untestable)
 * Coverage after extraction:  100% of pure core
 * ```
 */

int main() {}
