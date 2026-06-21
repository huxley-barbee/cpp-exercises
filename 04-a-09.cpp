/*
 * ## EXERCISE 9: Pre-C++11 STL Quirks — Containers and `typedef` [4.a.v]
 *
 * Write a program showing legacy container usage patterns.
 *
 * **Requirements:**
 * 1. Use `typedef` to alias container types (no `using`)
 * 2. Demonstrate the `>>` spacing bug: `vector<vector<int> >` (space required pre-C++11)
 * 3. Use `.push_back()` without move semantics — show copy overhead via a counter
 * 4. Show `std::map` iteration with a `std::pair<const Key, Value>` written out explicitly
 * 5. Show `std::string` without `string_view` — demonstrate unnecessary copies
 * 6. Use `std::auto_ptr` in a container (show it's broken) vs `boost::scoped_ptr` (mention)
 *
 * **Expected output:**
 * ```
 * === typedef Aliases ===
 * typedef std::vector<int> IntVec;
 * typedef std::map<std::string, int> StrIntMap;
 * Modern: using IntVec = std::vector<int>;
 *
 * === >> Spacing Bug ===
 * Pre-C++11: vector<vector<int> >  (space required!)
 * C++11+:    vector<vector<int>>   (fine)
 *
 * === push_back Copy Overhead ===
 * Pushing MyObject into vector (no move semantics):
 * Copy #1 called
 * Copy #2 called  (reallocation triggered)
 * Copy #3 called  (reallocation triggered)
 * Total copies: 3
 *
 * Modern: push_back uses move if available — 0 copies for moveable types
 *
 * === map Iteration (pre-C++11) ===
 * for (std::map<std::string,int>::iterator it = m.begin(); it != m.end(); ++it) {
 *     std::pair<const std::string, int>& entry = *it;
 *     ...
 * }
 * alice: 1
 * bob: 2
 * charlie: 3
 *
 * Modern: for (auto& [key, val] : m) { ... }
 *
 * === String Copy Overhead ===
 * C++98: pass by const string& (ok) or by value (copies!)
 * C++17: pass by string_view — zero copy, zero allocation
 * ```
 */

int main() {}
