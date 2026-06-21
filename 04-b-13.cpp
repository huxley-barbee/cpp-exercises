/*
 * ## EXERCISE 13: Comprehensive Integration [All of 4.b]
 *
 * You are maintaining a C++98 legacy `FixedIncomeBook` system. It uses virtual dispatch,
 * homegrown containers, manual copy semantics, `typedef`-heavy types, and global state.
 * Read, extend, and annotate the code.
 *
 * **Requirements:**
 *
 * Implement a `FixedIncomeBook` that:
 * 1. Uses a `DynArray<Bond*>` (homegrown container from Exercise 4) to store bonds
 * 2. Uses virtual dispatch: `Bond` derives from `Instrument` (Exercise 1)
 * 3. Uses `typedef double Price`, `typedef double Yield`, `typedef int Maturity`
 * 4. Has a global `int g_bondCount` that is incremented on each `Bond` construction
 * 5. Implements the Rule of Three (the `DynArray` member forces this)
 * 6. Uses a `LOG` macro for all operations
 * 7. Provides: `addBond()`, `totalValue()`, `printBook()`, `findBond(const char* name)`
 *
 * After the working C++98 implementation, add a **Pattern Audit** comment block listing
 * every legacy pattern used and its modern C++11/17 replacement.
 *
 * **Expected output:**
 * ```
 * === Legacy Fixed Income Book ===
 * [book.cpp:NN] Bond "UST 2Y" constructed (global count: 1)
 * [book.cpp:NN] Bond "UST 5Y" constructed (global count: 2)
 * [book.cpp:NN] Bond "UST 10Y" constructed (global count: 3)
 * [book.cpp:NN] addBond("UST 2Y"):  price=$99.50,  yield=0.0250
 * [book.cpp:NN] addBond("UST 5Y"):  price=$98.00,  yield=0.0310
 * [book.cpp:NN] addBond("UST 10Y"): price=$95.00,  yield=0.0385
 *
 * Fixed Income Book (3 bonds):
 *   UST 2Y    price=$99.50   yield=2.50%
 *   UST 5Y    price=$98.00   yield=3.10%
 *   UST 10Y   price=$95.00   yield=3.85%
 * Total value (100 units each): $29250.00
 *
 * findBond("UST 5Y"): found — price=$98.00
 * findBond("UST 30Y"): not found (NULL)
 *
 * [book.cpp:NN] ~FixedIncomeBook(): freeing 3 bonds
 *
 * === Pattern Audit ===
 * DynArray<Bond*>           -> std::vector<std::unique_ptr<Bond>>
 * Instrument* virtual base  -> same, but add override/final
 * typedef Price/Yield       -> using Price = double
 * global g_bondCount        -> std::atomic<int> or remove entirely
 * Rule of Three (DynArray)  -> Rule of Zero (vector member)
 * LOG macro                 -> inline template log function
 * Raw Bond* ownership       -> unique_ptr<Bond>
 * NULL                      -> nullptr
 * ```
 */

int main() {}
