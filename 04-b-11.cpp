/*
 * ## EXERCISE 11: Global State — Shared Mutable State Hazards [4.b.v]
 *
 * Legacy systems used global state for configuration, caches, and shared counters.
 *
 * **Requirements:**
 * 1. Create a global `PricingCache` that maps `std::string` instrument ID to `double` price
 *    — implemented as a plain `std::map` at file scope
 * 2. Create a global `int g_requestCount` and `double g_totalNotional`
 * 3. Write `priceInstrument(const std::string& id, double notional)` that:
 *    - Checks the cache; if miss, "computes" the price and inserts it
 *    - Increments `g_requestCount` and adds to `g_totalNotional`
 * 4. Show the initialisation-order fiasco: have a second global object whose constructor
 *    calls `priceInstrument` — the cache may not be constructed yet
 * 5. Show the hidden coupling: a unit test that calls `priceInstrument` may see stale
 *    cache state from a previous test
 * 6. Demonstrate three modern fixes:
 *    - Function-local static (Meyers singleton)
 *    - Dependency injection (pass cache as parameter)
 *    - Thread-local storage for counters
 *
 * **Expected output:**
 * ```
 * === Global Pricing Cache ===
 * priceInstrument("AAPL", 10000): cache miss — computed $150.00, cached
 * priceInstrument("AAPL", 5000):  cache hit  — returned $150.00
 * priceInstrument("MSFT", 8000):  cache miss — computed $300.00, cached
 * priceInstrument("MSFT", 2000):  cache hit  — returned $300.00
 *
 * g_requestCount:  4
 * g_totalNotional: $25000.00
 *
 * === Initialisation-Order Fiasco ===
 * GlobalUser constructor fires before PricingCache is ready!
 * (Undefined behaviour — result depends on link order)
 *
 * === Hidden Test Coupling ===
 * Test 1: inserts "FAKE" into cache
 * Test 2: finds "FAKE" in cache — TEST DATA POLLUTION
 *
 * === Modern Fix 1: Meyers Singleton ===
 * PricingCache& getCache() { static PricingCache c; return c; }
 * Thread-safe init (C++11), destroyed at program end
 *
 * === Modern Fix 2: Dependency Injection ===
 * double priceInstrument(PricingCache& cache, const string& id, double n);
 * No global state — fully testable
 *
 * === Modern Fix 3: thread_local counters ===
 * thread_local int t_requestCount = 0;
 * No shared mutable state — lock-free
 * ```
 */

int main() {}
