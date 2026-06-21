/*
 * ## EXERCISE 6: Makefiles — Anatomy of a Rule [5.c.ii]
 *
 * Legacy quant codebases use Makefiles directly. Write one from scratch for a small
 * trading library.
 *
 * **Requirements:**
 * 1. Write a `Makefile` for a project with `main.cpp`, `pricer.cpp`, `pricer.hpp`
 * 2. Cover all Makefile anatomy:
 *    - Variables: `CXX`, `CXXFLAGS`, `LDFLAGS`, `TARGET`, `SRCS`, `OBJS`
 *    - Pattern rule: `%.o: %.cpp`
 *    - Phony targets: `.PHONY: all clean rebuild help`
 *    - Automatic variables: `$@` (target name), `$<` (first prerequisite), `$^` (all prerequisites)
 *    - Header dependency tracking with `-MMD -MP` and `include $(DEPS)`
 * 3. Add `debug` and `release` sub-targets with different flags
 * 4. Add a `help` target that prints all available targets
 * 5. Demonstrate `make -j8` for parallel builds and `make -n` for dry run
 * 6. Show what happens on a clean build, an incremental build, and after a header change
 *
 * **Expected output:**
 * ```
 * === Makefile Anatomy ===
 *
 * $ make
 * g++ -std=c++17 -O2 -Wall -MMD -MP -c -o obj/main.o   src/main.cpp
 * g++ -std=c++17 -O2 -Wall -MMD -MP -c -o obj/pricer.o src/pricer.cpp
 * g++ -o bin/pricing_tool obj/main.o obj/pricer.o
 *
 * $ make  (nothing changed)
 * make: 'bin/pricing_tool' is up to date.
 *
 * $ touch src/pricer.cpp && make
 * g++ -std=c++17 -O2 -Wall -MMD -MP -c -o obj/pricer.o src/pricer.cpp
 * g++ -o bin/pricing_tool obj/main.o obj/pricer.o
 * (only pricer.o recompiled — incremental build)
 *
 * $ make clean
 * rm -rf obj/ bin/
 *
 * $ make help
 * Targets:
 *   all     - build the project (default)
 *   clean   - remove build artifacts
 *   debug   - build with -g -O0
 *   release - build with -O2 -DNDEBUG
 *   help    - show this message
 * ```
 */

int main() {}
