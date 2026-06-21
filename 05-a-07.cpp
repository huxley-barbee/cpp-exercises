/*
 * ## EXERCISE 7: Threads vs Processes — Creation and Overhead [5.a.iii]
 *
 * Threads share address space; processes do not. Write a program that measures the
 * cost of creating each.
 *
 * **Requirements:**
 * 1. Create 1000 `std::thread`s sequentially, measure total creation time
 * 2. `fork()` 100 child processes, measure total fork time
 * 3. Show that threads share global state (a `std::atomic<int>` counter incremented by all)
 * 4. Show that `fork()`ed children get a *copy* of the counter — changes don't propagate back
 * 5. Demonstrate `pthread_create` directly (lower level than `std::thread`) and compare overhead
 * 6. Show the memory cost: each thread needs a stack (default 8MB); a process gets a full
 *    copy of the address space
 * 7. Summarise: threads are cheaper to create, share memory, but share fate (one crash kills all);
 *    processes are isolated but costlier and require IPC
 *
 * **Expected output:**
 * ```
 * === Thread Creation Cost ===
 * Creating 1000 std::threads (join each immediately):
 *   Total time: 45ms
 *   Per thread: ~45µs
 *
 * === Process (fork) Creation Cost ===
 * Forking 100 child processes (wait each):
 *   Total time: 180ms
 *   Per fork:   ~1.8ms  (40x more expensive than thread)
 *
 * === Shared State: Threads ===
 * Global counter = 0
 * 10 threads each increment 1000 times
 * Final counter: 10000  (all increments visible — shared memory)
 *
 * === Copied State: fork() ===
 * Counter before fork = 42
 * Child increments to 142 (100 increments)
 * Parent reads counter: 42  (unchanged — child has a copy)
 *
 * === Memory Cost ===
 * Thread stack: 8MB each (configurable)
 * 1000 threads: ~8GB virtual (but sparse — not all resident)
 * fork: copies page tables (COW) — resident grows on write
 *
 * === When to Use Each ===
 * Threads: shared data, low overhead, same binary
 * Processes: isolation, separate address space, fault tolerance
 * ```
 */

int main() {}
