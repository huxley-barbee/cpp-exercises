/*
 * ## EXERCISE 2: gdb/LLDB — Debugging a Multithreaded Race Condition [7.b.i]
 *
 * Race conditions are among the hardest bugs to debug. Use gdb's thread commands.
 *
 * **Requirements:**
 *
 * Write `race_counter.cpp` — a deliberately racy shared counter:
 * ```cpp
 * #include <thread>
 * #include <vector>
 * int g_counter = 0;
 * void increment(int n) { for (int i = 0; i < n; ++i) ++g_counter; }
 * int main() {
 *     std::vector<std::thread> threads;
 *     for (int t = 0; t < 4; ++t)
 *         threads.emplace_back(increment, 250000);
 *     for (auto& t : threads) t.join();
 *     printf("Expected: 1000000  Got: %d\n", g_counter);
 * }
 * ```
 *
 * 1. Compile with `-g -O0 -fsanitize=thread` and run — show TSan output
 * 2. In gdb: set a breakpoint inside `increment`, run, then use:
 *    - `info threads` — list all threads
 *    - `thread N` — switch to a specific thread
 *    - `thread apply all bt` — backtrace all threads simultaneously
 *    - `scheduler-locking on` — freeze all threads except current
 * 3. Show how to set a conditional breakpoint: `break increment if i == 100000`
 * 4. Demonstrate `set follow-fork-mode child` for debugging forked processes
 * 5. Fix the race (use `std::atomic<int>`) and verify under TSan
 *
 * **Expected output:**
 * ```
 * === TSan output ===
 * WARNING: ThreadSanitizer: data race
 *   Write of size 4 at 0x... by thread T2
 *     #0 increment(int) race_counter.cpp:4
 *   Previous write of size 4 at 0x... by thread T1
 *     #0 increment(int) race_counter.cpp:4
 *
 * === gdb thread commands ===
 * (gdb) info threads
 *   Id  Target Id         Frame
 * * 1   Thread 0x... (LWP ...) main() ...
 *   2   Thread 0x... (LWP ...) increment(n=250000)
 *   3   Thread 0x... (LWP ...) increment(n=250000)
 *   4   Thread 0x... (LWP ...) increment(n=250000)
 *
 * (gdb) thread apply all bt
 * Thread 1: main() -> t.join()
 * Thread 2: increment() -> ++g_counter
 * ...
 *
 * === Fixed output ===
 * Expected: 1000000  Got: 1000000  CORRECT
 * ```
 */

int main() {}
