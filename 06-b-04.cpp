/*
 * ## EXERCISE 4: `std::future` Chaining and `std::when_all` Patterns [6.b.i]
 *
 * C++ does not have `then()` chaining natively (that's C++23 `std::execution`),
 * but you can simulate it. This exercise also covers collecting multiple futures.
 *
 * **Requirements:**
 * 1. Launch 8 async pricing tasks (one per instrument)
 * 2. Collect all futures in a `std::vector<std::future<double>>`
 * 3. Implement a `waitAll(futures)` helper that calls `get()` on each in order
 * 4. Implement a `waitAny(futures)` helper using `wait_for(0ms)` polling — returns the
 *    index of the first ready future
 * 5. Compute the total portfolio value as the sum of all results
 * 6. Show timeout handling: if any task takes more than 500ms, use a default value
 * 7. Implement a simple `then()` simulation: chain `async` calls where the second
 *    depends on the result of the first
 *
 * **Expected output:**
 * ```
 * === Parallel portfolio pricing (8 instruments) ===
 * Launched 8 async pricers
 *
 * waitAny: instrument 3 finished first (fastest computation)
 *
 * All results:
 *   Instrument 0: $1044.52
 *   Instrument 1: $155.00
 *   Instrument 2: $8.75
 *   Instrument 3: $72.40
 *   ...
 *   Instrument 7: $210.00
 *
 * Total portfolio value: $1823.45
 *
 * === Timeout handling ===
 * Instrument 5 timed out (>500ms), using default $0.00
 *
 * === then() simulation ===
 * Stage 1: fetch market data -> $150.00
 * Stage 2: price option using market data -> $10.45
 * Stage 3: compute delta -> 0.823
 * Pipeline result: delta=0.823
 * ```
 */

int main() {}
