/*
 * ## EXERCISE 13: Comprehensive Integration [All of 4.a]
 *
 * You are given a C++98 `Portfolio` class excerpt typical of legacy quant code.
 * Read and extend it, then annotate every legacy pattern with its modern equivalent.
 *
 * **Requirements:**
 *
 * The `Portfolio` class manages a dynamic array of `Position` structs using raw pointers.
 * It uses a macro for logging, a `typedef` for the position array, a raw Singleton for config,
 * and manual copy semantics.
 *
 * 1. Implement `Portfolio` exactly as described (C++98 style — no `auto`, no lambdas, no smart pointers)
 * 2. Add `addPosition()`, `totalValue()`, `print()`, destructor, copy constructor, copy assignment
 * 3. Use `LOG(msg)` macro for all output
 * 4. Add a `typedef double Price` and `typedef std::string Symbol`
 * 5. Demonstrate: construction, copying, assignment, and destruction with correct deep-copy semantics
 * 6. After the working C++98 version, add a comment block listing every pattern used and its modern replacement
 *
 * **Expected output:**
 * ```
 * === Legacy Portfolio System ===
 * [portfolio.cpp:NN] Portfolio created (capacity=10)
 * [portfolio.cpp:NN] Added position: AAPL x 100 @ $150.00
 * [portfolio.cpp:NN] Added position: GOOGL x 50 @ $2800.00
 * [portfolio.cpp:NN] Added position: MSFT x 200 @ $300.00
 *
 * Portfolio contents:
 *   AAPL  100 shares @ $150.00  = $15000.00
 *   GOOGL  50 shares @ $2800.00 = $140000.00
 *   MSFT  200 shares @ $300.00  = $60000.00
 * Total value: $215000.00
 *
 * [portfolio.cpp:NN] Copying portfolio...
 * Copy created (independent deep copy)
 * [portfolio.cpp:NN] Modifying original — copy unaffected
 *
 * [portfolio.cpp:NN] ~Portfolio() freeing 3 positions
 * [portfolio.cpp:NN] ~Portfolio() freeing 3 positions
 *
 * === Legacy Pattern Audit ===
 * Raw pointer array      -> std::vector<Position>
 * typedef Price          -> using Price = double
 * LOG macro              -> inline log() template + __FILE__/__LINE__
 * Manual copy ctor       -> Rule of Zero with vector member
 * Raw Singleton config   -> function-local static
 * No override keyword    -> override / final
 * auto_ptr (if used)     -> unique_ptr
 * NULL                   -> nullptr
 * ```
 */

int main() {}
