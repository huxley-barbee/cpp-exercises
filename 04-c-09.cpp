/*
 * ## EXERCISE 9: POD Types — Shared Memory and IPC [4.c.iv]
 *
 * In real-time trading systems, processes exchange data via shared memory. Only POD types
 * (or carefully laid-out structs) can safely cross process boundaries.
 *
 * **Requirements:**
 * 1. Define a `SharedPriceTable` POD struct that holds 8 instrument prices:
 *    ```c
 *    struct SharedPriceTable {
 *        uint32_t version;
 *        uint64_t timestamp_ns;
 *        double   prices[8];
 *        char     symbols[8][8];
 *        uint32_t seqNo;
 *    };
 *    ```
 * 2. Simulate writing to shared memory using a `uint8_t shm_buf[sizeof(SharedPriceTable)]`
 * 3. Write prices for 4 instruments using `memcpy` of the whole struct
 * 4. Simulate a reader process: copy the buffer into a new `SharedPriceTable` and read prices
 * 5. Show the ABI compatibility concern: the struct must be compiled identically by writer
 *    and reader — adding a field without updating both is a silent corruption bug
 * 6. Demonstrate the version field pattern for detecting mismatches
 * 7. Show `offsetof` to verify field positions match expected wire offsets
 *
 * **Expected output:**
 * ```
 * === Shared Price Table ===
 * sizeof(SharedPriceTable): 136 bytes
 *
 * Writer process:
 *   version=1, seqNo=42, timestamp=1700000000000000000
 *   AAPL:  $150.25
 *   MSFT:  $300.50
 *   GOOGL: $140.10
 *   AMZN:  $175.80
 *
 * Serialised to shm_buf (136 bytes)
 *
 * Reader process (reads from shm_buf):
 *   version=1 — OK (matches expected)
 *   seqNo=42
 *   AAPL:  $150.25
 *   MSFT:  $300.50
 *   GOOGL: $140.10
 *   AMZN:  $175.80
 *
 * === offsetof Verification ===
 * offsetof(SharedPriceTable, version):      0
 * offsetof(SharedPriceTable, timestamp_ns): 8
 * offsetof(SharedPriceTable, prices):       16
 * offsetof(SharedPriceTable, symbols):      80
 * offsetof(SharedPriceTable, seqNo):       144  (may vary)
 *
 * === ABI Mismatch Demo ===
 * Writer compiled with version=1 struct (5 fields)
 * Reader compiled with version=2 struct (6 fields — extra int32_t added)
 * Reader version check: got 1, expected 2 — MISMATCH detected!
 * ```
 */

int main() {}
