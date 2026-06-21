/*
 * ## EXERCISE 6: Adding Tests — Minimal Test Harness [7.a.ii]
 *
 * Many legacy quant codebases have no test infrastructure at all. Build a minimal
 * one that can be added without any external dependencies.
 *
 * **Requirements:**
 * 1. Implement a self-contained `TestRunner` class:
 *    - `test(name, fn)`: registers a named test function
 *    - `run()`: executes all tests, prints PASS/FAIL, returns exit code
 *    - `check(got, expected, tol, name)`: floating-point comparison helper
 *    - `checkEqual(got, expected, name)`: exact equality helper
 *    - `checkThrows<E>(fn, name)`: verifies an exception is thrown
 * 2. Support test fixtures: a setup/teardown pattern
 * 3. Print a summary: `N/M tests passed`
 * 4. Return exit code 0 on success, 1 on any failure (for CI integration)
 * 5. Demonstrate with 5 tests covering the `computeNPV` function
 * 6. Show coloured output (ANSI codes) for PASS (green) and FAIL (red)
 *
 * **Expected output:**
 * ```
 * === Minimal Test Harness ===
 *
 * Running 5 tests...
 *
 * [PASS] zero_rate_npv
 * [PASS] single_period
 * [PASS] multi_period
 * [FAIL] wrong_result
 *   Expected: 952.38  Got: 900.00  Diff: 52.38  (tol: 0.01)
 * [PASS] exception_on_negative_rate
 *
 * 4/5 tests passed.
 * Exit code: 1 (failures detected)
 * ```
 */

int main() {}
