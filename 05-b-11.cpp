/*
 * ## EXERCISE 11: NUMA — Thread and Memory Affinity [5.b.iv]
 *
 * Pinning threads to specific cores and allocating memory on the correct node are
 * essential for deterministic low latency.
 *
 * **Requirements:**
 * 1. Pin a thread to core 0 using `pthread_setaffinity_np` / `sched_setaffinity`
 * 2. Verify the pinning worked: read `/proc/self/status` for `Cpus_allowed`
 * 3. Allocate memory explicitly on the current thread's NUMA node using `mbind`
 * 4. Show the effect of not pinning: with OS scheduler free to migrate threads,
 *    a thread may access its local memory from a remote core (latency spike)
 * 5. Write a benchmark that shows the latency jitter introduced by thread migration
 *    (standard deviation of 1000 latency samples with vs without pinning)
 * 6. Demonstrate `MADV_HUGEPAGE` to enable transparent huge pages for large buffers
 *    (reduces TLB pressure)
 * 7. Show `numactl --cpunodebind=0 --membind=0 ./program` as the command-line alternative
 *
 * **Expected output:**
 * ```
 * === Thread Pinning ===
 * Before pin: allowed CPUs = 0-23
 * pthread_setaffinity_np(core=0): OK
 * After pin:  allowed CPUs = 0
 *
 * === Memory Binding ===
 * mbind(buf, 256MB, MPOL_BIND, node=0): OK
 * All pages allocated on node 0
 *
 * === Latency Jitter (1000 samples, 64-byte pointer chase) ===
 * Without pinning:
 *   Mean:   48ns   StdDev: 22ns   Max: 312ns  (migration spike!)
 *
 * With core pinning:
 *   Mean:   41ns   StdDev:  3ns   Max:  52ns
 *
 * Jitter reduction: 7.3x
 *
 * === Transparent Huge Pages ===
 * madvise(buf, size, MADV_HUGEPAGE)
 * TLB entries needed: 64  (2MB pages vs 4KB pages: 512 entries)
 * TLB miss reduction: 8x for large sequential scans
 *
 * === Command-Line Alternative ===
 * numactl --cpunodebind=0 --membind=0 ./trading_engine
 * ```
 */

int main() {}
