/*
 * ## EXERCISE 9: Conan — Package Management Basics [5.c.iii]
 *
 * Conan 2 is the most widely used C++ package manager in finance. Learn its core workflow.
 *
 * **Requirements:**
 * 1. Initialise a default Conan profile: `conan profile detect`
 * 2. Write a `conanfile.txt` requiring:
 *    - `spdlog/1.12.0`
 *    - `fmt/10.1.1`
 *    - `nlohmann_json/3.11.2`
 *    ```
 *    [requires]
 *    spdlog/1.12.0
 *    fmt/10.1.1
 *    nlohmann_json/3.11.2
 *
 *    [generators]
 *    CMakeDeps
 *    CMakeToolchain
 *    ```
 * 3. Run `conan install . --output-folder=build --build=missing`
 * 4. Integrate with CMake via `build/conan_toolchain.cmake` and `build/conanbuildinfo.cmake`
 * 5. Write `CMakeLists.txt` using `find_package(spdlog REQUIRED)` after Conan setup
 * 6. Write `main.cpp` that uses spdlog for logging and nlohmann_json for serialisation
 * 7. Show `conan search spdlog` and `conan inspect spdlog/1.12.0`
 * 8. Explain the Conan cache at `~/.conan2/p/`
 *
 * **Expected output:**
 * ```
 * === Conan 2 Workflow ===
 *
 * $ conan profile detect
 * Profile created: default
 *   [settings]
 *   os=Linux
 *   arch=x86_64
 *   compiler=gcc
 *   compiler.version=12
 *   compiler.libcxx=libstdc++11
 *   build_type=Release
 *
 * $ conan install . --output-folder=build --build=missing
 *   Downloading spdlog/1.12.0 ...
 *   Downloading fmt/10.1.1 ...
 *   Downloading nlohmann_json/3.11.2 ...
 *   Generated: build/conan_toolchain.cmake
 *
 * $ cmake -S . -B build \
 *     -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake \
 *     -DCMAKE_BUILD_TYPE=Release
 * $ cmake --build build
 *
 * $ ./build/pricing_app
 * [2024-01-15 10:30:01] [info] Pricing app started
 * Price: {"symbol":"AAPL","price":150.25}
 * ```
 */

int main() {}
