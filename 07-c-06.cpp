/*
 * ## EXERCISE 6: Code Review — Self-Review Checklist [7.c.ii]
 *
 * Before submitting any PR, a disciplined engineer performs a self-review.
 * Build and apply a domain-specific checklist for C++ quant code.
 *
 * **Requirements:**
 *
 * 1. Build a checklist with at least 20 items across these categories:
 *    - **Correctness**: numeric edge cases, integer overflow, NaN handling
 *    - **Memory safety**: ownership clear, no leaks, no use-after-free
 *    - **Concurrency**: shared state protected, no races, correct memory ordering
 *    - **Performance**: no allocations in hot paths, cache-friendly layout
 *    - **Error handling**: all error paths handled, exceptions documented
 *    - **Testability**: dependencies injectable, pure functions extracted
 *    - **Style**: naming conventions, Conventional Commits, no TODOs without tickets
 * 2. Apply the checklist to this PR snippet:
 *    ```cpp
 *    // PR: feat(risk): parallel VaR calculation
 *    void RiskEngine::computeAllVaR(std::vector<Position>& positions) {
 *        std::vector<std::thread> threads;
 *        for (auto& pos : positions)
 *            threads.push_back(std::thread([&pos, this]() {
 *                double var = computeVaR(pos);
 *                results_[pos.symbol] = var;    // shared map — no lock!
 *            }));
 *        for (auto& t : threads) t.join();
 *    }
 *    ```
 * 3. Show which checklist items are violated in this snippet
 * 4. Provide the corrected version
 *
 * **Expected output:**
 * ```
 * === Self-Review Checklist (25 items) ===
 *
 * CORRECTNESS
 * [ ] Integer arithmetic: no overflow in index calculations
 * [ ] Floating point: NaN/Inf propagation checked at entry points
 * [ ] Bounds: all array/vector accesses within valid range
 * [ ] Edge cases: empty containers, zero values, negative inputs
 * [ ] Numeric precision: fixed-point vs floating-point policy clear
 *
 * MEMORY SAFETY
 * [ ] Ownership: raw pointers only for non-owning references
 * [ ] Lifetimes: no dangling references (especially in lambdas)
 * [ ] RAII: all resources wrapped in owning types
 * [ ] No new/delete: use smart pointers or containers
 * [ ] ASan clean: run under AddressSanitizer before PR
 *
 * ... (20+ items total)
 *
 * === Checklist violations in the PR snippet ===
 * [FAIL] Concurrency: results_ map written from multiple threads without lock
 * [FAIL] Lifetime: lambda captures pos by reference — safe here (join before
 *        positions goes out of scope) but fragile; prefer capture by value
 * [FAIL] Performance: std::thread creation per position — use a thread pool
 * [FAIL] Error handling: no exception handling in thread lambda
 *
 * === Corrected version ===
 * void RiskEngine::computeAllVaR(std::vector<Position>& positions) {
 *     std::mutex resultsMutex;
 *     std::vector<std::future<void>> futures;
 *     for (auto& pos : positions)
 *         futures.push_back(pool_.submit([&pos, &resultsMutex, this]() {
 *             double var = computeVaR(pos);
 *             std::lock_guard<std::mutex> lk(resultsMutex);
 *             results_[pos.symbol] = var;
 *         }));
 *     for (auto& f : futures) f.get();   // propagates exceptions
 * }
 * ```
 */

int main() {}
