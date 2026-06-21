/*
 * ## EXERCISE 12: Time Sync — Hardware Timestamps and CLOCK_REALTIME [8.c.iv]
 *
 * Nanosecond-accurate timestamps are mandatory in trading. Understand the
 * sources of timestamp error and measure them.
 *
 * **Requirements:**
 * 1. Implement `getTimestampNs()` using four clock sources and compare:
 *    - `CLOCK_REALTIME` (wall clock, NTP-adjusted)
 *    - `CLOCK_MONOTONIC` (monotonic, no NTP jumps)
 *    - `CLOCK_MONOTONIC_RAW` (CPU TSC, no NTP smoothing)
 *    - `CLOCK_TAI` (International Atomic Time, no leap seconds)
 * 2. Measure the **cost of each clock call** (1M iterations):
 *    - `clock_gettime` overhead
 *    - Show that `rdtsc` is ~3× faster than `CLOCK_MONOTONIC`
 * 3. Implement `rdtsc()` using `__builtin_ia32_rdtsc()` and convert to
 *    nanoseconds using TSC frequency calibration
 * 4. Demonstrate **NTP adjustment hazard**: `CLOCK_REALTIME` can jump
 *    backwards during an NTP correction — show why this is catastrophic
 *    for sequencing and why `CLOCK_MONOTONIC` is safer for deltas
 * 5. Implement a `MonotonicTimestamper` that always produces increasing
 *    timestamps even if the underlying clock goes backwards
 *
 * **Expected output:**
 * ```
 * === Clock Source Benchmark (1M calls) ===
 *
 * CLOCK_REALTIME:      28ns per call
 * CLOCK_MONOTONIC:     27ns per call
 * CLOCK_MONOTONIC_RAW: 26ns per call
 * CLOCK_TAI:           28ns per call
 * rdtsc (calibrated):   9ns per call  (3x faster)
 *
 * === NTP Hazard Demo ===
 * CLOCK_REALTIME at t=0: 1705312345.123456789
 * Simulated NTP step:    -2ms correction applied
 * CLOCK_REALTIME at t=1: 1705312345.121456789  <- WENT BACKWARDS!
 *
 * CLOCK_MONOTONIC: always increasing  PASS
 * CLOCK_REALTIME:  can go backwards   HAZARD
 *
 * MonotonicTimestamper:
 *   Underlying clock went backwards by 2ms
 *   Output: max(new_ts, prev_ts + 1ns) = always increasing  PASS
 * ```
 */

int main() {}
