/*
 * ## EXERCISE 1: CMake — Minimal Project [5.c.i]
 *
 * Write the smallest correct CMake project structure for a single-executable pricing tool.
 *
 * **Requirements:**
 * 1. Create the following file tree:
 *    ```
 *    pricing_tool/
 *    ├── CMakeLists.txt
 *    └── src/
 *        └── main.cpp
 *    ```
 * 2. `CMakeLists.txt` must:
 *    - `cmake_minimum_required(VERSION 3.20)`
 *    - `project(PricingTool VERSION 1.0.0 LANGUAGES CXX)`
 *    - Set `CMAKE_CXX_STANDARD 17` and `CMAKE_CXX_STANDARD_REQUIRED ON`
 *    - Add executable target `pricing_tool` from `src/main.cpp`
 * 3. `main.cpp` prints the project name and version via CMake-generated `configure_file` defines
 * 4. Show the out-of-source build workflow:
 *    ```bash
 *    cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
 *    cmake --build build
 *    ./build/pricing_tool
 *    ```
 * 5. Explain why out-of-source builds are mandatory (never pollute the source tree)
 * 6. Show `cmake --build build --verbose` to see the raw compiler invocation
 * 7. Show `cmake --install build --prefix /tmp/pricing_install` and the resulting layout
 *
 * **Expected output:**
 * ```
 * === CMake Minimal Project ===
 *
 * File tree:
 *   pricing_tool/
 *   ├── CMakeLists.txt
 *   └── src/main.cpp
 *
 * Build steps:
 *   $ cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
 *   -- The CXX compiler identification is GNU 12.3.0
 *   -- Configuring done
 *   -- Build files have been written to: .../build
 *
 *   $ cmake --build build
 *   [100%] Linking CXX executable pricing_tool
 *
 *   $ ./build/pricing_tool
 *   PricingTool v1.0.0
 *   Built with: g++ -O2 -DNDEBUG
 *
 * Install layout (/tmp/pricing_install):
 *   bin/pricing_tool
 * ```
 */

int main() {}
