/*
 * ## EXERCISE 2: Memory Layout — Stack Frames and Local Variable Addresses [5.a.i]
 *
 * Understanding stack frame layout is essential for debugging, profiling, and writing
 * low-latency code that is cache-friendly.
 *
 * **Requirements:**
 * 1. Write a function `void inspectFrame()` that declares several local variables
 *    (`int a`, `double b`, `char c[16]`, `int* p`) and prints each address
 * 2. Show that locals are laid out contiguously (or nearly so) within a frame
 * 3. Write a recursive function that prints its own stack frame address at each depth
 * 4. Show how large stack allocations (`char buf[1024 * 1024]`) can cause silent stack overflow
 * 5. Demonstrate `alloca` for stack allocation of dynamic size — and why it is dangerous
 * 6. Compare with heap allocation for large buffers
 * 7. Show the effect of compiler optimisations: with `-O0` locals are on the stack; with
 *    `-O2` they may be in registers (address-of forces them to memory)
 *
 * **Expected output:**
 * ```
 * === Stack Frame Layout ===
 * Local variable addresses (inspectFrame):
 *   &a:    0x7fff...a0  (int,    4 bytes)
 *   &b:    0x7fff...98  (double, 8 bytes)  <- 8 bytes below a (alignment)
 *   &c[0]: 0x7fff...88  (char[16])
 *   &p:    0x7fff...80  (int*)
 *
 * Locals are contiguous within the frame (modulo alignment padding)
 *
 * === Recursive Frame Tracking ===
 * depth=1: frame ptr 0x7fff...f0
 * depth=2: frame ptr 0x7fff...d0  (grew down by 32 bytes)
 * depth=3: frame ptr 0x7fff...b0
 * ...
 *
 * === Large Stack Allocation ===
 * char buf[1MB] on stack: risky!
 * Default stack size: ~8MB (ulimit -s)
 * Allocating 8 x 1MB: stack overflow at depth 8 (SIGSEGV)
 * Fix: use heap (new / vector) for large buffers
 *
 * === alloca (dangerous) ===
 * alloca(n): stack allocation, no destructor, no bounds check
 * Freed automatically at function return — but no safety net
 * Fix: use std::vector<char>(n) instead
 * ```
 */

int main() {}
