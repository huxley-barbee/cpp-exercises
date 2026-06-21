/*
 * ## EXERCISE 4: Manual Memory Management — Resource Leak Patterns [4.a.ii]
 *
 * Write a program cataloguing the four classic C++98 memory leak patterns and their symptoms.
 *
 * **Requirements:**
 * 1. **Leak pattern A** — allocation in a loop without deletion inside the loop body
 * 2. **Leak pattern B** — early `return` before `delete`
 * 3. **Leak pattern C** — exception thrown after `new`, before `delete` (no RAII)
 * 4. **Leak pattern D** — array allocated with `new[]`, freed with `delete` (mismatch)
 * 5. For each pattern, print what the bug is and show the corrected version in a comment
 * 6. Add a `LeakTracker` struct with a global counter to simulate detecting leaks
 *
 * **Expected output:**
 * ```
 * === Leak Tracker ===
 * Starting allocation count: 0
 *
 * --- Pattern A: Loop Without Delete ---
 * Allocated 5 ints in loop
 * (Only last pointer kept — 4 leaks!)
 * Leaked: 4 allocation(s)
 * Fix: delete each in loop, or use vector<int>
 *
 * --- Pattern B: Early Return ---
 * Allocated buffer
 * Condition triggered — early return!
 * (delete never reached — LEAK)
 * Leaked: 1 allocation(s)
 * Fix: RAII / unique_ptr
 *
 * --- Pattern C: Exception Before Delete ---
 * Allocated resource
 * Exception thrown!
 * (delete never reached — LEAK)
 * Leaked: 1 allocation(s)
 * Fix: RAII / unique_ptr
 *
 * --- Pattern D: new[] / delete Mismatch ---
 * Allocated int[10] with new[]
 * Freed with delete (not delete[]) — UNDEFINED BEHAVIOUR
 * Fix: always match new[] with delete[]
 *
 * Total simulated leaks detected: 6
 * ```
 */

int main() {}
