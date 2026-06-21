/*
 * ## EXERCISE 4: Cache-Aware Programming — Prefetching [5.b.ii]
 *
 * Manual software prefetching can hide memory latency in streaming loops.
 *
 * **Requirements:**
 * 1. Write a streaming loop that processes a 256 MB array sequentially (e.g., prefix sum)
 * 2. Version A: no prefetch
 * 3. Version B: `__builtin_prefetch(ptr + DIST, 0, 1)` with varying `DIST` (8, 16, 32, 64 lines ahead)
 * 4. Find the optimal prefetch distance for your hardware
 * 5. Write a gather loop (indirect access via an index array) and apply prefetch
 * 6. Show when prefetching hurts: if the computation is compute-bound, prefetching the next
 *    cache line adds noise without benefit
 * 7. Demonstrate `_mm_prefetch` (SSE intrinsic) as an alternative
 * 8. Rule of thumb: prefetch distance = memory latency / loop iteration time
 *
 * **Expected output:**
 * ```
 * === Streaming Prefetch Benchmark (256MB) ===
 *
 * Prefetch distance    Time     Bandwidth    Notes
 * None                 175ms    1.46 GB/s    hardware prefetcher works well here
 * +8 lines             160ms    1.60 GB/s
 * +16 lines            148ms    1.72 GB/s    sweet spot on this machine
 * +32 lines            152ms    1.68 GB/s
 * +64 lines            165ms    1.55 GB/s    prefetching too far ahead (evicts cache)
 *
 * === Gather Loop (indirect access) ===
 * Without prefetch: 850ms   (cache miss per element)
 * With prefetch:    520ms   (latency hidden)
 * Speedup: 1.6x
 *
 * === When Prefetch Hurts ===
 * Compute-bound loop (heavy FP): no improvement from prefetch
 *   (CPU already busy — prefetch buffer fills, evicts useful data)
 *
 * Rule: prefetch 10-20 iterations ahead for streaming;
 *       measure before committing to a distance.
 * ```
 */

int main() {}
