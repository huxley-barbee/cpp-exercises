/*
 * ## EXERCISE 7: Copy Constructors for Resources — Deep vs Shallow [4.b.iii]
 *
 * The most common C++98 bug: forgetting that the compiler-generated copy is shallow.
 *
 * **Requirements:**
 * 1. Write `MarketDataSnapshot` with a raw `double* prices_` array (heap-allocated)
 * 2. First version: no copy constructor — demonstrate shallow copy crash (double-free)
 * 3. Second version: add proper deep-copy constructor and copy-assignment operator
 * 4. Write a function `processSnapshot(MarketDataSnapshot snap)` (pass by value) to trigger
 *    a copy — verify the original is unaffected after the function modifies `snap`
 * 5. Show that returning by value from a function also triggers a copy (pre-RVO world)
 * 6. Contrast with the modern approach: `std::vector<double>` member + Rule of Zero
 *
 * **Expected output:**
 * ```
 * === Shallow Copy (BUG) ===
 * snap1 prices: [100.0, 200.0, 300.0]
 * snap2 = snap1  (shallow copy — same pointer!)
 * ~MarketDataSnapshot: freed prices array
 * ~MarketDataSnapshot: freed same pointer again — DOUBLE FREE / crash!
 * (Commented out to avoid crash)
 *
 * === Deep Copy (CORRECT) ===
 * snap1 prices: [100.0, 200.0, 300.0]
 * snap2 = snap1  (deep copy — independent array)
 *
 * processSnapshot(snap1) modifying local copy:
 *   local prices: [999.0, 200.0, 300.0]
 *   snap1 prices: [100.0, 200.0, 300.0]  (original unchanged)
 *
 * Returning snapshot by value:
 *   Snapshot copy constructed during return
 *   Received: [50.0, 60.0, 70.0]
 *
 * ~MarketDataSnapshot: freed snap2 copy
 * ~MarketDataSnapshot: freed snap1
 *
 * Modern: use vector<double> prices_ — Rule of Zero, no manual copy needed
 * ```
 */

int main() {}
