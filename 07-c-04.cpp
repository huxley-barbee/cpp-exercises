/*
 * ## EXERCISE 4: Code Review — Reading a Pull Request [7.c.ii]
 *
 * A code review is a structured conversation about correctness, safety, performance,
 * and maintainability. This exercise teaches you to *give* a thorough review.
 *
 * **Requirements:**
 *
 * Review the following PR diff for a `computeVaR` function.
 * For each finding, state: **category** (correctness/performance/safety/style),
 * **severity** (blocker/major/minor/nit), **explanation**, and **suggested fix**.
 *
 * ```cpp
 * // PR: feat(risk): add historical VaR calculation
 * // File: risk/var_engine.cpp
 *
 * // ADDED:
 * double HistoricalVaR::compute(std::vector<double> returns,  // [A]
 *                                double confidence) {
 *     std::sort(returns.begin(), returns.end());
 *     int idx = returns.size() * (1.0 - confidence);          // [B]
 *     if (confidence > 1.0 || confidence < 0.0)               // [C]
 *         throw std::invalid_argument("confidence out of range");
 *     double var = -returns[idx];                              // [D]
 *     g_logger.log("VaR computed: " + std::to_string(var));   // [E]
 *     return var;
 * }
 *
 * // UNCHANGED (context):
 * extern Logger g_logger;                                      // [F]
 * ```
 *
 * Findings to identify (labelled A–F):
 * - A: pass `std::vector<double>` by value (unnecessary copy)
 * - B: integer truncation without bounds check (can produce index = size)
 * - C: validation after use of parameter (should come first)
 * - D: empty vector dereference (undefined behaviour if returns is empty)
 * - E: global logger (untestable, see section 7.a)
 * - F: extern global (ODR risk, untestable)
 *
 * **Expected output:**
 * ```
 * === Code Review: computeVaR ===
 *
 * [A] Performance — Minor
 *     Parameter 'returns' passed by value: unnecessary copy of potentially
 *     large vector. The function does sort the data, so a copy is needed —
 *     but the copy should be explicit at the call site, or the signature
 *     should take const& and sort a local copy.
 *     Fix: double compute(std::vector<double> returns, double confidence)
 *          is actually acceptable IF the caller uses std::move(). Add a
 *          comment explaining the intentional copy-on-modify pattern.
 *          Or: take const& and copy internally.
 *
 * [B] Correctness — Blocker
 *     Integer truncation: (int)(returns.size() * (1.0 - confidence))
 *     If confidence=0.0, idx = returns.size() — out of bounds!
 *     Fix: idx = std::max(0, (int)(returns.size() * (1.0 - confidence)) - 1)
 *          Also clamp to [0, size-1].
 *
 * [C] Correctness — Major
 *     Validation after the first use of 'confidence' in the sort index calc.
 *     If confidence is NaN, the UB happens before the check.
 *     Fix: move validation to the top of the function.
 *
 * [D] Correctness — Blocker
 *     If returns is empty, returns[idx] is undefined behaviour.
 *     Fix: if (returns.empty()) throw std::invalid_argument("empty returns");
 *
 * [E] Design — Major
 *     Global logger creates an untestable dependency (see 7.a).
 *     Fix: inject ILogger& via constructor or function parameter.
 *
 * [F] Design — Major
 *     extern global Logger — ODR risk if definition appears in multiple TUs.
 *     Fix: use a proper singleton or injected dependency.
 * ```
 */

int main() {}
