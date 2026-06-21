/*
 * ## EXERCISE 15: Low-Latency Logging — Design Principles [8.c.v]
 *
 * Logging in a trading system must be asynchronous, allocation-free, and
 * must never block the trading thread.
 *
 * **Requirements:**
 * 1. Identify and measure the **cost of naive logging**:
 *    - `printf` to stdout: measure latency
 *    - `std::cout` with mutex: measure latency and jitter
 *    - `fprintf` to file: measure latency (includes kernel write)
 *    - Show that even a no-op `printf` call has > 1µs latency
 * 2. Define the requirements for a low-latency logger:
 *    - Trading thread: < 50ns to log a message (enqueue only)
 *    - No heap allocation on hot path
 *    - No system calls on hot path
 *    - No locks on hot path
 *    - Async disk write from a dedicated logger thread
 * 3. Implement a **lock-free SPSC log queue**:
 *    - Fixed-size `LogEntry` struct (128 bytes, cache-line aligned)
 *    - SPSC queue between trading thread (producer) and logger thread (consumer)
 *    - `LogEntry` contains: timestamp_ns, level, pre-formatted message buffer
 * 4. Show the latency improvement: naive vs lock-free queue
 * 5. Discuss the `O_DIRECT` file write strategy for the logger thread
 *
 * **Expected output:**
 * ```
 * === Naive Logging Latency ===
 * printf to stdout:       1,240ns avg  8,400ns p99
 * std::cout (mutex):      1,890ns avg 12,200ns p99
 * fprintf to file:        4,800ns avg 45,000ns p99
 * spdlog (async):           180ns avg    820ns p99
 *
 * === Lock-free SPSC queue enqueue ===
 * Enqueue latency:          28ns avg     65ns p99  PASS (<50ns target)
 * sizeof(LogEntry):        128 bytes (2 cache lines)
 * Queue depth:           65536 entries (8MB)
 * 0 heap allocations on hot path  PASS
 *
 * Speedup vs fprintf: 171x (28ns vs 4800ns)
 * ```
 */

int main() {}
