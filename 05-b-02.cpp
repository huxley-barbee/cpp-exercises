/*
 * ## EXERCISE 2: Branch Prediction — `likely`/`unlikely` and Profile-Guided Layout [5.b.i]
 *
 * Show how annotation hints and code layout affect branch-prediction performance.
 *
 * **Requirements:**
 * 1. Write an order-validation function with three checks: `price > 0`, `qty > 0`, `qty < MAX_QTY`
 * 2. Instrument the "happy path" (all checks pass) and "error path" (any check fails)
 * 3. Version A: no hints — compiler places code in source order
 * 4. Version B: annotate with `[[likely]]` (C++20) / `__builtin_expect` (C++11) on the
 *    happy path
 * 5. Version C: restructure so the error path is an `[[unlikely]]` cold branch
 * 6. Benchmark all three with 99% valid orders and 1% invalid
 * 7. Show the generated assembly difference (hot path inline vs cold path out-of-line)
 * 8. Demonstrate `__attribute__((cold))` for error-handling functions
 *
 * **Expected output:**
 * ```
 * === Order Validation Benchmark (99% valid, 1% invalid) ===
 * 10M orders processed
 *
 * Version A (no hints):          85ms
 * Version B (__builtin_expect):  72ms   (speedup 1.18x)
 * Version C (cold error path):   68ms   (speedup 1.25x)
 *
 * Happy-path throughput:
 *   No hints:      118M orders/sec
 *   With hints:    147M orders/sec
 *
 * Error path layout with [[unlikely]]:
 *   Error handler compiled to cold section
 *   Hot loop: no jmp to error handler in instruction stream
 *   Misprediction cost paid only on the rare error case
 *
 * Rule: annotate conditions that are almost-always true with
 *       [[likely]] / __builtin_expect(x, 1).
 * ```
 */

int main() {}
