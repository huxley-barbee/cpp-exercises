/*
 * ## EXERCISE 10: CPU Cache Hierarchy — False Sharing [5.a.iv]
 *
 * False sharing is one of the most common performance bugs in multi-threaded C++ code.
 * Two threads modify different variables that happen to share a cache line.
 *
 * **Requirements:**
 * 1. Create a struct with two `int` counters `a` and `b` on the *same* cache line (adjacent)
 * 2. Run two threads: thread 1 increments `a` 10M times, thread 2 increments `b` 10M times
 * 3. Measure the total time — it will be much slower than single-threaded due to false sharing
 * 4. Fix by padding each counter to its own cache line using `alignas(64)` or a padding array
 * 5. Measure again — show the speedup (typically 4–10×)
 * 6. Show the same fix using `std::hardware_destructive_interference_size` (C++17)
 * 7. Demonstrate in a lock-free order book counter: bid count and ask count falsely shared
 *    vs properly padded
 *
 * **Expected output:**
 * ```
 * === False Sharing Demo ===
 *
 * Struct layout (false sharing):
 *   struct Counters { int a; int b; };
 *   &a = 0x[addr], &b = 0x[addr+4]  <- same cache line!
 *
 * Two threads, 10M increments each:
 *   With false sharing:    1850ms  (cache line bouncing between cores)
 *   Without false sharing: 210ms   (each core owns its cache line)
 *   Speedup: 8.8x
 *
 * === Cache Line Padding ===
 *
 * struct PaddedCounters {
 *     alignas(64) int a;
 *     alignas(64) int b;
 * };
 *
 * &a = 0x[addr],     (cache line 1)
 * &b = 0x[addr+64],  (cache line 2 — no sharing)
 *
 * === C++17: hardware_destructive_interference_size ===
 * std::hardware_destructive_interference_size = 64 bytes
 * alignas(std::hardware_destructive_interference_size) int a;
 *
 * === Order Book Counter (trading example) ===
 * Falsely shared  bid/ask counters: 1820ms
 * Padded bid/ask counters:           205ms
 * Speedup: 8.9x
 *
 * Rule: any hot variable written by one thread and read/written by another
 *       must be on its own cache line.
 * ```
 */

int main() {}
