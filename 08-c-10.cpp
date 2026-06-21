/*
 * ## EXERCISE 10: Feed Arbitration — Gap Fill and Recovery [8.c.iii]
 *
 * When a feed drops packets, the handler must detect the gap and recover
 * the missing data — without stalling downstream consumers.
 *
 * **Requirements:**
 * 1. Implement **gap detection**: track `expected_seq_no`; if received seq
 *    skips, record the gap as `{start_seq, end_seq, detected_at_ns}`
 * 2. Implement a **reorder buffer**: hold out-of-order packets until
 *    the gap is filled or a timeout expires (default 10ms)
 * 3. Implement **gap fill via retransmit request**:
 *    - Send a retransmit request to the exchange or a retransmit server
 *    - If retransmit arrives within 10ms, deliver in order
 *    - If not, apply a **gap fill policy**: either stall or skip the gap
 * 4. Implement **gap fill via secondary feed**: use Feed 1's data to fill
 *    gaps in Feed 0's sequence
 * 5. Implement a **heartbeat / end-of-event message** that flushes the
 *    reorder buffer even if no new data arrives
 * 6. Show the full gap detection → fill cycle with timing
 *
 * **Expected output:**
 * ```
 * === Gap Fill Cycle ===
 *
 * Received seq 1001, expected 999
 * Gap detected: seqs 999-1000 (gap=2)
 * Out-of-order buffer: holding seq 1001
 *
 * Retransmit request sent for seqs 999-1000 at t=0µs
 *
 * t=3,200µs: seq 1000 received (retransmit)
 * t=3,400µs: seq 999 received (retransmit)
 *
 * Reorder buffer delivers: 999, 1000, 1001 in order
 * Total gap recovery time: 3,400µs
 *
 * === Secondary feed gap fill ===
 * Feed 0 gap: seqs 5010-5015
 * Feed 1 has seqs 5010-5015 -> filled from Feed 1
 * Seamless delivery: 0 gaps visible to downstream
 * ```
 */

int main() {}
