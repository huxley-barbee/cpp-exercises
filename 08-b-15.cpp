/*
 * ## EXERCISE 15: Event-Driven Architecture — Event Types and Bus [8.b.iv]
 *
 * Design the core event system that decouples producers from consumers.
 *
 * **Requirements:**
 * 1. Define a base `Event` class with:
 *    - `EventType` enum (tick, order, fill, risk_limit, timer, config_change)
 *    - `int64_t timestamp_ns` (nanoseconds)
 *    - `uint64_t sequence_no` (monotonically increasing)
 *    - Virtual destructor
 * 2. Define concrete event types: `TickEvent`, `OrderEvent`, `FillEvent`, `RiskEvent`
 * 3. Implement a **synchronous event bus** (`SyncEventBus`):
 *    - `subscribe<T>(handler)` registers a callback for event type T
 *    - `publish(event)` calls all handlers immediately (in the caller's thread)
 *    - Handlers stored as `std::vector<std::function<void(const Event&)>>`
 * 4. Implement an **asynchronous event bus** (`AsyncEventBus`):
 *    - `publish(event)` enqueues to a ring buffer
 *    - A dedicated dispatch thread processes the queue
 *    - Handlers called in the dispatch thread
 * 5. Show that sync bus has lower latency but blocks the publisher
 * 6. Show that async bus decouples publisher latency from handler latency
 * 7. Benchmark: 1M events through sync vs async bus
 *
 * **Expected output:**
 * ```
 * === Event Bus Comparison (1M events) ===
 *
 * SyncEventBus:
 *   Publish latency p50:   450ns  (includes handler execution)
 *   Publish latency p99:   680ns
 *   Throughput:           2.2M events/sec
 *
 * AsyncEventBus:
 *   Publish latency p50:    85ns  (enqueue only)
 *   Publish latency p99:   130ns
 *   Handler latency p50:   520ns  (in dispatch thread)
 *   Throughput:           11.8M events/sec (publish side)
 *
 * Sync:  simpler, zero handler reorder risk
 * Async: lower publish latency, but handler sees stale state if market moves
 * ```
 */

int main() {}
