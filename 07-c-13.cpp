/*
 * ## EXERCISE 13: Comprehensive Integration [All of 7.c]
 *
 * Apply the complete version control and quality workflow to a realistic legacy
 * module, producing a PR-ready, CI-passing, reviewed, and analysed result.
 *
 * **Requirements:**
 *
 * Starting point: the `LegacyOrderRouter` from section 7.a.12, now with
 * additional code-quality issues:
 *
 * ```cpp
 * // legacy_order_router.cpp — has review and analysis issues
 * #include "everything.h"    // iwyu violation
 * int g_orderCount = 0;      // global — non-const, defined in cpp (ok) but
 *                            // declared extern in the header (ODR risk)
 *
 * class LegacyOrderRouter {
 * public:
 *     bool route(Order* order, int n, double* prices, int priceCount) {
 *         // [A] parameters in wrong order — easily swappable
 *         for (int i = 0; i <= n; ++i) {        // [B] off-by-one
 *             if (prices[i] < 0) continue;       // [C] OOB when i==n
 *             order[i].status = ROUTED;
 *             ++g_orderCount;                    // [D] non-atomic global
 *         }
 *         return true;  // [E] always returns true — errors silently swallowed
 *     }
 * };
 * ```
 *
 * Apply in order:
 * 1. **Git**: create a branch `fix/order-router-quality`, make atomic commits per fix
 * 2. **Static analysis**: run clang-tidy and cppcheck, document all findings
 * 3. **Code review**: write a self-review comment for each finding A–E
 * 4. **Fix**: apply all fixes, add `[[nodiscard]]`, use `std::span`, modernise
 * 5. **Tests**: add regression tests for the boundary conditions
 * 6. **Interactive rebase**: squash to two clean commits (fixes + tests)
 * 7. **CI check**: show the Makefile `lint` and `sanitize` targets passing
 * 8. **Tag**: `git tag fix/order-router-quality-v1`
 *
 * **Expected output:**
 * ```
 * === Static analysis findings ===
 * clang-tidy: bugprone-easily-swappable-parameters [A]
 * clang-tidy: cppcoreguidelines-avoid-non-const-global-variables [D]
 * cppcheck:   Array out of bounds [B/C]
 *
 * === Self-review comments ===
 * [A] Minor: 'order, n, prices, priceCount' — n and priceCount are easily
 *     transposed. Use a struct or std::span to group pointer+count.
 * [B/C] Blocker: i <= n reads prices[n] which is one past the end — UB.
 * [D] Major: g_orderCount non-atomic — data race under concurrent routing.
 * [E] Major: bool return always true — callers cannot detect routing failure.
 *
 * === Clean git log after rebase ===
 * * b2c3d4e fix(routing): correct off-by-one, add error return, atomic counter
 * * a1b2c3d test(routing): add boundary and error-path regression tests
 *
 * === CI output ===
 * lint:      PASS (0 clang-tidy warnings)
 * sanitize:  PASS (ASAN + UBSAN clean)
 * tests:     5/5 passed
 * ```
 *
 * ---
 *
 * ## Tool and Command Reference
 *
 * ```bash
 * # ---- Git advanced ----
 * git rebase -i HEAD~N              # interactive rebase last N commits
 * git rebase --onto main base feat  # transplant feat onto main
 * git bisect start
 * git bisect bad HEAD
 * git bisect good <tag>
 * git bisect run ./test.sh
 * git bisect reset
 * git cherry-pick <hash>
 * git reflog                        # recover lost commits
 * git stash / git stash pop
 * git worktree add ../branch2 branch2
 * git blame -L 10,20 file.cpp
 * git log --oneline --graph --all --decorate
 *
 * # ---- clang-tidy ----
 * clang-tidy file.cpp -- -std=c++17
 * clang-tidy --fix file.cpp -- -std=c++17
 * clang-tidy -checks='modernize-*,bugprone-*' file.cpp -- -std=c++17
 * # CMake integration:
 * cmake -DCMAKE_CXX_CLANG_TIDY="clang-tidy;-checks=modernize-*" ..
 *
 * # ---- clang-format ----
 * clang-format -i *.cpp *.h         # format in-place
 * clang-format --dry-run --Werror *.cpp  # check (for CI)
 * # Style config: .clang-format in repo root
 *
 * # ---- CSA (scan-build) ----
 * scan-build -o report/ make
 * scan-build -enable-checker alpha.security.ArrayBoundV2 make
 *
 * # ---- cppcheck ----
 * cppcheck --enable=all --std=c++17 --error-exitcode=1 src/
 *
 * # ---- iwyu ----
 * include-what-you-use file.cpp -- -std=c++17
 * iwyu_tool.py -p build/ src/ | fix_includes.py
 *
 * # ---- Git hooks (make executable) ----
 * chmod +x .git/hooks/pre-commit
 * chmod +x .git/hooks/pre-push
 * ```
 */

int main() {}
