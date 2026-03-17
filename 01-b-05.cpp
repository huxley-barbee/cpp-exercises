/*
 * ## EXERCISE 5: std::unordered_map - Hash Table [1.b.ii]
 * 
 * Write a program demonstrating unordered_map and comparing with map.
 * 
 * **Requirements:**
 * 1. Create unordered_map<string, int> for word frequencies
 * 2. Insert: "apple"->5, "banana"->3, "cherry"->7, "date"->2
 * 3. Print all entries (note: order is NOT guaranteed)
 * 4. Update "banana" count to 8
 * 5. Use count() to check if "elderberry" exists
 * 6. Print bucket_count and load_factor
 * 7. Compare iteration order with a regular map 
 * 
 * **Expected output format:**
 * ```
 * Word frequencies (unordered):
 * [order varies - hash table doesn't maintain order]
 * cherry: 7
 * apple: 5
 * date: 2
 * banana: 3
 * 
 * After updating banana: 8
 * Elderberry exists: 0 (false)
 * Bucket count: [implementation-dependent]
 * Load factor: [typically < 1.0]
 * 
 * Same data in std::map (ordered):
 * apple: 5
 * banana: 8
 * cherry: 7
 * date: 2
 * ```
 */ 

#include <iostream>
#include <map>
#include <unordered_map>

int main() {

    std::unordered_map<std::string, int> map;

    map["apple"] = 5;
    map["banana"] = 3;
    map["cherry"] = 7;
    map["date"] = 2;

    std::cout << "Word frequencies (unordered):" << std::endl;

    for (const auto record : map) {
        std::cout << record.first << ": " << record.second << std::endl;
    }

    map["banana"] = 8;

    std::cout << "After updating banana: " << map["banana"] << std::endl;

    std::cout << "Elderberry exists: " << map.count("elderberry")
        << std::endl;

    std::cout << "Bucket count: " << map.bucket_count() << std::endl;
    std::cout << "Load factor: " << map.load_factor() << std::endl;

    std::map<std::string, int> ordered_map;

    for (const auto record : map) {
        ordered_map[record.first] = record.second;
    }

    std::cout << "Same data in std::map (ordered):" << std::endl;
    for (const auto record : ordered_map) {
        std::cout << record.first << ": " << record.second << std::endl;
    }
}

