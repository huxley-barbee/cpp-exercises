/*
 * ## EXERCISE 12: POD Types — Fixed-Point Arithmetic in C-Style Code [4.c.iv]
 *
 * Floating-point is non-deterministic across machines. Legacy exchange interfaces and
 * risk systems use fixed-point integers for prices. This exercise works through the
 * idioms you will see in real code.
 *
 * **Requirements:**
 * 1. Define `typedef int64_t FixedPrice` where 1 unit = $0.0001 (4 decimal places)
 * 2. Write C-style conversion functions:
 *    - `FixedPrice fromDouble(double d)`
 *    - `double     toDouble(FixedPrice fp)`
 *    - `FixedPrice add(FixedPrice a, FixedPrice b)`
 *    - `FixedPrice multiply(FixedPrice price, int64_t quantity)` (returns notional in fixed-point)
 * 3. Show precision preservation: `fromDouble(1.0/3.0)` truncates — document the rounding policy
 * 4. Demonstrate overflow risk: multiplying two large `FixedPrice` values
 * 5. Write a `PriceLevel` POD struct: `FixedPrice price; int32_t quantity; char side`
 * 6. Populate an array of `PriceLevel`s representing an order book and print it
 * 7. Sort the bid side (descending) and ask side (ascending) using `qsort`
 * 8. Note: C++11 `std::round` / `<numeric>` and Boost.Multiprecision as modern replacements
 *
 * **Expected output:**
 * ```
 * === Fixed-Point Arithmetic ===
 * typedef int64_t FixedPrice;  // 1 unit = $0.0001
 *
 * fromDouble(150.25)  = 1502500
 * fromDouble(0.0001)  = 1
 * fromDouble(1.0/3.0) = 3333  (truncated — document rounding policy!)
 * toDouble(1502500)   = 150.2500
 *
 * add(1502500, 502500) = 2005000 ($200.5000)
 * multiply(1502500, 100) = 150250000  ($15025.0000 notional)
 *
 * === Overflow Risk ===
 * FixedPrice max: 9223372036854775807
 * multiply(92233720368547, 92233720368547): OVERFLOW!
 * Fix: use __int128 or check before multiply
 *
 * === Order Book (PriceLevel) ===
 * BID side (descending):
 *   $150.30 x 500
 *   $150.25 x 200
 *   $150.20 x 1000
 *
 * ASK side (ascending):
 *   $150.35 x 300
 *   $150.40 x 150
 *   $150.45 x 800
 * ```
 */

int main() {}
