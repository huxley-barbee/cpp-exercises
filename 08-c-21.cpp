/*
 * ## EXERCISE 21: Putting It Together — Feed Arbitration Under Failure [8.c.iii]
 *
 * Test the feed arbitrator's behaviour during realistic failure scenarios.
 *
 * **Requirements:**
 * 1. Simulate three failure modes and verify correct arbitration:
 *    - **Feed 0 packet loss**: random 1% packet drop
 *    - **Feed 1 latency spike**: occasional 1ms delay burst
 *    - **Feed 2 disconnect**: complete disconnect for 30 seconds
 * 2. Verify that the arbitrator produces a **continuous, gap-free sequence**
 *    to downstream consumers in all three scenarios
 * 3. Measure the **arbitration overhead** added to the best-path latency
 * 4. Show **feed correlation analysis**: if two feeds both produce outlier
 *    latency at the same time, it indicates a market event, not a feed fault
 * 5. Implement an **automatic quality degradation policy**: reduce a feed's
 *    weight when it shows persistent high latency
 * 6. Produce a failure report showing switchover events and their causes
 *
 * **Expected output:**
 * ```
 * === Feed Arbitration Failure Tests ===
 *
 * Test 1: 1% packet loss on Feed 0
 *   Gap fills from Feed 1: 7,140 (1% of 714K messages)
 *   Downstream gaps: 0  PASS
 *   Extra latency from gap fill: +3.2µs avg
 *
 * Test 2: 1ms latency spike on Feed 1 (100ms duration)
 *   Spike detected after 5 outliers: 12µs -> 1,200µs
 *   Feed 1 weight reduced: 1.0 -> 0.2
 *   Feed 0 wins 94% of arbitrations during spike
 *   Recovery: Feed 1 weight restored after 500ms quiet period
 *
 * Test 3: Feed 2 disconnect (30 seconds)
 *   Reconnect attempted: 30 times (1/sec backoff)
 *   Reconnected at t=30.4s
 *   Downstream impact: 0  (Feeds 0 and 1 covered)
 *
 * Arbitration overhead: 22ns  PASS (<50ns)
 * Feed correlation: spike at t=45s on all 3 feeds -> market event  LOGGED
 * ```
 */

int main() {}
