/*
 * ## EXERCISE 12: Combining Futures and Thread Pools — Pipeline Pattern [6.b.i–ii]
 *
 * A trading pipeline has stages: parse → validate → price → risk → route.
 * Each stage can run concurrently with the previous on different orders.
 *
 * **Requirements:**
 * 1. Define 4 pipeline stages as functions:
 *    - `Stage1Parse(raw) -> Order`
 *    - `Stage2Validate(Order) -> Order`
 *    - `Stage3Price(Order) -> PricedOrder`
 *    - `Stage4Risk(PricedOrder) -> bool`
 * 2. Use two thread pools: one for CPU-bound stages (pricing, risk) and one for
 *    I/O-bound stages (parse, validate)
 * 3. Chain stages using futures: each stage's output is the next stage's input
 * 4. Feed 100 orders through the pipeline concurrently
 * 5. Measure: latency per order (time from entry to exit), throughput (orders/sec)
 * 6. Show the pipeline filling up: stage 1 is busy with order N while stage 2
 *    processes order N-1, etc.
 * 7. Handle backpressure: if the risk stage rejects an order, log it and continue
 *
 * **Expected output:**
 * ```
 * === Order Processing Pipeline ===
 *
 * Stages:
 *   Stage 1 (Parse):    I/O pool, 2 threads
 *   Stage 2 (Validate): I/O pool, 2 threads
 *   Stage 3 (Price):    CPU pool, 4 threads
 *   Stage 4 (Risk):     CPU pool, 4 threads
 *
 * Processing 100 orders...
 *
 * Pipeline filling:
 *   t=0ms:   Order 0 -> Stage1
 *   t=1ms:   Order 0 -> Stage2, Order 1 -> Stage1
 *   t=2ms:   Order 0 -> Stage3, Order 1 -> Stage2, Order 2 -> Stage1
 *   ...
 *
 * Results:
 *   Orders accepted: 95
 *   Orders rejected (risk): 5
 *   Avg latency: 12ms/order
 *   Throughput:  83 orders/sec
 *
 * Serial (no pipeline): 48ms/order, 21 orders/sec
 * Speedup: 4.0x
 * ```
 */

int main() {}
