/*
 * ## EXERCISE 21: Message Buses — Multicast and Feed Redundancy [8.b.v]
 *
 * Production market data arrives via multicast UDP. Implement a multicast
 * receiver with redundancy handling.
 *
 * **Requirements:**
 * 1. Implement a **UDP multicast receiver** using POSIX sockets:
 *    - Join a multicast group (`239.1.1.1:5000`)
 *    - Receive datagrams in a tight loop on a dedicated thread
 *    - Parse each datagram as one or more ticks
 * 2. Implement **sequence gap detection and recovery**:
 *    - Track `expected_seq_no`; if gap detected, request retransmit
 *    - Buffer out-of-order packets (reorder buffer, max 64 packets)
 *    - After gap fill, deliver packets in order
 * 3. Implement **dual-feed redundancy** (primary + secondary feed):
 *    - Two network cards, same data, slightly different latency
 *    - Deduplicate: first-seen packet wins, second-seen discarded
 *    - Track which feed is faster (primary or secondary) over time
 * 4. Show the **heartbeat / end-of-event** logic:
 *    if no data received in 5 seconds, declare feed dead and switch to backup
 * 5. Benchmark: UDP receive throughput, jitter
 *
 * **Expected output:**
 * ```
 * === UDP Multicast Receiver ===
 *
 * Joined group 239.1.1.1:5000 on eth0, eth1
 *
 * Primary feed:   latency p50=12µs  p99=45µs
 * Secondary feed: latency p50=14µs  p99=52µs
 * Primary wins 67% of deduplication races
 *
 * === Gap Detection ===
 * Received seq 1000, expected 998 -> gap of 2
 * Buffered seq 1000 (waiting for 998, 999)
 * Retransmit requested: seqs 998, 999
 * Received 999 (retransmit)
 * Received 998 (retransmit)
 * Gap filled: delivered 998, 999, 1000 in order  PASS
 *
 * === Feed Failover ===
 * Primary feed dead (no data 5s) -> switch to secondary
 * Secondary: 0 gaps in failover window  PASS
 * ```
 */

int main() {}
