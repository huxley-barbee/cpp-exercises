/*
 * ## EXERCISE 8: Copy Constructors for Resources — Self-Assignment and Exception Safety [4.b.iii]
 *
 * **Requirements:**
 * 1. Write a `PriceTimeSeries` class holding a raw heap `double*` and a `size_t len_`
 * 2. Implement copy assignment with a self-assignment guard (`if (this == &other)`)
 * 3. Show what happens without the guard (free then copy from freed memory)
 * 4. Implement the copy-and-swap idiom for strong exception safety:
 *    - `swap(PriceTimeSeries&)` member (no-throw)
 *    - `operator=(PriceTimeSeries other)` (takes by value, then swaps)
 * 5. Prove strong exception safety: if the copy-constructor throws mid-way, the original
 *    is left unchanged (simulate with a throwing copy constructor that fails after N copies)
 * 6. Note the modern alternative: `std::vector<double>` gives all this for free
 *
 * **Expected output:**
 * ```
 * === Self-Assignment Without Guard ===
 * ts = ts  (no guard)
 * delete[] data_ — freed own memory!
 * memcpy from freed memory — UNDEFINED BEHAVIOUR
 * (Commented out)
 *
 * === Self-Assignment With Guard ===
 * ts = ts  (with guard)
 * this == &other — returning *this safely
 *
 * === Copy-and-Swap Idiom ===
 * ts1: [1.0, 2.0, 3.0]
 * ts2 = ts1:
 *   1. Copy-construct temporary from ts1
 *   2. swap(*this, temp)
 *   3. temp destructor frees old ts2 data
 * ts2: [1.0, 2.0, 3.0]  (correct)
 * ts1: [1.0, 2.0, 3.0]  (unchanged)
 *
 * === Exception Safety ===
 * ts_bad = ts1  (allocates, then throws during copy)
 * Exception caught: copy failed partway through
 * ts1 still valid: [1.0, 2.0, 3.0]  (copy-and-swap guarantees this)
 *
 * Modern: std::vector<double> — copy-and-swap built-in, Rule of Zero
 * ```
 */

int main() {}
