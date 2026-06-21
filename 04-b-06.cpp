/*
 * ## EXERCISE 6: Homegrown Containers — Ring Buffer [4.b.ii]
 *
 * Ring buffers appear everywhere in legacy market-data and order-management systems.
 *
 * **Requirements:**
 * 1. Implement a C++98 `RingBuffer<T>` with:
 *    - Fixed capacity set at construction, raw `T*` array
 *    - `push(const T&)` — overwrites oldest entry when full
 *    - `pop(T&)` — returns false if empty
 *    - `size()`, `empty()`, `full()`
 *    - Destructor, copy constructor, copy assignment
 * 2. Test with `double` (tick prices)
 * 3. Show wrap-around: fill buffer past capacity, verify oldest entries are overwritten
 * 4. Show thread-safety concern (mention — no threads required)
 * 5. Demonstrate iteration over all current elements in insertion order
 * 6. Note `std::deque` / `boost::circular_buffer` as alternatives
 *
 * **Expected output:**
 * ```
 * === RingBuffer<double> capacity=4 ===
 * push(1.10): size=1
 * push(1.11): size=2
 * push(1.12): size=3
 * push(1.13): size=4  (full)
 * push(1.14): size=4  (overwrote oldest: 1.10)
 * push(1.15): size=4  (overwrote oldest: 1.11)
 *
 * Current contents (insertion order): 1.12 1.13 1.14 1.15
 *
 * pop() -> 1.12: size=3
 * pop() -> 1.13: size=2
 *
 * === Copy ===
 * buf2 = buf1
 * buf1.push(1.16) — buf2 unaffected
 * buf2 contents: 1.14 1.15
 *
 * Thread safety concern: push/pop not atomic — needs mutex in concurrent code
 * Modern: boost::circular_buffer<T> or std::deque<T>
 * ```
 */

int main() {}
