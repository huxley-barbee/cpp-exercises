/*
 * ## EXERCISE 11: Integrating Tools into CI [7.c.i–iii]
 *
 * All three tool categories (Git hooks, code review automation, static analysis)
 * should run automatically in CI. Build the full pipeline.
 *
 * **Requirements:**
 *
 * 1. **Pre-commit hook** (`.git/hooks/pre-commit`):
 *    - Run `clang-format --dry-run` on staged C++ files
 *    - Run `clang-tidy` on changed files with a strict subset of checks
 *    - Block the commit if either fails
 * 2. **Pre-push hook** (`.git/hooks/pre-push`):
 *    - Build the project and run all tests
 *    - Run ASAN build and tests
 * 3. **GitHub Actions / CI pipeline** (`.github/workflows/ci.yml`):
 *    - Job 1: build and test (Debug + Release)
 *    - Job 2: sanitisers (ASan + TSan + UBSan)
 *    - Job 3: static analysis (clang-tidy + cppcheck)
 *    - Job 4: code coverage (gcov/lcov)
 * 4. **Branch protection rules**: require all 4 CI jobs to pass before merge
 * 5. Show how `git bisect run` integrates with the CI test script
 * 6. Show a `Makefile` with targets: `check`, `lint`, `sanitize`, `coverage`
 *
 * **Expected output:**
 * ```
 * === Pre-commit hook ===
 * $ git commit -m "feat: add bond pricer"
 * [pre-commit] Checking formatting...
 * [pre-commit] legacy_pricer.cpp: NEEDS FORMATTING
 *   Run: clang-format -i legacy_pricer.cpp
 * Commit blocked.
 *
 * === Pre-push hook ===
 * $ git push origin feature/bond-pricer
 * [pre-push] Building and testing...
 * [pre-push] ASAN build...
 * All checks passed. Pushing.
 *
 * === CI pipeline (GitHub Actions) ===
 * Job 1: Build & Test      ✓  (45s)
 * Job 2: Sanitisers        ✓  (120s)
 * Job 3: Static Analysis   ✗  (30s) — 2 clang-tidy warnings
 * Job 4: Coverage          ✓  (60s) — 87% line coverage
 *
 * PR blocked: Job 3 must pass before merge.
 *
 * === Makefile targets ===
 * make check     # build + test
 * make lint      # clang-tidy + clang-format check
 * make sanitize  # ASAN + UBSAN + TSAN builds and tests
 * make coverage  # gcov report
 * ```
 */

int main() {}
