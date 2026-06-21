/*
 * ## EXERCISE 5: Homegrown Containers — Hash Map [4.b.ii]
 *
 * Before `std::unordered_map` (C++11), quant codebases often contained hand-rolled hash maps.
 *
 * **Requirements:**
 * 1. Implement a C++98 `HashMap<K, V>` using separate chaining (array of linked lists)
 * 2. Provide `insert(key, value)`, `find(key)` returning `V*` (NULL if absent), `remove(key)`
 * 3. Use a `hash(const K&)` function — provide specialisations for `int` and `const char*`
 * 4. Handle collisions: print bucket distribution after inserting 20 entries
 * 5. Demonstrate `find` returning NULL for missing keys vs a valid pointer for present keys
 * 6. Show that copying the map requires deep copy of all chains
 * 7. Note `std::unordered_map<K,V>` as the replacement
 *
 * **Expected output:**
 * ```
 * === Legacy HashMap ===
 * Inserted 20 entries
 *
 * Bucket distribution (16 buckets):
 * Bucket  0: 2 entries
 * Bucket  1: 1 entry
 * Bucket  2: 0 entries
 * ...
 * Bucket 15: 1 entry
 * Max chain length: 3
 * Load factor: 1.25
 *
 * find("AAPL"):  $150.00 (found)
 * find("TSLA"):  NULL    (not found)
 *
 * remove("AAPL"): OK
 * find("AAPL"):  NULL    (correctly absent)
 *
 * === Deep Copy ===
 * map2 = map1  (copy)
 * Modify map1["MSFT"] — map2["MSFT"] unchanged
 *
 * Modern: std::unordered_map<std::string, double>
 * ```
 */

int main() {}
