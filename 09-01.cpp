/*
 * ## EXERCISE 1: Boost — Date/Time for Trading Calendars [9.a]
 *
 * Financial date arithmetic is surprisingly complex: business day counting,
 * holiday calendars, end-of-month rules, and day-count conventions all matter.
 * Boost.Date_Time handles them cleanly.
 *
 * **Requirements:**
 * 1. Use `boost::gregorian::date` to represent trade dates
 * 2. Implement a `TradingCalendar` class that:
 *    - Stores a `std::set<boost::gregorian::date>` of holidays
 *    - `isBusinessDay(date)`: returns false for weekends and holidays
 *    - `addBusinessDays(date, n)`: advances `n` business days (T+N settlement)
 *    - `businessDaysBetween(from, to)`: counts business days in a range
 * 3. Implement three day-count conventions using `boost::gregorian`:
 *    - **ACT/365**: actual days / 365
 *    - **ACT/360**: actual days / 360
 *    - **30/360**: assumes 30 days per month
 * 4. Compute the settlement date for a spot FX trade (T+2 business days)
 * 5. Compute coupon dates for a semi-annual bond using `boost::gregorian::months`
 * 6. Show end-of-month rule: if start is last business day of a month,
 *    coupons also fall on the last business day
 *
 * **Expected output:**
 * ```
 * === Trading Calendar ===
 * Holidays loaded: 9 (US 2024)
 *
 * addBusinessDays(2024-01-05, 2) = 2024-01-09  (skips weekend)
 * addBusinessDays(2024-01-03, 5) = 2024-01-10  (skips holiday+weekend)
 *
 * businessDaysBetween(2024-01-01, 2024-01-31) = 22
 *
 * === Day-Count Conventions ===
 * From 2024-01-15 to 2025-01-15:
 *   ACT/365: 366/365 = 1.002740
 *   ACT/360: 366/360 = 1.016667
 *   30/360:  360/360 = 1.000000
 *
 * === FX T+2 Settlement ===
 * Trade date: 2024-01-15 (Monday)
 * Settlement: 2024-01-17 (Wednesday, T+2)
 *
 * === Bond Coupon Dates (semi-annual, issue 2024-01-15, maturity 2026-01-15) ===
 * 2024-07-15
 * 2025-01-15
 * 2025-07-15
 * 2026-01-15
 * ```
 */

int main() {}
