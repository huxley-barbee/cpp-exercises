/*
 * ## EXERCISE 6: Function Pointers — Callbacks and Strategy Pattern [4.c.iii]
 *
 * Legacy C++ systems use function pointers for callbacks — event handlers, validators,
 * risk checks — anywhere the caller wants to inject behaviour.
 *
 * **Requirements:**
 * 1. Implement a C++98 event system using function pointer callbacks:
 *    - `typedef void (*TradeCallback)(const char* symbol, double price, int qty)`
 *    - `registerCallback(TradeCallback cb)` and `fireCallbacks(...)` functions
 *    - Register three different callbacks and fire them
 * 2. Implement the C++98 strategy pattern: a `Sorter` that takes a comparison function pointer
 *    `bool (*cmp)(double a, double b)` and sorts a `DynArray`
 * 3. Show the C `qsort` callback signature and its pitfalls (void*, casting, UB for non-POD)
 * 4. Demonstrate a stateless vs stateful callback problem: function pointers cannot capture
 *    state — show why, and demonstrate the C workaround (`void* userData` parameter)
 * 5. Show the modern replacement: `std::function` + lambda for stateful callbacks
 *
 * **Expected output:**
 * ```
 * === C++98 Event Callbacks ===
 * Registered 3 callbacks
 * fireCallbacks("AAPL", 150.0, 100):
 *   [Logger]    TRADE: AAPL 100@150.00
 *   [RiskCheck] TRADE AAPL: VaR within limits
 *   [Audit]     AUDIT: AAPL qty=100 price=150.00
 *
 * === Strategy Pattern (function pointer) ===
 * Sorter with ascending cmp:  [1.1, 2.5, 3.7, 4.0, 9.2]
 * Sorter with descending cmp: [9.2, 4.0, 3.7, 2.5, 1.1]
 *
 * === qsort callback ===
 * qsort comparator must return int, takes const void*
 * Sorted ints via qsort: [1, 3, 5, 7, 9]
 * Pitfall: casting non-POD types through void* is UB
 *
 * === Stateless Callback Problem ===
 * Function pointer cannot capture local state:
 *   int threshold = 50;
 *   // bool (*cb)(int) = [threshold](int x){ return x > threshold; }; // NO — can't capture
 *
 * === void* userData workaround ===
 * typedef bool (*FilterFn)(int value, void* userData);
 * Filtered (threshold=50): [55, 60, 75]
 *
 * === Modern: lambda + std::function ===
 * int threshold = 50;
 * auto cb = [threshold](int x){ return x > threshold; };
 * Filtered (threshold=50): [55, 60, 75]
 * (Captures state cleanly — no void* needed)
 * ```
 */

int main() {}
