/*
 * ## EXERCISE 6: Thread Pool — Work Stealing [6.b.ii]
 *
 * A single shared queue becomes a bottleneck under high submission rates.
 * Work-stealing distributes the queue per-thread and steals from neighbours when idle.
 *
 * **Requirements:**
 * 1. Implement `WorkStealingPool` with one `std::deque` per worker thread
 * 2. `submit(task)` pushes to the calling thread's local queue (or round-robins)
 * 3. A worker first tries its own queue (back, LIFO for cache locality)
 * 4. If own queue is empty, it tries to steal from another thread's queue (front, FIFO)
 * 5. Use `std::mutex` per deque (or lock-free if ambitious)
 * 6. Benchmark against the single-queue `ThreadPool` for 10,000 tasks with
 *    variable duration (mix of short and long)
 * 7. Show that work-stealing reduces idle time: log idle steal attempts per worker
 *
 * **Expected output:**
 * ```
 * === Work-Stealing Pool (4 workers) ===
 *
 * Submitting 10000 tasks (mix: 80% fast, 20% slow)...
 *
 * Results:
 *   Single-queue ThreadPool: 1850ms  (slow tasks block queue)
 *   Work-stealing Pool:      1240ms  speedup 1.5x
 *
 * Per-worker steal stats:
 *   Worker 0: 1240 tasks own, 82 stolen
 *   Worker 1: 1180 tasks own, 135 stolen
 *   Worker 2: 1210 tasks own, 98 stolen
 *   Worker 3: 1370 tasks own, 45 stolen
 *
 * Work-stealing balances load across workers automatically.
 * ```
 */

int main() {}
