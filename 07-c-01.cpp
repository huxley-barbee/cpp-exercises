/*
 * ## EXERCISE 1: Git — Interactive Rebase for a Clean History [7.c.i]
 *
 * A clean commit history is the foundation of effective code review and bisect.
 * Interactive rebase lets you rewrite history before pushing.
 *
 * **Requirements:**
 *
 * Simulate a realistic messy development sequence:
 * 1. Create a new branch `feature/bond-pricer` from `main`
 * 2. Make the following five commits (use a simple C++ file as the subject):
 *    - `"Add priceBond skeleton"` — function signature, returns 0
 *    - `"WIP: discount factor loop"` — partial implementation, doesn't compile
 *    - `"fix compile error"` — single semicolon added
 *    - `"Implement priceBond"` — working implementation
 *    - `"Add tests for priceBond"` — test file added
 * 3. Use `git rebase -i HEAD~5` to:
 *    - **squash** the three WIP/fix commits into one clean commit
 *    - **reword** the remaining commits to follow Conventional Commits format:
 *      `feat(pricing): add priceBond discounted cash-flow implementation`
 *    - **reorder** so the test commit comes before the implementation (to show TDD)
 * 4. Show the before/after `git log --oneline` output
 * 5. Show `git log --oneline --graph --all` to visualise the branch
 * 6. Demonstrate `git rebase --abort` and `git rebase --continue` for conflict handling
 *
 * **Expected output:**
 * ```
 * === Before rebase ===
 * git log --oneline feature/bond-pricer
 * a7f3c91 Add tests for priceBond
 * 3e8d021 Implement priceBond
 * 99c1b44 fix compile error
 * d4a0f78 WIP: discount factor loop
 * b2e19ac Add priceBond skeleton
 *
 * === After interactive rebase ===
 * git log --oneline feature/bond-pricer
 * f1d4a22 test(pricing): add priceBond characterisation tests
 * c8b7e31 feat(pricing): add priceBond discounted cash-flow implementation
 *
 * === Graph ===
 * * f1d4a22 (feature/bond-pricer) test(pricing): add tests
 * * c8b7e31 feat(pricing): add priceBond implementation
 * | * 1a2b3c4 (main) chore: initial project setup
 * |/
 * (diverged from main — ready for PR)
 *
 * === Conflict handling ===
 * git rebase --abort    # undo entire rebase, return to original
 * git rebase --continue # after resolving a conflict, proceed
 * git rebase --skip     # skip the current commit during conflict
 * ```
 */

int main() {}
