/*
 * ## EXERCISE 9: Static Analyzers — Clang Static Analyzer (CSA) and `cppcheck` [7.c.iii]
 *
 * The Clang Static Analyzer performs deeper inter-procedural analysis than
 * `clang-tidy`. `cppcheck` is a simpler tool that works without a compilation
 * database.
 *
 * **Requirements:**
 *
 * Write `static_analysis_target.cpp` with bugs detectable by CSA:
 * ```cpp
 * int* allocateBuffer(int n) { return new int[n]; }  // returned without delete
 * void process(int* buf, int n) {
 *     for (int i = 0; i <= n; ++i) buf[i] = i * 2;  // off-by-one
 * }
 * int main() {
 *     int* buf = allocateBuffer(10);
 *     if (rand() % 2) return 1;  // early return — leak on this path
 *     process(buf, 10);
 *     delete[] buf;
 * }
 * ```
 *
 * 1. Run CSA: `scan-build -o report/ g++ -std=c++17 static_analysis_target.cpp`
 * 2. View the HTML report: `open report/*/index.html`
 * 3. Show the path-sensitive analysis output — CSA traces the exact execution path
 *    that leads to the leak
 * 4. Run `cppcheck --enable=all --std=c++17 static_analysis_target.cpp`
 * 5. Compare: what CSA finds that `cppcheck` misses and vice versa
 * 6. Show `scan-build` with a CMake project:
 *    `scan-build cmake -S . -B build && scan-build cmake --build build`
 *
 * **Expected output:**
 * ```
 * === Clang Static Analyzer ===
 * static_analysis_target.cpp:7:9: warning: Potential memory leak
 *   [unix.Malloc]
 *     if (rand() % 2) return 1;
 *                     ^~~~~~~~
 *   Path:
 *     Line 5: buf = allocateBuffer(10)   <- memory allocated here
 *     Line 7: return 1                    <- memory leaked here
 *
 * static_analysis_target.cpp:3:31: warning: Loop condition
 *   [alpha.security.ArrayBoundV2]
 *     for (int i = 0; i <= n; ++i)        <- i reaches n (out of bounds)
 *
 * === cppcheck ===
 * [static_analysis_target.cpp:3] (error) Array 'buf[10]' accessed at
 * index 10, which is out of bounds.
 * [static_analysis_target.cpp:7] (error) Memory leak: buf
 *
 * === Comparison ===
 * CSA finds:  path-sensitive leak (only on the early-return path)
 * cppcheck:   simpler OOB and leak checks, no compilation database needed
 * Both miss:  race conditions (use TSan), UB (use UBSAN)
 * ```
 */

int main() {}
