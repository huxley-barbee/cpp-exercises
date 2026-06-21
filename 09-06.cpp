/*
 * ## EXERCISE 6: Spdlog — Structured Async Logging [9.d]
 *
 * `spdlog` provides asynchronous, structured logging with minimal impact on
 * the trading thread. This exercise builds a production-quality logging setup.
 *
 * **Requirements:**
 * 1. Create an **async logger** with a background thread and a 32768-slot queue:
 *    ```cpp
 *    auto tp = std::make_shared<spdlog::details::thread_pool>(32768, 1);
 *    auto logger = std::make_shared<spdlog::async_logger>("trading",
 *        sink, tp, spdlog::async_overflow_policy::overrun_oldest);
 *    ```
 * 2. Create two sinks: a **rotating file sink** (10MB, 5 files) and a
 *    **console sink** (coloured, INFO+ only)
 * 3. Set a **custom pattern** for trading:
 *    `"[%Y-%m-%d %H:%M:%S.%f] [%n] [%l] %v"`
 * 4. Log structured data using `spdlog::info("symbol={} side={} qty={} price={:.4f}",
 *    symbol, side, qty, price)`
 * 5. Use `SPDLOG_LOGGER_TRACE` / `SPDLOG_LOGGER_DEBUG` macros that compile to
 *    nothing in Release builds (`SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_INFO`)
 * 6. Implement a **trade blotter logger**: each fill logged to a separate daily file
 * 7. Measure: hot-path logging latency (enqueue only, not disk write)
 * 8. Show `logger->flush()` and clean shutdown
 *
 * **Expected output:**
 * ```
 * === Spdlog Async Logger ===
 * [2024-01-15 10:23:45.123456] [trading] [info] symbol=AAPL side=BUY qty=100 price=150.2500
 * [2024-01-15 10:23:45.124102] [trading] [warn] sequence gap: expected=10001 got=10003
 * [2024-01-15 10:23:45.124890] [trading] [error] order rejected: reason=price_outside_limits
 *
 * === Logging latency ===
 * Async enqueue:    42ns avg  PASS (does not block trading thread)
 * Sync file write: 4800ns avg (in background thread)
 *
 * === Debug macros in release ===
 * SPDLOG_LOGGER_DEBUG: compiled to nothing in Release  PASS
 *
 * Flush and shutdown: 127 queued messages flushed  PASS
 * ```
 */

int main() {}
