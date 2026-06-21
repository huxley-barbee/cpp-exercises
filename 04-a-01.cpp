/*
 * ## EXERCISE 1: Raw Pointers — Ownership and Lifetime [4.a.i]
 *
 * Write a program that demonstrates the core ownership problems raw pointers introduce.
 *
 * **Requirements:**
 * 1. Allocate an `int` and a `double` on the heap using raw `new`
 * 2. Demonstrate passing ownership between functions with a raw pointer (caller allocates, callee deletes)
 * 3. Show a dangling pointer: delete an object, then attempt to read through the old pointer
 * 4. Show a double-delete scenario (comment out the crash line, explain what would happen)
 * 5. Show a null-pointer dereference guard using an `if` check (C++98 style — no `nullptr`)
 * 6. For each problem, note the modern C++11 fix in a comment
 *
 * **Expected output:**
 * ```
 * === Raw Pointer Ownership ===
 * Allocated int at: 0x[addr], value: 42
 * Ownership transferred to consumePointer()
 * consumePointer() deleting memory...
 *
 * === Dangling Pointer ===
 * ptr before delete: 0x[addr], value: 100
 * Memory deleted.
 * ptr still holds old address: 0x[addr]
 * Reading dangling pointer — undefined behaviour! (commented out)
 * Modern fix: set ptr = NULL after delete
 *
 * === Double Delete ===
 * First delete: OK
 * Second delete: UNDEFINED BEHAVIOUR (commented out)
 * Modern fix: ptr = NULL; // delete NULL is a no-op
 *
 * === Null Pointer Guard (C++98) ===
 * if (ptr != NULL) — pointer is null, safe!
 * Modern fix: if (ptr != nullptr)
 * ```
 */

int main() {}
