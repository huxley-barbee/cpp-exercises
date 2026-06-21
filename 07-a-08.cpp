/*
 * ## EXERCISE 8: Replacing Globals — The Singleton Migration Pattern [7.a.iii]
 *
 * The safest way to migrate a global is to introduce a Singleton as an intermediate
 * step, then inject it, then delete the Singleton.
 *
 * **Requirements:**
 *
 * Migrate `g_logger` (a raw global `Logger*`) through these phases:
 * 1. **Phase 0 — Status quo**: `extern Logger* g_logger;` used everywhere
 * 2. **Phase 1 — Singleton wrapper**: `Logger& Logger::instance()` — all callers
 *    changed to `Logger::instance().log(...)` — only one change site at a time
 * 3. **Phase 2 — Inject into new code**: new classes take `Logger&` as constructor
 *    parameter, internally default to `Logger::instance()` for backwards compat
 * 4. **Phase 3 — Thread through**: callers pass the logger explicitly, singleton
 *    call sites decrease one by one
 * 5. **Phase 4 — Delete singleton**: once all callers inject, remove `instance()`
 * 6. Demonstrate the full migration on a `BondPricer` class
 * 7. Show how to verify each phase with a test: a `MockLogger` that captures log lines
 *
 * **Expected output:**
 * ```
 * === Phase 0: Raw global ===
 * extern Logger* g_logger;
 * g_logger->log("pricing AAPL");   // 47 call sites
 *
 * === Phase 1: Singleton ===
 * Logger::instance().log("pricing AAPL");  // mechanical replace
 *
 * === Phase 2: Inject with default ===
 * class BondPricer {
 *     Logger& log_;
 * public:
 *     BondPricer() : log_(Logger::instance()) {}           // old callers work
 *     BondPricer(Logger& log) : log_(log) {}              // new callers inject
 * };
 *
 * === Phase 3+4: Thread through ===
 * MockLogger mock;
 * BondPricer pricer(mock);
 * pricer.price("AAPL");
 * mock.assertLogged("pricing AAPL");  PASS
 *
 * Singleton deleted — Logger::instance() removed
 * All 47 call sites now inject their logger.
 * ```
 */

int main() {}
