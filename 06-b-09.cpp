/*
 * ## EXERCISE 9: Executors — The Concept [6.b.iii]
 *
 * An executor is an object that knows *where* and *how* to run work. This is the
 * abstraction that underpins Asio, `std::execution` (C++23), and every modern async
 * framework.
 *
 * **Requirements:**
 * 1. Define an `Executor` concept (as a C++20 concept or as a duck-typed interface):
 *    `void execute(std::function<void()> f)`
 * 2. Implement three executors:
 *    - `InlineExecutor`: runs the task immediately in the calling thread
 *    - `ThreadPoolExecutor`: forwards to your `ThreadPool` from Exercise 5
 *    - `StrandExecutor`: serialises tasks (one at a time) even if the underlying pool
 *      has multiple threads — critical for avoiding lock-free ordered access
 * 3. Write `scheduleWork(Executor& ex, std::vector<Task> tasks)` that submits all tasks
 *    to the given executor
 * 4. Show all three executors producing correct results for the same set of tasks
 * 5. Show the `StrandExecutor` ensuring serialisation: 100 tasks that each increment a
 *    counter without any mutex — the strand guarantees single-threaded execution
 *
 * **Expected output:**
 * ```
 * === Executor Concept ===
 *
 * InlineExecutor:
 *   All tasks run in calling thread [thread id: main]
 *   5 tasks complete, counter=5
 *
 * ThreadPoolExecutor:
 *   Tasks distributed across 4 worker threads
 *   5 tasks complete, counter=5 (protected by pool)
 *
 * StrandExecutor:
 *   Tasks serialised through strand (one at a time)
 *   Counter incremented 1000 times without mutex
 *   Final counter: 1000  CORRECT (no race — strand serialises)
 *
 * === scheduleWork dispatch ===
 *   InlineExecutor    -> 10 tasks -> all results correct
 *   ThreadPoolExecutor -> 10 tasks -> all results correct
 *   StrandExecutor    -> 10 tasks -> all results correct, serialised
 * ```
 */

int main() {}
