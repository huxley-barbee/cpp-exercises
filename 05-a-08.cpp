/*
 * ## EXERCISE 8: Threads vs Processes — Inter-Process Communication [5.a.iii]
 *
 * When processes must share data they need IPC. Write a program that benchmarks
 * the major IPC mechanisms available on Linux.
 *
 * **Requirements:**
 * 1. **Pipes**: parent writes 1 MB in 4096-byte chunks, child reads — measure throughput
 * 2. **Named pipes (FIFO)**: same test across two independent processes
 * 3. **POSIX shared memory** (`shm_open` + `mmap`): write/read 1 MB — measure throughput
 * 4. **POSIX message queues** (`mq_open`): send 1000 messages, measure latency
 * 5. **Unix domain sockets**: round-trip latency for a 64-byte message
 * 6. Rank them by throughput and latency
 * 7. State which mechanism real trading systems use for market-data distribution and why
 *    (shared memory + lock-free ring buffer)
 *
 * **Expected output:**
 * ```
 * === IPC Benchmark (1MB transfer) ===
 *
 * Mechanism              Throughput      Latency (64B round-trip)
 * Pipe                   1.2 GB/s        8µs
 * Named pipe (FIFO)      1.1 GB/s        9µs
 * POSIX shared memory    12.0 GB/s       0.3µs   (memory speed)
 * POSIX message queue    0.8 GB/s        15µs
 * Unix domain socket     2.5 GB/s        4µs
 *
 * === Shared Memory Detail ===
 * shm_open("pricing_feed", O_CREAT|O_RDWR): fd=4
 * ftruncate(fd, 1MB): OK
 * mmap: mapped at 0x[addr]
 * Write 1MB: 0.08ms
 * Read 1MB:  0.07ms
 * Throughput: ~12 GB/s  (limited by L3 cache, not OS)
 *
 * === Trading System Choice ===
 * Market-data distribution: shared memory + lock-free ring buffer
 *   - Zero copy: publisher writes once, N subscribers read
 *   - No kernel involvement in the hot path
 *   - Latency: ~200ns publisher-to-subscriber
 *
 * Order routing: Unix domain socket or pipe
 *   - Small messages, low frequency
 *   - Kernel provides ordering guarantees
 * ```
 */

int main() {}
