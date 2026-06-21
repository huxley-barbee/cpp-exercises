/*
 * ## EXERCISE 5: Function Pointers — Basics [4.c.iii]
 *
 * Function pointers are the C mechanism for callbacks, strategy patterns, and dispatch
 * tables. They appear throughout legacy C and C++98 code.
 *
 * **Requirements:**
 * 1. Declare and call a function pointer to a free function: `double (*priceFn)(double, double)`
 * 2. Store function pointers in an array (dispatch table): one entry per instrument type
 * 3. Pass a function pointer as a parameter to a `sort`-like function
 * 4. Return a function pointer from a factory function based on a string key
 * 5. Show the syntax for function pointers to member functions (different from free functions)
 * 6. Demonstrate `typedef` for function pointer types to reduce syntactic noise
 * 7. Compare with `std::function<>` (C++11) — show the cleaner syntax
 *
 * **Expected output:**
 * ```
 * === Basic Function Pointer ===
 * double (*priceFn)(double, double) = &bondPrice;
 * priceFn(100.0, 0.05) = $95.24
 *
 * === Dispatch Table ===
 * instruments[0] = "Bond",   pricer = bondPrice
 * instruments[1] = "Equity", pricer = equityPrice
 * instruments[2] = "Option", pricer = optionPrice
 *
 * Dispatching:
 *   Bond   price: $95.24
 *   Equity price: $110.00
 *   Option price: $5.50
 *
 * === Function Pointer as Parameter ===
 * applyPricer(100.0, 0.05, bondPrice)   = $95.24
 * applyPricer(100.0, 0.05, equityPrice) = $110.00
 *
 * === Factory Function ===
 * getPricer("bond")   -> bondPrice -> $95.24
 * getPricer("equity") -> equityPrice -> $110.00
 * getPricer("unknown") -> NULL
 *
 * === Member Function Pointer ===
 * typedef double (PricingModel::*ModelFn)(double) const;
 * ModelFn fn = &PricingModel::computePrice;
 * (model.*fn)(100.0) = $97.50
 *
 * === Modern: std::function ===
 * std::function<double(double,double)> fn = bondPrice;
 * fn(100.0, 0.05) = $95.24
 * (cleaner, type-safe, accepts lambdas too)
 * ```
 */

int main() {}
