/*
 * ## EXERCISE 11: Market Data Dispatch — Normalisation Layer [8.b.iii]
 *
 * Different exchanges send data in different formats. Build a normalisation layer.
 *
 * **Requirements:**
 * 1. Define a canonical `NormalisedTick` format (your internal standard)
 * 2. Implement feed adapters for three simulated venues:
 *    - **VenueA**: sends `{sym, bid_cents, ask_cents, sizes}` as ASCII
 *    - **VenueB**: sends binary struct with price as `float` (lossy!)
 *    - **VenueC**: sends FIX-like tag=value format
 * 3. Each adapter implements `INormalisedFeed`:
 *    ```cpp
 *    class INormalisedFeed {
 *    public:
 *        virtual NormalisedTick normalise(const RawMessage&) = 0;
 *        virtual std::string venueName() const = 0;
 *    };
 *    ```
 * 4. Implement a `FeedDispatcher` that routes incoming messages to the correct
 *    adapter based on a venue ID in the message header
 * 5. Show precision loss from VenueB's float prices:
 *    `float(150.255) = 150.254997` — round-trip error
 * 6. Implement a **sequence gap detector**: if `seq_no` jumps, log a gap and
 *    request a retransmit
 * 7. Benchmark: normalisation throughput for each venue (messages/sec)
 *
 * **Expected output:**
 * ```
 * === Feed Normalisation ===
 *
 * VenueA (ASCII):  "AAPL|15025|15026|100|200" -> NormTick{AAPL, 150.25, 150.26}
 * VenueB (binary float): price=150.255f -> stored as 150.254997  PRECISION LOSS
 * VenueC (FIX-like): "35=D|55=AAPL|44=150.25|..." -> NormTick{AAPL, 150.25, ...}
 *
 * Throughput:
 *   VenueA (ASCII parse):    2.1M msg/sec
 *   VenueB (binary cast):   18.4M msg/sec
 *   VenueC (tag-value scan):  0.8M msg/sec
 *
 * Sequence gap detected: seq 99 -> 101 (gap=1), requesting retransmit
 * ```
 */

int main() {}
