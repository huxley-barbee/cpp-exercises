/*
 * ## EXERCISE 4: Syscalls — What Happens Under the Hood [5.a.ii]
 *
 * Every `printf`, `malloc`, `fopen`, and `new` eventually calls a syscall. Write a program
 * that makes syscalls directly using the Linux syscall interface, then observe the same
 * syscalls through a higher-level wrapper.
 *
 * **Requirements:**
 * 1. Use `syscall(SYS_write, STDOUT_FILENO, buf, len)` to write directly to stdout
 * 2. Use `syscall(SYS_getpid)` and compare with `getpid()`
 * 3. Use `syscall(SYS_gettimeofday, ...)` and compare with `clock_gettime`
 * 4. Trace syscalls made by a simple `printf("hello\n")` using `strace` — document the output
 *    in a comment (actual `strace` output from a test run)
 * 5. Show the cost difference: a raw syscall vs an inlined `gettimeofday` that uses the
 *    vDSO (virtual dynamic shared object — no kernel entry)
 * 6. Demonstrate `open`/`read`/`write`/`close` syscalls directly on a file
 * 7. Explain the user-space / kernel-space boundary and the cost (~100–300ns per syscall)
 *
 * **Expected output:**
 * ```
 * === Direct Syscall: write ===
 * syscall(SYS_write): Hello from a raw syscall!
 *
 * === PID via syscall vs getpid() ===
 * syscall(SYS_getpid): 12345
 * getpid():            12345  (same)
 *
 * === Time via syscall vs vDSO ===
 * syscall(SYS_gettimeofday): 1700000000.123456
 * clock_gettime(CLOCK_REALTIME): 1700000000.123456
 *
 * Timing 1M calls:
 *   Raw syscall gettimeofday:  450ms  (~450ns each — full kernel entry)
 *   vDSO clock_gettime:         12ms  (~12ns each  — no kernel entry!)
 *   Speedup: ~37x (vDSO maps kernel time into user space)
 *
 * === File I/O via raw syscalls ===
 * open("test.txt", O_WRONLY|O_CREAT): fd=3
 * write(fd, "hello syscall\n", 14): 14 bytes written
 * close(fd): OK
 * open("test.txt", O_RDONLY): fd=3
 * read(fd, buf, 64): "hello syscall\n"
 * close(fd): OK
 *
 * === Syscall cost ===
 * User-to-kernel transition: ~100-300ns
 * Avoid in hot paths — batch I/O, use vDSO for time
 * ```
 */

int main() {}
