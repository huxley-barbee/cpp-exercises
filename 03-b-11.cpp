/*
 * ## EXERCISE 11: Modern Factory Functions [3.b.i]
 *
 * Write a program showing modern factory patterns that never expose raw `new`.
 *
 * **Requirements:**
 * 1. Show an old-style factory returning a raw pointer
 * 2. Replace with a factory returning `std::unique_ptr`
 * 3. Show a shared-ownership factory returning `std::shared_ptr`
 * 4. Use `emplace_back` for in-place container construction
 * 5. Show return-by-value with move semantics (RVO)
 * 6. Benchmark old vs new approach
 *
 * **Expected output:**
 * ```
 * === Old Factory (BAD) ===
 * Widget* w = Widget::create(42);   // Caller must delete!
 * Used widget: 42
 * delete w;                          // Easy to forget
 *
 * Problems: leak-prone, exception-unsafe, unclear ownership
 *
 * === Modern Factory: make_unique ===
 * auto w = Widget::create(42);      // Returns unique_ptr
 * Used widget: 42
 * // Automatic cleanup — no delete needed
 *
 * Benefits: RAII, exception-safe, clear single ownership
 *
 * === Modern Factory: make_shared ===
 * auto w1 = Widget::createShared(42);
 * auto w2 = w1;                     // Shared ownership
 * use_count: 2
 * Both widgets freed when last owner exits scope
 *
 * === Emplace: In-Place Construction ===
 * push_back(Widget(42)):   1 construction + 1 move
 * emplace_back(42):        1 construction (faster!)
 *
 * === Return by Value ===
 * createLargeVector() returns vector<int>(1 000 000)
 * No copy — RVO or move semantics apply
 * Time to return: ~2ms (move) vs ~50ms (copy)
 *
 * === Benchmark (10 000 objects) ===
 * Raw new/delete:  15ms  + leak risk
 * make_unique:     15ms  + zero leak risk
 * make_shared:     12ms  + zero leak risk (single allocation)
 *
 * Always use make_unique / make_shared — never raw new!
 * ```
 */

int main() {}
