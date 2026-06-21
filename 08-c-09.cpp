/*
 * ## EXERCISE 9: Feed Arbitration — Multi-Feed Consolidation [8.c.iii]
 *
 * Multiple market data feeds carry the same information with different latency
 * profiles. Feed arbitration selects the best data from all available sources.
 *
 * **Requirements:**
 * 1. Implement a `FeedArbitrator` that manages N feeds for the same symbol:
 *    - Each feed has a `feed_id`, `latency_estimate_ns`, and `reliability_score`
 *    - On each tick, decide which feed's data to use
 * 2. Implement three arbitration policies as strategies (Strategy pattern):
 *    - **Primary/Backup**: always use Feed 0; fall back to Feed 1 if Feed 0 is stale
 *    - **Fastest-first**: use whichever feed delivers a given sequence number first
 *    - **Voting**: if 2 out of 3 feeds agree (within 1 tick), use the majority
 * 3. Implement **staleness detection**: a feed is stale if no update received
 *    in `stale_threshold_ns` (configurable, default 500ms)
 * 4. Implement **feed latency tracking**: measure the arrival time of each
 *    seq number across feeds, compute per-feed latency statistics
 * 5. Show feed switching: Feed 0 goes stale at t=5s, arbitrator switches to Feed 1
 * 6. Benchmark: arbitration decision latency (target < 50ns)
 *
 * **Expected output:**
 * ```
 * === Feed Arbitration (3 feeds, AAPL) ===
 *
 * Feed 0 (Primary):   latency p50=12µs  reliability=99.98%
 * Feed 1 (Backup):    latency p50=15µs  reliability=99.95%
 * Feed 2 (Secondary): latency p50=18µs  reliability=99.92%
 *
 * Policy: Primary/Backup
 *   t=0-5s:  using Feed 0 (primary)
 *   t=5.001s: Feed 0 stale (no data 500ms)
 *   t=5.001s: SWITCH to Feed 1  switch_latency=8µs
 *   t=5.843s: Feed 0 recovered
 *   t=5.843s: SWITCH back to Feed 0
 *
 * Policy: Fastest-first (seq 100482):
 *   Feed 1 arrived first at t+12µs -> used
 *   Feed 0 arrived at t+15µs -> discarded (dup)
 *   Feed 2 arrived at t+18µs -> discarded (dup)
 *
 * Arbitration latency: 22ns  PASS
 * ```
 */

int main() {}
