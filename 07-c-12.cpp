/*
 * ## EXERCISE 12: Comprehensive Git Workflow — A Full Feature Lifecycle [7.c.i–ii]
 *
 * Simulate the complete lifecycle of a feature in a professional quant codebase:
 * from branch creation through PR, review, fixes, and merge.
 *
 * **Requirements:**
 *
 * 1. **Create feature branch**: `git checkout -b feature/yield-curve-interpolation`
 * 2. **Develop with good commits**: 4 commits following Conventional Commits
 * 3. **Rebase onto updated main**: `git fetch origin && git rebase origin/main`
 * 4. **Resolve a conflict**: show the conflict markers and resolution
 * 5. **Interactive rebase**: squash fixup commits, reword commit messages
 * 6. **Push and open PR**: `git push -u origin feature/yield-curve-interpolation`
 * 7. **Respond to review comments**: push a new commit addressing each finding
 * 8. **Final squash and merge**: clean single commit on `main`
 * 9. **Tag the release**: `git tag -a v1.3.0 -m "feat: yield curve interpolation"`
 * 10. Show `git log --oneline --graph` after the full cycle
 *
 * **Expected output:**
 * ```
 * === Feature branch commits (before cleanup) ===
 * 5 commits: initial skeleton, implementation, test, fixup, review fix
 *
 * === After rebase onto main ===
 * Conflict in pricing/yield_curve.cpp:
 * <<<<<<< HEAD (main)
 *     return linearInterpolate(tenors_, rates_, t);
 * =======
 *     return cubicSplineInterpolate(tenors_, rates_, t);
 * >>>>>>> feature/yield-curve-interpolation
 * Resolved: keep cubic spline (feature adds new capability)
 *
 * === After interactive rebase (clean history) ===
 * feat(pricing): add cubic spline yield curve interpolation
 * test(pricing): add yield curve interpolation regression tests
 *
 * === After merge to main ===
 * * a1b2c3d (tag: v1.3.0, main) feat(pricing): add cubic spline interpolation
 * * f0e1d2c (tag: v1.2.0) feat(risk): add parallel VaR calculation
 * * 9e8f7a6 (tag: v1.1.0) feat(pricing): add Black-Scholes option pricer
 * ```
 */

int main() {}
