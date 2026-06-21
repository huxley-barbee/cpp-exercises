/*
 * ## EXERCISE 3: `std::packaged_task` — Wrapping Callables [6.b.i]
 *
 * `std::packaged_task` wraps any callable and connects it to a `std::future`.
 * It is the building block of thread pools.
 *
 * **Requirements:**
 * 1. Wrap a bond-pricing function in `std::packaged_task<double(double,double,int)>`
 * 2. Get the future from the task, then invoke the task
 * 3. Show that the task can be moved into a thread for deferred execution
 * 4. Demonstrate storing heterogeneous tasks in a queue using type erasure:
 *    `std::queue<std::packaged_task<void()>>` — wrap all tasks as `void()`
 * 5. Build a minimal serial task runner that processes the queue
 * 6. Show the move-only nature of `packaged_task` — it cannot be copied
 * 7. Demonstrate a retry pattern: catch exception from future, resubmit the task
 *
 * **Expected output:**
 * ```
 * === packaged_task basics ===
 * Task created, future obtained
 * Task invoked
 * Result: $1044.52
 *
 * === packaged_task in thread ===
 * Task moved into thread
 * Thread executing task...
 * Main retrieved result: $1044.52
 *
 * === Heterogeneous task queue ===
 * Enqueued 5 tasks (bond, equity, option, fx, commodity prices)
 * Running serial task runner...
 * [Task 1] Bond price:     $1044.52
 * [Task 2] Equity price:   $155.00
 * [Task 3] Option price:   $8.75
 * [Task 4] FX rate:        1.0823
 * [Task 5] Commodity price: $72.40
 * All tasks complete
 *
 * === Move-only ===
 * packaged_task cannot be copied — move only
 * task2 = std::move(task1): OK
 * task1 valid: false, task2 valid: true
 * ```
 */

int main() {}
