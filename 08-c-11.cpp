/*
 * ## EXERCISE 11: Feed Arbitration — Latency Measurement and Feed Quality [8.c.iii]
 *
 * To make good arbitration decisions, you must continuously measure and model
 * each feed's latency characteristics.
 *
 * **Requirements:**
 * 1. Implement a **per-feed latency tracker**:
 *    - For each sequence number received, record `{seq, feed_id, arrival_ns}`
 *    - Compute relative latency: `feed_k_latency = feed_k_arrival - min_arrival`
 *    - Track running statistics: mean, variance, p50, p99
 * 2. Implement a **feed quality score**:
 *    `quality = reliability_weight * (1 - gap_rate) + latency_weight * (1 / avg_latency)`
 * 3. Implement **exponential moving average (EMA)** of latency:
 *    `EMA_new = alpha * latency + (1-alpha) * EMA_old`
 *    Use a fast integer approximation: `EMA = (EMA * 7 + latency) >> 3` (alpha=1/8)
 * 4. Implement **jitter measurement**: `jitter = EMA(|latency - prev_latency|)`
 * 5. Show that feed quality scores correlate with observed arbitration wins
 * 6. Produce a feed quality report over a 60-second window
 *
 * **Expected output:**
 * ```
 * === Feed Quality Report (60s window) ===
 *
 * Feed 0 (Primary):
 *   Messages:   720,420
 *   Gap rate:   0.0014%
 *   Avg latency: 12.3µs  EMA: 12.1µs  jitter: 2.4µs
 *   Quality score: 0.982
 *
 * Feed 1 (Backup):
 *   Messages:   721,102
 *   Gap rate:   0.0008%
 *   Avg latency: 15.1µs  EMA: 14.9µs  jitter: 3.1µs
 *   Quality score: 0.963
 *
 * Feed 2 (Secondary):
 *   Messages:   719,840
 *   Gap rate:   0.0031%
 *   Avg latency: 18.7µs  EMA: 18.3µs  jitter: 5.2µs
 *   Quality score: 0.924
 *
 * Arbitration wins: Feed0=67%  Feed1=22%  Feed2=11%
 *   Correlation with quality score: 0.89  (higher quality -> more wins)
 * ```
 */

int main() {}
