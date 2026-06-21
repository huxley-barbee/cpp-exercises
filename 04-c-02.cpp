/*
 * ## EXERCISE 2: `extern "C"` — Exposing a C++ Class to C [4.c.i]
 *
 * C has no classes. To expose C++ class functionality to C you must write a C-linkage
 * wrapper API using opaque handles.
 *
 * **Requirements:**
 * 1. Write a C++ class `PricingEngine` with:
 *    - Constructor taking a `double riskFreeRate`
 *    - `double priceOption(double S, double K, double T, double sigma) const` (Black-Scholes call)
 *    - Destructor
 * 2. Write a C-linkage wrapper API:
 *    - `void* pricing_engine_create(double rate)`
 *    - `double pricing_engine_price_option(void* handle, double S, double K, double T, double sigma)`
 *    - `void pricing_engine_destroy(void* handle)`
 * 3. Use `static_cast<PricingEngine*>(handle)` to recover the pointer inside each wrapper
 * 4. Show that the C API hides all C++ details — only `void*` crosses the boundary
 * 5. Demonstrate use from a simulated C caller (a plain C-style function in the same file)
 * 6. Show error handling: what happens if `handle` is NULL (add a null guard)
 *
 * **Expected output:**
 * ```
 * === C++ PricingEngine ===
 * PricingEngine created (r=0.05)
 * priceOption(S=100, K=100, T=1, sigma=0.2): $10.45
 *
 * === C-Linkage Wrapper API ===
 * void* pricing_engine_create(0.05)       -> handle: 0x[addr]
 * pricing_engine_price_option(handle, ...): $10.45
 * pricing_engine_destroy(handle)          -> PricingEngine destroyed
 *
 * === Null Handle Guard ===
 * pricing_engine_price_option(NULL, ...): 0.0 (null guard triggered)
 *
 * === Simulated C Caller ===
 * void c_caller() {
 *     void* eng = pricing_engine_create(0.05);
 *     double px  = pricing_engine_price_option(eng, 100,100,1,0.2);
 *     pricing_engine_destroy(eng);
 * }
 * Price from C caller: $10.45
 * ```
 */

int main() {}
