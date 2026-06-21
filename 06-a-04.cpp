/*
 * ## EXERCISE 4: Mutexes — Deadlock and How to Avoid It [6.a.i]
 *
 * **Requirements:**
 * 1. Demonstrate a **deadlock**: two threads each hold one mutex and wait for the other
 *    (run for 2 seconds then break out — use `try_lock` to detect and abort)
 * 2. Fix with **lock ordering**: always acquire mutexes in a consistent global order
 * 3. Fix with `std::scoped_lock(m1, m2)` (uses deadlock-avoidance algorithm internally)
 * 4. Fix with `std::lock(m1, m2)` then adopt with `std::lock_guard`
 * 5. Demonstrate **livelock**: two threads each back off and retry — show it resolving
 * 6. Demonstrate **priority inversion** concept: a high-priority thread blocked on a mutex
 *    held by a low-priority thread (explain, no code required — write as detailed comment)
 * 7. Show the trading-system rule: in a market-data handler, never hold a lock while
 *    calling external code (callbacks, logging, I/O)
 *
 * **Expected output:**
 * ```
 * === Deadlock Demo ===
 * Thread A: acquired mutex1, waiting for mutex2...
 * Thread B: acquired mutex2, waiting for mutex1...
 * DEADLOCK detected after 2s — aborting with try_lock
 *
 * === Fix 1: Lock Ordering ===
 * Both threads acquire in order: mutex1 then mutex2
 * No deadlock — thread B waits while A holds both
 *
 * === Fix 2: scoped_lock ===
 * std::scoped_lock lock(m1, m2)  -> atomically acquires both
 * No deadlock possible
 *
 * === Fix 3: std::lock + adopt ===
 * std::lock(m1, m2)
 * std::lock_guard lk1(m1, std::adopt_lock)
 * std::lock_guard lk2(m2, std::adopt_lock)
 *
 * === Livelock ===
 * Thread A backs off (1ms), Thread B backs off (1ms)
 * Thread A retries... Thread B retries...
 * Resolved after 3 attempts (randomised backoff)
 *
 * === Trading Rule ===
 * // NEVER do this:
 * // {
 * //   std::lock_guard lk(price_mutex);
 * //   callback(price);   // callback may acquire another lock -> deadlock
 * //   log(price);        // logger may block -> latency spike
 * // }
 * // DO this: copy data out, release lock, then call external code
 * ```
 */

int main() {}
