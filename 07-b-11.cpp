/*
 * ## EXERCISE 11: Core Dumps — Debugging Production Crashes [7.b.iv]
 *
 * Production environments often have stripped binaries. You need debug symbols
 * in a separate file and the right gdb setup to use them.
 *
 * **Requirements:**
 *
 * 1. Compile a release binary with separate debug symbols:
 *    ```bash
 *    g++ -O2 -g pricer.cpp -o pricer
 *    objcopy --only-keep-debug pricer pricer.dbg
 *    strip pricer
 *    objcopy --add-gnu-debuglink=pricer.dbg pricer
 *    ```
 * 2. Show that `gdb pricer core` still loads symbols from `pricer.dbg`
 * 3. Simulate a production crash: the stripped binary crashes, you load the core
 *    with the debug symbol file
 * 4. Show `gdb -ex "set debug-file-directory /usr/lib/debug"` for system library symbols
 * 5. Demonstrate `coredumpctl` (systemd) to list and extract core dumps:
 *    `coredumpctl list`, `coredumpctl gdb`
 * 6. Show how to add metadata to a crash report: `gdb` Python scripts to extract
 *    custom fields from the core
 * 7. Discuss the build-id mechanism: each binary has a unique build-id embedded;
 *    debug servers (like debuginfod) serve symbols by build-id
 *
 * **Expected output:**
 * ```
 * === Separate debug symbols ===
 * $ ls -lh pricer pricer.dbg
 * -rwxr-xr-x pricer       42K  (stripped — no debug info)
 * -rw-r--r-- pricer.dbg  245K  (debug symbols only)
 *
 * $ gdb pricer core
 * Reading symbols from pricer...
 * Reading symbols from pricer.dbg...done.
 * (gdb) bt
 * #0 computeGreeks (b=0x0...) at pricer.cpp:15  <- symbols loaded!
 *
 * === coredumpctl ===
 * $ coredumpctl list
 * TIME                 PID  UID  SIG COREFILE EXE
 * Mon 2024-01-15 03:14 4521 1000   11 present /path/pricer
 *
 * $ coredumpctl gdb 4521
 * (gdb) bt
 * [full backtrace from production crash]
 * ```
 */

int main() {}
