/*
 * ## EXERCISE 9: Range-Based For Loops [1.b.iv]
 * 
 * Write a program demonstrating range-based for loops.
 * 
 * **Requirements:**
 * 1. Create vector of strings: {"one", "two", "three"}
 * 2. Iterate by value (copies elements)
 * 3. Iterate by const reference (read-only, no copies)
 * 4. Iterate by reference (can modify elements)
 * 5. Demonstrate with map (structured bindings in C++17)
 * 6. Use auto for type deduction 
 * 
 * **Expected output format:**
 * ```
 * Iterating by value:
 *   one two three
 * Iterating by const reference:
 *   one two three
 * Modifying via reference (converting to uppercase):
 * Before: one two three
 * After: ONE TWO THREE
 * 
 * Iterating map with structured bindings:
 * Alice: 25
 * Bob: 30
 * Charlie: 35
 * ```
 */ 

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cctype>

int main() {

    std::vector<std::string> numbers = { "one", "two", "three" };

    std::cout << "Iterating by value:" << std::endl;
    for (auto it : numbers) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterating by const reference:" << std::endl;
    for (const auto& it : numbers) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    std::cout << "Modifying via by reference (converting to uppercase):"
        << std::endl;
    std::cout << "Before: ";
    bool first = true;
    for (const auto& it : numbers) {
        if (!first) {
            std::cout << " ";
        }
        first = false;
        std::cout << it;
    }
    std::cout << std::endl;

    std::cout << "After: ";
    first = true;
    for (auto& it : numbers) {
        for (auto& ch : it) {
            ch = std::toupper(static_cast<unsigned char>(ch));
        }

        if (!first) {
            std::cout << " ";
        }
        first = false;
        std::cout << it;
    }
    std::cout << std::endl;

    std::map<std::string, int> ages;
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages["Charlie"] = 35;

    std::cout << "Iterating through maps with structure bindings:"
        << std::endl;
    for (const auto& [name, age] : ages) {
        std::cout << name << ": " << age << std::endl;
    }

}
