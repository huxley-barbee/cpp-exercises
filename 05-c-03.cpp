/*
 * ## EXERCISE 3: CMake — Compiler Flags and Build Types [5.c.i]
 *
 * Production trading systems need precise control over compiler flags for latency.
 *
 * **Requirements:**
 * 1. Write a `CMakeLists.txt` that handles four standard build types:
 *    `Debug`, `Release`, `RelWithDebInfo`, `MinSizeRel`
 * 2. Add a custom build type `LatencyOpt` with flags:
 *    `-O3 -march=native -fno-omit-frame-pointer -DLATENCY_OPT`
 *    applied only via generator expressions: `$<$<CONFIG:LatencyOpt>:-O3;-march=native;...>`
 * 3. Add a sanitiser build type `Asan` with:
 *    `-fsanitize=address,undefined -fno-omit-frame-pointer -O1 -g`
 * 4. Use `target_compile_options` (per-target) rather than `add_compile_options` (global) and explain the difference
 * 5. Enable LTO (`CMAKE_INTERPROCEDURAL_OPTIMIZATION`) for Release builds
 * 6. Show how to pass extra flags at configure time: `cmake -DCMAKE_CXX_FLAGS="-march=native"`
 * 7. Verify flags applied: `cmake --build build --verbose`
 *
 * **Expected output:**
 * ```
 * === CMake Compiler Flags ===
 *
 * Build types and their flags:
 *   Debug:          -g -O0
 *   Release:        -O2 -DNDEBUG
 *   RelWithDebInfo: -O2 -g -DNDEBUG
 *   MinSizeRel:     -Os -DNDEBUG
 *   LatencyOpt:     -O3 -march=native -fno-omit-frame-pointer -DLATENCY_OPT
 *   Asan:           -fsanitize=address,undefined -O1 -g
 *
 * $ cmake -S . -B build -DCMAKE_BUILD_TYPE=LatencyOpt
 * $ cmake --build build --verbose
 *   g++ -O3 -march=native -fno-omit-frame-pointer -DLATENCY_OPT ...
 *
 * LTO for Release:
 *   -flto -fno-fat-lto-objects  (link-time optimisation across TUs)
 * ```
 */

int main() {}
