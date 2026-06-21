/*
 * ## EXERCISE 2: Move Semantics - Rule of Five [3.a.i]
 *
 * Write a program demonstrating the Rule of Five.
 *
 * **Requirements:**
 * 1. Create a class that manages a resource
 * 2. Implement all five special member functions:
 *    - Destructor
 *    - Copy constructor
 *    - Copy assignment operator
 *    - Move constructor
 *    - Move assignment operator
 * 3. Show when each is called
 * 4. Demonstrate that move operations leave source in valid state
 * 5. Show self-assignment handling
 *
 * **Expected output format:**
 * ```
 * === Rule of Five Demo ===
 *
 * Creating Resource A
 * Constructor called
 *
 * Creating Resource B (copy from A)
 * Copy constructor called
 *
 * Creating Resource C (move from B)
 * Move constructor called
 * Source left in valid state
 *
 * D = A (copy assignment)
 * Copy assignment operator called
 *
 * E = std::move(C) (move assignment)
 * Move assignment operator called
 * Source left in valid state
 *
 * Self-assignment: A = A
 * Copy assignment: detected self-assignment, skipping
 *
 * Destroying resources:
 * Destructor called for E
 * Destructor called for D
 * Destructor called for C (moved-from, empty)
 * Destructor called for B (moved-from, empty)
 * Destructor called for A
 *
 * All five special members used correctly!
 * ```
 */

int main() {}
