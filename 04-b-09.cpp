/*
 * ## EXERCISE 9: `typedef`-Heavy Code — Reading Legacy Type Aliases [4.b.iv]
 *
 * Legacy quant code is dense with `typedef` chains. Write a program that reproduces a
 * realistic slice of a C++98 fixed-income library's type system.
 *
 * **Requirements:**
 * 1. Define a layered set of `typedef`s:
 *    - `typedef double                         Price`
 *    - `typedef double                         Yield`
 *    - `typedef double                         Spread`
 *    - `typedef int                            Maturity`   // years
 *    - `typedef std::pair<Price, Yield>        PriceYieldPair`
 *    - `typedef std::vector<PriceYieldPair>    PriceYieldCurve`
 *    - `typedef std::map<Maturity, Yield>      YieldCurveMap`
 *    - `typedef std::vector<YieldCurveMap>     ScenarioSet`
 * 2. Write functions using these aliases:
 *    - `PriceYieldPair computePriceYield(Price p, Yield y)`
 *    - `void printCurve(const PriceYieldCurve& curve)`
 *    - `Yield interpolate(const YieldCurveMap& curve, Maturity m)`
 * 3. In `main()`, construct and print a `PriceYieldCurve` and a `YieldCurveMap`
 * 4. Show how deeply nested `typedef`s make reading error messages painful
 * 5. Rewrite each `typedef` as its `using` equivalent and note the difference in clarity
 * 6. Show `typedef` for function pointers (especially confusing) vs `using`
 *
 * **Expected output:**
 * ```
 * === Legacy typedef Chain ===
 * typedef double Price;
 * typedef double Yield;
 * typedef std::pair<Price,Yield> PriceYieldPair;
 * ...
 * (6 levels deep)
 *
 * PriceYieldCurve:
 *   Maturity 1Y: price=$99.50, yield=0.0250
 *   Maturity 2Y: price=$98.75, yield=0.0275
 *   Maturity 5Y: price=$96.00, yield=0.0320
 *
 * YieldCurveMap interpolation at 3Y: 0.0298 (linear)
 *
 * === Function Pointer typedef (confusing) ===
 * typedef double (*PricingFunc)(double, double);
 * vs
 * using PricingFunc = double(*)(double, double);
 *
 * result via function pointer: $102.50
 *
 * === Modern using Equivalents ===
 * using Price           = double;
 * using PriceYieldPair  = std::pair<Price, Yield>;
 * using PriceYieldCurve = std::vector<PriceYieldPair>;
 * (Clearer — especially for templates and function pointers)
 * ```
 */

int main() {}
