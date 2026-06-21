/*
 * ## EXERCISE 1: `std::async` and `std::future` — Basics [6.b.i]
 *
 * `std::async` launches a task and returns a `std::future` that carries the result.
 *
 * **Requirements:**
 * 1. Launch a bond-pricing computation asynchronously with `std::async(std::launch::async, ...)`
 * 2. Do other work in main while the computation runs
 * 3. Retrieve the result with `future.get()`
 * 4. Show the difference between `launch::async` (always new thread) and `launch::deferred`
 *    (lazy evaluation, runs on `get()` call in the calling thread)
 * 5. Demonstrate `future.wait()`, `future.wait_for()`, and `future.wait_until()`
 * 6. Show that calling `get()` a second time throws `std::future_error`
 * 7. Demonstrate exception propagation: an exception thrown in the async task is
 *    re-thrown at `get()`
 *
 * **Expected output:**
 * ```
 * === std::async basics ===
 *
 * Launched async bond pricer
 * Doing other work in main...
 *
 * Future ready? wait_for(0ms): not ready
 * Future ready? wait_for(50ms): ready
 *
 * Bond price: $1044.52
 *
 * === launch::deferred ===
 * Deferred task created (not started yet)
 * Calling get() now...
 * Deferred task running in thread: [main thread id]
 * Result: $1044.52
 *
 * === Exception propagation ===
 * Async task threw: std::runtime_error("invalid yield")
 * Caught in main: invalid yield
 *
 * === Double get() ===
 * First get(): $1044.52
 * Second get(): throws std::future_error: no state
 * ```
 */

int main() {}
