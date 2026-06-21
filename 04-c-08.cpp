/*
 * ## EXERCISE 8: POD Types — Layout and Serialisation [4.c.iv]
 *
 * POD (Plain Old Data) types have a well-defined binary layout. They are the only types
 * safe to serialise with `memcpy`, send over a socket, or share via shared memory.
 *
 * **Requirements:**
 * 1. Define POD structs: `QuoteRecord`, `TradeRecord`, `OrderRecord` that model a binary
 *    market-data feed format (use exact-width types from Exercise 4)
 * 2. Verify POD-ness using `std::is_pod<T>` (C++11) or manual checklist (C++03)
 * 3. Serialise a `TradeRecord` to a `uint8_t` byte buffer using `memcpy`
 * 4. Print the buffer as hex
 * 5. Deserialise back: create a new `TradeRecord` from the buffer using `memcpy` and verify
 *    all fields match
 * 6. Show what breaks POD-ness: add a constructor, virtual function, or non-POD member and
 *    check `std::is_pod` again
 * 7. Demonstrate struct padding: show that adding an `int8_t` field may add 3 bytes of padding
 * 8. Use `#pragma pack(1)` to remove padding and discuss the trade-offs
 *
 * **Expected output:**
 * ```
 * === POD Verification ===
 * is_pod<QuoteRecord>:  true
 * is_pod<TradeRecord>:  true
 * is_pod<OrderRecord>:  true
 *
 * is_pod<NonPOD>:       false  (has constructor)
 * is_pod<NonPOD2>:      false  (has virtual function)
 *
 * === Serialisation ===
 * TradeRecord:
 *   seqNo:    1001
 *   price:    1502500 (= $150.2500 fixed-point)
 *   quantity: 100
 *   symbol:   "AAPL"
 *   side:     'B'
 *
 * sizeof(TradeRecord): 24 bytes
 * Hex: 00 00 00 00 e9 03 00 00 ...
 *
 * Deserialised TradeRecord matches original: YES
 *
 * === Padding Demo ===
 * struct Padded   { int8_t a; int32_t b; }
 * sizeof(Padded): 8 bytes  (3 bytes padding after a)
 *
 * struct Packed   { int8_t a; int32_t b; } __attribute__((packed))
 * sizeof(Packed): 5 bytes  (no padding)
 *
 * Trade-off: packed structs may cause unaligned access — slower on x86, crash on ARM
 * ```
 */

int main() {}
