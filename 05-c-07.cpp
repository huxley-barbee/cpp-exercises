/*
 * ## EXERCISE 7: Makefiles — Dependency Tracking [5.c.ii]
 *
 * Header changes must trigger recompilation of every translation unit that includes them.
 *
 * **Requirements:**
 * 1. Compile a `.cpp` file with `-MMD -MP`, then examine the generated `.d` file to
 *    understand its format
 * 2. Show the `include $(wildcard obj/*.d)` pattern that feeds dep files back into Make
 * 3. Demonstrate that touching `pricer.hpp` causes **both** `main.cpp` and `pricer.cpp`
 *    to recompile (both include it)
 * 4. Build a non-recursive Makefile that handles two subdirectories (`src/` and `lib/`)
 *    from a single top-level `Makefile` — explain why this is better than recursive make
 * 5. Show the recursive make anti-pattern (`$(MAKE) -C subdir`) and its jobserver problem
 * 6. Add a `compile_commands.json` target (using `bear -- make` or via CMake's
 *    `CMAKE_EXPORT_COMPILE_COMMANDS=ON`) for IDE/clangd integration
 * 7. Demonstrate `$(MAKE)` vs bare `make` for sub-invocations (jobserver token propagation)
 *
 * **Expected output:**
 * ```
 * === Dependency Tracking ===
 *
 * Generated obj/pricer.o.d:
 *   obj/pricer.o: src/pricer.cpp src/pricer.hpp
 *
 * Generated obj/main.o.d:
 *   obj/main.o: src/main.cpp src/pricer.hpp
 *
 * $ touch src/pricer.hpp && make
 * Compiling src/main.cpp...    <- both recompiled
 * Compiling src/pricer.cpp...
 * Linking...
 *
 * $ touch src/pricer.cpp && make
 * Compiling src/pricer.cpp...  <- only pricer.cpp recompiled
 * Linking...
 *
 * Non-recursive Makefile:
 *   Single Makefile governs src/ and lib/
 *   Full dependency graph visible to make
 *   Parallel builds work correctly (-j8)
 *   No jobserver fragmentation
 * ```
 */

int main() {}
