/*
 * ## EXERCISE 16: Low-Latency Logging — Wait-Free Log Entry Formatting [8.c.v]
 *
 * Even formatting a log message must be fast. `printf` and `std::string`
 * are too slow. Implement a fast, wait-free message formatter.
 *
 * **Requirements:**
 * 1. Implement a `LogFormatter` that formats log entries into a fixed-size
 *    `char[96]` buffer with no heap allocation:
 *    - Fast integer-to-ASCII: implement `writeInt64(buf, val)` without `printf`
 *    - Fast double-to-ASCII: implement `writeDouble(buf, val, decimals)` using
 *      integer arithmetic (multiply + truncate, no `sprintf`)
 *    - Fast timestamp formatter: nanoseconds → `HH:MM:SS.nnnnnnnnn`
 * 2. Implement **structured logging**: key-value pairs serialised into the
 *    fixed buffer as `key=value ` space-separated
 * 3. Implement **log level filtering** as a compile-time constant:
 *    `#define LOG_LEVEL_MIN LOG_INFO` — DEBUG messages are eliminated by the
 *    compiler, not by a runtime check
 * 4. Benchmark: compare formatting approaches for a typical trading log line:
 *    `"[10:23:45.123456789] FILL qty=100 price=150.250000 symbol=AAPL"`
 * 5. Show the **hot/cold path split**: format only the timestamp and a numeric
 *    code on the hot path; expand to full text in the logger thread
 *
 * **Expected output:**
 * ```
 * === Log Formatting Benchmark ===
 *
 * Format: "[HH:MM:SS.nnnnnnnnn] FILL qty=100 price=150.25 sym=AAPL"
 *
 * snprintf:           385ns
 * std::ostringstream: 820ns
 * Fast formatter:      22ns  (17x faster than snprintf)
 *
 * Fast integer-to-ASCII:  3ns  (vs 45ns for snprintf %lld)
 * Fast double-to-ASCII:   8ns  (vs 90ns for snprintf %f)
 * Timestamp format:      11ns
 *
 * === Hot/cold split ===
 * Hot path (trading thread):
 *   Write: {timestamp=14400001234ns, code=FILL, qty=100, price=15025000}
 *   Cost: 18ns  (just a struct copy into the ring buffer)
 *
 * Cold path (logger thread):
 *   Expand code -> "FILL", format timestamp, format doubles
 *   Cost: 45ns  (acceptable — off critical path)
 * ```
 */

int main() {}
