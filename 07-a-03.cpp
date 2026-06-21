/*
 * ## EXERCISE 3: Untangling Dependencies — Breaking a Circular Dependency [7.a.i]
 *
 * Circular dependencies (`A` includes `B`, `B` includes `A`) are the hardest
 * structural problem in legacy codebases.
 *
 * **Requirements:**
 *
 * You have:
 * ```
 * RiskEngine.h  includes  PricingEngine.h
 * PricingEngine.h includes RiskEngine.h   (circular!)
 * ```
 *
 * Both need to call methods on each other at runtime.
 *
 * 1. Demonstrate the circular include problem: write minimal headers that cause it
 * 2. Apply **forward declaration** to break the compile-time cycle:
 *    use `class RiskEngine;` instead of `#include "RiskEngine.h"` in PricingEngine.h
 * 3. Move method implementations to `.cpp` files (so the full type is available)
 * 4. Apply the **Dependency Inversion Principle**: introduce `IRiskEngine` and
 *    `IPricingEngine` interfaces; each concrete class depends only on the interface
 * 5. Show the final include graph with no cycles (ASCII)
 * 6. Demonstrate that both engines compile independently and can be tested in isolation
 *
 * **Expected output:**
 * ```
 * === Circular Dependency (BROKEN) ===
 * RiskEngine.h   -> #include "PricingEngine.h"
 * PricingEngine.h -> #include "RiskEngine.h"
 * Compile error: recursive include
 *
 * === Step 1: Forward declaration ===
 * // PricingEngine.h
 * class RiskEngine;   // forward decl — no include needed
 * class PricingEngine {
 *     void computeGreeks(RiskEngine& re);
 * };
 *
 * === Step 2: Dependency Inversion ===
 * IRiskEngine    <- RiskEngine implements
 * IPricingEngine <- PricingEngine implements
 *
 * RiskEngine    depends on IPricingEngine (interface only)
 * PricingEngine depends on IRiskEngine    (interface only)
 *
 * === Final include graph (no cycles) ===
 * interfaces.h  (IRiskEngine, IPricingEngine — no deps)
 *     ^               ^
 * RiskEngine.h   PricingEngine.h
 * (includes interfaces only)
 *
 * Compiles cleanly, each testable in isolation.
 * ```
 */

int main() {}
