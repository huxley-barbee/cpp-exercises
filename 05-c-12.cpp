/*
 * ## EXERCISE 12: Integrating All Three — A Real Project Setup [5.c.i–iii]
 *
 * Combine CMake + Conan + a Makefile wrapper into a production-ready project skeleton.
 *
 * **Requirements:**
 *
 * Project: `OptionPricer` — prices European options using Black-Scholes.
 *
 * 1. **Directory layout:**
 *    ```
 *    option_pricer/
 *    ├── CMakeLists.txt
 *    ├── conanfile.txt
 *    ├── Makefile               (thin wrapper — CI entry points)
 *    ├── cmake/
 *    │   └── CompilerFlags.cmake
 *    ├── src/
 *    │   ├── pricer.hpp
 *    │   └── pricer.cpp
 *    ├── apps/
 *    │   └── main.cpp
 *    └── tests/
 *        └── test_pricer.cpp
 *    ```
 * 2. `Makefile` targets: `configure`, `build`, `test`, `clean`, `asan`, `release`
 * 3. `CompilerFlags.cmake`: C++17 standard, strict warnings, LTO for Release,
 *    generator-expression-based flag selection
 * 4. `conanfile.txt`: requires `spdlog/1.12.0`, `catch2/3.4.0`, `fmt/10.1.1`
 * 5. CTest runs `test_pricer` which uses Catch2 `TEST_CASE` macros
 * 6. Show the complete workflow: `make configure && make build && make test`
 * 7. Annotate with CI pipeline steps in comments
 *
 * **Expected output:**
 * ```
 * === OptionPricer Full Build ===
 *
 * $ make configure
 *   conan install . --output-folder=build --build=missing
 *   cmake -S . -B build \
 *     -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake \
 *     -DCMAKE_BUILD_TYPE=Release
 *
 * $ make build
 *   cmake --build build -j$(nproc)
 *   [100%] Linking CXX executable apps/option_pricer
 *
 * $ make test
 *   ctest --test-dir build --output-on-failure
 *   Test 1: test_pricer ... Passed
 *
 * $ make asan
 *   conan install . --output-folder=build-asan -pr:h=profiles/debug
 *   cmake -S . -B build-asan \
 *     -DCMAKE_BUILD_TYPE=Debug \
 *     -DCMAKE_CXX_FLAGS="-fsanitize=address,undefined"
 *   cmake --build build-asan
 *
 * $ ./build/apps/option_pricer
 * [info] Black-Scholes call: $10.45
 * [info] Delta: 0.637
 * [info] Vega:  39.58
 * ```
 */

int main() {}
