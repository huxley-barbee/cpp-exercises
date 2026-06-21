/*
 * ## EXERCISE 2: Git — `git bisect` to Find a Regression [7.c.i]
 *
 * `git bisect` performs a binary search through commit history to find the exact
 * commit that introduced a bug or performance regression.
 *
 * **Requirements:**
 *
 * 1. Create a repository with 10 commits, each modifying a `computeNPV` function.
 *    One commit in the middle introduces a bug (uses the wrong discount formula).
 * 2. Write a `test_npv.sh` bisect script:
 *    ```bash
 *    #!/bin/bash
 *    make -q && ./test_npv
 *    exit $?   # 0 = good, non-zero = bad
 *    ```
 * 3. Run the full `git bisect` session:
 *    - `git bisect start`
 *    - `git bisect bad HEAD` — current HEAD is broken
 *    - `git bisect good v1.0` — a known-good tag
 *    - `git bisect run ./test_npv.sh` — automated binary search
 * 4. Show the binary search output: which commits were tested (log₂10 ≈ 4 steps)
 * 5. Show `git bisect log` to record the session
 * 6. Show `git bisect reset` to return to HEAD
 * 7. Demonstrate a **performance bisect**: instead of pass/fail, the test measures
 *    latency and exits 1 if latency > threshold (e.g., > 100ms)
 *
 * **Expected output:**
 * ```
 * === git bisect session ===
 *
 * $ git bisect start
 * $ git bisect bad HEAD
 * $ git bisect good v1.0
 * Bisecting: 4 revisions left to test after this (roughly 3 steps)
 * [commit5] refactor: extract helper functions
 *
 * running ./test_npv.sh
 * Bisecting: 1 revision left to test after this (roughly 1 step)
 * [commit3] perf: optimise inner loop
 *
 * running ./test_npv.sh
 * Bisecting: 0 revisions left to test after this (roughly 0 steps)
 * [commit4] fix: correct boundary condition
 *
 * running ./test_npv.sh
 * 9abc123 is the first bad commit
 * commit 9abc123
 * Author: dev <dev@firm.com>
 * Date:   Mon Jan 15 10:23:00 2024
 *
 *     fix: correct boundary condition
 *     (BUG: changed '< n' to '<= n' — introduced off-by-one)
 *
 * $ git bisect reset
 * HEAD is now at abc1234 (HEAD)
 *
 * === Performance bisect ===
 * test exits 1 if runtime > 100ms
 * Found: commit that changed O(n) algorithm to O(n²) hash rebuild
 * ```
 */

int main() {}
