/*
 * ## EXERCISE 7: Atomics — `std::atomic` Fundamentals [6.a.iii]
 *
 * **Requirements:**
 * 1. Demonstrate all basic atomic operations on `std::atomic<int>`:
 *    `load`, `store`, `fetch_add`, `fetch_sub`, `fetch_and`, `fetch_or`, `exchange`
 * 2. Show `compare_exchange_weak` in a CAS retry loop to implement a lock-free counter
 * 3. Show `compare_exchange_strong` for a single-attempt swap
 * 4. Demonstrate `std::atomic<bool>` as a ready-flag between producer and consumer
 * 5. Show `std::atomic<double>` — note it may not be lock-free on all platforms;
 *    use `is_lock_free()` to check
 * 6. Demonstrate `std::atomic_flag` (always lock-free): implement a spinlock
 * 7. Benchmark the spinlock against `std::mutex` for a short critical section (1–10 instructions)
 *
 * **Expected output:**
 * ```
 * === Atomic Operations ===
 * load():       42
 * store(100):   100
 * fetch_add(5): old=100 new=105
 * fetch_sub(3): old=105 new=102
 * exchange(0):  old=102 new=0
 * fetch_or(0b1010): 0 | 10 = 10
 * fetch_and(0b1100): 10 & 12 = 8
 *
 * === CAS Loop (lock-free increment) ===
 * 10 threads x 100K CAS increments
 * Result: 1000000  PASS
 *
 * === atomic<bool> ready flag ===
 * Producer: data=42, ready.store(true, release)
 * Consumer: while(!ready.load(acquire)); data=42  PASS
 *
 * === atomic<double> ===
 * is_lock_free: true (x86_64 with SSE2)
 * Operations: load, store (no fetch_add — use CAS loop)
 *
 * === atomic_flag spinlock ===
 * Spinlock vs mutex (1M lock/unlock, 2 threads):
 *   spinlock:  38ms  (fast for tiny critical sections)
 *   mutex:    185ms
 *   spinlock wins when: contention is low AND critical section < ~50ns
 *   mutex wins when:    contention is high OR thread may sleep
 * ```
 */

int main() {}
