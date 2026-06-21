/*
 * ## EXERCISE 1: Threads — Creation, Joining, and Detaching [6.a.i]
 *
 * **Requirements:**
 * 1. Spawn 8 `std::thread`s, each printing its thread ID and a work result
 * 2. Join all threads and verify all results are collected before `main` returns
 * 3. Demonstrate `std::thread::hardware_concurrency()` to query core count
 * 4. Show what happens when you forget to join or detach before the `std::thread`
 *    destructor fires (it calls `std::terminate` — document in a comment, don't crash)
 * 5. Demonstrate `detach()`: fire-and-forget a background logger thread
 * 6. Pass arguments to a thread function three ways:
 *    - By value (copy into thread)
 *    - By `std::ref` (reference into thread)
 *    - Via lambda capture
 * 7. Show that passing a dangling reference to a detached thread is undefined behaviour
 *
 * **Expected output:**
 * ```
 * === Thread Creation ===
 * Hardware concurrency: 8
 *
 * Thread 0 (id=140234...): result = 0
 * Thread 1 (id=140235...): result = 1
 * ...
 * Thread 7 (id=140241...): result = 7
 *
 * All 8 threads joined — results collected.
 *
 * === Argument Passing ===
 * By value:      local=10  thread sees copy=10  (original unchanged after thread modifies)
 * By std::ref:   local=10  thread doubles it -> local=20
 * By lambda:     captured x=42 -> computed 42*42=1764
 *
 * === Detached Logger ===
 * [logger] background thread started
 * Main continues immediately (logger detached)
 * [logger] flushed 100 messages
 *
 * === Destructor Trap ===
 * // std::thread t(worker);
 * // // forgot join/detach -> std::terminate() on scope exit!
 * // Fix: always RAII-wrap threads (std::jthread C++20, or manual guard)
 * ```
 */

int main() {}
