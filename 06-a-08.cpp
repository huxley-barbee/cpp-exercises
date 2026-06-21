/*
 * ## EXERCISE 8: Atomics — Lock-Free Data Structures [6.a.iii]
 *
 * **Requirements:**
 * 1. Implement a **lock-free single-producer single-consumer (SPSC) queue** of `int`s
 *    with capacity 1024 using two `std::atomic<uint64_t>` indices
 * 2. Verify correctness: producer sends 10M items, consumer sums them
 * 3. Implement a **lock-free multi-producer single-consumer (MPSC) counter** using CAS
 * 4. Demonstrate a **lock-free stack** (Treiber stack) — push and pop with CAS on head
 * 5. For each structure, show:
 *    - Which memory orderings are used and why
 *    - Whether it is wait-free or lock-free (but not wait-free)
 *    - The ABA risk (if any) and mitigation
 * 6. Benchmark against the equivalent `std::queue`/`std::stack` + `std::mutex`
 *
 * **Expected output:**
 * ```
 * === SPSC Queue ===
 * Producer: 10M ints
 * Consumer sum: 49999995000000  PASS
 *
 * Benchmark (10M items):
 *   SPSC queue:    180ms   18ns/item
 *   queue+mutex:  2800ms  280ns/item
 *   Speedup: 15.6x
 *
 * === MPSC Counter ===
 * 8 threads x 125K CAS increments
 * Result: 1000000  PASS
 * Memory order: fetch_add(relaxed) — no ordering needed for pure counter
 *
 * === Lock-Free Stack ===
 * push(1), push(2), push(3)
 * pop() -> 3, pop() -> 2, pop() -> 1  (LIFO)
 * Correctness: PASS
 *
 * === Properties ===
 * SPSC queue:  wait-free (no loops) — one producer, one consumer
 * MPSC counter: wait-free (fetch_add is single instruction)
 * Treiber stack: lock-free (CAS may retry but system progresses)
 *   ABA risk: mitigated with tagged pointers or epoch reclamation
 * ```
 */

int main() {}
