/*
 * ## EXERCISE 4: std::map - Ordered Associative Container [1.b.ii]
 * 
 * Write a program using std::map for a phone book.
 * 
 * **Requirements:**
 * 1. Create map<string, string> for name->phone mapping
 * 2. Insert entries: Alice->555-1234, Bob->555-5678, Charlie->555-9012
 * 3. Access Bob's number using []
 * 4. Try to access David's number (will create empty entry)
 * 5. Use find() to safely check if "Eve" exists
 * 6. Iterate through map (should be alphabetically ordered by key)
 * 7. Erase Charlie's entry
 * 8. Print final size
 * 
 * **Expected output format:**
 * ```
 * Bob's phone: 555-5678
 * David's phone (auto-created): 
 * Eve found: No
 * Phone book (alphabetically ordered):
 * Alice: 555-1234
 * Bob: 555-5678
 * Charlie: 555-9012
 * David: 
 * After erasing Charlie:
 * Alice: 555-1234
 * Bob: 555-5678
 * David: 
 * Final size: 3
 * ```
 */ 

#include <iostream>
#include <map>

int main() {

    std::map<std::string, std::string> map;

    map["Alice"] = "555-1234";
    map["Bob"] = "555-5678";
    map["Charlie"] = "555-9012";

    std::cout << "Bob's phone: " << map["Bob"] << std::endl;

    std::cout << "David's phone (auto-created): " << map["David"]
        << std::endl;

    if (map.find("Eve") != map.end()) {
        std::cout << "Eve found: No" <<  std::endl;
    }

    for (const auto record : map) {
        std::cout << record.first << ": " << record.second << std::endl;
    }

    map.erase("Charlie");

    std::cout << "After erasing Charlie:" << std::endl;

    for (const auto record : map) {
        std::cout << record.first << ": " << record.second << std::endl;
    }

    std::cout << "Final size: " << map.size() << std::endl;
}
