/*
 * ## EXERCISE 5: Syscalls — `mmap`, `munmap`, and Memory-Mapped Files [5.a.ii]
 *
 * Memory-mapped files are the foundation of shared-memory IPC between trading processes.
 *
 * **Requirements:**
 * 1. Create a file, write 4096 bytes to it using `write()`
 * 2. `mmap` the file with `PROT_READ | PROT_WRITE` and `MAP_SHARED`
 * 3. Modify the mapped memory — verify the file on disk is updated (no explicit `write` needed)
 * 4. `mmap` the same file in a second region with `MAP_PRIVATE` — show changes don't propagate
 * 5. Use `msync` to flush dirty pages to disk
 * 6. Demonstrate anonymous shared memory for IPC: `mmap(MAP_ANONYMOUS | MAP_SHARED)`
 *    — simulate two "processes" sharing a counter via a pointer into the mapping
 * 7. Show `mprotect` to make a region read-only and catch the resulting `SIGSEGV`
 * 8. Note the trading-system use case: market-data feeds often use shared memory + `mmap`
 *    for zero-copy delivery between publisher and subscriber processes
 *
 * **Expected output:**
 * ```
 * === Memory-Mapped File ===
 * Created test.dat (4096 bytes, all zeros)
 *
 * mmap MAP_SHARED:
 *   Mapped at: 0x[addr]
 *   Write "AAPL$150.25" at offset 0 via pointer
 *   msync: flushed to disk
 *   Read back from file: "AAPL$150.25"  (file updated — no write() needed)
 *
 * mmap MAP_PRIVATE (copy-on-write):
 *   Write "MSFT$300.00" via MAP_PRIVATE pointer
 *   Read from MAP_PRIVATE: "MSFT$300.00"
 *   Read from file:        "AAPL$150.25"  (original unchanged)
 *
 * === Anonymous Shared Memory (IPC) ===
 * Shared counter at: 0x[addr]
 * "Process A" increments counter 1000 times
 * "Process B" reads counter: 1000  (sees updates)
 *
 * === mprotect Read-Only ===
 * mprotect(region, 4096, PROT_READ): OK
 * Attempting write to read-only region...
 * SIGSEGV caught — write to read-only page denied
 *
 * Cleanup: munmap
 * ```
 */

int main() {}
