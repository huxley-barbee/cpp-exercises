/*
 * ## EXERCISE 13: Comprehensive Integration [All of 7.b]
 *
 * You are given a `MarketDataProcessor` module that has been in production for
 * two years with no tests. It occasionally crashes, leaks memory under load, and
 * is 3× slower than it should be. Apply the full diagnostic workflow.
 *
 * **Requirements:**
 *
 * ```cpp
 * // market_data_processor.cpp — legacy code with multiple issues
 * struct Tick { char sym[12]; double bid; double ask; long ts; };
 *
 * class MarketDataProcessor {
 *     Tick*   buffer_;
 *     int     capacity_;
 *     int     count_;
 *     double* priceHistory_;  // for moving average
 *
 * public:
 *     MarketDataProcessor(int cap) : capacity_(cap), count_(0) {
 *         buffer_      = (Tick*)malloc(cap * sizeof(Tick));
 *         priceHistory_ = new double[cap * 10];
 *         // priceHistory not initialised
 *     }
 *
 *     void processTick(const char* sym, double bid, double ask, long ts) {
 *         if (count_ >= capacity_) return;
 *         Tick& t = buffer_[count_++];
 *         memcpy(t.sym, sym, 12);  // no null termination guaranteed
 *         t.bid = bid; t.ask = ask; t.ts = ts;
 *
 *         // Moving average: reads priceHistory_ before it is set
 *         double mid = (bid + ask) / 2.0;
 *         priceHistory_[count_] = mid;  // off-by-one potential
 *         double ma = 0.0;
 *         for (int i = 0; i < 5 && i < count_; ++i)
 *             ma += priceHistory_[count_ - i];  // reads uninitialised for first 4
 *         ma /= (count_ < 5 ? count_ : 5);
 *     }
 *
 *     ~MarketDataProcessor() {
 *         free(buffer_);
 *         // priceHistory_ leaked (new/delete mismatch with malloc/free mixed)
 *     }
 * };
 * ```
 *
 * Apply in order:
 * 1. **Characterise** current behaviour with 3 characterisation tests
 * 2. **Valgrind** run — document all errors found
 * 3. **ASAN + UBSAN** run — document all errors found
 * 4. **gdb** — set a watchpoint on `count_`, trace the first tick processing
 * 5. **Profiler** — `perf stat` to measure instruction count and cache misses
 * 6. **Fix all bugs** — uninitialised memory, missing null terminator, off-by-one,
 *    mixed malloc/new, leak
 * 7. **Modernise** — replace C-style allocation with `std::vector<Tick>` and
 *    `std::vector<double>` (Rule of Zero eliminates the destructor bug entirely)
 * 8. **Verify** — all tools clean, all characterisation tests still pass
 *
 * **Expected output:**
 * ```
 * === Diagnostic Workflow ===
 *
 * Step 1 — Characterisation tests: 3/3 recorded
 *
 * Step 2 — Valgrind:
 *   definitely lost: capacity*10*8 bytes (priceHistory_ leak)
 *   use of uninitialised value in moving average
 *
 * Step 3 — ASAN/UBSAN:
 *   use-of-uninitialized-value: priceHistory_ read before write
 *   potential off-by-one at priceHistory_[count_]
 *
 * Step 4 — gdb watchpoint:
 *   watch count_
 *   Stopped at: processTick, count_ changed 0 -> 1
 *
 * Step 5 — perf stat:
 *   Cache miss rate: 18% (priceHistory_ accessed non-sequentially)
 *
 * Step 6+7 — After fixes and modernisation:
 *   Valgrind: 0 errors, 0 leaks
 *   ASAN:     0 errors
 *   UBSAN:    0 errors
 *   perf stat: cache miss rate reduced to 2%
 *   Characterisation tests: 3/3 still pass
 *   LOC reduced by 12 (Rule of Zero eliminates destructor)
 * ```
 */

int main() {}
