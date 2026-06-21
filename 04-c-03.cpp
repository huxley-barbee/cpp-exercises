/*
 * ## EXERCISE 3: C Headers — Using `<cstdio>`, `<cstring>`, `<cmath>` [4.c.ii]
 *
 * C++ wraps all C standard library headers. Knowing which C functions map to which C++
 * equivalents is essential when reading legacy quant code.
 *
 * **Requirements:**
 * 1. Use `<cstdio>`: `printf`, `fprintf`, `sprintf`, `snprintf`, `fopen`/`fclose`/`fwrite`/`fread`
 * 2. Use `<cstring>`: `strlen`, `strcpy`, `strncpy`, `strcmp`, `strncmp`, `memcpy`, `memset`, `memmove`
 * 3. Use `<cmath>`: `sqrt`, `exp`, `log`, `pow`, `fabs`, `ceil`, `floor`, `fmod`
 * 4. Use `<cstdlib>`: `malloc`/`free`, `atoi`, `atof`, `strtod`, `qsort`, `abs`
 * 5. For each C function demonstrate:
 *    - The C call
 *    - A common bug or pitfall (e.g., `strcpy` overflow, `malloc` without `free`)
 *    - The modern C++ equivalent
 * 6. Show that C++ places C library symbols in both `::` and `std::` namespaces
 *
 * **Expected output:**
 * ```
 * === <cstdio> ===
 * printf: Hello from C: value=3.14
 * sprintf into buf[8]: "3.14159"  (safe with snprintf)
 * snprintf pitfall: truncation silent — always check return value
 * fprintf to stderr: [ERROR] something went wrong
 *
 * === <cstring> ===
 * strlen("hello"): 5
 * strcpy BUG: no bounds check — use strncpy or std::string
 * strncpy("hello world", buf, 5): "hello" (no null terminator added!)
 * strcmp("abc","abd"): negative
 * memcpy: [1,2,3,4,5] copied to dest
 * memset: buffer zeroed
 * memmove: handles overlapping regions correctly
 *
 * === <cmath> ===
 * sqrt(2.0):  1.41421
 * exp(1.0):   2.71828
 * log(M_E):   1.00000
 * pow(2,10):  1024
 * fabs(-3.5): 3.5
 * ceil(1.2):  2,  floor(1.8): 1
 *
 * === <cstdlib> ===
 * malloc/free: value=42
 * atoi("123"): 123  (no error detection — use strtol)
 * strtod("3.14abc", &end): 3.14, remainder="abc"
 * qsort: [1, 2, 3, 5, 7, 8]
 *
 * === Namespace: C symbols in std:: ===
 * std::sqrt(2.0) == sqrt(2.0): true
 * ```
 */

int main() {}
