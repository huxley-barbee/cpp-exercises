/*
 * ## EXERCISE 8: Static Analyzers — `clang-tidy` for Concurrency [7.c.iii]
 *
 * Thread-safety bugs are common in trading systems. `clang-tidy` has concurrency
 * checks; this exercise focuses on finding and annotating them.
 *
 * **Requirements:**
 *
 * Write `concurrent_cache.cpp` with deliberate thread-safety violations:
 * ```cpp
 * class PriceCache {
 *     std::map<std::string, double> cache_;
 *     // No mutex — accessed from multiple threads
 * public:
 *     void update(const std::string& sym, double price) { cache_[sym] = price; }
 *     double get(const std::string& sym) const { return cache_.at(sym); }
 * };
 * ```
 *
 * 1. Run `clang-tidy` with `thread-safety-analysis` checks enabled
 * 2. Add `__attribute__((capability("mutex")))` annotations (Clang thread safety)
 * 3. Show the full annotation system:
 *    - `GUARDED_BY(mutex_)` on data members
 *    - `REQUIRES(mutex_)` on methods that must be called with lock held
 *    - `EXCLUDES(mutex_)` on methods that must NOT hold the lock (avoid deadlock)
 * 4. Demonstrate that annotated code catches lock omissions at compile time
 * 5. Show `THREAD_ANNOTATION_ATTRIBUTE__` macros for portable annotations
 * 6. Fix the cache using `std::shared_mutex` and apply all annotations
 *
 * **Expected output:**
 * ```
 * === Thread safety annotations ===
 *
 * class PriceCache {
 *     mutable std::shared_mutex mutex_;
 *     std::map<std::string, double> cache_ GUARDED_BY(mutex_);
 * public:
 *     void update(const std::string& sym, double price)
 *         EXCLUDES(mutex_) {
 *         std::unique_lock<std::shared_mutex> lk(mutex_);
 *         cache_[sym] = price;
 *     }
 *     double get(const std::string& sym) const
 *         EXCLUDES(mutex_) {
 *         std::shared_lock<std::shared_mutex> lk(mutex_);
 *         return cache_.at(sym);
 *     }
 *     // Internal method requiring lock to be held
 *     void updateInternal(const std::string& sym, double p)
 *         REQUIRES(mutex_) {
 *         cache_[sym] = p;
 *     }
 * };
 *
 * === Violation detected at compile time ===
 * cache_unlocked.cpp:15: warning: writing variable 'cache_' requires
 * holding mutex 'mutex_' exclusively [-Wthread-safety-analysis]
 * ```
 */

int main() {}
