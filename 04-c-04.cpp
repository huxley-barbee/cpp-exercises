/*
 * ## EXERCISE 4: C Headers — `<cstdint>` and Exact-Width Types [4.c.ii]
 *
 * Binary protocols, FIX messages, and shared-memory structures require exact-width integer
 * types. Legacy code used `typedef`s in `<stdint.h>`; modern code uses `<cstdint>`.
 *
 * **Requirements:**
 * 1. Use `int8_t`, `uint8_t`, `int16_t`, `uint16_t`, `int32_t`, `uint32_t`, `int64_t`, `uint64_t`
 * 2. Print `sizeof` and `std::numeric_limits` min/max for each
 * 3. Demonstrate overflow behaviour: `uint8_t` at 255, `int8_t` at 127
 * 4. Write a `MarketDataMessage` struct using exact-width types to match a binary wire format:
 *    ```c
 *    struct MarketDataMessage {
 *        uint32_t seqNo;
 *        int64_t  timestamp;   // nanoseconds since epoch
 *        char     symbol[8];
 *        int32_t  price;       // price * 10000 (fixed point)
 *        int32_t  quantity;
 *    };
 *    ```
 * 5. Serialise and deserialise the struct using `memcpy` into a `uint8_t` buffer
 * 6. Print the buffer as hex bytes
 * 7. Verify `sizeof(MarketDataMessage)` is what you expect (discuss padding)
 *
 * **Expected output:**
 * ```
 * === Exact-Width Integer Types ===
 * int8_t:   size=1, min=-128,        max=127
 * uint8_t:  size=1, min=0,           max=255
 * int16_t:  size=2, min=-32768,      max=32767
 * uint16_t: size=2, min=0,           max=65535
 * int32_t:  size=4, min=-2147483648, max=2147483647
 * uint64_t: size=8, min=0,           max=18446744073709551615
 *
 * === Overflow ===
 * uint8_t 255 + 1 = 0   (wraps)
 * int8_t  127 + 1 = -128 (wraps — UB for signed, but common in practice)
 *
 * === MarketDataMessage ===
 * sizeof(MarketDataMessage): 32 bytes (may vary with padding)
 * Serialised hex: [02 00 00 00 ...]
 * Deserialised:
 *   seqNo:     2
 *   timestamp: 1700000000000000000
 *   symbol:    "AAPL"
 *   price:     $150.2500 (fixed point: 1502500)
 *   quantity:  100
 * ```
 */

int main() {}
