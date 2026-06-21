/*
 * ## EXERCISE 9: Google Benchmark — Micro-Benchmarking [9.f]
 *
 * Google Benchmark provides statistically rigorous micro-benchmarking with
 * automatic iteration scaling, CPU counter support, and variance reporting.
 *
 * **Requirements:**
 * 1. Write a benchmark for three implementations of **Black-Scholes**:
 *    - Scalar (naive)
 *    - Eigen vectorised (`ArrayXd`)
 *    - Manual loop with precomputed constants
 * 2. Use `benchmark::State` correctly: the timed region must include only
 *    the work being measured; setup outside the loop
 * 3. Use `benchmark::DoNotOptimize` and `benchmark::ClobberMemory` to prevent
 *    the compiler from eliminating work
 * 4. Use `BENCHMARK` macro, `->Arg(N)` for parametric benchmarks,
 *    `->Range(8, 8<<10)` for power-of-2 sweeps
 * 5. Run with `--benchmark_repetitions=5 --benchmark_report_aggregates_only=true`
 *    to get mean/median/stddev
 * 6. Use `benchmark::RegisterMemoryManager` or manual `malloc_count` to track
 *    allocations per iteration
 * 7. Compare a **map lookup** vs **unordered_map lookup** vs **array lookup**
 *    for a 100-symbol order book dispatch
 *
 * **Expected output:**
 * ```
 * === Google Benchmark Results ===
 *
 * Benchmark                         Time     CPU   Iterations
 * BM_BlackScholes_Scalar/1000    12412 ns  12400 ns      56321
 * BM_BlackScholes_Eigen/1000      3821 ns   3819 ns     183442   (3.2x faster)
 * BM_BlackScholes_Loop/1000       4102 ns   4099 ns     170811
 *
 * BM_MapLookup/100               2341 ns   2339 ns     299012
 * BM_UnorderedMapLookup/100       412 ns    411 ns    1701234   (5.7x faster)
 * BM_ArrayLookup/100               48 ns     48 ns   14560000  (48.8x faster)
 *
 * Statistical summary (5 repetitions):
 *   BM_BlackScholes_Scalar/1000_mean:   12412 ns
 *   BM_BlackScholes_Scalar/1000_stddev:   124 ns  (1.0% variance)
 * ```
 */

int main() {}
