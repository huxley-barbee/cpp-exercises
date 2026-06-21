/*
 * ## EXERCISE 4: Homegrown Containers — Dynamic Array [4.b.ii]
 *
 * Legacy quant code often contains hand-rolled dynamic arrays written before `std::vector` was
 * trusted for performance-critical code.
 *
 * **Requirements:**
 * 1. Write a C++98 `DynArray<T>` class template with:
 *    - Raw `T*` buffer, `int size_`, `int capacity_`
 *    - `push_back(const T&)` — doubles capacity when full
 *    - `operator[]` (checked and unchecked versions)
 *    - `size()`, `capacity()`, `clear()`
 *    - Destructor, copy constructor, copy assignment (Rule of Three)
 * 2. Test with `int` and with a struct `Trade { int id; double notional; }`
 * 3. Show that capacity doubles: print size and capacity after each push
 * 4. Demonstrate the iterator-invalidation problem: take a pointer into the array, trigger
 *    reallocation, show the pointer is now dangling
 * 5. Note the `std::vector<T>` equivalent for each operation
 *
 * **Expected output:**
 * ```
 * === DynArray<int> ===
 * push_back(10): size=1, capacity=1
 * push_back(20): size=2, capacity=2
 * push_back(30): size=3, capacity=4  (grew!)
 * push_back(40): size=4, capacity=4
 * push_back(50): size=5, capacity=8  (grew!)
 *
 * Elements: 10 20 30 40 50
 *
 * === Iterator Invalidation ===
 * int* ptr = &arr[0];  // points into buffer
 * Before realloc: *ptr = 10
 * arr.push_back(60)... reallocation triggered!
 * After realloc: *ptr = ??? (DANGLING — undefined behaviour)
 *
 * Modern: std::vector — same invalidation rules, but clearly documented
 *
 * === DynArray<Trade> ===
 * Trade{1, 100000.0}, Trade{2, 250000.0}, Trade{3, 75000.0}
 * Total notional: $425000.00
 *
 * === Deep Copy ===
 * arr2 = arr1  (copy)
 * Modify arr1[0]: arr2[0] unchanged (independent)
 * ```
 */

int main() {}
