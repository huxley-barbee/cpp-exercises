/*
 * ## EXERCISE 5: Thread Pool — Fixed-Size Implementation [6.b.ii]
 *
 * A thread pool amortises thread-creation cost by reusing a fixed set of threads.
 * This is the most important concurrency pattern in quant finance systems.
 *
 * **Requirements:**
 * 1. Implement `ThreadPool` with:
 *    - Constructor taking `size_t numThreads`
 *    - `submit(F&& f) -> std::future<ReturnType>` using `std::packaged_task`
 *    - Internal `std::queue<std::function<void()>>` protected by `std::mutex`
 *    - `std::condition_variable` to wake idle workers
 *    - Destructor that drains the queue and joins all threads
 * 2. Workers loop: lock, wait for task or shutdown, pop and execute
 * 3. Test: submit 100 pricing tasks, collect all futures, verify sum
 * 4. Benchmark: compare thread pool vs `std::async` (new thread per task) for 1000
 *    short tasks
 * 5. Show the shutdown sequence: set a stop flag, `notify_all`, join workers
 * 6. Handle exceptions: if a task throws, the exception is captured in the future
 *
 * **Expected output:**
 * ```
 * === Thread Pool (4 workers) ===
 * Pool created with 4 threads
 *
 * Submitting 100 pricing tasks...
 * All 100 futures collected
 *
 * Processing...
 * Sum of 100 bond prices: $104452.00  CORRECT
 *
 * === Benchmark: 1000 short tasks ===
 * std::async (new thread per task): 2850ms
 * ThreadPool (4 workers):            185ms
 * Speedup: 15.4x  (thread reuse amortises creation cost)
 *
 * === Exception handling ===
 * Task 42 threw: invalid_argument("negative yield")
 * future[42].get() re-throws: invalid_argument: negative yield
 * Other futures unaffected
 * ```
 */

int main() {}
