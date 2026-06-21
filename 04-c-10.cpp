/*
 * ## EXERCISE 10: Combining `extern "C"`, C Headers, and POD Types [4.c.i–iv]
 *
 * Write a complete C-callable shared library interface for a market-data decoder.
 *
 * **Requirements:**
 * 1. Define a POD `RawTick` struct (seqNo, timestamp, symbol[8], price, qty)
 * 2. Write a C++ `TickDecoder` class that:
 *    - Holds a ring buffer of `RawTick`s
 *    - `decode(const uint8_t* buf, size_t len)` parses a binary buffer into `RawTick`s
 *    - `getLatest(RawTick* out)` fills a caller-provided POD struct
 *    - `tickCount()` returns the number of decoded ticks
 * 3. Expose a complete `extern "C"` API:
 *    - `tick_decoder_create() -> void*`
 *    - `tick_decoder_decode(void*, const uint8_t*, size_t) -> int` (returns ticks decoded)
 *    - `tick_decoder_get_latest(void*, RawTick*) -> int` (1 = ok, 0 = empty)
 *    - `tick_decoder_count(void*) -> int`
 *    - `tick_decoder_destroy(void*)`
 * 4. Write a C-style `test_from_c()` function that uses only the C API
 * 5. Demonstrate round-trip: encode a `RawTick` to bytes, decode it, verify all fields
 *
 * **Expected output:**
 * ```
 * === TickDecoder C++ Interface ===
 * TickDecoder created
 * Encoded RawTick to 32 bytes:
 *   seqNo=1, sym="AAPL", price=1502500, qty=100
 *
 * decode(buf, 32): 1 tick decoded
 * getLatest():
 *   seqNo:    1
 *   symbol:   "AAPL"
 *   price:    $150.2500
 *   quantity: 100
 *
 * === C API (extern "C") ===
 * void* h = tick_decoder_create()     -> 0x[addr]
 * tick_decoder_decode(h, buf, 32)     -> 1
 * tick_decoder_get_latest(h, &tick)   -> 1
 * tick_decoder_count(h)               -> 1
 * tick_decoder_destroy(h)             -> TickDecoder destroyed
 *
 * === Simulated C Caller ===
 * test_from_c():
 *   create -> decode -> get_latest -> destroy
 *   Got tick: AAPL qty=100 price=$150.2500
 * ```
 */

int main() {}
