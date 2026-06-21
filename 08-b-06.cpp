/*
 * ## EXERCISE 6: Pricing Engines — Engine Interface Design [8.b.ii]
 *
 * Design a clean, extensible pricing engine hierarchy that can accommodate
 * new models without breaking existing callers.
 *
 * **Requirements:**
 * 1. Define a `PricingRequest` struct (instrument, market data, model params)
 * 2. Define a `PricingResult` struct (price, greeks map, model name, timestamp)
 * 3. Define an abstract `IPricingEngine` interface:
 *    ```cpp
 *    class IPricingEngine {
 *    public:
 *        virtual PricingResult price(const PricingRequest&) = 0;
 *        virtual bool canPrice(const Instrument&) const = 0;
 *        virtual std::string modelName() const = 0;
 *        virtual ~IPricingEngine() = default;
 *    };
 *    ```
 * 4. Implement concrete engines:
 *    - `BlackScholeEngine` — European vanilla options
 *    - `BinomialEngine` — American options (CRR tree)
 *    - `AnalyticBarrierEngine` — single-barrier options
 *    - `AnalyticBondEngine` — fixed-rate bonds
 * 5. Implement an `EngineRegistry` that maps instrument types to engines:
 *    `registry.registerEngine(InstrumentType::EUROPEAN_CALL, std::make_shared<BlackScholesEngine>())`
 * 6. Implement automatic engine selection: `registry.getEngine(instrument)` returns
 *    the best available engine
 * 7. Show graceful degradation: if no specialised engine exists, fall back to MC
 *
 * **Expected output:**
 * ```
 * === Pricing Engine Registry ===
 *
 * Registered engines:
 *   EUROPEAN_CALL  -> BlackScholesEngine
 *   EUROPEAN_PUT   -> BlackScholesEngine
 *   AMERICAN_PUT   -> BinomialEngine (N=1000)
 *   BARRIER_CALL   -> AnalyticBarrierEngine
 *   FIXED_BOND     -> AnalyticBondEngine
 *   EXOTIC_*       -> MonteCarloEngine (fallback)
 *
 * Pricing 5 instruments:
 *   EUR call K=100:   $10.451  [BlackScholesEngine]   0.02ms
 *   USD amer put K=100: $6.085 [BinomialEngine]       1.24ms
 *   DO call H=90:     $6.242  [AnalyticBarrierEngine] 0.03ms
 *   10Y bond 4.5%:   $101.42  [AnalyticBondEngine]   0.01ms
 *   Exotic basket:    $12.38  [MonteCarloEngine]     42.10ms
 * ```
 */

int main() {}
