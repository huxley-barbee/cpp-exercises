/*
 * ## EXERCISE 4: Valgrind — Detecting Memory Errors [7.b.ii]
 *
 * Valgrind's Memcheck tool catches use-after-free, reads of uninitialised memory,
 * heap overwrites, and memory leaks.
 *
 * **Requirements:**
 *
 * Write `memcheck_demo.cpp` with five distinct memory errors:
 * 1. **Heap buffer overflow**: write one past the end of a `new int[5]`
 * 2. **Use-after-free**: read from a pointer after `delete[]`
 * 3. **Uninitialised read**: use a value before it is assigned
 * 4. **Memory leak**: allocate with `new`, never `delete`
 * 5. **Invalid free**: call `delete` on a stack variable
 *
 * For each error:
 * - Show the Valgrind output identifying the error
 * - Explain what the error means
 * - Show the fix
 * - Show that Valgrind is clean after the fix
 *
 * Run with: `valgrind --leak-check=full --track-origins=yes ./memcheck_demo`
 *
 * **Expected output:**
 * ```
 * === Valgrind: heap buffer overflow ===
 * ==PID== Invalid write of size 4
 * ==PID==    at 0x...: main (memcheck_demo.cpp:8)
 * ==PID==  Address 0x... is 0 bytes after a block of size 20 alloc'd
 *
 * === Valgrind: use-after-free ===
 * ==PID== Invalid read of size 8
 * ==PID==    at 0x...: main (memcheck_demo.cpp:15)
 * ==PID==  Address 0x... is 24 bytes inside a block of size 40 free'd
 *
 * === Valgrind: uninitialised read ===
 * ==PID== Conditional jump or move depends on uninitialised value(s)
 *
 * === Valgrind: memory leak ===
 * ==PID== LEAK SUMMARY:
 * ==PID==    definitely lost: 40 bytes in 1 blocks
 *
 * === After all fixes ===
 * ==PID== ERROR SUMMARY: 0 errors from 0 contexts
 * ==PID== All heap blocks were freed -- no leaks are possible
 * ```
 */

int main() {}
