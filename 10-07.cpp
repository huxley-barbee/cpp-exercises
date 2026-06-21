/*
 * ## EXERCISE 7: Build with CMake — Full Project Setup [10.d]
 *
 * Create a complete, professional CMake build system for a multi-library
 * quant finance project.
 *
 * **Requirements:**
 *
 * Create the following directory structure and all necessary files:
 *
 * ```
 * quant_lib/
 * ├── CMakeLists.txt          (root)
 * ├── cmake/
 * │   └── FindQuantLib.cmake
 * ├── lib/
 * │   ├── CMakeLists.txt
 * │   ├── pricing/
 * │   │   ├── CMakeLists.txt
 * │   │   ├── black_scholes.hpp
 * │   │   └── black_scholes.cpp
 * │   └── risk/
 * │       ├── CMakeLists.txt
 * │       ├── var_engine.hpp
 * │       └── var_engine.cpp
 * ├── app/
 * │   ├── CMakeLists.txt
 * │   └── main.cpp
 * ├── tests/
 * │   ├── CMakeLists.txt
 * │   └── test_pricing.cpp
 * └── python/
 *     ├── CMakeLists.txt
 *     └── bindings.cpp
 * ```
 *
 * 1. Root `CMakeLists.txt`:
 *    - `cmake_minimum_required(VERSION 3.20)`
 *    - `project(QuantLib VERSION 1.0.0 LANGUAGES CXX)`
 *    - `set(CMAKE_CXX_STANDARD 17)` with `CMAKE_CXX_STANDARD_REQUIRED`
 *    - Find packages: Eigen3, fmt, GTest, pybind11
 *    - `add_subdirectory` for lib, app, tests, python
 *    - `install` targets
 *    - `CPack` for packaging
 * 2. Library targets with correct `PUBLIC`/`PRIVATE`/`INTERFACE` visibility
 * 3. Test target using `CTest` with `enable_testing()`
 * 4. Build types: `Debug`, `Release`, `RelWithDebInfo`
 * 5. Sanitiser presets using `CMakePresets.json`
 *
 * **Expected output:**
 * ```
 * === CMake Configure ===
 * $ cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
 * -- Found Eigen3: /usr/include/eigen3 (version 3.4.0)
 * -- Found fmt: /usr/lib (version 9.1.0)
 * -- Found GTest: /usr/lib (version 1.13.0)
 * -- Configuring done (0.8s)
 * -- Build files written to: build/
 *
 * === Build ===
 * $ cmake --build build -j8
 * [100%] Built target quant_pricing
 * [100%] Built target quant_risk
 * [100%] Built target quant_app
 * [100%] Built target quant_tests
 * [100%] Built target quant_python
 *
 * === Tests ===
 * $ ctest --test-dir build --output-on-failure
 * Test 1: test_blackscholes .... PASSED
 * Test 2: test_var_engine ..... PASSED
 * 2/2 tests passed
 *
 * === Sanitiser preset ===
 * $ cmake --preset asan
 * $ cmake --build --preset asan
 * ```
 */

int main() {}
