/*
 * ## EXERCISE 13: Comprehensive Integration — Production Build System [All of 5.c]
 *
 * Design and implement the complete build system for a production-grade trading library.
 *
 * **Requirements:**
 *
 * Project: `TradingCore` — a shared library consumed by multiple trading applications.
 *
 * 1. **Directory layout:**
 *    ```
 *    trading_core/
 *    ├── CMakeLists.txt
 *    ├── conanfile.py           (Conan recipe — supports conan create)
 *    ├── Makefile               (CI entry points)
 *    ├── cmake/
 *    │   ├── TradingCoreConfig.cmake.in
 *    │   └── CompilerFlags.cmake
 *    ├── src/
 *    ├── include/trading_core/  (public headers)
 *    ├── apps/
 *    ├── tests/
 *    └── benchmarks/
 *    ```
 * 2. CMake must produce an **installable** package: `cmake --install` generates
 *    `TradingCoreConfig.cmake` so downstream projects can `find_package(TradingCore)`
 * 3. Write a `conanfile.py` with class `TradingCoreConan(ConanFile)`:
 *    - `requires = "spdlog/1.12.0", "eigen/3.4.0", "catch2/3.4.0"`
 *    - `options = {"shared": [True, False], "with_asan": [True, False]}`
 *    - `def generate(self)` calls `CMakeToolchain(self).generate()`
 * 4. Add a `benchmarks/` CMake target using Google Benchmark
 * 5. Write a downstream `CMakeLists.txt` that `find_package(TradingCore REQUIRED)` and
 *    uses `TradingCore::trading_core`
 * 6. Write the full CI pipeline as an annotated shell script in comments
 * 7. Show what `cmake --build build --target install` produces
 *
 * **Expected output:**
 * ```
 * === TradingCore Production Build ===
 *
 * === Configure ===
 * $ conan install . --output-folder=build --build=missing
 * $ cmake -S . -B build \
 *     -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake \
 *     -DCMAKE_BUILD_TYPE=Release \
 *     -DCMAKE_INSTALL_PREFIX=/opt/trading_core
 *
 * === Build ===
 * $ cmake --build build -j$(nproc)
 *   [25%]  Building CXX object src/...
 *   [50%]  Linking CXX static library libtrading_core.a
 *   [75%]  Linking CXX executable apps/order_router
 *   [100%] Linking CXX executable benchmarks/bench_pricer
 *
 * === Test ===
 * $ ctest --test-dir build -j4 --output-on-failure
 * 100% tests passed, 0 tests failed
 *
 * === Benchmark ===
 * $ ./build/benchmarks/bench_pricer
 * BM_BlackScholes/1     18 ns   18 ns
 * BM_BlackScholes/8     22 ns   22 ns  (vectorised batch)
 *
 * === Install ===
 * $ cmake --install build
 * -- Installing: /opt/trading_core/lib/libtrading_core.a
 * -- Installing: /opt/trading_core/include/trading_core/
 * -- Installing: /opt/trading_core/lib/cmake/TradingCore/TradingCoreConfig.cmake
 *
 * === Downstream find_package ===
 * find_package(TradingCore REQUIRED)
 * target_link_libraries(my_app PRIVATE TradingCore::trading_core)
 * # Automatically inherits include dirs, compile definitions, link deps
 * ```
 */

int main() {}
