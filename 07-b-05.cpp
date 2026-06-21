/*
 * ## EXERCISE 5: ASAN — AddressSanitizer in Depth [7.b.ii]
 *
 * ASan catches memory errors at runtime with much less overhead than Valgrind (~2×
 * slowdown vs ~20×) and is the preferred tool during development.
 *
 * **Requirements:**
 *
 * Write `asan_demo.cpp` targeting each ASan detector:
 * 1. **Stack buffer overflow**: `char buf[8]; buf[8] = 'x';`
 * 2. **Global buffer overflow**: write past a global array
 * 3. **Heap use-after-free**: shown with a `unique_ptr` that is explicitly released
 * 4. **Stack use-after-return**: return a pointer to a local variable and use it
 * 5. **Container overflow**: access `std::vector` beyond `size()` but within `capacity()`
 *    (requires `-fsanitize=address` + `-D_GLIBCXX_SANITIZE_VECTOR`)
 *
 * Compile: `g++ -fsanitize=address -fno-omit-frame-pointer -g asan_demo.cpp`
 *
 * For each error show:
 * - The ASan error report with the shadow bytes diagram
 * - The fix
 * - The clean ASan run
 *
 * **Expected output:**
 * ```
 * === ASan: stack buffer overflow ===
 * =================================================================
 * ==PID==ERROR: AddressSanitizer: stack-buffer-overflow
 * WRITE of size 1 at 0x... thread T0
 *     #0 0x... in main asan_demo.cpp:5
 * Shadow bytes around the buggy address:
 *   ...
 *   [f2] — redzone (stack overflow detected here)
 *
 * === ASan: heap-use-after-free ===
 * ==PID==ERROR: AddressSanitizer: heap-use-after-free
 * READ of size 4 at 0x...
 *     #0 0x... in main asan_demo.cpp:22
 * 0x... is located 0 bytes inside of 16-byte region [freed]
 *
 * === Clean run ===
 * (no ASan output — program exits 0)
 * ```
 */

int main() {}
