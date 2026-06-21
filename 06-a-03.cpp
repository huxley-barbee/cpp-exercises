/*
 * ## EXERCISE 3: Mutexes — Preventing Data Races [6.a.i]
 *
 * **Requirements:**
 * 1. Demonstrate a **data race**: two threads increment a plain `int` counter 1M times
 *    each — show the final value is less than 2M (race condition)
 * 2. Fix with `std::mutex` + `std::lock_guard` — show the final value is exactly 2M
 * 3. Fix with `std::atomic<int>` — show the same result, measure the speed difference
 * 4. Use `std::unique_lock` to demonstrate:
 *    - Deferred locking: `std::unique_lock lk(m, std::defer_lock)`
 *    - `try_lock()` with a timeout (`std::timed_mutex`)
 *    - Manual `unlock()` to release before end of scope
 * 5. Demonstrate `std::scoped_lock` to lock two mutexes deadlock-free
 * 6. Show the RAII guarantee: mutex is always released even if an exception is thrown
 *    inside the locked region
 *
 * **Expected output:**
 * ```
 * === Data Race (unfixed) ===
 * Two threads, 1M increments each
 * Expected: 2000000
 * Got:      1843219  (RACE — varies each run)
 *
 * === Fixed with mutex ===
 * Got: 2000000  CORRECT
 *
 * === Fixed with atomic ===
 * Got: 2000000  CORRECT
 *
 * === Timing (1M increments, 2 threads) ===
 * mutex:   185ms
 * atomic:   42ms   (4.4x faster)
 *
 * === unique_lock deferred ===
 * Lock acquired manually after construction
 * Lock released early (before scope end)
 *
 * === timed_mutex try_lock ===
 * Thread 1: acquired lock
 * Thread 2: try_lock_for(50ms) -> FAILED (thread 1 holding)
 * Thread 1: released
 *
 * === scoped_lock (two mutexes) ===
 * Acquired m1 and m2 atomically — no deadlock
 *
 * === Exception safety ===
 * Exception thrown inside locked region
 * lock_guard destructor: mutex released  (RAII guarantee)
 * ```
 */

int main() {}
