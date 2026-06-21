/*
 * ## EXERCISE 5: Adding Tests — Seam-Based Testing [7.a.ii]
 *
 * A **seam** is a place where you can alter behaviour without modifying the source.
 * The classic C++ seams are: virtual function seam, preprocessor seam, link seam.
 *
 * **Requirements:**
 * 1. Given a legacy class that calls a hardcoded `extern "C"` market-data function:
 *    ```cpp
 *    extern "C" double get_market_price(const char* sym); // from libmds.so
 *    class Valuation {
 *    public:
 *        double value(const char* sym, int qty) {
 *            return get_market_price(sym) * qty;
 *        }
 *    };
 *    ```
 * 2. Demonstrate the **link seam**: provide a fake `get_market_price` in the test
 *    binary that returns controlled values — without changing `valuation.cpp`
 * 3. Demonstrate the **virtual seam**: extract a `IMarketPrice` interface, inject it,
 *    use a mock in tests
 * 4. Demonstrate the **preprocessor seam**: `#define get_market_price test_get_price`
 *    in a test-only compile (show why this is fragile but sometimes necessary)
 * 5. Rank the three seam types by safety and maintainability
 * 6. Show a test for each seam type, all producing correct results
 *
 * **Expected output:**
 * ```
 * === Link Seam ===
 * // test_main.cpp provides its own get_market_price
 * extern "C" double get_market_price(const char* sym) {
 *     return sym[0]=='A' ? 150.0 : 100.0;  // test stub
 * }
 * Valuation v; double result = v.value("AAPL", 10);
 * Expected: 1500.0  Got: 1500.0  PASS
 *
 * === Virtual Seam ===
 * MockMarketPrice mock; mock.setPrice("AAPL", 150.0);
 * Valuation v(mock); double result = v.value("AAPL", 10);
 * Expected: 1500.0  Got: 1500.0  PASS
 *
 * === Preprocessor Seam ===
 * #define get_market_price test_get_price  (test-only header)
 * Expected: 1500.0  Got: 1500.0  PASS (fragile — avoid if possible)
 *
 * === Seam Ranking ===
 * 1. Virtual seam:      safest, most maintainable, refactoring-friendly
 * 2. Link seam:         no source changes, but requires separate test binary
 * 3. Preprocessor seam: last resort — brittle, hides real dependencies
 * ```
 */

int main() {}
