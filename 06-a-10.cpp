/*
 * ## EXERCISE 10: Memory Ordering — Happens-Before and Synchronises-With [6.a.iv]
 *
 * **Requirements:**
 * 1. Demonstrate **synchronises-with**: a `release` store synchronises-with an
 *    `acquire` load on the same atomic — everything before the store is visible
 *    after the load
 * 2. Build a three-thread example: thread A writes data, stores a flag with `release`;
 *    thread B loads flag with `acquire`, reads data, stores a second flag with `release`;
 *    thread C loads second flag with `acquire` and reads the original data — show
 *    transitivity: A's data is visible to C even though C never directly synchronised
 *    with A
 * 3. Demonstrate **happens-before is not total order** under `relaxed`: two independent
 *    stores may be seen in different orders by different threads
 * 4. Show the **double-checked locking pattern** (DCLP) done correctly with atomics
 * 5. Implement a correct **once-flag** (like `std::call_once` but manual) using
 *    `compare_exchange_strong` and `release`/`acquire`
 *
 * **Expected output:**
 * ```
 * === Synchronises-With ===
 * A: data=42; flag_A.store(1, release)
 * B: while(!flag_A.load(acquire)); assert(data==42) PASS
 *    result=84; flag_B.store(1, release)
 * C: while(!flag_B.load(acquire)); assert(result==84) PASS
 *    (C also sees data==42 by transitivity)
 *
 * === Relaxed: No Total Order ===
 * Two threads store x and y with relaxed
 * Two observers may see (x=1,y=0) and (x=0,y=1) simultaneously
 * This is allowed — relaxed has no cross-thread ordering
 *
 * === Double-Checked Locking (correct) ===
 * atomic<Singleton*> instance{nullptr}
 * Thread 1: loads null -> acquires mutex -> creates -> stores(release)
 * Thread 2: loads non-null(acquire) -> uses directly — no mutex needed
 * Thread 3: same as thread 2
 *
 * === Manual Once-Flag ===
 * call_once_manual: 8 threads race to init
 * Init ran exactly: 1 time  PASS
 * ```
 */

int main() {}
