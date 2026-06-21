/*
 * ## EXERCISE 13: Comprehensive Integration [All of 7.a]
 *
 * Apply all four refactoring techniques to a realistic legacy `FixedIncomePricer`
 * module and document every step.
 *
 * **Requirements:**
 *
 * Starting point — a C++98 legacy module with all the classic problems:
 * ```cpp
 * // C++98 — everything wrong
 * #include "everything.h"   // pulls in 50 headers
 *
 * extern ConfigStore    g_config;
 * extern MarketDataFeed g_feed;
 * extern AuditLogger    g_audit;
 * extern RiskEngine     g_risk;
 * int g_pricedToday = 0;  // ODR violation — defined in header
 *
 * class FixedIncomePricer {
 * public:
 *     FixedIncomePricer() {   // side effects in ctor
 *         g_config.load();
 *         g_feed.connect("prod:9001");
 *     }
 *
 *     double priceYieldCurve(const char* currency) {
 *         double r = g_feed.getRate(currency);
 *         double s = g_config.getSpread(currency);
 *         g_audit.record("pricing", currency);
 *         double npv = r / (1 + s);
 *         ++g_pricedToday;
 *         g_risk.check(npv);
 *         return npv;
 *     }
 * };
 * ```
 *
 * Apply in order:
 * 1. **Untangle**: extract `IFeed`, `IConfig`, `IAudit`, `IRisk` interfaces;
 *    fix ODR violation; remove side effects from constructor
 * 2. **Add tests**: write characterisation tests of current behaviour;
 *    write 5 unit tests using stubs; verify all pass
 * 3. **Replace globals**: inject all 4 dependencies via `PricerContext` struct;
 *    migrate `g_pricedToday` to an atomic member variable
 * 4. **Modernise**: `NULL`→`nullptr`, raw pointers→`shared_ptr`, C++98 loops→range-for,
 *    manual string handling→`std::string`, add `[[nodiscard]]`, add `noexcept`
 *
 * Show the full before/after diff summary and all tests passing.
 *
 * **Expected output:**
 * ```
 * === FixedIncomePricer Refactoring ===
 *
 * BEFORE: 1 class, 4 globals, 0 tests, 0 interfaces
 * AFTER:  1 class, 0 globals, 8 tests, 4 interfaces
 *
 * === Step 1: Untangle dependencies ===
 * Extracted: IFeed, IConfig, IAudit, IRisk
 * Fixed ODR: g_pricedToday moved to class member
 * Constructor: no more side effects
 *
 * === Step 2: Characterisation tests ===
 * [PASS] records_current_behaviour_currency_USD
 * [PASS] records_current_behaviour_currency_EUR
 * 2 characterisation tests locked in
 *
 * === Step 3: Unit tests with stubs ===
 * [PASS] prices_correctly_with_stub_feed
 * [PASS] logs_audit_event
 * [PASS] increments_priced_today
 * [PASS] risk_check_called
 * [PASS] exception_on_bad_rate
 * 5/5 unit tests passed
 *
 * === Step 4: Replace globals ===
 * PricerContext ctx{stubFeed, stubConfig, stubAudit, stubRisk};
 * FixedIncomePricer pricer(ctx);
 * All 7 tests still pass after injection
 *
 * === Step 5: Modernise ===
 * nullptr, shared_ptr, range-for, string_view, [[nodiscard]], noexcept
 * All 7 tests still pass after modernisation
 *
 * === Summary ===
 * Globals removed:    4
 * Interfaces added:   4
 * Tests added:        7
 * LOC changed:       ~85 (out of 120 original)
 * Breaking changes:   0  (all callers compile with injected ctor)
 * ```
 *
 * ---
 *
 * ## Notes on Running the Exercises
 *
 * ```bash
 * # Standard build
 * g++ -std=c++17 -O0 -g -Wall -Wextra exercise.cpp -o exercise
 *
 * # AddressSanitizer (catch memory errors introduced by refactoring)
 * g++ -std=c++17 -fsanitize=address,undefined -g exercise.cpp -o exercise
 *
 * # ThreadSanitizer (for exercises involving atomic globals)
 * g++ -std=c++17 -fsanitize=thread -g exercise.cpp -o exercise
 *
 * # Clang-tidy: identify remaining legacy patterns
 * clang-tidy exercise.cpp --checks='modernize-*,cppcoreguidelines-*' \
 *     -- -std=c++17
 *
 * # Include-what-you-use: find unnecessary includes
 * include-what-you-use exercise.cpp -- -std=c++17
 *
 * # Verify no ODR violations
 * g++ -std=c++17 -fno-common exercise.cpp -o exercise
 *
 * # Check for unused globals (link-time)
 * g++ -std=c++17 -Wunused -fdata-sections -ffunction-sections \
 *     -Wl,--gc-sections exercise.cpp -o exercise
 * ```
 */

int main() {}
