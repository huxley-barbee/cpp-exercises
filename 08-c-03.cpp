/*
 * ## EXERCISE 3: Market Data Handlers — Normalised Feed Handler [8.c.i]
 *
 * A production feed handler normalises exchange-specific formats, applies
 * corporate action adjustments, and publishes to downstream consumers.
 *
 * **Requirements:**
 * 1. Implement a `FeedHandler` class with the following pipeline stages:
 *    - **Stage 1 — Receive**: read from SPSC ring buffer (from network thread)
 *    - **Stage 2 — Parse**: dispatch to message-type handler
 *    - **Stage 3 — Validate**: check sequence numbers, timestamps, price sanity
 *    - **Stage 4 — Normalise**: convert to internal tick format
 *    - **Stage 5 — Publish**: write to downstream SPSC queues (pricing, risk, logger)
 * 2. Implement **price sanity checks**:
 *    - Reject ticks where `|new_price - last_price| / last_price > 5%` (circuit breaker)
 *    - Reject ticks with `bid >= ask`
 *    - Reject ticks with `size <= 0`
 * 3. Implement **per-symbol state**: maintain `last_price`, `last_seq`, `last_ts`
 *    in a `std::array<SymbolState, MAX_SYMBOLS>` (no hash map in hot path)
 * 4. Show the latency budget for each stage
 * 5. Measure total pipeline latency: ring buffer read → downstream publish
 *
 * **Expected output:**
 * ```
 * === Feed Handler Pipeline (1M messages) ===
 *
 * Stage latencies (per message, median):
 *   Stage 1 Receive:    18ns
 *   Stage 2 Parse:      12ns
 *   Stage 3 Validate:    8ns
 *   Stage 4 Normalise:  10ns
 *   Stage 5 Publish:    15ns
 *   Total pipeline:     63ns
 *
 * Validation rejections (out of 1M):
 *   Sequence gaps:    12
 *   Crossed markets:   3
 *   Price spikes:      7
 *   Zero size:         2
 *   Total rejected:   24 (0.0024%)
 *
 * Memory: 0 heap allocations in steady state  PASS
 * ```
 */

int main() {}
