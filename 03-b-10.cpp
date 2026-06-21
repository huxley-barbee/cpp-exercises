/*
 * ## EXERCISE 10: RAII and Exception Safety [3.b.i / 3.b.ii]
 *
 * Write a program demonstrating RAII as the mechanism behind exception-safe resource management.
 *
 * **Requirements:**
 * 1. Create a `ScopedLock` RAII wrapper around a simulated mutex
 * 2. Create a `FileHandle` RAII wrapper
 * 3. Show that both are released in LIFO order even when an exception is thrown
 * 4. Demonstrate the three exception-safety levels: no-throw, strong, basic
 * 5. Show a `finally`-style scope guard using a lambda and RAII
 *
 * **Expected output:**
 * ```
 * === RAII Exception Safety ===
 *
 * Acquiring FileHandle: report.txt
 * Acquiring ScopedLock: mutex_1
 *
 * Inside critical section...
 * Exception thrown!
 *
 * ScopedLock released: mutex_1   (LIFO order)
 * FileHandle closed: report.txt  (LIFO order)
 *
 * Resources released correctly despite exception!
 *
 * === Exception Safety Levels ===
 *
 * 1. No-throw guarantee (noexcept)
 *    Example: swap(), move operations
 *    Promise: never throws
 *
 * 2. Strong guarantee (commit-or-rollback)
 *    Example: vector::push_back
 *    Promise: succeeds completely or leaves state unchanged
 *
 * 3. Basic guarantee
 *    Example: most container operations
 *    Promise: no resource leaks; object remains valid
 *
 * === Scope Guard (finally pattern) ===
 *
 * {
 *     auto guard = finally([]{ std::cout << "Cleanup!\n"; });
 *     throw std::runtime_error("oops");
 * }
 * Output: Cleanup!   (always runs)
 *
 * RAII provides exception safety with zero runtime overhead!
 * ```
 */

int main() {}
