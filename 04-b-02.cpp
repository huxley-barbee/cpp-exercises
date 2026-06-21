/*
 * ## EXERCISE 2: Virtual Dispatch — The Fragile Base Class Problem [4.b.i]
 *
 * A classic legacy maintenance hazard: modifying a base class breaks derived classes silently.
 *
 * **Requirements:**
 * 1. Create base class `RiskModel` with virtual `double computeVaR(double notional) const`
 * 2. Create `HistoricalVaR` and `MonteCarloVaR` derived classes
 * 3. Add a new virtual method `double computeCVaR(double notional) const` to the base
 *    **without** providing an override in `MonteCarloVaR` — show the silent fallback to base
 * 4. Show what happens when the base implementation changes and derived classes are not updated
 * 5. Demonstrate the pure-virtual technique for forcing derived classes to implement new methods
 * 6. Add a non-virtual wrapper `double computeRisk(double notional) const` that calls both
 *    VaR and CVaR and returns the worse — show how it is reused without re-implementation
 *
 * **Expected output:**
 * ```
 * === Fragile Base Class ===
 *
 * HistoricalVaR::computeVaR(1000000):   $25000.00
 * MonteCarloVaR::computeVaR(1000000):   $28000.00
 *
 * Adding computeCVaR to base...
 * HistoricalVaR::computeCVaR(1000000):  $31000.00
 * MonteCarloVaR::computeCVaR(1000000):  $20000.00  <- silently calls BASE version!
 *
 * === Fix: Pure Virtual Forces Override ===
 * Making computeCVaR pure virtual:
 *   MonteCarloVaR must now implement it — compile error if missing
 *
 * === Non-Virtual Wrapper (NVI reuse) ===
 * HistoricalVaR::computeRisk(1000000):  $31000.00  (max of VaR, CVaR)
 * MonteCarloVaR::computeRisk(1000000):  $32000.00  (max of VaR, CVaR)
 * Non-virtual wrapper reused without re-implementation.
 * ```
 */

int main() {}
