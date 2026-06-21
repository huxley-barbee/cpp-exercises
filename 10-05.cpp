/*
 * ## EXERCISE 5: Diagnose Memory Corruption — Buffer Overflows and Use-After-Free [10.c]
 *
 * Work through three realistic memory corruption scenarios using ASan, Valgrind,
 * and gdb, documenting every step.
 *
 * **Requirements:**
 *
 * **Scenario A — Silent heap corruption in a C++98 order book:**
 * ```cpp
 * class LegacyOrderBook {
 *     double* prices_;
 *     int     capacity_, count_;
 * public:
 *     LegacyOrderBook(int cap) : capacity_(cap), count_(0) {
 *         prices_ = new double[cap];
 *     }
 *     void add(double price) { prices_[count_++] = price; } // no bounds check!
 *     ~LegacyOrderBook() { delete[] prices_; }
 * };
 * // Bug: add() called cap+5 times -> writes past end of allocation
 * ```
 *
 * **Scenario B — Use-after-free in a market data callback:**
 * ```cpp
 * std::function<void(double)> g_callback;
 * void setupHandler() {
 *     std::string sym = "AAPL"; // local variable
 *     g_callback = [&sym](double price) { // captures reference to local!
 *         std::cout << sym << ": " << price << "\n";
 *     };
 * } // sym destroyed here; g_callback now holds dangling reference
 * ```
 *
 * **Scenario C — Double-free in a position manager:**
 * ```cpp
 * struct Position { double value; };
 * void processPositions(Position* p, int n) {
 *     for (int i=0;i<n;++i) {
 *         if (p[i].value < 0) {
 *             delete &p[i]; // BUG: p was not individually allocated
 *         }
 *     }
 * }
 * ```
 *
 * For each scenario:
 * 1. Write a reproduction test
 * 2. Run under ASan (`-fsanitize=address`) and show the error report
 * 3. Set a watchpoint in gdb to catch the corruption in action
 * 4. Fix the bug and verify ASan is clean
 *
 * **Expected output:**
 * ```
 * === Scenario A: Heap buffer overflow ===
 * ASan report:
 *   ERROR: AddressSanitizer: heap-buffer-overflow on address 0x...
 *   WRITE of size 8 at offset 80 (capacity=10, writing index=10)
 *   #0 LegacyOrderBook::add() legacy_order_book.cpp:8
 *
 * Fix: add bounds check or use std::vector<double>
 * ASan after fix: 0 errors  PASS
 *
 * === Scenario B: Use-after-free ===
 * ASan report:
 *   ERROR: AddressSanitizer: stack-use-after-return
 *   READ of size 8 inside lambda captured reference
 * Fix: capture sym by value [sym] not by reference [&sym]
 *
 * === Scenario C: Double-free / invalid-free ===
 * ASan report:
 *   ERROR: AddressSanitizer: attempting free on address which
 *   was not malloc()-ed
 * Fix: only delete[] the whole array, never &p[i]
 * ```
 */

int main() {}
