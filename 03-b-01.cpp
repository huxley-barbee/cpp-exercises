/*
 * ## EXERCISE 1: Avoiding raw new/delete — Smart Pointers [3.b.i]
 *
 * Write a program demonstrating why you should avoid raw `new`/`delete`.
 *
 * **Requirements:**
 * 1. Show problems with raw `new`/`delete`: memory leaks and exceptions
 * 2. Replace with `std::unique_ptr`
 * 3. Replace with `std::shared_ptr` where appropriate
 * 4. Use `make_unique` and `make_shared`
 * 5. Demonstrate exception safety with smart pointers
 * 6. Compare resource management between raw and smart pointers
 *
 * **Expected output:**
 * ```
 * === Problems with raw new/delete ===
 *
 * Scenario 1: Memory leak from exception
 * Allocated raw int (42)
 * Exception thrown before delete — LEAKED 4 bytes
 *
 * Scenario 2: Forgot to delete
 * Allocated raw int (100)
 * (Memory never freed — LEAKED 4 bytes)
 *
 * === Solution: Smart Pointers ===
 *
 * Scenario 1 with unique_ptr:
 * Allocated unique_ptr<int> (42)
 * Exception thrown — NO LEAK (unique_ptr cleaned up automatically)
 *
 * Scenario 2 with unique_ptr:
 * Allocated unique_ptr<int> (100)
 * Scope ended — NO LEAK (RAII guarantees cleanup)
 *
 * === Overhead Comparison ===
 * Raw pointer overhead: 0 bytes
 * unique_ptr overhead:  0 bytes (zero-cost abstraction!)
 * shared_ptr overhead:  ~16 bytes (reference count block)
 *
 * Smart pointers provide safety with zero cost (unique_ptr)!
 * ```
 */

int main() {}
