/*
 * ## EXERCISE 10: Static Analyzers — `include-what-you-use` and `iwyu` [7.c.iii]
 *
 * `include-what-you-use` (IWYU) enforces the "include what you use" principle:
 * every symbol used in a `.cpp` file must have its header explicitly included,
 * and headers that are not directly used must be removed.
 *
 * **Requirements:**
 *
 * Write `iwyu_target.cpp` with include problems:
 * ```cpp
 * #include "everything.h"   // a mega-header that includes 50 other headers
 * #include <iostream>        // only used in a commented-out debug line
 *
 * using namespace std;       // pollutes namespace — pulls in hundreds of names
 * map<string, double> prices;  // uses map and string via "everything.h" transitively
 * ```
 *
 * 1. Run IWYU: `include-what-you-use iwyu_target.cpp -- -std=c++17`
 * 2. Show which `#include` directives should be added and which removed
 * 3. Apply fixes using `iwyu-fix-includes` script
 * 4. Show the "thin header" pattern: headers include only what they declare,
 *    not what their implementations need
 * 5. Demonstrate a `CMakeLists.txt` integration using `CMAKE_CXX_INCLUDE_WHAT_YOU_USE`
 * 6. Show the relationship between IWYU compliance and faster compilation times:
 *    before/after include cleanup, measure compile time with `-ftime-report`
 *
 * **Expected output:**
 * ```
 * === IWYU output ===
 * iwyu_target.cpp should add these includes:
 *   #include <map>       // for std::map
 *   #include <string>    // for std::string
 *
 * iwyu_target.cpp should remove these includes:
 *   - #include "everything.h"  // not directly used
 *   - #include <iostream>       // not used in this file
 *
 * === After IWYU fixes ===
 * #include <map>
 * #include <string>
 *
 * std::map<std::string, double> prices;   // explicit qualification
 *
 * === Compile time comparison ===
 * Before IWYU (including everything.h): 2.4s
 * After  IWYU (only map + string):      0.18s
 * Speedup: 13x faster compilation
 * ```
 */

int main() {}
