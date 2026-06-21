/*
 * ## EXERCISE 8: Build with CMake — Dependencies and Packaging [10.d]
 *
 * A production build system must manage external dependencies reproducibly
 * and produce a distributable package.
 *
 * **Requirements:**
 * 1. Use **Conan** to manage dependencies (Eigen, fmt, spdlog):
 *    - Write a `conanfile.py` with `requires` and `generators`
 *    - Show the `conan install` → `cmake` → `build` workflow
 * 2. Use **FetchContent** as an alternative (no Conan needed):
 *    - Fetch Google Test at configure time
 *    - Show `FetchContent_Declare` and `FetchContent_MakeAvailable`
 * 3. Write a `cmake/QuantLibConfig.cmake.in` for `find_package(QuantLib)` support:
 *    - Other projects can `find_package(QuantLib REQUIRED)`
 *    - Header paths and library targets included
 * 4. Configure **CPack** to produce:
 *    - `.tar.gz` source archive
 *    - `.deb` binary package with correct install prefix
 * 5. Write a `CMakePresets.json` with four presets:
 *    `default`, `debug`, `release`, `asan`
 *
 * **Expected output:**
 * ```
 * === Conan workflow ===
 * $ conan install . --output-folder=build --build=missing
 * ...Eigen/3.4.0: Downloaded
 * ...fmt/9.1.0: Downloaded
 *
 * $ cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake
 * -- Conan toolchain: activated
 *
 * === FetchContent ===
 * $ cmake -S . -B build
 * -- Fetching googletest from github...
 * -- googletest v1.13.0 configured
 *
 * === CPack ===
 * $ cmake --build build --target package
 * CPack: Create package: quant_lib-1.0.0.tar.gz  PASS
 * CPack: Create package: quant_lib-1.0.0-Linux.deb  PASS
 *
 * === CMakePresets.json ===
 * $ cmake --preset asan
 * -- ASan preset: -fsanitize=address,undefined enabled
 * ```
 */

int main() {}
