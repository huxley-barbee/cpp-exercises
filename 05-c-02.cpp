/*
 * ## EXERCISE 2: CMake — Libraries and Targets [5.c.i]
 *
 * Most quant systems are split into a core library and multiple executable entry points.
 * Write a CMake project that demonstrates the modern target-based model.
 *
 * **Requirements:**
 * 1. Create the following structure:
 *    ```
 *    quant_lib/
 *    ├── CMakeLists.txt
 *    ├── lib/
 *    │   ├── CMakeLists.txt
 *    │   ├── pricer.hpp
 *    │   └── pricer.cpp        (Black-Scholes call price)
 *    └── apps/
 *        ├── CMakeLists.txt
 *        └── price_option.cpp
 *    ```
 * 2. `lib/CMakeLists.txt`: define a `STATIC` library target `quant_core`
 * 3. Set include directories with `target_include_directories(quant_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})`
 * 4. `apps/CMakeLists.txt`: define executable `price_option`, link with `target_link_libraries(price_option PRIVATE quant_core)`
 * 5. Demonstrate the **modern CMake target model**: no global `include_directories()`, no manual `-I` flags — everything flows through target properties
 * 6. Write comments explaining `PUBLIC` vs `PRIVATE` vs `INTERFACE` propagation
 * 7. Add `add_subdirectory(lib)` and `add_subdirectory(apps)` to the root `CMakeLists.txt`
 * 8. Build in both `Debug` and `Release` and print the flag difference
 *
 * **Expected output:**
 * ```
 * === CMake Library + Executable ===
 *
 * Target graph:
 *   price_option -> quant_core (STATIC)
 *
 * PUBLIC include: consumers of quant_core automatically get -I lib/
 * PRIVATE include: internal only, not propagated to consumers
 * INTERFACE include: header-only — propagated but not used by quant_core itself
 *
 * Debug build:   -g -O0
 * Release build: -O2 -DNDEBUG
 *
 * $ ./build/apps/price_option
 * Black-Scholes call: $10.45  (S=100 K=100 T=1 r=0.05 sigma=0.2)
 * ```
 */

int main() {}
