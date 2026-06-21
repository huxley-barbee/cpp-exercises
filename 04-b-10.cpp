/*
 * ## EXERCISE 10: `typedef`-Heavy Code — Template `typedef` Workarounds [4.b.iv]
 *
 * C++98 had no template type aliases (`using` aliases are C++11). Legacy code worked around
 * this with nested `typedef`s inside helper structs.
 *
 * **Requirements:**
 * 1. Write a C++98 template alias workaround for `std::vector<T>`:
 *    ```cpp
 *    template<typename T>
 *    struct Vec { typedef std::vector<T> type; };
 *    // Usage: Vec<int>::type v;
 *    ```
 * 2. Write the same for `std::map<std::string, T>`:
 *    ```cpp
 *    template<typename T>
 *    struct StringMap { typedef std::map<std::string, T> type; };
 *    ```
 * 3. Write a `Rebind` allocator pattern (common in legacy container code)
 * 4. Show how iterator typedefs worked inside a custom container:
 *    ```cpp
 *    typedef T*       iterator;
 *    typedef const T* const_iterator;
 *    ```
 * 5. Rewrite everything using `using` (C++11) and note the improvement
 * 6. Show `typename` disambiguation required when using dependent typedefs
 *
 * **Expected output:**
 * ```
 * === C++98 Template typedef Workaround ===
 * Vec<int>::type v = {1, 2, 3};
 * StringMap<double>::type m;
 * m["rate"] = 0.05;
 *
 * Using nested typedef:
 *   Vec<double>::type v;  // verbose
 *   typename Vec<double>::type v;  // needed in template context
 *
 * === Iterator typedefs ===
 * MyContainer<int>::iterator it = c.begin();
 * MyContainer<int>::const_iterator cit = c.cbegin();
 *
 * === Modern using Alias Templates ===
 * template<typename T>
 * using Vec = std::vector<T>;
 *
 * Vec<int> v = {1, 2, 3};  // clean — no ::type
 *
 * template<typename T>
 * using StringMap = std::map<std::string, T>;
 *
 * StringMap<double> m;
 * m["rate"] = 0.05;
 *
 * typename no longer needed in most alias contexts
 * ```
 */

int main() {}
