/*
 * ## EXERCISE 5: `auto_ptr` — Understanding a Broken Smart Pointer [4.a.iii]
 *
 * Write a program demonstrating `std::auto_ptr` (C++98) and why it was deprecated and removed.
 *
 * > **Note:** `auto_ptr` was removed in C++17. Compile this exercise with `-std=c++14` or use
 * > a wrapper struct that mimics its broken transfer-on-copy semantics for modern compilers.
 *
 * **Requirements:**
 * 1. Show `auto_ptr`'s "move on copy" behaviour: after `auto_ptr<T> b = a`, `a` is null
 * 2. Show that storing `auto_ptr` in a `std::vector` is broken (silently nullifies elements)
 * 3. Show `auto_ptr` in a function parameter — ownership is unexpectedly transferred
 * 4. Demonstrate `auto_ptr::release()` and `reset()`
 * 5. For each broken behaviour, note the `unique_ptr` fix
 *
 * **Expected output:**
 * ```
 * === auto_ptr Transfer-on-Copy ===
 * a holds: 42
 * b = a  (copy — but auto_ptr MOVES ownership!)
 * a holds: NULL (stolen!)
 * b holds: 42
 *
 * Modern fix: unique_ptr — copy is deleted, must use std::move
 *
 * === auto_ptr in vector (BROKEN) ===
 * Pushed 3 auto_ptrs into vector
 * Copying vector...
 * Original vector elements after copy:
 *   [0]: NULL  (ownership stolen by copy!)
 *   [1]: NULL
 *   [2]: NULL
 *
 * Modern fix: vector<unique_ptr<T>> — won't compile on accidental copy
 *
 * === auto_ptr as Function Parameter ===
 * Before call: ptr holds 99
 * void process(auto_ptr<int> p) — ownership transferred in!
 * After call: ptr holds NULL (silently stolen)
 *
 * Modern fix: pass unique_ptr by reference, or std::move explicitly
 *
 * === release() and reset() ===
 * auto_ptr holds: 7
 * raw = ap.release() — ap now NULL, raw owns memory
 * raw value: 7
 * delete raw; // must manually delete released pointer
 *
 * ap.reset(new int(55)) — ap now holds 55
 * ap out of scope — auto-deleted
 * ```
 */

int main() {}
