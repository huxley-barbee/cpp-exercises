/*
 * ## EXERCISE 3: Boost — String Algorithms and Lexical Cast [9.a]
 *
 * Market data messages often arrive as text that must be parsed quickly and
 * safely. Boost provides clean, exception-safe alternatives to C string functions.
 *
 * **Requirements:**
 * 1. Use `boost::algorithm::split` to parse a pipe-delimited FIX-like message:
 *    `"AAPL|BUY|100|150.25|LIMIT"`
 * 2. Use `boost::lexical_cast<double>` and `boost::lexical_cast<int>` to convert
 *    fields, showing exception safety vs `atof`/`atoi`
 * 3. Use `boost::algorithm::trim`, `to_upper`, `to_lower` on symbol strings
 * 4. Use `boost::algorithm::starts_with` / `ends_with` for message type routing
 * 5. Implement a `MessageParser` that uses `boost::spirit::qi` (or simpler:
 *    `boost::tokenizer`) to parse CSV instrument reference data from a file
 * 6. Show `boost::format` for building log messages (then compare to `{fmt}` in Exercise 5)
 * 7. Demonstrate `boost::bad_lexical_cast` vs silent failure of `atof`
 *
 * **Expected output:**
 * ```
 * === FIX-like message parse ===
 * Raw: "AAPL|BUY|100|150.25|LIMIT"
 * Symbol: "AAPL"  Side: "BUY"  Qty: 100  Price: 150.25  Type: "LIMIT"
 *
 * === Lexical cast safety ===
 * lexical_cast<double>("150.25"):  150.25  PASS
 * lexical_cast<double>("abc"):     throws boost::bad_lexical_cast  PASS
 * atof("abc"):                     0.0  (silent failure!)
 *
 * === String algorithms ===
 * trim("  AAPL  "):    "AAPL"
 * to_upper("aapl"):   "AAPL"
 * starts_with("35=D", "35"): true  (FIX NewOrderSingle)
 *
 * === boost::format vs {fmt} ===
 * boost::format: "%1% filled at %2$.2f") % "AAPL" % 150.25
 *   Result: "AAPL filled at 150.25"  (750ns)
 * {fmt}:         "{} filled at {:.2f}", "AAPL", 150.25
 *   Result: "AAPL filled at 150.25"  (42ns)  18x faster
 * ```
 */

int main() {}
