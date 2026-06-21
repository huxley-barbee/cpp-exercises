/*
 * ## EXERCISE 7: Lock-Free Concepts — `std::atomic` Basics [5.b.iii]
 *
 * Before writing lock-free data structures you must understand atomic operations
 * and memory ordering.
 *
 * **Requirements:**
 * 1. Demonstrate all six memory orderings with `std::atomic<int>`:
 *    `relaxed`, `consume`, `acquire`, `release`, `acq_rel`, `seq_cst`
 * 2. Write a producer/consumer flag using `release`/`acquire` — prove the message is
 *    always visible to the consumer
 * 3. Show the cost of each ordering using a tight benchmark (1M atomic operations)
 * 4. Demonstrate compare-and-swap (CAS) with `compare_exchange_weak` and
 *    `compare_exchange_strong` — explain when to use each
 * 5. Show ABA problem with CAS and how to mitigate (tagged pointer / version counter)
 * 6. Demonstrate `std::atomic_thread_fence` as a standalone fence
 *
 * **Expected output:**
 * ```
 * === Memory Ordering Costs (1M ops, single thread) ===
 * relaxed:   8ms   (~8ns)   no synchronisation
 * consume:   8ms   (~8ns)   data dependency only
 * acquire:   9ms   (~9ns)   one-way barrier (load side)
 * release:   9ms   (~9ns)   one-way barrier (store side)
 * acq_rel:  10ms  (~10ns)   both barriers
 * seq_cst:  45ms  (~45ns)   full fence — most expensive
 *
 * === Producer/Consumer with release/acquire ===
 * Producer: data=42, flag.store(1, release)
 * Consumer: while(!flag.load(acquire)); assert(data==42) -> PASS
 *
 * === CAS Demo ===
 * compare_exchange_weak:   may fail spuriously (use in retry loop)
 * compare_exchange_strong: no spurious failure (use for single attempt)
 *
 * CAS loop: 10 threads incrementing shared counter via CAS
 * Result: 10000  (correct — no lost updates)
 *
 * === ABA Problem ===
 * Thread 1 reads A, thread 2 changes A->B->A
 * Thread 1 CAS succeeds (sees A) — but state has changed!
 * Fix: tag the pointer with a version counter
 *   atomic<pair<ptr, uint64_t>> — version incremented on every change
 * ```
 */

int main() {}
