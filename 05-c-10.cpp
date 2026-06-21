/*
 * ## EXERCISE 10: Conan — Profiles and Reproducible Builds [5.c.iii]
 *
 * Different environments (dev, CI, prod) need different compiler settings. Conan profiles
 * capture the full build environment.
 *
 * **Requirements:**
 * 1. Create three profiles under `profiles/`:
 *    - `profiles/debug`: `build_type=Debug`, ASAN flags via `[conf]`
 *    - `profiles/release`: `build_type=Release`, `-O2 -march=native` via `[conf]`
 *    - `profiles/ci`: `build_type=RelWithDebInfo`, static linking
 * 2. Show the full profile file format: `[settings]`, `[options]`, `[env]`, `[conf]`, `[buildenv]`
 * 3. Use a profile: `conan install . -pr:h=profiles/release --build=missing`
 * 4. Show package options: `spdlog:shared=True` vs `spdlog:shared=False`
 *    (static preferred for latency — no PLT indirection)
 * 5. Create a lockfile for reproducible builds: `conan lock create .` → `conan.lock`
 * 6. Show `conan create` to publish a local package to the local cache
 * 7. Explain the host profile (`-pr:h`) vs build profile (`-pr:b`) distinction for
 *    cross-compilation
 *
 * **Expected output:**
 * ```
 * === Conan Profiles ===
 *
 * profiles/release:
 *   [settings]
 *   build_type=Release
 *   compiler.cppstd=17
 *   [conf]
 *   tools.build:cxxflags=["-O2", "-march=native"]
 *
 * profiles/debug:
 *   [settings]
 *   build_type=Debug
 *   [conf]
 *   tools.build:cxxflags=["-g", "-fsanitize=address,undefined"]
 *
 * $ conan install . -pr:h=profiles/release --build=missing
 *   Generated: build/conan_toolchain.cmake  (with -O2 -march=native)
 *
 * $ conan lock create .
 *   Generated: conan.lock  (exact versions pinned for reproducibility)
 *
 * spdlog:shared=False -> .a  (default — zero PLT overhead, better latency)
 * spdlog:shared=True  -> .so (required for hot-reload scenarios)
 *
 * Host vs Build profiles:
 *   -pr:h  target machine (where binary will run)
 *   -pr:b  build machine  (where compilation happens)
 *   Different when cross-compiling (e.g. x86 -> ARM)
 * ```
 */

int main() {}
