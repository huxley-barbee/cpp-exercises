/*
 * ## EXERCISE 1: Read & Modify C++98 Code — Understanding the Legacy Codebase [10.a]
 *
 * Walk through a realistic legacy C++98 pricing utility and understand every
 * construct before modifying it.
 *
 * **Requirements:**
 *
 * Study the following C++98 bond pricer and answer the analysis questions:
 *
 * ```cpp
 * // legacy_bond.h (C++98)
 * #ifndef LEGACY_BOND_H
 * #define LEGACY_BOND_H
 *
 * #include <vector>
 * #include <cmath>
 * #include <stdexcept>
 *
 * typedef std::vector<double> DoubleVec;
 *
 * class BondPricer {
 * public:
 *     BondPricer(double par, double coupon, double maturity, int freq)
 *         : par_(par), coupon_(coupon), maturity_(maturity), freq_(freq),
 *           cached_price_(-1.0), dirty_(true) {
 *         if (par <= 0 || coupon < 0 || maturity <= 0 || freq <= 0)
 *             throw std::invalid_argument("invalid bond parameters");
 *         buildSchedule();
 *     }
 *     ~BondPricer() {}
 *
 *     double price(double yield) {
 *         if (!dirty_ && yield == last_yield_)
 *             return cached_price_;
 *         cached_price_ = computeNPV(yield);
 *         last_yield_ = yield;
 *         dirty_ = false;
 *         return cached_price_;
 *     }
 *
 *     void setParValue(double par) { par_ = par; dirty_ = true; }
 *     double getParValue() const    { return par_; }
 *
 *     DoubleVec getCashflows() const { return cashflows_; }
 *
 * private:
 *     double par_, coupon_, maturity_;
 *     int    freq_;
 *     double cached_price_, last_yield_;
 *     bool   dirty_;
 *     DoubleVec cashflows_;
 *     DoubleVec times_;
 *
 *     void buildSchedule() {
 *         double dt = 1.0 / freq_;
 *         double c  = par_ * coupon_ / freq_;
 *         for (double t = dt; t <= maturity_ + 1e-9; t += dt) {
 *             cashflows_.push_back(c);
 *             times_.push_back(t);
 *         }
 *         cashflows_.back() += par_;  // add principal at maturity
 *     }
 *
 *     double computeNPV(double yield) const {
 *         double npv = 0.0;
 *         double y_dt = yield / freq_;
 *         for (size_t i = 0; i < cashflows_.size(); ++i)
 *             npv += cashflows_[i] / std::pow(1.0 + y_dt, (i + 1));
 *         return npv;
 *     }
 * };
 * #endif
 * ```
 *
 * 1. List every C++98 construct and its modern C++17 equivalent
 * 2. Identify the cache invalidation bug: the cache checks `yield == last_yield_`
 *    using floating-point equality — explain why this is unsafe and propose a fix
 * 3. Identify the `buildSchedule` precision accumulation bug: `t += dt` in
 *    a floating-point loop — explain the risk and how `t = (i+1)*dt` fixes it
 * 4. Rewrite the class in C++17:
 *    - `typedef` → `using`
 *    - Manual cache → `std::optional<double> cached_price_`
 *    - Raw members → constructor delegation or default member initialisers
 *    - `getCashflows()` returning by value → returning `const std::vector<double>&`
 *    - Add `[[nodiscard]]` to `price()`
 * 5. Write two unit tests that catch the two bugs before and after the fix
 *
 * **Expected output:**
 * ```
 * === C++98 Analysis ===
 * 1. typedef DoubleVec -> using DoubleVec = std::vector<double>
 * 2. Manual caching -> std::optional + structured comparison
 * 3. float accumulation -> index-based schedule generation
 * 4. ~BondPricer() {} -> Rule of Zero (implicit destructor)
 * 5. dirty_ bool flag -> optional<pair<double,double>>
 *
 * === Bug demonstration ===
 * Bug 1 (float equality): price(0.05) then price(0.05+1e-16)
 *   Returns cached_price_ even though yield changed: INCORRECT
 * Bug 2 (accumulation): at maturity=5, freq=12, step 60
 *   Accumulated t = 4.99999... != 5.0 -> last coupon dropped!
 *   Cashflows without fix: 59  (should be 60)
 *
 * === C++17 version ===
 * All tests pass, [[nodiscard]] warns on ignored return value
 * ```
 */

int main() {}
