/*
 * ## EXERCISE 11: Function Pointers — C Library Callbacks (`qsort`, `bsearch`) [4.c.iii]
 *
 * `qsort` and `bsearch` are the canonical examples of C-style callbacks. Legacy quant code
 * uses them for sorting instrument arrays and binary searching sorted price tables.
 *
 * **Requirements:**
 * 1. Sort an array of `Trade` POD structs by price using `qsort` with a comparator
 * 2. Sort the same array by quantity using a different comparator
 * 3. Use `bsearch` to find a trade by price in the sorted array
 * 4. Show the `const void*` → concrete-type cast and its pitfalls
 * 5. Implement your own `myQsort` that takes a comparison function pointer — mimicking the
 *    `qsort` signature — to understand how the callback is threaded through
 * 6. Show the same operations with `std::sort` + lambda (C++11) for contrast
 * 7. Benchmark `qsort` vs `std::sort` briefly (note: `std::sort` is typically faster due to inlining)
 *
 * **Expected output:**
 * ```
 * === qsort by price ===
 * Before: [(A,$100,10),(B,$50,30),(C,$200,5),(D,$75,20)]
 * After:  [(B,$50,30),(D,$75,20),(A,$100,10),(C,$200,5)]
 *
 * === qsort by quantity ===
 * After:  [(C,$200,5),(A,$100,10),(D,$75,20),(B,$50,30)]
 *
 * === bsearch by price ===
 * Sorted by price: [(B,$50),(D,$75),(A,$100),(C,$200)]
 * bsearch($100): found -> Trade A, qty=10
 * bsearch($999): not found -> NULL
 *
 * === myQsort (manual callback threading) ===
 * typedef int (*CmpFn)(const void*, const void*);
 * void myQsort(void* base, size_t n, size_t sz, CmpFn cmp);
 * Result matches qsort: YES
 *
 * === std::sort + lambda (C++11) ===
 * std::sort(trades, trades+4, [](const Trade& a, const Trade& b){
 *     return a.price < b.price;
 * });
 * Same result, but type-safe and inlineable by compiler
 * ```
 */

int main() {}
