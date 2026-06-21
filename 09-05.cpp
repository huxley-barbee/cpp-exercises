/*
 * ## EXERCISE 5: Fmt — Fast, Type-Safe Formatting [9.c]
 *
 * `{fmt}` replaces `printf`, `snprintf`, and `std::ostringstream` with a
 * type-safe, significantly faster alternative. It is the basis of C++20 `std::format`.
 *
 * **Requirements:**
 * 1. Format a trade confirmation using `fmt::format`:
 *    - `"FILL: {} {} @ {:.4f} | notional={:.0f} | ts={}"`
 *    - Symbol, side, price, notional, timestamp
 * 2. Use `fmt::format_to` with a pre-allocated `fmt::memory_buffer` to avoid
 *    heap allocation in the hot path
 * 3. Implement a **structured log line** using named arguments:
 *    `fmt::format("symbol={symbol} side={side} qty={qty} price={price:.2f}",...)`
 * 4. Use `fmt::print` for stdout (faster than `printf`)
 * 5. Format a yield curve table using `fmt::format` with alignment and padding:
 *    `{:>10.4f}` for right-aligned floating point
 * 6. Benchmark: `fmt::format` vs `snprintf` vs `std::ostringstream` for a
 *    typical trading log line (1M iterations)
 * 7. Show `FMT_COMPILE` for compile-time format string checking
 *
 * **Expected output:**
 * ```
 * === fmt::format ===
 * FILL: AAPL BUY @ 150.2500 | notional=15025 | ts=10:23:45.123
 *
 * === fmt::format_to (no heap alloc) ===
 * Buffer written in-place: "FILL qty=100 price=150.25"
 * Heap allocations: 0  PASS
 *
 * === Yield curve table ===
 * Tenor      Rate     DF
 *   0.25     3.20%   0.9920
 *   0.50     3.45%   0.9829
 *   1.00     3.70%   0.9637
 *   2.00     3.95%   0.9249
 *
 * === Benchmark (1M iterations) ===
 * snprintf:            385ns
 * std::ostringstream:  820ns
 * fmt::format:          42ns   9.2x faster than snprintf
 * fmt::format_to:       28ns  (no allocation)
 * ```
 */

int main() {}
