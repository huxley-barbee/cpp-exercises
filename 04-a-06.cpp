/*
 * ## EXERCISE 6: Macros — Logging [4.a.iv]
 *
 * Write a program showing how C++98 codebases used preprocessor macros for logging,
 * and contrast with modern alternatives.
 *
 * **Requirements:**
 * 1. Define a `LOG(msg)` macro that prints `[FILE:LINE] msg`
 * 2. Define a `LOG_VAR(x)` macro that prints `[FILE:LINE] x = <value>`
 * 3. Define a `LOG_IF(cond, msg)` macro (conditional logging)
 * 4. Demonstrate macro pitfalls: no type safety, double-evaluation, namespace pollution
 * 5. Show the double-evaluation bug with `LOG_VAR(++i)`
 * 6. Show the modern replacement: an `inline` template logging function or `std::format`
 *
 * **Expected output:**
 * ```
 * === C++98 Logging Macros ===
 * [exercise.cpp:42] Starting computation
 * [exercise.cpp:43] x = 10
 * [exercise.cpp:44] y = 3.14
 * [exercise.cpp:45] Result = 31.4
 * [exercise.cpp:46] Condition met: value is positive
 *
 * === Macro Pitfalls ===
 *
 * Pitfall 1: Double evaluation
 * int i = 0;
 * LOG_VAR(++i)
 * Expected i = 1, but macro expanded i twice: i = 2  (BUG!)
 *
 * Pitfall 2: No type safety
 * LOG_VAR accepts anything — no compile-time checks
 *
 * Pitfall 3: Namespace pollution
 * LOG defined globally — clashes with any user symbol named LOG
 *
 * === Modern Alternative ===
 * template<typename T>
 * inline void log_var(const char* name, const T& val, const char* file, int line) {
 *     std::cout << "[" << file << ":" << line << "] " << name << " = " << val << "\n";
 * }
 * #define LOG_VAR_SAFE(x) log_var(#x, (x), __FILE__, __LINE__)
 *
 * LOG_VAR_SAFE(i): i = 1  (evaluated once — correct!)
 * Type safe, inlined, no double evaluation.
 * ```
 */

int main() {}
