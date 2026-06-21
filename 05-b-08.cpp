/*
 * ## EXERCISE 8: Lock-Free Concepts — Lock-Free Stack [5.b.iii]
 *
 * Implement a classic lock-free stack using CAS and measure it against a mutex-protected stack.
 *
 * **Requirements:**
 * 1. Implement `LockFreeStack<T>` using `std::atomic<Node*>`:
 *    - `push(T val)`: allocate node, CAS head
 *    - `pop()`: returns `std::optional<T>`, CAS head
 * 2. Implement `MutexStack<T>` using `std::mutex` as a baseline
 * 3. Test correctness: 4 producer threads push 250K items each; 4 consumer threads pop
 *    until all 1M items consumed — verify total and no duplicates
 * 4. Benchmark: measure total time for the 4+4 thread scenario
 * 5. Show the ABA hazard specific to this stack and why `std::atomic<Node*>` alone is
 *    insufficient without a memory reclamation scheme
 * 6. Mention hazard pointers and epoch-based reclamation as solutions
 * 7. Show performance vs `std::queue` + `std::mutex`
 *
 * **Expected output:**
 * ```
 * === Lock-Free Stack Correctness ===
 * 4 producers x 250K pushes = 1M total
 * 4 consumers pop until empty
 * Items popped: 1000000  PASS
 * No duplicates: PASS
 *
 * === Benchmark (1M push+pop, 8 threads) ===
 * MutexStack:         1850ms
 * LockFreeStack:       620ms
 * std::queue+mutex:   1900ms
 *
 * Speedup (lock-free vs mutex): 3.0x
 *
 * === ABA Hazard ===
 * Thread 1: reads head -> A
 * Thread 2: pops A, pops B, pushes A back (same pointer, different state)
 * Thread 1: CAS(head, A, new_node) SUCCEEDS — B is lost!
 *
 * Fix options:
 *   1. Hazard pointers (mark pointers in use before reading)
 *   2. Epoch-based reclamation (defer free until no thread references epoch)
 *   3. Tagged pointer: atomic<uintptr_t> with version in low bits
 * ```
 */

int main() {}
