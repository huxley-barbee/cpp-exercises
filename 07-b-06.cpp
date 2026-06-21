/*
 * ## EXERCISE 6: UBSAN — Undefined Behaviour Sanitizer [7.b.ii]
 *
 * UBSAN catches signed integer overflow, null dereference, misaligned access,
 * out-of-bounds array indexing, and many other forms of UB that produce silently
 * wrong results in optimised builds.
 *
 * **Requirements:**
 *
 * Write `ubsan_demo.cpp` triggering each UBSAN detector:
 * 1. **Signed integer overflow**: `INT_MAX + 1`
 * 2. **Null pointer dereference**: dereference a null pointer
 * 3. **Shift overflow**: `1 << 32` on a 32-bit int
 * 4. **Division by zero**: `int x = 1 / 0`
 * 5. **Invalid enum value**: cast an out-of-range integer to an enum
 * 6. **Array index out of bounds**: `int arr[4]; arr[4] = 1`
 * 7. **Misaligned pointer**: cast a `char*` to `int*` and dereference
 *
 * Compile: `g++ -fsanitize=undefined -fno-sanitize-recover=all -g ubsan_demo.cpp`
 *
 * For each: show the UBSAN report and the fix.
 *
 * **Expected output:**
 * ```
 * === UBSAN: signed integer overflow ===
 * ubsan_demo.cpp:6:24: runtime error: signed integer overflow:
 * 2147483647 + 1 cannot be represented in type 'int'
 *
 * === UBSAN: null pointer dereference ===
 * ubsan_demo.cpp:11:5: runtime error: null pointer dereference
 * (member access through null pointer of type 'Bond')
 *
 * === UBSAN: shift overflow ===
 * ubsan_demo.cpp:16:14: runtime error: shift exponent 32 is too large
 * for 32-bit type 'int'
 *
 * === UBSAN: division by zero ===
 * ubsan_demo.cpp:21:18: runtime error: division by zero
 *
 * === UBSAN: invalid enum ===
 * ubsan_demo.cpp:28:20: runtime error: load of value 99 is not a valid
 * value for type 'InstrumentType'
 * ```
 */

int main() {}
