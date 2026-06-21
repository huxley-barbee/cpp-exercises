/*
 * ## EXERCISE 3: Branch Prediction — Jump Tables vs Switch [5.b.i]
 *
 * `switch` statements on dense integer ranges compile to jump tables — a single indirect
 * branch that the CPU's indirect branch predictor handles well.
 *
 * **Requirements:**
 * 1. Write a message dispatcher using a `switch` on `MessageType` (8 types)
 * 2. Write the same dispatcher using `if/else if` chains
 * 3. Write it using a function-pointer jump table (as in Exercise 7 of section 4c)
 * 4. Benchmark all three dispatching 50 million messages with uniformly random types
 * 5. Show the assembly for the `switch` case — confirm it emits an indirect jump
 * 6. Show the `if/else` case — confirm it emits a chain of conditional jumps
 * 7. Discuss indirect branch predictor (IBP) — the CPU learns which targets a given
 *    indirect branch tends to jump to
 * 8. Show that with only 1 or 2 message types the `if/else` can be faster (simpler prediction)
 *
 * **Expected output:**
 * ```
 * === Dispatch Benchmark (50M messages, 8 types uniform) ===
 *
 * Method              Time    ns/dispatch  Notes
 * switch (jump table) 185ms   3.7ns        1 indirect branch
 * if/else chain       320ms   6.4ns        up to 7 comparisons
 * function ptr table  195ms   3.9ns        1 bounds check + indirect call
 *
 * With 2 types only (alternating):
 *   switch:   140ms  (IBP learns alternating pattern)
 *   if/else:  110ms  (single predictable branch — beats switch)
 *
 * Rule: switch for N >= 3 dense integer types;
 *       if/else for N == 1 or 2 with predictable patterns.
 * ```
 */

int main() {}
