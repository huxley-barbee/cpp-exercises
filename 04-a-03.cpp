/*
 * ## EXERCISE 3: Manual Memory Management — C++98 Class [4.a.ii]
 *
 * Write a C++98-style `String` class that manually manages a `char*` buffer.
 *
 * **Requirements:**
 * 1. Private members: `char* data_`, `size_t len_`
 * 2. Constructor: `explicit String(const char* s)` — allocates and copies
 * 3. Destructor: frees `data_`
 * 4. Copy constructor: deep copy
 * 5. Copy assignment operator: handle self-assignment, free old, allocate new
 * 6. `const char* c_str() const` accessor
 * 7. `size_t length() const` accessor
 * 8. In `main()`: create, copy, assign, and destroy instances — verify no double-free
 * 9. Add a comment explaining what the Rule of Three is and why it applies here
 *
 * **Expected output:**
 * ```
 * === C++98 Manual String ===
 * s1: "hello" (len=5)
 * s2 (copy of s1): "hello" (len=5)
 *
 * Modifying s1's internal buffer directly...
 * s1: "HELLO"
 * s2: "hello" (deep copy — independent)
 *
 * s3 = s1 (copy assignment):
 * s3: "HELLO"
 *
 * Self-assignment s1 = s1: safe (no crash)
 *
 * Destructors called in reverse order:
 * ~String("HELLO")
 * ~String("hello")
 * ~String("HELLO")
 *
 * Rule of Three: destructor + copy ctor + copy assignment all defined.
 * ```
 */

int main() {}
