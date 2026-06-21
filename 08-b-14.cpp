/*
 * ## EXERCISE 14: Market Data Dispatch — Consolidated Quote and NBBO [8.b.iii]
 *
 * A trading system must aggregate quotes from multiple venues and compute
 * the National Best Bid and Offer (NBBO).
 *
 * **Requirements:**
 * 1. Maintain a **per-venue top-of-book** for each symbol: `std::unordered_map<symbol, VenueQuote[N_VENUES]>`
 * 2. Compute the **NBBO**: `best_bid = max(all venue bids)`, `best_ask = min(all venue asks)`
 * 3. Implement the NBBO update as a free function (not a method) for testability
 * 4. Track the **venue contributing the best bid/ask** at each update
 * 5. Implement a **crossed-market detector**: if `best_bid >= best_ask`, log a warning
 * 6. Implement **stale quote filtering**: reject quotes older than 500ms
 * 7. Show the **NBBO update cascade**: when one venue's quote changes, the NBBO
 *    may or may not change — only publish a new NBBO if it actually changed
 * 8. Benchmark: NBBO computation time for 100 symbols, 5 venues, 1M updates
 *
 * **Expected output:**
 * ```
 * === NBBO Computation ===
 * Symbol: AAPL   Venues: XNAS, XNYS, BATS, EDGX, IEX
 *
 * Venue quotes:
 *   XNAS: bid=150.24  ask=150.26  size=100/200
 *   XNYS: bid=150.25  ask=150.27  size= 50/100
 *   BATS: bid=150.23  ask=150.25  size=200/300
 *   EDGX: bid=150.24  ask=150.26  size=150/150
 *   IEX:  bid=150.22  ask=150.26  size=300/200
 *
 * NBBO: bid=150.25 (XNYS)  ask=150.25 (BATS)
 * WARNING: NBBO crossed! bid=150.25 >= ask=150.25
 *
 * After correction:
 * NBBO: bid=150.25 (XNYS)  ask=150.26 (XNAS/EDGX/IEX)
 *
 * === Benchmark ===
 * 100 symbols, 5 venues, 1M updates: 38ms (26M NBBO updates/sec)
 * NBBO actually changed: 73% of updates triggered a new NBBO
 * ```
 */

int main() {}
