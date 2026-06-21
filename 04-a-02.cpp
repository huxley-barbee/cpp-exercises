/*
 * ## EXERCISE 2: Raw Pointers — Pointer Arithmetic and Arrays [4.a.i]
 *
 * Write a program showing how raw pointer arithmetic was used as an array interface in C++98 code.
 *
 * **Requirements:**
 * 1. Allocate a dynamic `int` array of size 5 with `new[]`
 * 2. Fill it using pointer arithmetic (no `[]` subscript)
 * 3. Print it by incrementing a pointer from `begin` to `begin + size`
 * 4. Write a C++98-style `find` function: `int* find(int* begin, int* end, int value)`
 * 5. Write a C++98-style `sum` function: `int sum(const int* begin, const int* end)`
 * 6. Delete with `delete[]`, then note what happens if you use plain `delete` (UB — comment out)
 * 7. Show the modern `std::vector` equivalent in a comment block
 *
 * **Expected output:**
 * ```
 * === Raw Array via Pointer Arithmetic ===
 * Allocated int[5] at: 0x[addr]
 * Filling: 10 20 30 40 50
 * Printing via pointer walk: 10 20 30 40 50
 *
 * === C++98-Style Algorithms ===
 * find(30): found at offset 2
 * find(99): not found (returned end pointer)
 * sum: 150
 *
 * === Cleanup ===
 * delete[] — OK
 * (delete without [] would corrupt heap — UB)
 *
 * Modern equivalent: std::vector<int> v = {10,20,30,40,50};
 * ```
 */

int main() {}
