/*
 * ## EXERCISE 6: Syscalls — Timing and Clock Sources [5.a.ii]
 *
 * Accurate timestamping is critical in trading systems. Write a program that explores
 * all major clock sources and measures their overhead.
 *
 * **Requirements:**
 * 1. Benchmark all four `CLOCK_*` sources: `CLOCK_REALTIME`, `CLOCK_MONOTONIC`,
 *    `CLOCK_MONOTONIC_RAW`, `CLOCK_PROCESS_CPUTIME_ID`
 * 2. Use `__rdtsc()` (x86 TSC) directly and convert cycles to nanoseconds
 * 3. Show the resolution of each clock using `clock_getres()`
 * 4. Demonstrate the vDSO optimisation: `CLOCK_REALTIME` and `CLOCK_MONOTONIC` avoid
 *    the kernel transition; `CLOCK_MONOTONIC_RAW` does not
 * 5. Measure the overhead of each in a tight loop (1 million calls)
 * 6. Show `CLOCK_TAI` for financial timestamps (no leap-second ambiguity)
 * 7. Recommend the right clock for each trading use case:
 *    - Order timestamps: `CLOCK_REALTIME` or `CLOCK_TAI`
 *    - Latency measurement: `CLOCK_MONOTONIC` or TSC
 *    - CPU profiling: `CLOCK_PROCESS_CPUTIME_ID`
 *
 * **Expected output:**
 * ```
 * === Clock Sources ===
 *
 * Clock               Resolution    Overhead(1M calls)  vDSO?
 * CLOCK_REALTIME      1ns           12ms  (~12ns)        YES
 * CLOCK_MONOTONIC     1ns           12ms  (~12ns)        YES
 * CLOCK_MONOTONIC_RAW 1ns           380ms (~380ns)       NO (syscall)
 * CLOCK_PROCESS_CPU   1ns           15ms  (~15ns)        YES
 * RDTSC               1 cycle       2ms   (~2ns)         N/A
 *
 * === TSC: Cycles to Nanoseconds ===
 * CPU frequency: ~3.6 GHz
 * 1 TSC tick = 0.278 ns
 * rdtsc overhead: ~20 cycles (~5.5ns)
 *
 * === Clock Resolution ===
 * CLOCK_REALTIME      res: 1ns
 * CLOCK_MONOTONIC     res: 1ns
 * CLOCK_MONOTONIC_RAW res: 1ns
 *
 * === Trading Recommendations ===
 * Order timestamps:    CLOCK_REALTIME (wall-clock, NTP-synced)
 * Latency measurement: CLOCK_MONOTONIC or RDTSC (monotonic, no jumps)
 * CPU profiling:       CLOCK_PROCESS_CPUTIME_ID
 * Leap-second safe:    CLOCK_TAI
 * ```
 */

int main() {}
