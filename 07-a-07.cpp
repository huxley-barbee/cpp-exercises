/*
 * ## EXERCISE 7: Replacing Globals — Inventory and Impact Analysis [7.a.iii]
 *
 * Before replacing a global you must understand every caller.
 *
 * **Requirements:**
 *
 * Given this header full of globals (typical of legacy C++98 quant code):
 * ```cpp
 * // globals.h
 * extern int         g_maxPositions;
 * extern double      g_riskFreeRate;
 * extern char        g_configPath[256];
 * extern Logger*     g_logger;
 * extern PriceFeed*  g_feed;
 * extern RiskEngine* g_engine;
 * bool g_marketOpen = false;    // definition in header — ODR violation!
 * ```
 *
 * 1. Identify every problem with each global:
 *    - ODR violation (`bool g_marketOpen` defined in header)
 *    - Non-const globals with hidden mutation
 *    - Raw owning pointer (`Logger*`) — who deletes it?
 *    - Implicit initialisation order dependency
 * 2. Enumerate 5 different code sites that would need to change for each global replaced
 * 3. Show a dependency map: which globals depend on which other globals at init time
 * 4. Prioritise the replacement order: which globals are safest to replace first?
 * 5. Write a **before** and **after** sketch for replacing `g_riskFreeRate` with an
 *    injected parameter — the smallest, safest first step
 *
 * **Expected output:**
 * ```
 * === Global Inventory ===
 *
 * g_maxPositions:  int, mutable, read by 12 sites, written by 3 — replace with config struct
 * g_riskFreeRate:  double, read by 28 sites, written by 1 — safest to replace first (pure value)
 * g_configPath:    char[256], read at startup only — replace with constructor parameter
 * g_logger:        Logger*, raw owning pointer, 47 call sites — replace last (most disruption)
 * g_feed:          PriceFeed*, raw owning pointer, depends on g_configPath at init
 * g_engine:        RiskEngine*, depends on g_feed — replace after g_feed
 * g_marketOpen:    bool, ODR VIOLATION — must fix immediately
 *
 * === Replacement Priority ===
 * 1. Fix ODR violation (g_marketOpen) — zero-risk mechanical fix
 * 2. Replace g_riskFreeRate — pure value, few mutations, easy to inject
 * 3. Replace g_configPath — startup only, easy to thread through
 * 4. Replace g_maxPositions — small scope
 * 5. Replace g_feed — needs interface extraction first
 * 6. Replace g_engine — depends on g_feed replacement
 * 7. Replace g_logger — most callers, do last
 *
 * === g_riskFreeRate: before/after ===
 * BEFORE: double price = bondPrice(par, g_riskFreeRate, years);
 * AFTER:  double price = bondPrice(par, riskFreeRate, years);
 *         // riskFreeRate passed as parameter from caller's context
 * ```
 */

int main() {}
