/*
 * ## EXERCISE 7: Static Analyzers — `clang-tidy` [7.c.iii]
 *
 * `clang-tidy` is the standard C++ linter. It can find bugs, enforce modernisation,
 * and check coding guidelines — all automatically in CI.
 *
 * **Requirements:**
 *
 * 1. Configure a `.clang-tidy` file for a quant finance codebase:
 *    - Enable `modernize-*` (use C++17 idioms)
 *    - Enable `cppcoreguidelines-*` (C++ Core Guidelines)
 *    - Enable `performance-*` (performance anti-patterns)
 *    - Enable `bugprone-*` (common bug patterns)
 *    - Disable specific checks that conflict with the codebase style
 * 2. Run `clang-tidy` on a legacy source file and categorise all warnings
 * 3. Show `clang-tidy --fix` to automatically apply safe fixes
 * 4. Write a `Makefile` target `lint` that runs clang-tidy on all changed files
 * 5. Show how to suppress a specific warning inline:
 *    `// NOLINT(bugprone-easily-swappable-parameters)`
 * 6. Demonstrate `clang-tidy` as a CMake check using `CMAKE_CXX_CLANG_TIDY`
 * 7. Show the difference between `clang-tidy` and `clang --analyze` (CSA)
 *
 * **Expected output:**
 * ```
 * === .clang-tidy configuration ===
 * ---
 * Checks: >
 *   clang-diagnostic-*,
 *   cppcoreguidelines-avoid-non-const-global-variables,
 *   cppcoreguidelines-owning-memory,
 *   modernize-use-nullptr,
 *   modernize-use-using,
 *   modernize-use-override,
 *   modernize-loop-convert,
 *   performance-unnecessary-copy-initialization,
 *   performance-move-const-arg,
 *   bugprone-use-after-move,
 *   bugprone-integer-division,
 *   bugprone-signed-char-misuse,
 *   -modernize-use-trailing-return-type
 * WarningsAsErrors: 'cppcoreguidelines-owning-memory,bugprone-use-after-move'
 * HeaderFilterRegex: '(lib|app)/.*\.h$'
 * ...
 *
 * === clang-tidy output on legacy file ===
 * legacy_pricer.cpp:12:5: warning: use nullptr [modernize-use-nullptr]
 *     ptr = NULL;
 *           ^~~~
 *           nullptr
 *
 * legacy_pricer.cpp:34:17: warning: use range-based for loop [modernize-loop-convert]
 *     for (int i = 0; i < vec.size(); i++)
 *
 * legacy_pricer.cpp:56:3: error: owning pointer not managed by RAII
 *     [cppcoreguidelines-owning-memory]
 *     double* buf = new double[n];
 *
 * === Auto-fix ===
 * $ clang-tidy --fix legacy_pricer.cpp -- -std=c++17
 * Applied 3 fixes: NULL->nullptr, for->range-for, (ownership requires manual fix)
 * ```
 */

int main() {}
