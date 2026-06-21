/*
 * ## EXERCISE 11: CPU Cache Hierarchy — Cache-Friendly Data Structures [5.a.iv]
 *
 * The layout of data in memory determines how efficiently it can be processed.
 * Write a program comparing Array of Structures (AoS) vs Structure of Arrays (SoA).
 *
 * **Requirements:**
 * 1. Define a `TradeAoS` struct: `{ int64_t timestamp; double price; int32_t qty; char sym[8]; }`
 * 2. Define SoA equivalents: separate arrays `timestamps[]`, `prices[]`, `qtys[]`, `syms[][]`
 * 3. Task: sum all `price` fields for 1 million trades
 * 4. Measure AoS vs SoA for the price-sum task — SoA should win because:
 *    - AoS: every cache line loads timestamp, qty, sym too (wasted bandwidth)
 *    - SoA: every cache line is pure price data
 * 5. Task: process all fields for a single trade (random access) — AoS wins here
 * 6. Show `std::vector<TradeAoS>` vs four parallel `std::vector`s
 * 7. Draw a memory layout diagram (ASCII) showing why SoA is better for column operations
 * 8. Recommend: SoA for analytics / batch processing; AoS for per-record operations
 *
 * **Expected output:**
 * ```
 * === AoS vs SoA: 1M Trades ===
 *
 * Array of Structures (AoS):
 *   [ts|price|qty|sym][ts|price|qty|sym][ts|price|qty|sym]...
 *   struct size: 32 bytes
 *   Cache line (64B) holds: 2 trades
 *   Useful bytes per cache line for price sum: 16/64 = 25%
 *
 * Structure of Arrays (SoA):
 *   prices[]: [p0][p1][p2][p3][p4][p5][p6][p7]...
 *   Cache line (64B) holds: 8 doubles
 *   Useful bytes per cache line for price sum: 64/64 = 100%
 *
 * === Benchmark: sum all prices ===
 * AoS sum (1M trades): 8.2ms
 * SoA sum (1M trades): 2.1ms
 * Speedup: 3.9x
 *
 * === Benchmark: process one full trade (random access) ===
 * AoS single trade: 0.9ns  (all fields in same cache line)
 * SoA single trade: 3.5ns  (4 separate cache lines)
 * AoS wins for per-record access
 *
 * === Recommendation ===
 * Risk/PnL batch analytics: SoA  (iterate one field across many records)
 * Order processing (per record): AoS  (need all fields together)
 * ```
 */

int main() {}
