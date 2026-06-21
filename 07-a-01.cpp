/*
 * ## EXERCISE 1: Untangling Dependencies — Recognising Dependency Smells [7.a.i]
 *
 * Before you can untangle dependencies you must be able to identify them.
 *
 * **Requirements:**
 *
 * Study the following legacy pricing system sketch and identify every dependency smell:
 *
 * ```cpp
 * // legacy_pricer.h  (C++98 style)
 * #include <cmath>
 * #include <cstdio>
 * #include "global_config.h"      // pulls in everything
 * #include "market_data_feed.h"   // opens a socket in its constructor!
 * #include "logger.h"             // writes to a hardcoded file path
 *
 * class BondPricer {
 * public:
 *     BondPricer() {
 *         g_logger.open("/var/log/pricer.log");    // global logger
 *         g_feed.connect("prod-mds:9000");         // global market data feed
 *         g_config.load("/etc/pricer.conf");       // global config
 *     }
 *
 *     double price(const char* symbol) {
 *         double yield = g_feed.getYield(symbol);   // hidden dependency
 *         double spread = g_config.getSpread();      // hidden dependency
 *         double result = computeNPV(yield, spread);
 *         g_logger.log("Priced %s: %.4f", symbol, result);
 *         return result;
 *     }
 *
 * private:
 *     double computeNPV(double yield, double spread);
 * };
 * ```
 *
 * 1. List every dependency smell with a one-line explanation of why it is harmful
 * 2. Draw the dependency graph (ASCII) showing what `BondPricer` actually depends on
 * 3. Identify which dependencies are **necessary** (the computation itself) and which
 *    are **accidental** (infrastructure wired in at construction time)
 * 4. Write the ideal dependency graph after refactoring (ASCII) — `BondPricer` should
 *    depend only on abstract interfaces, not concrete infrastructure
 * 5. List the steps required to get from the current graph to the ideal graph without
 *    breaking any existing callers
 *
 * **Expected output:**
 * ```
 * === Dependency Smells Found ===
 * 1. Global logger (g_logger):   hidden write side-effect; untestable
 * 2. Global feed (g_feed):       network I/O in constructor; cannot unit-test
 * 3. Global config (g_config):   hardcoded file path; environment-dependent
 * 4. Concrete header includes:   including market_data_feed.h forces socket code
 *                                 into every translation unit that includes pricer.h
 * 5. Side effects in constructor: constructor opens files, connects to network —
 *                                 object construction can fail silently
 *
 * === Current Dependency Graph ===
 * BondPricer
 *   ├── g_logger      (global, writes to /var/log/pricer.log)
 *   ├── g_feed        (global, opens socket to prod-mds:9000)
 *   ├── g_config      (global, reads /etc/pricer.conf)
 *   └── computeNPV()  (pure computation — the only necessary dependency)
 *
 * === Ideal Dependency Graph ===
 * BondPricer
 *   ├── IYieldSource  (interface: getYield(symbol))
 *   ├── ISpreadSource (interface: getSpread())
 *   └── ILogger       (interface: log(msg))
 *   (computeNPV is a free function or static method — no state needed)
 *
 * === Refactoring Steps ===
 * Step 1: Extract interfaces IYieldSource, ISpreadSource, ILogger
 * Step 2: Inject via constructor parameters (not globals)
 * Step 3: Move computeNPV to a free function
 * Step 4: Remove side effects from constructor
 * Step 5: Replace global usages with injected implementations
 * ```
 */

int main() {}
