/*
 * ## EXERCISE 11: Mutexes + Atomics — Condition Variables [6.a.i]
 *
 * **Requirements:**
 * 1. Implement a **thread-safe bounded queue** using `std::mutex` +
 *    `std::condition_variable` with `wait`, `notify_one`, `notify_all`
 * 2. Show the **spurious wakeup** problem and the predicate loop fix:
 *    `cv.wait(lk, []{ return !queue.empty(); })`
 * 3. Use `wait_for` with a timeout to implement a non-blocking consumer with a deadline
 * 4. Model a **market-data fan-out**: one publisher notifies N subscriber threads
 *    using `notify_all`
 * 5. Demonstrate `std::condition_variable_any` with a `std::shared_mutex`
 * 6. Show `std::counting_semaphore` (C++20) as a lighter alternative to CV + counter
 *
 * **Expected output:**
 * ```
 * === Bounded Queue (capacity=16) ===
 * Producer: 1000 items
 * Consumer: 1000 items received, sum correct  PASS
 *
 * === Spurious Wakeup Fix ===
 * while (!predicate()) cv.wait(lk)
 * // or equivalently:
 * cv.wait(lk, predicate)
 *
 * === wait_for timeout ===
 * Consumer: waited 100ms, no data -> timeout, returning nullopt
 *
 * === Market-Data Fan-Out ===
 * Publisher: new price $150.25 -> notify_all
 * Subscriber 1: received $150.25
 * Subscriber 2: received $150.25
 * Subscriber 3: received $150.25
 * All 3 subscribers updated atomically
 *
 * === counting_semaphore ===
 * std::counting_semaphore<16> slots(16)
 * Producer: acquire slot, write item, release
 * Consumer: acquire item count, read, release slot
 * Simpler than CV for pure producer/consumer counting
 * ```
 */

int main() {}
