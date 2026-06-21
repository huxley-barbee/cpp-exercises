/*
 * ## EXERCISE 3: Memory Layout — Virtual Memory and Page Faults [5.a.i]
 *
 * Linux uses virtual memory with demand paging. Pages are not physically allocated until
 * first accessed. Write a program that observes this.
 *
 * **Requirements:**
 * 1. Allocate a large buffer (256 MB) with `mmap(MAP_ANONYMOUS | MAP_PRIVATE)`
 * 2. Measure the time to allocate (should be near-zero — pages not committed yet)
 * 3. Touch every page (write one byte per 4096 bytes) and measure the time
 * 4. Repeat but pre-fault the memory with `MAP_POPULATE` — compare times
 * 5. Use `/proc/self/status` to read `VmRSS` (resident set size) before and after touching
 * 6. Demonstrate `mlock` to pin pages and prevent swapping (relevant for latency-critical code)
 * 7. Show `munmap` for cleanup
 * 8. Explain the relevance to trading systems: pre-faulting ring buffers at startup eliminates
 *    latency spikes during live trading
 *
 * **Expected output:**
 * ```
 * === Virtual Memory and Page Faults ===
 *
 * Allocating 256MB with mmap (no MAP_POPULATE):
 *   Time to allocate: 0.05ms   (virtual only — no physical pages)
 *   VmRSS before touch: ~5MB   (only stack/text resident)
 *
 * Touching all pages (first access — page faults):
 *   Time to touch 65536 pages: 180ms
 *   VmRSS after touch: ~261MB  (pages now resident)
 *
 * Allocating 256MB with MAP_POPULATE (pre-fault):
 *   Time to allocate+fault: 175ms  (faults happen at alloc time)
 *   VmRSS immediately: ~261MB
 *
 * Locking pages with mlock:
 *   mlock(256MB): pages pinned — OS will not swap them out
 *   Relevant for trading: eliminates swap-in latency spikes
 *
 * Cleanup: munmap — pages returned to OS
 *   VmRSS after munmap: ~5MB
 *
 * Trading system lesson:
 *   Pre-fault all ring buffers and shared memory at startup.
 *   Use mlock for latency-critical buffers.
 * ```
 */

int main() {}
