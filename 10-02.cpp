/*
 * ## EXERCISE 2: Read & Modify C++98 Code — Safe Incremental Modernisation [10.a]
 *
 * Apply the modernisation steps from Exercise 1 in order, keeping tests green
 * at each step.
 *
 * **Requirements:**
 *
 * Given the C++98 `PortfolioManager` below, apply each transformation
 * one at a time, running the test suite between each step:
 *
 * ```cpp
 * // C++98 PortfolioManager
 * class PortfolioManager {
 *     std::vector<BondPricer*> bonds_;       // owns pointers
 *     std::map<std::string, double> yields_; // symbol -> yield
 *     int next_id_;
 *     static int instance_count_;
 *
 * public:
 *     PortfolioManager() : next_id_(0) { ++instance_count_; }
 *     ~PortfolioManager() {
 *         for (int i = 0; i < bonds_.size(); ++i)
 *             delete bonds_[i];
 *     }
 *     // ... copy constructor, assignment operator (manual deep copy)
 *     int addBond(double par, double coupon, double mat, int freq) {
 *         bonds_.push_back(new BondPricer(par, coupon, mat, freq));
 *         return next_id_++;
 *     }
 *     double totalValue(double default_yield) const {
 *         double total = 0.0;
 *         for (int i = 0; i < bonds_.size(); ++i) {
 *             std::string key = "bond_" + std::to_string(i);
 *             std::map<std::string,double>::const_iterator it = yields_.find(key);
 *             double y = (it != yields_.end()) ? it->second : default_yield;
 *             total += bonds_[i]->price(y);
 *         }
 *         return total;
 *     }
 * };
 * ```
 *
 * Transformations (in order):
 * 1. Raw `int` loop → range-based `for`
 * 2. `new BondPricer*` → `std::unique_ptr<BondPricer>`
 * 3. Manual destructor → Rule of Zero
 * 4. `map::const_iterator` → `auto`
 * 5. `"bond_" + std::to_string(i)` → `fmt::format("bond_{}", i)`
 * 6. Copy constructor → deleted (unique ownership)
 * 7. `static int instance_count_` → `std::atomic<int>` (thread-safety)
 *
 * For each transformation: show the diff, confirm tests still pass.
 *
 * **Expected output:**
 * ```
 * === Step 1: range-based for ===
 * Before: for (int i = 0; i < bonds_.size(); ++i)
 * After:  for (const auto& bond : bonds_)
 * Tests: PASS
 *
 * === Step 2: unique_ptr ===
 * Before: std::vector<BondPricer*> bonds_; ... delete bonds_[i];
 * After:  std::vector<std::unique_ptr<BondPricer>> bonds_;
 *         // destructor is now generated automatically
 * Tests: PASS
 *
 * ... (steps 3-7)
 *
 * === All 7 transformations complete ===
 * Lines of code: 82 -> 61 (25% reduction)
 * Tests: 5/5 PASS
 * ```
 */

int main() {}
