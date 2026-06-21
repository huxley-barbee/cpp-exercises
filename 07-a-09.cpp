/*
 * ## EXERCISE 9: Replacing Globals — Dependency Injection Container [7.a.iii]
 *
 * When many classes need the same set of dependencies, a lightweight DI container
 * avoids threading the same parameters through 10 layers of constructors.
 *
 * **Requirements:**
 * 1. Implement a minimal `ServiceLocator` / DI container:
 *    - `register<T>(std::shared_ptr<T>)`: stores an instance keyed by type
 *    - `get<T>()`: retrieves the instance, throws if not registered
 * 2. Show the anti-pattern: a global `ServiceLocator` is just a fancy global — still untestable
 * 3. Show the correct pattern: pass the `ServiceLocator` explicitly to components that need it
 * 4. Implement a `Context` struct that groups all application-level dependencies:
 *    ```cpp
 *    struct TradingContext {
 *        std::shared_ptr<ILogger>     logger;
 *        std::shared_ptr<IPriceFeed>  feed;
 *        std::shared_ptr<IRiskEngine> risk;
 *    };
 *    ```
 * 5. Rewrite `BondPricer` and `RiskCalculator` to accept `TradingContext const&`
 * 6. In tests, construct a `TradingContext` with stubs
 * 7. In production, construct with real implementations
 * 8. Show a test that verifies `BondPricer` and `RiskCalculator` interact correctly
 *    through the shared context
 *
 * **Expected output:**
 * ```
 * === Service Locator (anti-pattern) ===
 * GlobalServiceLocator::register<ILogger>(realLogger);  // still a global!
 * auto& log = GlobalServiceLocator::get<ILogger>();      // hidden dependency
 *
 * === TradingContext (correct) ===
 * // Test context
 * TradingContext testCtx {
 *     std::make_shared<MockLogger>(),
 *     std::make_shared<StubPriceFeed>(),
 *     std::make_shared<StubRiskEngine>()
 * };
 *
 * BondPricer pricer(testCtx);
 * RiskCalculator risk(testCtx);
 *
 * pricer.price("UST2Y");
 * risk.computeVaR("UST2Y", 1000000);
 *
 * // Verify via mocks
 * testCtx.logger->assertLogged("Priced UST2Y");  PASS
 * testCtx.feed->assertQueried("UST2Y");          PASS
 * ```
 */

int main() {}
