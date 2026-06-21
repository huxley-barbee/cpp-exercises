/*
 * ## EXERCISE 7: Rule of Three [3.b.iii]
 *
 * Write a program demonstrating the Rule of Three for classes that manage raw resources.
 *
 * **Requirements:**
 * 1. Create a `Buffer` class that holds a raw `char*` (simulating legacy resource ownership)
 * 2. Show the problem with the compiler-generated copy (shallow copy / double-free)
 * 3. Implement the three special members: destructor, copy constructor, copy assignment operator
 * 4. Verify deep copy behaviour
 * 5. Explain when Rule of Three is necessary (legacy code, custom allocators)
 *
 * **Expected output:**
 * ```
 * === Without Rule of Three (BUG) ===
 *
 * Buffer b1("hello");
 * Buffer b2 = b1;   // Compiler-generated — shallow copy!
 *
 * b1 and b2 point to same memory
 * Modifying b2 corrupts b1: "HELLO"
 * Destructor for b2 frees memory
 * Destructor for b1 — DOUBLE FREE! Undefined behaviour!
 *
 * === With Rule of Three (CORRECT) ===
 *
 * Buffer b1("hello");     // Constructor
 * Buffer b2 = b1;         // Copy constructor (deep copy)
 * b2 = b1;                // Copy assignment (deep copy)
 *
 * b1 data: "hello"
 * b2 data: "hello" (independent copy)
 *
 * Modifying b2:
 * b1 data: "hello" (unchanged)
 * b2 data: "HELLO"
 *
 * Destructor b2: freed own memory
 * Destructor b1: freed own memory — no double free!
 *
 * Rule of Three: if you need a destructor, also write
 * copy constructor and copy assignment operator.
 * ```
 */

int main() {}
