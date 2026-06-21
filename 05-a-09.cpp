/*
 * ## EXERCISE 9: CPU Cache Hierarchy — Measuring Cache Effects [5.a.iv]
 *
 * The cache hierarchy is the single biggest factor in hot-loop performance. Write a
 * program that directly measures L1, L2, and L3 cache latencies.
 *
 * **Requirements:**
 * 1. Allocate arrays of increasing size: 4KB, 32KB, 256KB, 4MB, 64MB
 * 2. For each size, perform a **sequential read** pass and a **random read** pass
 * 3. Plot (print) latency vs array size to identify the cache boundaries:
 *    - Sequential: L1 (~1ns), L2 (~4ns), L3 (~12ns), RAM (~60ns)
 *    - Random: similar boundaries but much more pronounced (pointer chasing)
 * 4. Implement a pointer-chasing benchmark (linked list with shuffled nodes) for the
 *    random case — this directly measures cache miss latency
 * 5. Show the bandwidth test: sequentially sum all elements as fast as possible
 * 6. Use `CLOCK_MONOTONIC` or RDTSC for timing
 * 7. Print a table of latency per element for each size
 *
 * **Expected output:**
 * ```
 * === Cache Hierarchy Benchmark ===
 *
 * Array Size   Sequential Latency   Random Latency   Notes
 * 4 KB         0.9 ns/elem          1.1 ns/elem      L1 cache (32KB)
 * 32 KB        1.0 ns/elem          1.2 ns/elem      L1/L2 boundary
 * 256 KB       3.5 ns/elem          8.0 ns/elem      L2 cache (256KB)
 * 4 MB         10.0 ns/elem         40.0 ns/elem     L3 cache (8MB)
 * 64 MB        14.0 ns/elem         62.0 ns/elem     Main RAM
 *
 * L1 cache:  ~32KB,  ~1ns
 * L2 cache:  ~256KB, ~4ns
 * L3 cache:  ~8MB,   ~12ns
 * Main RAM:           ~60ns
 *
 * === Pointer Chasing (pure cache miss latency) ===
 * Chasing 1M pointers through 64MB array:
 *   Time per chase: 62ns  (one DRAM access per step)
 *
 * === Sequential Bandwidth ===
 * Summing 64MB array: 15.2 GB/s  (limited by L3/RAM bandwidth)
 * ```
 */

int main() {}
