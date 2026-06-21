/*
 * ## EXERCISE 2: Untangling Dependencies — Extract Interface [7.a.i]
 *
 * The first mechanical step: wrap the concrete dependency in an interface so it can
 * be replaced with a test double.
 *
 * **Requirements:**
 * 1. Given this concrete market-data feed:
 *    ```cpp
 *    class MarketDataFeed {
 *    public:
 *        void connect(const char* host);
 *        double getYield(const char* symbol);
 *        double getPrice(const char* symbol);
 *        bool   isConnected() const;
 *    };
 *    ```
 * 2. Extract a pure-virtual interface `IMarketDataFeed` with the same methods
 * 3. Make `MarketDataFeed` implement `IMarketDataFeed`
 * 4. Create a `StubMarketDataFeed` (test double) that returns fixed values
 * 5. Rewrite `BondPricer` to accept `IMarketDataFeed&` via constructor injection
 * 6. Show a test that uses `StubMarketDataFeed` — no network needed
 * 7. Show the production path that uses `MarketDataFeed`
 * 8. Discuss: why pass by reference/pointer rather than by value? What about ownership?
 *
 * **Expected output:**
 * ```
 * === Interface Extraction ===
 *
 * struct IMarketDataFeed {
 *     virtual double getYield(const char* symbol) = 0;
 *     virtual double getPrice(const char* symbol) = 0;
 *     virtual ~IMarketDataFeed() = default;
 * };
 *
 * === Stub for testing ===
 * StubMarketDataFeed stub;
 * stub.setYield("UST2Y", 0.045);
 * stub.setPrice("UST2Y", 98.50);
 *
 * BondPricer pricer(stub);   // no network, no file I/O
 *
 * double price = pricer.price("UST2Y");
 * Expected: $982.34  Got: $982.34  PASS
 *
 * === Production path ===
 * MarketDataFeed liveFeeed;
 * liveFeed.connect("prod-mds:9000");
 * BondPricer livePricer(liveFeed);
 * // ...
 * ```
 */

int main() {}
