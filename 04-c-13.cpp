/*
 * ## EXERCISE 13: Comprehensive Integration [All of 4.c]
 *
 * Build a complete C-callable market-data library that combines all topics from section 4.c.
 *
 * **Requirements:**
 *
 * The library has two layers:
 * - **Internal C++ layer**: `OrderBook` class using STL containers and proper RAII
 * - **External C API**: `extern "C"` functions operating on POD types and opaque handles
 *
 * 1. Define POD types: `BidLevel`, `AskLevel`, `BookSnapshot` (exact-width types throughout)
 * 2. Implement `OrderBook` C++ class:
 *    - `addBid(uint32_t price, uint32_t qty)`
 *    - `addAsk(uint32_t price, uint32_t qty)`
 *    - `getSnapshot(BookSnapshot* out) const` — fills a POD struct for the C API
 *    - `bestBid()` / `bestAsk()` returning fixed-point prices
 * 3. Write `extern "C"` wrapper API:
 *    - `order_book_create() -> void*`
 *    - `order_book_add_bid(void*, uint32_t price, uint32_t qty)`
 *    - `order_book_add_ask(void*, uint32_t price, uint32_t qty)`
 *    - `order_book_snapshot(void*, BookSnapshot*) -> int`
 *    - `order_book_destroy(void*)`
 * 4. Write a C-style `register_price_callback` that stores a function pointer
 *    `void (*PriceCallback)(const char* sym, uint32_t price)` and fires it on best-price change
 * 5. Demonstrate the full stack: create book → add levels → snapshot → callback fires → destroy
 * 6. Conclude with a **Pattern Audit** naming every 4.c technique used
 *
 * **Expected output:**
 * ```
 * === Market-Data Library ===
 *
 * === C++ Layer ===
 * OrderBook created
 * addBid(1502500, 200)
 * addBid(1502000, 500)
 * addAsk(1503000, 300)
 * addAsk(1503500, 150)
 *
 * bestBid: $150.2500
 * bestAsk: $150.3000
 * spread:  $0.0500
 *
 * === C API ===
 * void* h = order_book_create()
 * order_book_add_bid(h, 1502500, 200)
 * order_book_add_ask(h, 1503000, 300)
 *
 * order_book_snapshot(h, &snap):
 *   bidPrice=1502500 ($150.2500), bidQty=200
 *   askPrice=1503000 ($150.3000), askQty=300
 *
 * === Function Pointer Callback ===
 * register_price_callback(h, onPriceUpdate)
 * addBid(1502600, 100) -> best bid changed!
 *   [CALLBACK] onPriceUpdate("AAPL", 1502600)
 *
 * === BookSnapshot (POD) ===
 * sizeof(BookSnapshot): 24 bytes
 * is_pod<BookSnapshot>: true
 * Serialised to 24-byte buffer — safe for IPC/shared memory
 *
 * order_book_destroy(h) -> OrderBook destroyed
 *
 * === Pattern Audit ===
 * extern "C" wrappers      -> safe C linkage, no mangling
 * void* opaque handle      -> hides C++ class from C callers
 * POD BookSnapshot         -> safe memcpy, IPC, shared memory
 * exact-width types        -> deterministic wire format
 * function pointer callback -> C-compatible event notification
 * null handle guards       -> defensive C API design
 * offsetof / sizeof checks -> ABI verification
 * ```
 */

int main() {}
