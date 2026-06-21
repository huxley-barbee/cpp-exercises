/*
 * ## EXERCISE 1: gdb/LLDB — Basic Session [7.b.i]
 *
 * Walk through a complete interactive debugging session on a crashing pricer.
 *
 * **Requirements:**
 *
 * Write a program `crash_pricer.cpp` that crashes in a non-obvious way:
 * ```cpp
 * struct Bond { double par; double* coupons; int nCoupons; };
 * double sumCoupons(const Bond* b) {
 *     double sum = 0.0;
 *     for (int i = 0; i <= b->nCoupons; ++i)  // off-by-one: reads one past end
 *         sum += b->coupons[i];
 *     return sum;
 * }
 * int main() {
 *     Bond b{1000.0, new double[3]{50.0, 50.0, 50.0}, 3};
 *     double total = sumCoupons(&b);   // crashes or gives wrong answer
 *     printf("Sum: %.2f\n", total);
 *     delete[] b.coupons;
 * }
 * ```
 *
 * 1. Compile with debug symbols: `g++ -g -O0 crash_pricer.cpp -o crash_pricer`
 * 2. Document the full gdb session showing:
 *    - `run` — observe the crash
 *    - `bt` (backtrace) — find which frame crashed
 *    - `frame N` — switch to the relevant frame
 *    - `list` — show source context
 *    - `print b->nCoupons`, `print b->coupons[3]` — inspect the bad access
 *    - `watch b->nCoupons` — set a watchpoint
 *    - `break sumCoupons` — set a breakpoint
 *    - `next`, `step`, `continue` — stepping controls
 * 3. Show the same session in LLDB (command equivalents)
 * 4. Fix the bug and verify the fix under gdb
 * 5. Show `info locals`, `info args`, `x/4xg` (examine memory) commands
 *
 * **Expected output:**
 * ```
 * === gdb session ===
 *
 * (gdb) run
 * Program received signal SIGSEGV, Segmentation fault.
 * 0x0000... in sumCoupons (b=0x...) at crash_pricer.cpp:5
 * 5           sum += b->coupons[i];
 *
 * (gdb) bt
 * #0  sumCoupons (b=0x7ffd...) at crash_pricer.cpp:5
 * #1  main () at crash_pricer.cpp:11
 *
 * (gdb) frame 0
 * (gdb) print i
 * $1 = 3
 * (gdb) print b->nCoupons
 * $2 = 3
 * (gdb) print b->coupons[3]
 * $3 = <optimized out / garbage value>
 *
 * Bug: loop condition i <= nCoupons should be i < nCoupons
 *
 * === LLDB equivalents ===
 * (lldb) run
 * (lldb) bt           (same as gdb)
 * (lldb) frame select 0
 * (lldb) p i          (print variable)
 * (lldb) memory read  (examine memory)
 * ```
 */

int main() {}
