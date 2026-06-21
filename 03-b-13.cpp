/*
 * ## EXERCISE 13: Comprehensive Integration [All of 3.b]
 *
 * Implement a modern `DynamicArray<T>` class that applies every best practice from section 3.b.
 *
 * **Requirements:**
 * 1. Use `std::unique_ptr<T[]>` internally — no raw `new`/`delete`
 * 2. Apply Rule of Zero where possible; explicitly delete copy, default move
 * 3. Provide `emplace_back` with perfect forwarding
 * 4. Provide zero-cost `begin()`/`end()` iterators (raw pointers are fine)
 * 5. Provide a static factory function
 * 6. Ensure strong exception safety for `emplace_back`
 * 7. Write a brief benchmark comparing it with `std::vector`
 *
 * **Expected output:**
 * ```
 * === DynamicArray<int> ===
 *
 * Created via factory: DynamicArray::create(8)
 * emplace_back(1) ... emplace_back(5)
 * Elements: [1, 2, 3, 4, 5]
 * Size: 5 / Capacity: 8
 *
 * === Growth (strong exception safety) ===
 * emplace_back triggers reallocation:
 *   New capacity: 16
 *   All elements copied/moved safely
 *   Old buffer freed via unique_ptr
 *
 * === Move Semantics ===
 * DynamicArray moved — no allocation
 * Original: empty (valid moved-from state)
 * New owner: [1, 2, 3, 4, 5]
 *
 * Copy: explicitly deleted (ownership is unique)
 *
 * === Zero-Cost Iteration ===
 * Range-based for: 1 2 3 4 5
 * (begin/end return raw pointers — no overhead)
 *
 * === Perfect Forwarding emplace_back ===
 * emplace_back("hello", 42):
 *   Constructs Widget in-place — 0 extra copies
 *
 * === Benchmark (1 000 000 push/emplace) ===
 * std::vector:    ~15ms
 * DynamicArray:   ~16ms  (within noise — equivalent)
 *
 * === Design Checklist ===
 * ✓ No raw new/delete
 * ✓ Rule of Zero (move) / explicit delete (copy)
 * ✓ Zero-cost iterators
 * ✓ Perfect forwarding in emplace_back
 * ✓ Strong exception safety
 * ✓ Modern factory function
 * ✓ Move semantics tested
 *
 * Modern best practices: safety and performance together!
 * ```
 */

int main() {}
