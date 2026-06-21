/*
 * ## EXERCISE 4: Zero-Cost Abstractions — Templates vs Virtual [3.b.ii]
 *
 * Write a program comparing runtime polymorphism (virtual functions) with compile-time polymorphism (templates).
 *
 * **Requirements:**
 * 1. Implement a `speak()` operation via virtual dispatch
 * 2. Implement the same operation via a function template (no vtable)
 * 3. Measure the performance difference
 * 4. Explain the trade-offs
 * 5. State when to prefer each approach
 *
 * **Expected output:**
 * ```
 * === Runtime Polymorphism (Virtual Functions) ===
 * Dog says: Woof
 * Cat says: Meow
 *
 * Overhead per object:
 * - vtable pointer: 8 bytes
 * - Indirect call:  ~2-3 cycles
 *
 * === Compile-Time Polymorphism (Templates) ===
 * Dog says: Woof
 * Cat says: Meow
 *
 * Overhead per object:
 * - vtable pointer: 0 bytes
 * - Direct call:    ~0-1 cycles
 *
 * === Performance (10 000 000 calls) ===
 * Virtual dispatch: ~450ms
 * Template calls:   ~120ms
 * Speedup:          ~3.75x
 *
 * === When to Use Each ===
 *
 * Use virtual functions when:
 * - Runtime type flexibility is required
 * - Storing heterogeneous types in one container
 * - Plugin / extension architectures
 * - Types are unknown at compile time
 *
 * Use templates when:
 * - Types are known at compile time
 * - Maximum throughput is critical
 * - No runtime dispatch is needed
 * - Writing generic algorithms
 *
 * Templates = zero-cost abstraction for compile-time-known types!
 * ```
 */

int main() {}
