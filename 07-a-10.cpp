/*
 * ## EXERCISE 10: Incremental Modernisation — C++98 to C++11 [7.a.iv]
 *
 * Modernisation should happen one well-understood transformation at a time, each
 * step independently reviewable.
 *
 * **Requirements:**
 *
 * Apply each of the following transformations to the legacy `PortfolioManager` class,
 * one at a time, with a test verifying the transformation did not change behaviour:
 *
 * ```cpp
 * // C++98 PortfolioManager
 * class PortfolioManager {
 *     std::vector<Position*>  positions_;   // owns pointers
 *     std::map<std::string, double> prices_;
 *     Logger* logger_;
 *
 * public:
 *     PortfolioManager(Logger* log) : logger_(log) {}
 *     ~PortfolioManager();  // manually deletes all positions_
 *     PortfolioManager(const PortfolioManager&);      // deep copy
 *     PortfolioManager& operator=(const PortfolioManager&);
 *
 *     void addPosition(const std::string& sym, int qty, double px);
 *     double totalValue() const;
 *     void   updatePrice(const std::string& sym, double px);
 * };
 * ```
 *
 * Transformations (one per step):
 * 1. `NULL` → `nullptr`
 * 2. `typedef` → `using`
 * 3. Manual `delete` loop → `std::unique_ptr<Position>`  (Rule of Zero)
 * 4. `Logger*` raw pointer member → `Logger&` reference (non-owning)
 * 5. Loop-based copy constructor → deleted (unique ownership)
 * 6. `std::map::find` + pointer check → `std::optional` return
 * 7. Explicit iterator loops → range-based `for`
 * 8. `std::string` key lookup → `std::string_view` parameter
 *
 * For each transformation: show before, after, and the test that stays green.
 *
 * **Expected output:**
 * ```
 * === Incremental Transformations ===
 *
 * Step 1: NULL -> nullptr
 *   Before: if (logger_ == NULL)
 *   After:  if (logger_ == nullptr)
 *   Test [PASS]: behaviour unchanged
 *
 * Step 2: typedef -> using
 *   Before: typedef std::map<std::string,double> PriceMap;
 *   After:  using PriceMap = std::map<std::string,double>;
 *   Test [PASS]: behaviour unchanged
 *
 * Step 3: raw pointer -> unique_ptr (Rule of Zero)
 *   Before: std::vector<Position*> positions_;  ~PM() { for(auto*p:positions_) delete p; }
 *   After:  std::vector<std::unique_ptr<Position>> positions_;  // destructor generated
 *   Test [PASS]: no memory leaks (verified with ASan)
 *
 * ... (steps 4-8 similar)
 *
 * All 8 transformations: 8/8 tests passed, behaviour unchanged.
 * ```
 */

int main() {}
