/*
 * ## EXERCISE 11: Concurrency Library - Threads [3.a.viii]
 *
 * Write a program demonstrating basic thread usage.
 *
 * **Requirements:**
 * 1. Create and launch threads
 * 2. Show thread join and detach
 * 3. Pass arguments to thread functions
 * 4. Demonstrate move-only types with threads
 * 5. Show thread::hardware_concurrency()
 * 6. Handle exceptions in threads
 *
 * **Expected output format:**
 * ```
 * === Thread Basics ===
 *
 * Creating thread...
 * Thread function executing
 * Thread ID: 0x...
 * Main thread ID: 0x...
 *
 * Waiting for thread to finish (join)...
 * Thread completed
 *
 * === Thread with Arguments ===
 * void print(int n, const std::string& s) { ... }
 *
 * std::thread t(print, 42, "hello");
 * Thread output: 42 hello
 *
 * === Multiple Threads ===
 * Hardware concurrency: 8 cores
 *
 * Launching 4 worker threads...
 * Worker 0 starting
 * Worker 1 starting
 * Worker 2 starting
 * Worker 3 starting
 *
 * All workers completed
 *
 * === Detached Thread ===
 * std::thread t(work);
 * t.detach();  // Thread runs independently
 * Main continues...
 * (Note: detached thread may outlive main!)
 *
 * === Move-Only Types ===
 * std::thread t1(work);
 * std::thread t2 = std::move(t1);  // OK: move
 * // std::thread t3 = t1;  // ERROR: no copy
 *
 * === Exception Handling ===
 * std::thread t([]() {
 *     throw std::runtime_error("Thread exception");
 * });
 *
 * try {
 *     t.join();
 * } catch (...) {
 *     // Exception not caught! Terminates program
 * }
 *
 * WARNING: Uncaught exceptions in threads terminate program!
 *
 * std::thread enables parallel execution!
 * ```
 */

int main() {}
