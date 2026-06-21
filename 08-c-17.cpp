/*
 * ## EXERCISE 17: Low-Latency Logging — Binary Log Format [8.c.v]
 *
 * Binary logging is faster to write than text and compact on disk.
 * The trade-off is that a decoder is needed for human-readable output.
 *
 * **Requirements:**
 * 1. Design a **binary log format**:
 *    - 4-byte magic number `0x4C4F4747` ("LOGG")
 *    - 1-byte version
 *    - 8-byte nanosecond timestamp
 *    - 1-byte log level
 *    - 1-byte event code (maps to a string table)
 *    - 2-byte payload length
 *    - Variable payload (raw bytes, no string encoding)
 *    - Total fixed header: 17 bytes
 * 2. Implement `BinaryLogger::write(EventCode, const void* payload, uint16_t len)`
 *    — writes directly to an `O_DIRECT` file descriptor in 512-byte aligned blocks
 * 3. Implement a **decoder tool** that reads the binary log and reconstructs
 *    a human-readable text log
 * 4. Implement **log rotation**: when the current log file reaches 1GB,
 *    atomically swap to a new file without losing messages
 * 5. Compare: binary log write throughput vs text log
 * 6. Show **compression ratio**: binary log compressed with LZ4 achieves 10× reduction
 *
 * **Expected output:**
 * ```
 * === Binary Log Format ===
 * Header: magic(4)+ver(1)+ts(8)+level(1)+code(1)+paylen(2) = 17 bytes
 * Typical event: 17 + 24 bytes payload = 41 bytes/event
 *
 * Write benchmark (1M events):
 *   Text log (spdlog):  180ns/event  180ms total  (45MB text)
 *   Binary log:          38ns/event   38ms total  (41MB binary)
 *   Binary speedup: 4.7x
 *
 * Decoder output:
 *   [10:23:45.123456789] FILL qty=100 price=150.250000 sym=AAPL [decoded from binary]
 *
 * Log rotation: atomic file swap, 0 messages lost  PASS
 * Binary + LZ4: 41MB -> 4.2MB (10.2x compression ratio)
 * ```
 */

int main() {}
