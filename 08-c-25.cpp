/*
 * ## EXERCISE 25: System Hardening — Latency Spike Mitigation [8.c.i–v]
 *
 * Latency spikes (jitter) are as damaging as average latency in HFT.
 * Identify and mitigate the common sources.
 *
 * **Requirements:**
 * 1. Identify and demonstrate five sources of latency spikes:
 *    - **TLB shootdowns**: `mprotect()` on a shared mapping; show the stall
 *    - **Page faults**: access a new memory page during trading; measure cost
 *    - **Context switches**: `sleep(0)` or `sched_yield()`; measure preemption latency
 *    - **GCC false sharing**: two threads updating adjacent cache-line variables
 *    - **Timer coalescing**: kernel batches timer interrupts; show jitter at 1ms boundaries
 * 2. Implement mitigations for each:
 *    - Pre-fault all memory at startup (`mlockall(MCL_CURRENT | MCL_FUTURE)`)
 *    - CPU affinity + `SCHED_FIFO` to minimise context switches
 *    - `alignas(64)` on hot variables to prevent false sharing
 *    - `CLOCK_MONOTONIC_RAW` with TSC to avoid timer interrupt jitter
 * 3. Measure the latency improvement for each mitigation
 * 4. Implement a **latency spike detector**: log any operation taking > 10× its
 *    median latency as an anomaly
 *
 * **Expected output:**
 * ```
 * === Latency Spike Sources ===
 *
 * TLB shootdown (mprotect on shared mapping):
 *   Without mitigation: spike=42µs  (TLB flush on all cores)
 *   With mitigation (no mprotect after init): spike=0
 *
 * Page fault (first access to new page):
 *   Without mlockall: fault=8,200ns
 *   With mlockall:    fault=0ns (pre-faulted at startup)  PASS
 *
 * Context switch (SCHED_OTHER):
 *   Preemption jitter: up to 500µs
 *   With SCHED_FIFO:  jitter < 10µs  PASS
 *
 * False sharing (adjacent cache line):
 *   Without alignas: extra latency=38ns per operation (cache bouncing)
 *   With alignas(64): 0ns extra  PASS
 *
 * Timer coalescing jitter: 80-120µs at 1ms boundaries
 *   With TSC timestamps (no timer dependency): < 1µs  PASS
 *
 * === Latency spike detector ===
 * Threshold: > 10x median (>880ns for median=88ns)
 * Spikes detected in 1M ticks: 847 (0.085%)
 * Most common cause: context switch (OS jitter)
 * ```
 */

int main() {}
