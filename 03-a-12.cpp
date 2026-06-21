/*
 * ## EXERCISE 12: Concurrency - Mutex and Lock Guards [3.a.viii]
 *
 * Write a program demonstrating thread synchronization.
 *
 * **Requirements:**
 * 1. Show race condition without mutex
 * 2. Fix with std::mutex
 * 3. Use std::lock_guard for RAII
 * 4. Demonstrate std::unique_lock
 * 5. Show deadlock scenario and fix
 * 6. Use std::scoped_lock (C++17)
 *
 * **Expected output format:**
 * ```
 * === Race Condition (WITHOUT mutex) ===
 * Incrementing counter 1000 times from 10 threads
 * Expected: 10000
 * Actual: 7843  (WRONG due to race condition!)
 *
 * === Fixed with Mutex ===
 * std::mutex mtx;
 * void increment() {
 *     std::lock_guard<std::mutex> lock(mtx);
 *     counter++;
 * }
 *
 * Expected: 10000
 * Actual: 10000  (CORRECT!)
 *
 * === Lock Guard (RAII) ===
 * {
 *     std::lock_guard<std::mutex> lock(mtx);
 *     // Critical section
 *     // Lock automatically released at scope end
 * }
 *
 * === Unique Lock (More Flexible) ===
 * std::unique_lock<std::mutex> lock(mtx);
 * // Can unlock manually
 * lock.unlock();
 * // Do work without lock
 * lock.lock();  // Re-lock
 *
 * === Deadlock Scenario ===
 * Thread 1: Lock A, then Lock B
 * Thread 2: Lock B, then Lock A
 * Result: DEADLOCK (both threads waiting forever)
 *
 * === Deadlock Prevention with scoped_lock ===
 * std::scoped_lock lock(mtx1, mtx2);  // Locks both atomically
 * // Critical section using both resources
 * // Both unlocked automatically
 *
 * === Performance Impact ===
 * Without lock: 10ms
 * With lock: 45ms
 * Lock overhead: ~4.5x slower
 *
 * Mutex ensures thread safety but adds overhead!
 * ```
 */

int main() {}
