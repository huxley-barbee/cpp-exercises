/*
 * ## EXERCISE 9: Profilers — Memory Profiling [7.b.iii]
 *
 * Memory allocation patterns are a major source of latency in trading systems.
 * Find and fix allocation hot spots.
 *
 * **Requirements:**
 *
 * Write `alloc_heavy.cpp` with three allocation patterns:
 * 1. A function that allocates a `std::string` on every tick (100K ticks)
 * 2. A function that allocates a `std::vector<double>` per risk calculation
 * 3. A function using an object pool (pre-allocated, zero allocation per tick)
 *
 * Tools to use:
 * 1. `valgrind --tool=massif ./alloc_heavy` + `ms_print massif.out.PID`
 * 2. `heaptrack ./alloc_heavy` (if available)
 * 3. Manual allocation counting using a custom `operator new` override
 * 4. Show peak heap usage for each pattern
 * 5. Fix pattern 1 (use `std::string_view` or a fixed buffer)
 * 6. Fix pattern 2 (reuse the vector, just call `clear()` and `resize()`)
 * 7. Compare peak heap usage before and after
 *
 * **Expected output:**
 * ```
 * === Allocation Profiling ===
 *
 * Pattern 1 (string per tick, 100K ticks):
 *   Total allocations:  100,000
 *   Peak heap:          2.4 MB
 *   Allocation rate:    ~24 bytes/tick
 *
 * Pattern 2 (vector per risk calc, 10K calcs):
 *   Total allocations:  10,000
 *   Peak heap:          820 KB
 *
 * Pattern 3 (object pool):
 *   Total allocations:  1  (at startup)
 *   Peak heap:          64 KB
 *   Allocation rate:    0 bytes/tick
 *
 * === After fixes ===
 * Pattern 1 (string_view / fixed buffer):
 *   Total allocations:  0 per tick
 *   Allocation rate:    0 bytes/tick
 *
 * Pattern 2 (vector reuse):
 *   Total allocations:  1
 *   Allocation rate:    0 bytes/calc
 *
 * Peak heap reduction: 2.4MB -> 64KB (97% reduction)
 * ```
 */

int main() {}
