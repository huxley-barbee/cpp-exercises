/*
 * ## EXERCISE 8: SFINAE with Type Traits [2.c.iii]
 * 
 * Write a program using SFINAE with custom type traits.
 * 
 * **Requirements:**
 * 1. Create has_size_method trait to detect if type has size() method
 * 2. Use SFINAE to provide different implementations
 * 3. Create is_container trait
 * 4. Demonstrate compile-time introspection
 * 5. Show decltype and declval usage in SFINAE
 * 
 * **Expected output format:**
 * ```
 * === Type Trait Detection ===
 * 
 * has_size_method<std::vector<int>>: true
 * has_size_method<int>: false
 * has_size_method<std::string>: true
 * 
 * === SFINAE with Custom Traits ===
 * 
 * getSize(vector):
 * Container has size() method
 * Size: 5
 * 
 * getSize(int):
 * Type doesn't have size() method
 * Size: 1 (default)
 * 
 * === is_container Trait ===
 * std::vector<int> is container: true
 * std::list<double> is container: true
 * int is container: false
 * std::string is container: true
 * 
 * SFINAE enables compile-time detection of type properties!
 * ```
 */

#include <iostream>
#include <string>
#include <type_traits>
#include <list>
#include <vector>

template <typename T, typename = void>
struct has_size_method : std::false_type {};

template <typename T>
struct has_size_method<T, std::void_t<decltype(std::declval<T>().size())>> : std::true_type {};

template <typename T>
std::enable_if_t<has_size_method<T>::value, void>
getSize(const T& thing) {
    std::cout << "Container has size() method\n";
    std::cout << "Size: " << thing.size() << "\n";
}

template <typename T>
std::enable_if_t<!has_size_method<T>::value, void>
getSize(const T& thing) {
    std::cout << "Type doesn't have size() method\n";
    std::cout << "Size: 1 (default)\n";
}

template <typename T>
std::enable_if_t<has_size_method<T>::value, void>
isContainer(const T& thing) {
    std::cout << "true";
}

template <typename T>
std::enable_if_t<!has_size_method<T>::value, void>
isContainer(const T& thing) {
    std::cout << "false";
}

int main() {

    std::cout << "=== Type Trait Detection ===\n\n";


    std::cout << "has_size_method<std::vector<int>>: ";
    std::cout << std::boolalpha << has_size_method<std::vector<int>>::value << "\n";
    std::cout << "has_size_method<int>: ";
    std::cout << std::boolalpha << has_size_method<int>::value << "\n";
    std::cout << "has_size_method<std::string>: ";
    std::cout << std::boolalpha << has_size_method<std::string>::value << "\n";

    std::cout << "\n";

    std::cout << "=== SFINAE with Custom Traits ===\n";
    std::cout << "\n";
    std::cout << "getSize(vector):\n";
    std::vector<int> v(5);
    getSize(v);
    std::cout << "\n";

    std::cout << "getSize(int):\n";
    getSize(47);
    std::cout << "\n";

    std::cout << "\n";

    std::cout << "=== is_container Trait ===\n";
    std::vector<int> vi;
    std::cout << "std::vector<int> is container: ";
    isContainer(vi);
    std::cout << "\n";
    std::list<double> ld;
    std::cout << "std::list<double> is container: ";
    isContainer(ld);
    std::cout << "\n";
    std::cout << "int is container: ";
    isContainer(47);
    std::cout << "\n";
    std::cout << "std::string is container: ";
    isContainer("yo");
    std::cout << "\n";

    std::cout << "\n";

    std::cout << "SFINAE enables compile-time detection of type properties!\n";

}
