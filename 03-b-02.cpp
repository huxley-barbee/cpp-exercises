/*
 * ## EXERCISE 2: Avoiding raw new/delete — Containers [3.b.i]
 *
 * Write a program showing how STL containers eliminate the need for manual memory management.
 *
 * **Requirements:**
 * 1. Show manual dynamic array management with `new[]`/`delete[]`
 * 2. Replace with `std::vector`
 * 3. Show manual linked list vs `std::list`
 * 4. Demonstrate `std::array` for fixed-size arrays
 * 5. Show exception safety with containers
 * 6. Summarise the trade-offs
 *
 * **Expected output:**
 * ```
 * === Manual Array Management (BAD) ===
 * Allocated int[100]
 * Filled array
 * (Must remember to call delete[] — easy to forget!)
 * Freed int[100]
 *
 * Problems:
 * - Manual size tracking
 * - No bounds checking
 * - Easy to forget delete[]
 * - Exception unsafe
 *
 * === std::vector (GOOD) ===
 * Created vector<int> with 100 elements
 * Filled vector
 * Scope ended — automatic cleanup
 *
 * Benefits:
 * - Automatic size tracking via size()
 * - Bounds-checked access via at()
 * - Automatic RAII cleanup
 * - Exception safe
 * - Dynamically resizable
 *
 * === Fixed-Size Array ===
 * Manual:     int* arr = new int[5]; ... delete[] arr;
 * Better:     std::array<int, 5> arr = {};
 *
 * std::array advantages:
 * - Stack allocated (faster)
 * - Compile-time size
 * - Zero overhead
 * - STL algorithm compatible
 *
 * === Exception Safety with Containers ===
 * vector<int> allocated
 * Exception thrown inside scope
 * NO LEAK — vector cleaned up automatically
 *
 * Always prefer containers over raw arrays!
 * ```
 */

int main() {}
