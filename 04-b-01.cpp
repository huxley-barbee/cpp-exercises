/*
 * ## EXERCISE 1: Virtual Dispatch — Basic Runtime Polymorphism [4.b.i]
 *
 * C++98 codebases relied heavily on virtual dispatch for runtime polymorphism. Write a
 * program modelling a legacy quant pricing engine.
 *
 * **Requirements:**
 * 1. Create a base class `Instrument` with:
 *    - `virtual double price() const = 0`
 *    - `virtual const char* name() const = 0`
 *    - `virtual ~Instrument()` (virtual destructor)
 * 2. Create concrete classes: `Bond`, `Equity`, `Option` — each overrides `price()` and `name()`
 * 3. Store instruments in a raw `Instrument*` array (no `vector`, no smart pointers — C++98 style)
 * 4. Loop over the array calling `price()` polymorphically
 * 5. Show the vtable overhead: print `sizeof` each class with and without the virtual function
 * 6. Demonstrate the NVI (Non-Virtual Interface) pattern — a public non-virtual `describe()`
 *    that calls private virtual `doDescribe()`
 * 7. Note the modern equivalents (`override`, `std::vector<std::unique_ptr<Instrument>>`)
 *
 * **Expected output:**
 * ```
 * === Legacy Pricing Engine ===
 * Instrument* portfolio[3]
 *
 * Bond        price: $102.50
 * Equity      price: $155.00
 * Option      price: $8.75
 *
 * === sizeof with / without virtual ===
 * sizeof(PlainStruct):    4 bytes  (no vtable)
 * sizeof(Instrument):     8 bytes  (vtable pointer added)
 *
 * === NVI Pattern ===
 * Bond::describe():
 *   [NVI] Instrument: Bond
 *   [NVI] Price: $102.50
 * Equity::describe():
 *   [NVI] Instrument: Equity
 *   [NVI] Price: $155.00
 *
 * Modern fix:
 *   vector<unique_ptr<Instrument>> portfolio;
 *   override keyword on all derived methods
 * ```
 */

int main() {}
