/*
 * ## EXERCISE 10: Core Dumps — Generating and Analysing [7.b.iv]
 *
 * A core dump is a snapshot of a process's memory at the moment it crashed.
 * It is the primary tool for post-mortem debugging of production crashes.
 *
 * **Requirements:**
 *
 * 1. Enable core dumps: `ulimit -c unlimited` and configure `core_pattern`
 * 2. Write `crash_in_production.cpp` — a program that crashes with an interesting
 *    call stack:
 *    ```cpp
 *    double computeGreeks(const Bond* b, double h);
 *    double pricePortfolio(const Bond* bonds, int n);
 *    int main() { pricePortfolio(nullptr, 10); }  // null pointer crash
 *    ```
 * 3. Run the program — it produces a core file
 * 4. Load the core in gdb: `gdb ./crash_in_production core`
 * 5. Show the post-mortem session:
 *    - `bt` — full backtrace from the core
 *    - `frame N` — inspect each frame
 *    - `print` variables from the core
 *    - `info registers` — CPU register state at crash
 * 6. Show how to load a core from a different machine (matching binary needed)
 * 7. Show `eu-stack` (elfutils) as a lightweight alternative to gdb for backtraces
 *
 * **Expected output:**
 * ```
 * === Core dump generated ===
 * $ ulimit -c unlimited
 * $ ./crash_in_production
 * Segmentation fault (core dumped)
 * $ ls -lh core
 * -rw------- 1 user group 512K core
 *
 * === Post-mortem gdb session ===
 * $ gdb ./crash_in_production core
 * (gdb) bt
 * #0  computeGreeks (b=0x0, h=0.01) at crash_in_production.cpp:3
 * #1  pricePortfolio (bonds=0x0, n=10) at crash_in_production.cpp:8
 * #2  main () at crash_in_production.cpp:11
 *
 * (gdb) frame 1
 * (gdb) print bonds
 * $1 = (Bond *) 0x0   <- null pointer!
 *
 * (gdb) info registers
 * rip    0x... <computeGreeks+N>
 * rsp    0x7fff...
 * ```
 */

int main() {}
