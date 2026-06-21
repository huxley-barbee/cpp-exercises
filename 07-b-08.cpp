/*
 * ## EXERCISE 8: Profilers — Flame Graphs [7.b.iii]
 *
 * Flame graphs provide the most intuitive view of where CPU time is spent in
 * a call stack.
 *
 * **Requirements:**
 *
 * 1. Profile `profile_target` with `perf record -g --call-graph dwarf`
 * 2. Use `perf script | stackcollapse-perf.pl | flamegraph.pl > flame.svg`
 *    (Brendan Gregg's FlameGraph scripts) to produce a flame graph SVG
 * 3. Describe how to interpret a flame graph:
 *    - X axis: alphabetical ordering of stack frames (not time order)
 *    - Y axis: call depth
 *    - Width of a frame: proportion of samples that include it
 * 4. Show a textual representation of what the flame graph would look like
 * 5. Add annotations: identify the widest frame (hot spot), the deepest call chain
 * 6. Use `perf annotate` to drill into the assembly of the hot function
 * 7. Show `heaptrack` (heap profiler) for memory allocation hot spots
 * 8. Show `valgrind --tool=callgrind` + `kcachegrind` as an alternative
 *
 * **Expected output:**
 * ```
 * === Flame Graph (text representation) ===
 *
 * main (100%)
 * ├── slow_bs (68%)
 * │   ├── std::log (35%)
 * │   ├── std::exp (20%)
 * │   └── normCDF  (13%)
 * │       └── std::erfc (13%)
 * ├── log_result (21%)
 * │   ├── std::to_string (12%)
 * │   └── std::string::append (9%)
 * └── fast_bs (9%)
 *     └── normCDF (7%)
 *
 * Hot spot: slow_bs -> std::log (35% of total time)
 * Fix: cache log(S/K) and reuse across calls.
 *
 * === perf annotate: hot instructions in slow_bs ===
 *   35.2%:  callq  0x... <std::log>
 *   21.1%:  callq  0x... <std::exp>
 *    8.3%:  vmulsd %xmm0, %xmm1, %xmm0
 * ```
 */

int main() {}
