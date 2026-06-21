/*
 * ## EXERCISE 2: `std::promise` and `std::future` — Manual Signalling [6.b.i]
 *
 * `std::promise` is the write-end of a future channel. It lets you decouple the
 * producer of a value from its consumer across threads.
 *
 * **Requirements:**
 * 1. Create a `std::promise<double>` and get its associated `std::future<double>`
 * 2. Spawn a thread that performs a computation and calls `promise.set_value(result)`
 * 3. Main thread calls `future.get()` — blocks until the promise is fulfilled
 * 4. Show `promise.set_exception()` to propagate an error
 * 5. Implement a one-shot event flag using `promise<void>` / `future<void>`
 * 6. Show the "broken promise" case: promise destroyed without `set_value` →
 *    `std::future_error` with `broken_promise` code at `get()`
 * 7. Demonstrate `std::shared_future` for broadcasting a single result to multiple
 *    consumer threads — all can call `get()` safely
 *
 * **Expected output:**
 * ```
 * === promise/future channel ===
 * Main: waiting for price computation...
 * Worker: computing price...
 * Worker: set_value($1044.52)
 * Main: received $1044.52
 *
 * === promise set_exception ===
 * Worker: throwing invalid_argument
 * Main: caught: invalid yield rate
 *
 * === promise<void> event flag ===
 * Main: waiting for market open signal...
 * Signal thread: market is open!
 * Main: received market open signal, proceeding
 *
 * === Broken promise ===
 * Promise destroyed without set_value
 * Future get() threw: broken promise
 *
 * === shared_future (1 result -> 4 consumers) ===
 * Consumer 1: received $1044.52
 * Consumer 2: received $1044.52
 * Consumer 3: received $1044.52
 * Consumer 4: received $1044.52
 * All consumers received the same result
 * ```
 */

int main() {}
