/*
 * ## EXERCISE 11: vcpkg — Microsoft's Package Manager [5.c.iii]
 *
 * vcpkg is widely used in cross-platform quant shops and Windows-heavy environments.
 *
 * **Requirements:**
 * 1. Bootstrap vcpkg:
 *    ```bash
 *    git clone https://github.com/microsoft/vcpkg.git
 *    cd vcpkg && ./bootstrap-vcpkg.sh
 *    export VCPKG_ROOT=$(pwd)
 *    ```
 * 2. Install packages in classic mode: `vcpkg install eigen3 spdlog fmt nlohmann-json`
 * 3. Write a `vcpkg.json` manifest (modern mode):
 *    ```json
 *    {
 *      "name": "quant-pricer",
 *      "version": "1.0.0",
 *      "dependencies": ["eigen3", "spdlog", "fmt", "nlohmann-json"]
 *    }
 *    ```
 * 4. Integrate with CMake:
 *    `cmake -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake ...`
 * 5. Write `CMakeLists.txt` using `find_package(Eigen3 REQUIRED)` and
 *    `target_link_libraries(... Eigen3::Eigen)`
 * 6. Show `vcpkg list`, `vcpkg search eigen`, and `vcpkg x-history eigen3`
 * 7. Compare vcpkg vs Conan across five dimensions:
 *    profile system, binary caching, Windows integration, manifest files, cross-compilation
 *
 * **Expected output:**
 * ```
 * === vcpkg Workflow ===
 *
 * $ ./bootstrap-vcpkg.sh
 * Building vcpkg... done
 *
 * $ vcpkg install eigen3 spdlog fmt
 * Installing eigen3:x64-linux ...
 * Installing spdlog:x64-linux ...
 * Installing fmt:x64-linux ...
 *
 * vcpkg.json (manifest mode):
 * {
 *   "name": "quant-pricer",
 *   "dependencies": ["eigen3", "spdlog", "fmt"]
 * }
 *
 * $ cmake -S . -B build \
 *     -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
 * $ cmake --build build
 *
 * $ ./build/quant_pricer
 * Eigen version: 3.4.0
 * Matrix product computed
 *
 * === vcpkg vs Conan ===
 * Feature             vcpkg          Conan
 * Profile system      limited        rich (settings/options/conf)
 * Binary caching      yes            yes
 * Windows integration excellent      good
 * Manifest files      vcpkg.json     conanfile.txt / .py
 * Cross-compilation   via triplets   via host/build profiles
 * ```
 */

int main() {}
