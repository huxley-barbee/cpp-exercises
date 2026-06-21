/*
 * ## EXERCISE 10: Executors — Asio-Style I/O Executor [6.b.iii]
 *
 * Real trading systems use I/O event loops (Asio, libuv, io_uring) driven by an
 * executor. Implement a minimal event loop executor.
 *
 * **Requirements:**
 * 1. Implement `EventLoop` with:
 *    - An internal `std::deque<std::function<void()>>` protected by mutex
 *    - `post(f)`: enqueue a callback (thread-safe)
 *    - `dispatch(f)`: run immediately if on the event-loop thread, else post
 *    - `run()`: process all callbacks until `stop()` is called
 *    - `stop()`: signal the loop to exit after current batch
 * 2. Run the event loop on a dedicated thread
 * 3. From other threads, `post()` pricing tasks and collect results via promises
 * 4. Show that callbacks run on the event-loop thread (single-threaded context)
 * 5. Implement a simple timer: `scheduleAfter(ms, callback)` posts the callback
 *    after a delay
 * 6. Demonstrate the pattern used by Asio: a strand wraps multiple handlers so they
 *    never run concurrently
 *
 * **Expected output:**
 * ```
 * === EventLoop Executor ===
 * Event loop started on thread: [loop thread id]
 *
 * post() from main thread (id: [main id])
 * post() from worker thread (id: [worker id])
 *
 * All callbacks running on loop thread: [loop thread id]  CORRECT
 *
 * Callback 1: bond price = $1044.52
 * Callback 2: equity price = $155.00
 * Callback 3: option price = $8.75
 *
 * === scheduleAfter ===
 * t=0ms:   timer set for 100ms
 * t=102ms: timer fired! callback executed on loop thread
 *
 * === dispatch() ===
 * dispatch() from non-loop thread: posted (runs later)
 * dispatch() from loop thread:     runs immediately (no queue)
 *
 * === stop() ===
 * Event loop stopping... processed 8 callbacks
 * Loop thread joined.
 * ```
 */

int main() {}
