/*
 * ## EXERCISE 4: CMake — Testing with CTest [5.c.i]
 *
 * All production quant codebases have a test suite. CTest integrates testing into the
 * CMake build.
 *
 * **Requirements:**
 * 1. Add `enable_testing()` to the root `CMakeLists.txt`
 * 2. Write three small test executables: `test_pricer`, `test_risk`, `test_utils`
 *    (each returns 0 on success, non-zero on failure)
 * 3. Register each with `add_test(NAME test_pricer COMMAND test_pricer)`
 * 4. Show passing test arguments: `add_test(NAME test_pricer_fast COMMAND test_pricer --fast)`
 * 5. Set a timeout: `set_tests_properties(test_pricer PROPERTIES TIMEOUT 30)`
 * 6. Add a label: `set_tests_properties(test_pricer PROPERTIES LABELS "unit")`
 * 7. Run with `ctest --test-dir build -V` and `ctest --test-dir build -L unit`
 * 8. Show `ctest --output-on-failure` for CI
 * 9. Show how to rerun a single failed test: `ctest --test-dir build -R test_pricer --rerun-failed`
 *
 * **Expected output:**
 * ```
 * === CTest Integration ===
 *
 * $ ctest --test-dir build -V
 *     Start 1: test_pricer
 * 1/3 Test #1: test_pricer .................   Passed    0.02 sec
 *     Start 2: test_risk
 * 2/3 Test #2: test_risk ...................   Passed    0.01 sec
 *     Start 3: test_utils
 * 3/3 Test #3: test_utils ..................   Passed    0.01 sec
 *
 * 100% tests passed, 0 tests failed out of 3
 *
 * $ ctest --test-dir build -L unit -V
 * -- Only running tests labelled 'unit'
 *
 * $ ctest --test-dir build --output-on-failure
 * (shows stdout/stderr only on failure — CI-friendly)
 * ```
 */

int main() {}
