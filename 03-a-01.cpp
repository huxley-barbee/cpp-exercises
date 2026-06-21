/*
 * ## EXERCISE 1: Move Semantics - Basics [3.a.i]
 *
 * Write a program demonstrating move semantics and the difference from copy semantics.
 *
 * **Requirements:**
 * 1. Create a class with dynamically allocated resource
 * 2. Implement copy constructor (deep copy)
 * 3. Implement move constructor (transfer ownership)
 * 4. Show performance difference between copy and move
 * 5. Demonstrate std::move()
 * 6. Show that moved-from object is in valid but unspecified state
 *
 * **Expected output format:**
 * ```
 * === Copy Semantics ===
 * Creating Buffer with 1000000 elements
 * Copy constructor called (deep copy)
 *   Allocating new memory
 *   Copying 1000000 elements
 * Time for copy: 15ms
 *
 * === Move Semantics ===
 * Creating Buffer with 1000000 elements
 * Move constructor called (transfer ownership)
 *   Taking ownership of memory
 *   Original pointer nullified
 * Time for move: 0ms
 *
 * Move is ~infinite times faster (no allocation/copy)
 *
 * After move:
 *   Source buffer size: 0 (moved-from state)
 *   Destination buffer size: 1000000
 *
 * Move semantics enable efficient resource transfer!
 * ```
 */

int main() {}
