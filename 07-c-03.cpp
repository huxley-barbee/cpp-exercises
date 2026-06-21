/*
 * ## EXERCISE 3: Git — Advanced Branch Management [7.c.i]
 *
 * Managing long-running feature branches and integrating upstream changes are
 * daily tasks in a multi-developer quant codebase.
 *
 * **Requirements:**
 *
 * 1. Show the difference between `git merge` and `git rebase` for integrating `main`
 *    into a feature branch — produce both graphs and explain when to use each
 * 2. Demonstrate `git cherry-pick` to port a hotfix from `main` to a release branch
 * 3. Show `git reflog` to recover from an accidentally deleted branch or bad rebase
 * 4. Demonstrate `git stash` / `git stash pop` for switching context mid-task
 * 5. Show `git worktree add` to work on two branches simultaneously without stashing
 * 6. Demonstrate `git tag -s v1.2.0 -m "Release 1.2.0"` for signed release tags
 * 7. Show `git log --oneline --graph --all --decorate` for a complex multi-branch view
 * 8. Demonstrate `git blame -L 15,25 pricing.cpp` to find who wrote a specific section
 *
 * **Expected output:**
 * ```
 * === merge vs rebase ===
 *
 * After merge (preserves history, creates merge commit):
 * *   a1b2c3d Merge branch 'main' into feature/risk-engine
 * |\
 * | * f0e1d2c feat: add rate curve bootstrapping (main)
 * * | 9e8f7a6 wip: var engine (feature)
 *
 * After rebase (linear history, replays commits on top of main):
 * * b2c3d4e wip: var engine (replayed)
 * * f0e1d2c feat: add rate curve bootstrapping (main)
 *
 * Rule:
 *   rebase:  feature branches before PR (clean history)
 *   merge:   integrating into main/release (preserve context)
 *
 * === cherry-pick ===
 * $ git cherry-pick abc1234   # port hotfix to release branch
 * [release/1.2 9f8e7d6] fix: correct NPV sign convention
 *  1 file changed, 1 insertion(+), 1 deletion(-)
 *
 * === reflog recovery ===
 * $ git reflog | head -5
 * abc1234 HEAD@{0}: rebase: onto main
 * def5678 HEAD@{1}: commit: feat: add greeks
 * ...
 * $ git checkout -b recovered HEAD@{1}
 *
 * === git blame ===
 * $ git blame -L 15,25 pricing.cpp
 * 9abc123 (Alice  2024-01-10) double priceBond(double par,
 * 9abc123 (Alice  2024-01-10)     double coupon, double yield, int years) {
 * b2c3d4e (Bob    2024-01-12)     double npv = 0.0;
 * ```
 */

int main() {}
