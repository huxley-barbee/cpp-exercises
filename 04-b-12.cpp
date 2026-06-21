/*
 * ## EXERCISE 12: Global State — The God Object Anti-Pattern [4.b.v]
 *
 * A common legacy pattern: one giant global object that "knows everything."
 *
 * **Requirements:**
 * 1. Create a `TradingSystem` class with static members:
 *    - `static PriceFeed*   priceFeed_`
 *    - `static RiskEngine*  riskEngine_`
 *    - `static OrderRouter* orderRouter_`
 *    - `static bool         initialised_`
 * 2. Implement `TradingSystem::init()` and `TradingSystem::shutdown()`
 * 3. Show the problems:
 *    - Order-of-init and order-of-shutdown are implicit and fragile
 *    - Impossible to have two independent instances (for testing or multi-portfolio)
 *    - Any module that includes the header is now coupled to the entire system
 * 4. Refactor to a `TradingContext` struct that is passed by reference
 * 5. Show that the refactored version is unit-testable: create two independent contexts
 *
 * **Expected output:**
 * ```
 * === God Object Anti-Pattern ===
 * TradingSystem::init()
 *   PriceFeed    initialised
 *   RiskEngine   initialised
 *   OrderRouter  initialised
 * TradingSystem ready
 *
 * Processing order via global system:
 *   PriceFeed: AAPL = $150.00
 *   RiskEngine: VaR OK
 *   OrderRouter: order sent
 *
 * TradingSystem::shutdown()
 *   OrderRouter  destroyed
 *   RiskEngine   destroyed
 *   PriceFeed    destroyed
 *
 * Problems:
 * - Singleton — cannot create two instances
 * - Global state — tests pollute each other
 * - Shutdown order is manual and fragile
 *
 * === Refactored: TradingContext ===
 * TradingContext ctx1 (test environment)
 * TradingContext ctx2 (prod environment)
 *
 * ctx1 and ctx2 are fully independent
 * Unit test: ctx1 with mock PriceFeed — no global state
 * ctx1 destroyed — no effect on ctx2
 * ```
 */

int main() {}
