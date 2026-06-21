/*
 * ## EXERCISE 7: Thread Pool — Priority Queue [6.b.ii]
 *
 * In a trading system, risk checks must preempt normal pricing tasks.
 * Implement a priority-aware thread pool.
 *
 * **Requirements:**
 * 1. Define `enum class Priority { HIGH=0, NORMAL=1, LOW=2 }`
 * 2. Replace the `std::queue` with a `std::priority_queue` ordered by priority
 * 3. `submit(f, priority)` pushes tasks with the given priority
 * 4. High-priority tasks always run before normal, which always run before low
 * 5. Test: submit 50 LOW tasks, then 10 HIGH tasks, then 20 NORMAL tasks
 *    — verify HIGH tasks complete before NORMAL, NORMAL before LOW
 * 6. Show a starvation risk: continuous HIGH submission can starve LOW tasks
 * 7. Implement aging: LOW tasks that wait > N ms are promoted to NORMAL
 *
 * **Expected output:**
 * ```
 * === Priority Thread Pool (4 workers) ===
 *
 * Submitted: 50 LOW, 10 HIGH, 20 NORMAL
 *
 * Completion order (first 20):
 *   HIGH  task  0 completed  (t=12ms)
 *   HIGH  task  1 completed  (t=13ms)
 *   ...
 *   HIGH  task  9 completed  (t=21ms)
 *   NORMAL task 0 completed  (t=22ms)
 *   ...
 *   NORMAL task 19 completed (t=41ms)
 *   LOW   task  0 completed  (t=42ms)
 *
 * All HIGH tasks completed before any NORMAL: CORRECT
 * All NORMAL tasks completed before any LOW:  CORRECT
 *
 * === Aging (starvation prevention) ===
 * LOW task waiting 200ms -> promoted to NORMAL
 * LOW task waiting 200ms -> promoted to NORMAL
 * No LOW task starved beyond 200ms
 * ```
 */

int main() {}
