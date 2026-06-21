/*
 * ## EXERCISE 4: Adding Tests — Characterisation Tests [7.a.ii]
 *
 * Before refactoring legacy code you must pin its current behaviour with tests —
 * even if that behaviour is wrong. These are called **characterisation tests**.
 *
 * **Requirements:**
 *
 * Given this legacy function (do not change it yet):
 * ```cpp
 * // legacy_npv.cpp
 * double computeNPV(const double* cashflows, int n,
 *                   double rate, int settlement_days) {
 *     double npv = 0.0;
 *     for (int i = 0; i < n; ++i) {
 *         // BUG: uses i+1 but should account for settlement_days offset
 *         double df = 1.0 / pow(1.0 + rate, i + 1 + settlement_days);
 *         npv += cashflows[i] * df;
 *     }
 *     return npv;
 * }
 * ```
 *
 * 1. Write characterisation tests that **record the current output** — even if it's wrong
 * 2. Use a minimal hand-rolled test harness (no external framework)
 * 3. Cover: zero cash flows, single cash flow, multiple cash flows, zero rate,
 *    different settlement days
 * 4. Record the exact floating-point outputs (use `std::to_string` or `%.10f`)
 * 5. Show that the tests pass against the current (buggy) code
 * 6. Show that changing `i + 1 + settlement_days` to `i + 1` breaks one test —
 *    proving the tests are sensitive to the bug
 * 7. Discuss: characterisation tests protect against *accidental* changes while you
 *    are working on something else
 *
 * **Expected output:**
 * ```
 * === Characterisation Tests for computeNPV ===
 * (Recording current behaviour — including any bugs)
 *
 * [PASS] zero_cashflows:        npv = 0.0000000000
 * [PASS] single_cashflow_0d:    npv = 952.3809523810  (settlement=0)
 * [PASS] single_cashflow_5d:    npv = 746.2153966312  (settlement=5)
 * [PASS] multi_cashflow:        npv = 1044.5182xxxxxx
 * [PASS] zero_rate:             npv = 1050.0000000000
 * [PASS] negative_settlement:   npv = [recorded value]
 *
 * 6/6 characterisation tests passed.
 *
 * Modifying bug (remove settlement_days from exponent):
 * [FAIL] single_cashflow_5d: expected 746.2153... got 952.3809...
 * Characterisation test caught the change — working correctly.
 * ```
 */

int main() {}
