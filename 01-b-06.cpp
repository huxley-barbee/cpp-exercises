/*
 * ## EXERCISE 6: std::string - Basic Operations [1.b.iii]
 * 
 * Write a program demonstrating string operations.
 * 
 * **Requirements:**
 * 1. Create string "Hello"
 * 2. Append " World" using +=
 * 3. Get length using both size() and length()
 * 4. Access individual characters with []
 * 5. Use substr() to extract "World"
 * 6. Find position of 'W' using find()
 * 7. Replace "World" with "C++" using replace()
 * 8. Compare two strings with == and compare()
 * 
 * **Expected output format:**
 * ```
 * Original: Hello
 * After append: Hello World
 * Length: 11 (size and length are the same)
 * Character at index 6: W
 * Substring from index 6, length 5: World
 * Position of 'W': 6
 * After replace: Hello C++
 * Comparison "Hello" == "Hello": true
 * Comparison "Hello".compare("World"): negative value
 * ```
 */ 

#include <iostream>
#include <string>

int main() {

    std::string hello = "Hello";

    std::cout << "Original: " << hello << std::endl;

    hello += " World";

    std::cout << "After append: " << hello << std::endl;

    std::cout << "Length: " << hello.length() << " (size and length are the same)"
        << std::endl;

    std::cout << "Character at index 6: " << hello[6] << std::endl;

    std::string sub = hello.substr(6);

    std::cout << "Substring from index 6, length " << sub.size() << ": "
        << sub << std::endl;

    size_t position = hello.find('W');
    std::cout << "Position of 'W': " << position << std::endl;

    hello.replace(position, 5, "C++");

    std::cout << "After replace: " << hello << std::endl;

    std::cout << "Comparison \"Hello\" == \"Hello\": "
          << std::boolalpha << (std::string("Hello") == "Hello")
          << std::endl;

    int cmp = std::string("Hello").compare("World");
    std::cout << "Comparison \"Hello\".compare(\"World\"): "
          << (cmp < 0 ? "negative value" : (cmp > 0 ? "positive value" : "0"))
          << std::endl;

}
