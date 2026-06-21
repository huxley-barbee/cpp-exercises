/*
 * ## EXERCISE 8: Rule of Five [3.b.iii]
 *
 * Write a program demonstrating the Rule of Five, extending Rule of Three with move semantics.
 *
 * **Requirements:**
 * 1. Start from the Rule-of-Three `Buffer` class
 * 2. Add a move constructor
 * 3. Add a move assignment operator
 * 4. Show that moving is cheaper than copying (no heap allocation)
 * 5. Demonstrate `std::move` usage
 * 6. Show the moved-from state is valid but unspecified
 *
 * **Expected output:**
 * ```
 * === Rule of Five Demo ===
 *
 * Buffer b1("hello world");  // Constructor
 * Buffer b2 = b1;            // Copy constructor — deep copy
 *
 * b1: "hello world"
 * b2: "hello world" (independent)
 *
 * Buffer b3 = std::move(b1); // Move constructor — no allocation
 *
 * b1: "" (moved-from, valid but empty)
 * b3: "hello world" (took b1's resource)
 *
 * b3 = std::move(b2);        // Move assignment
 *
 * b2: "" (moved-from)
 * b3: "hello world"
 *
 * === Performance (1 000 000 operations) ===
 * Copy Buffer: ~180ms  (heap allocation + memcpy each time)
 * Move Buffer: ~15ms   (pointer swap only)
 * Speedup:     ~12x
 *
 * Rule of Five = Rule of Three + move constructor + move assignment.
 * If you write any special member, define all five.
 * ```
 */

int main() {}
