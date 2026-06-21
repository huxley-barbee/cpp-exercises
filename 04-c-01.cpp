/*
 * ## EXERCISE 1: `extern "C"` — Preventing Name Mangling [4.c.i]
 *
 * C++ compilers mangle function names to encode type information. C compilers do not.
 * When linking C and C++ code, this mismatch causes linker errors.
 *
 * **Requirements:**
 * 1. Write a small C++ function `double computeNPV(double* cashflows, int n, double rate)`
 * 2. Show what the mangled name looks like using `nm` or by printing the symbol (comment out)
 * 3. Wrap the function in `extern "C"` so it is callable from C
 * 4. Write a second version: a C++ header safe for inclusion from both C and C++:
 *    ```c
 *    #ifdef __cplusplus
 *    extern "C" {
 *    #endif
 *    double computeNPV(double* cashflows, int n, double rate);
 *    #ifdef __cplusplus
 *    }
 *    #endif
 *    ```
 * 5. Show that `extern "C"` disables overloading — two functions with the same name but
 *    different signatures cannot both be `extern "C"`
 * 6. Show `extern "C"` applied to an entire block vs a single declaration
 * 7. Demonstrate calling the `extern "C"` function from a C++ `main()`
 *
 * **Expected output:**
 * ```
 * === Name Mangling Demo ===
 * Without extern "C":
 *   C++ mangled name: _Z12computeNPVPdid  (example — compiler-specific)
 *   C cannot link to this symbol
 *
 * With extern "C":
 *   Symbol name: computeNPV  (plain C name — C can link)
 *
 * === extern "C" Block ===
 * extern "C" {
 *     double computeNPV(double*, int, double);
 *     double computePV(double, double, int);
 * }
 *
 * === Cannot Overload extern "C" ===
 * // extern "C" double process(int);    // OK
 * // extern "C" double process(double); // ERROR: same C name 'process'
 * Overloading disabled for C-linkage functions
 *
 * === Calling from C++ ===
 * cashflows: [-1000, 200, 300, 400, 250]
 * NPV at 5%: $27.93
 *
 * === C/C++ Compatible Header Pattern ===
 * #ifdef __cplusplus
 * extern "C" {
 * #endif
 *     ... declarations ...
 * #ifdef __cplusplus
 * }
 * #endif
 * This header is safe to #include from both C and C++.
 * ```
 */

int main() {}
