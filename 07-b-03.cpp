/*
 * ## EXERCISE 3: gdb/LLDB — Reverse Debugging and Watchpoints [7.b.i]
 *
 * Reverse debugging lets you step *backwards* to find when a variable was corrupted.
 *
 * **Requirements:**
 *
 * Write `heap_corrupt.cpp` — a program where a value is corrupted before it is used:
 * ```cpp
 * struct PriceRecord { double bid; double ask; int seqNo; };
 * void processBatch(PriceRecord* records, int n) {
 *     for (int i = 0; i < n; ++i)
 *         records[i].ask = records[i].bid * 1.001;
 *     // BUG: off-by-one write that corrupts the next record's seqNo
 *     records[n].seqNo = 999;   // one past end!
 * }
 * int main() {
 *     PriceRecord rec[3] = {{150.0,0.0,1},{300.0,0.0,2},{100.0,0.0,3}};
 *     processBatch(rec, 2);   // corrupts rec[2].seqNo or adjacent memory
 *     printf("rec[2].seqNo = %d\n", rec[2].seqNo); // may print wrong value
 * }
 * ```
 *
 * 1. Show how to set a **watchpoint** on `rec[2].seqNo`:
 *    `watch rec[2].seqNo` in gdb
 * 2. Run the program — gdb stops when the value changes
 * 3. Show the backtrace at the watchpoint hit — reveals the corrupt write
 * 4. Show **reverse stepping** with gdb's record/replay:
 *    `record`, then `reverse-next`, `reverse-step`, `reverse-continue`
 * 5. Show `rr` (Mozilla's record-and-replay tool) as a production alternative
 * 6. Show `watch -l` (location watchpoint, survives function returns)
 *
 * **Expected output:**
 * ```
 * === Watchpoint session ===
 * (gdb) watch rec[2].seqNo
 * Hardware watchpoint 1: rec[2].seqNo
 *
 * (gdb) run
 * Hardware watchpoint 1: rec[2].seqNo
 * Old value = 3
 * New value = 999
 * processBatch (records=0x..., n=2) at heap_corrupt.cpp:4
 * 4       records[n].seqNo = 999;
 *
 * (gdb) bt
 * #0  processBatch at heap_corrupt.cpp:4
 * #1  main at heap_corrupt.cpp:9
 *
 * Bug found: records[n] is one past the valid range.
 *
 * === Reverse debugging ===
 * (gdb) record
 * (gdb) run  (reaches the corruption)
 * (gdb) reverse-continue  (goes back to just before corruption)
 * (gdb) reverse-next      (step backward one line)
 * ```
 */

int main() {}
