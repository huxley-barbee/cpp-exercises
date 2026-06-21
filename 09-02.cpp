/*
 * ## EXERCISE 2: Boost — Circular Buffer and Intrusive Containers [9.a]
 *
 * `boost::circular_buffer` is ideal for rolling windows in market data handlers.
 * `boost::intrusive` containers eliminate allocations in order book management.
 *
 * **Requirements:**
 * 1. Use `boost::circular_buffer<double>` to implement a **rolling VWAP**
 *    (Volume-Weighted Average Price) over the last N ticks:
 *    - Store `{price, volume}` pairs in the buffer
 *    - `vwap()`: returns `sum(price*volume) / sum(volume)`
 *    - Buffer is fixed capacity; oldest ticks evicted automatically
 * 2. Implement a **rolling volatility estimator**:
 *    - Use a `circular_buffer` of log-returns
 *    - `annualisedVol()` = `sqrt(252) * stddev(log_returns)`
 * 3. Use `boost::circular_buffer` as a **tick history** for a market data feed;
 *    show that push to a full buffer takes O(1) with no allocation
 * 4. Demonstrate `boost::intrusive::list` for an order book free list:
 *    - Pre-allocate a pool of `Order` objects
 *    - Orders on the free list cost zero allocation on new order
 *
 * **Expected output:**
 * ```
 * === Rolling VWAP (window=10 ticks) ===
 * After 5 ticks:  VWAP = $150.023
 * After 10 ticks: VWAP = $150.031
 * After 15 ticks: VWAP = $150.028  (oldest 5 evicted, window full)
 * 0 heap allocations after initial construction  PASS
 *
 * === Rolling Volatility (252-tick window) ===
 * After 252 ticks: annualised vol = 22.4%
 * After 300 ticks: annualised vol = 21.8%  (rolling window)
 *
 * === Intrusive Order Free List ===
 * Pool: 1000 pre-allocated Order objects
 * New order: allocated from pool (0 heap allocs)  PASS
 * Delete order: returned to pool                  PASS
 * ```
 */

int main() {}
