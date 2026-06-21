/*
 * ## EXERCISE 5: CMake — `find_package` and System Libraries [5.c.i]
 *
 * Learn to link against system-installed libraries using the modern CMake `find_package`
 * mechanism.
 *
 * **Requirements:**
 * 1. `find_package(Threads REQUIRED)` → link with `Threads::Threads`
 * 2. `find_package(Boost 1.74 REQUIRED COMPONENTS system filesystem)` → link imported targets
 * 3. `find_package(OpenSSL REQUIRED)` → link `OpenSSL::SSL` and `OpenSSL::Crypto`
 * 4. Show the error message when a required package is missing
 * 5. Write a `cmake/FindQuantLib.cmake` module (Module mode) for a library that ships
 *    no CMake config files, using `find_path` and `find_library`
 * 6. Show `CMAKE_PREFIX_PATH` to point CMake at a non-standard install directory
 * 7. Distinguish **Config mode** (`<Pkg>Config.cmake`) from **Module mode** (`Find<Pkg>.cmake`)
 *
 * **Expected output:**
 * ```
 * === find_package Demo ===
 *
 * find_package(Threads REQUIRED):
 *   Threads::Threads -> -lpthread
 *
 * find_package(Boost 1.74):
 *   Boost 1.80.0 at /usr/include
 *   Boost::system, Boost::filesystem
 *
 * find_package(OpenSSL REQUIRED):
 *   OpenSSL 3.0.2
 *   OpenSSL::SSL    -> libssl.so
 *   OpenSSL::Crypto -> libcrypto.so
 *
 * Missing package:
 *   CMake Error: Could not find a package configuration file for "MissingLib"
 *
 * FindQuantLib.cmake (Module mode):
 *   find_path(QuantLib_INCLUDE_DIR ql/quantlib.hpp ...)
 *   find_library(QuantLib_LIBRARY QuantLib ...)
 *   Sets: QuantLib_FOUND, QuantLib_INCLUDE_DIRS, QuantLib_LIBRARIES
 *
 * Config vs Module:
 *   Config: package ships its own <Pkg>Config.cmake  (preferred)
 *   Module: CMake ships or you write a Find<Pkg>.cmake (fallback)
 * ```
 */

int main() {}
