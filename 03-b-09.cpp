/*
 * ## EXERCISE 9: Combining Rules — When to Use Which [3.b.iii]
 *
 * Write a program comparing Rule of Zero, Three, and Five in context.
 *
 * **Requirements:**
 * 1. Implement three classes: `ModernResource` (Rule of Zero), `LegacyBuffer` (Rule of Three), `EfficientBuffer` (Rule of Five)
 * 2. For each, demonstrate copy and move behaviour
 * 3. Show the default-deleted move in Rule of Three
 * 4. Explain the guideline: prefer Rule of Zero; use Rule of Five only when you own a raw resource
 *
 * **Expected output:**
 * ```
 * === Rule of Zero: ModernResource ===
 * Uses: unique_ptr<int>
 * Copy: deleted (unique_ptr not copyable — correct!)
 * Move: compiler-generated, free
 *
 * Moved ModernResource: value = 42
 * Original after move: null
 *
 * === Rule of Three: LegacyBuffer ===
 * Uses: raw char*
 * Destructor, copy constructor, copy assignment defined
 * Move: NOT defined — falls back to copy (expensive!)
 *
 * "Copying" LegacyBuffer (actually a copy, not a move):
 * Time: ~180ms for 1 000 000 ops
 *
 * === Rule of Five: EfficientBuffer ===
 * Uses: raw char*
 * All five special members defined
 *
 * Moving EfficientBuffer:
 * Time: ~15ms for 1 000 000 ops (12x faster than Rule of Three!)
 *
 * === Decision Guide ===
 * No raw resources?              → Rule of Zero (best)
 * Raw resource, no move needed?  → Rule of Three
 * Raw resource, performance critical? → Rule of Five
 * ```
 */

int main() {}
