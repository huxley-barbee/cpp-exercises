/*
 * ## EXERCISE 5: Code Review — Writing Review Comments [7.c.ii]
 *
 * Effective review comments are specific, actionable, and educational.
 * This exercise practises writing them.
 *
 * **Requirements:**
 *
 * For each of the following code snippets from a legacy market-data handler,
 * write a professional review comment in the GitHub PR comment style:
 * - One sentence stating **what** the issue is
 * - One sentence explaining **why** it matters
 * - A concrete **suggested fix** (inline code block)
 * - A **severity label**: `[blocker]`, `[major]`, `[minor]`, `[nit]`
 *
 * Snippets to review:
 *
 * 1. ```cpp
 *    char symbol[8];
 *    strncpy(symbol, input, 8);  // [missing null terminator]
 *    printf("Symbol: %s\n", symbol);
 *    ```
 *
 * 2. ```cpp
 *    double* prices = new double[n];
 *    processTick(prices, n);
 *    return prices;  // [ownership ambiguity]
 *    ```
 *
 * 3. ```cpp
 *    for (int i = 0; i < orders.size(); ++i)  // [signed/unsigned mismatch]
 *        process(orders[i]);
 *    ```
 *
 * 4. ```cpp
 *    if (bid > ask)
 *        swap(bid, ask);  // [silent data corruption if pointers alias]
 *    ```
 *
 * 5. ```cpp
 *    double npv = computeNPV(cashflows, n, rate);
 *    // npv used 50 lines later without checking for NaN  [NaN propagation]
 *    ```
 *
 * 6. ```cpp
 *    std::mutex m;
 *    void updatePrice(double p) {
 *        std::lock_guard<std::mutex> lk(m);
 *        price_ = p;
 *    }
 *    double getPrice() { return price_; }  // [missing lock on read]
 *    ```
 *
 * **Expected output:**
 * ```
 * === Review Comment 1: strncpy missing null terminator ===
 * [blocker] `strncpy` does not write a null terminator when `input` is ≥ 8
 * characters, causing `printf` to read past the buffer (undefined behaviour /
 * potential crash). Use `strncpy(symbol, input, 7); symbol[7] = '\0';` or
 * prefer `std::string` / `std::string_view`.
 *
 * === Review Comment 2: ownership ambiguity ===
 * [major] Returning a raw `double*` from a `new` allocation transfers ownership
 * to the caller with no indication in the type system — callers may forget to
 * `delete[]`, causing a memory leak. Return `std::unique_ptr<double[]>` or
 * `std::vector<double>` instead.
 *
 * ... (comments 3–6 similar)
 * ```
 */

int main() {}
