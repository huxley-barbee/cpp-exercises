/*
 * ## EXERCISE 9: Lock-Free Concepts — SPSC Ring Buffer [5.b.iii]
 *
 * The Single-Producer Single-Consumer (SPSC) ring buffer is the workhorse of low-latency
 * market-data pipelines. It needs only `acquire`/`release` — no CAS required.
 *
 * **Requirements:**
 * 1. Implement `SPSCQueue<T, N>` (power-of-two N):
 *    - Write index owned by producer (on its own cache line)
 *    - Read index owned by consumer (on its own cache line)
 *    - `push(const T&)` returns bool (false if full)
 *    - `pop(T&)` returns bool (false if empty)
 * 2. Verify: producer writes 10M `int`s; consumer reads and sums — verify sum
 * 3. Benchmark: measure throughput and average latency per item
 * 4. Compare with `std::queue<T>` + `std::mutex`
 * 5. Show why `relaxed` loads of the *other thread's* index are wrong (stale visibility)
 *    and why `acquire`/`release` are the minimum correct ordering
 * 6. Show the false-sharing fix: producer and consumer indices on separate cache lines
 *
 * **Expected output:**
 * ```
 * === SPSC Queue Correctness ===
 * Producer: 10M ints (sum expected: 49999995000000)
 * Consumer sum: 49999995000000  PASS
 *
 * === Benchmark (10M items) ===
 * std::queue + mutex:  2800ms   280ns/item
 * SPSCQueue:            180ms    18ns/item
 * Speedup: 15.6x
 *
 * === Memory Ordering ===
 * Producer writes:
 *   data[writeIdx & MASK] = val;
 *   writeIdx.store(writeIdx+1, memory_order_release);  // publish
 *
 * Consumer reads:
 *   uint64_t w = writeIdx.load(memory_order_acquire);  // see published data
 *   val = data[readIdx & MASK];
 *   readIdx.store(readIdx+1, memory_order_release);    // return slot
 *
 * Using relaxed on writeIdx.load: consumer may see stale index
 *   -> appears empty when it is not -> incorrect behaviour
 *
 * === Cache Lines ===
 * writeIdx at offset 0  (producer's cache line)
 * readIdx  at offset 64 (consumer's cache line — no false sharing)
 * ```
 */

int main() {}
