/*
 * ## EXERCISE 12: Market Data Dispatch — Symbol Mapping and Instrument Reference Data [8.b.iii]
 *
 * A market data system must map raw exchange symbols to internal instrument IDs.
 *
 * **Requirements:**
 * 1. Implement a `SymbolMapper` class:
 *    - Maps exchange-specific symbols (e.g., `AAPL.XNAS`, `AAPL.XNYS`) to
 *      internal instrument IDs (e.g., `EQUITY_US_AAPL`)
 *    - Loaded from a CSV reference data file at startup
 *    - `O(1)` lookup using `std::unordered_map`
 * 2. Implement **fuzzy matching** for unknown symbols: if exact match fails,
 *    try stripping exchange suffix and matching by base symbol
 * 3. Implement **instrument reference data**:
 *    - Lot size, tick size, currency, exchange, expiry (for futures/options)
 *    - Store as `std::shared_ptr<const InstrumentRef>` (immutable after load)
 * 4. Implement **corporate action adjustment**: adjust historical prices for splits
 *    using an adjustment factor stored per (symbol, date)
 * 5. Show how to handle **options symbology** (OCC format: `AAPL240119C00150000`)
 * 6. Benchmark: symbol lookup latency (target < 100ns)
 *
 * **Expected output:**
 * ```
 * === Symbol Mapper ===
 * Loaded 12,450 mappings from reference_data.csv
 *
 * Lookup: "AAPL.XNAS" -> EQUITY_US_AAPL  latency=42ns  PASS
 * Lookup: "AAPL.XNYS" -> EQUITY_US_AAPL  latency=38ns  PASS
 * Lookup: "AAPL999"   -> EQUITY_US_AAPL  (fuzzy match, latency=115ns)
 * Lookup: "UNKNWN"    -> NOT_FOUND
 *
 * OCC option: "AAPL240119C00150000"
 *   -> EQUITY_US_AAPL, CALL, K=$150.00, expiry=2024-01-19
 *
 * Corporate action: AAPL 4:1 split 2020-08-31
 *   Pre-split price: $452.00 -> adjusted: $113.00
 * ```
 */

int main() {}
