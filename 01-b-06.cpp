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

    std::cout << "Length: " << hello.length() << ", Size: "
        << hello.size() << std::endl;

    std::cout << "Character at index 6: " << hello[6] << std::endl;

    std::string sub = hello.substr(6);

    std::cout << "Substring from index 6, length " << sub.size() << " "
        << sub << std::endl;

    int position = hello.find('W');
    std::cout << "Position of 'W': " << position << std::endl;

    hello.replace(position, 5, "C++");

    std::cout << "After replace: " << hello << std::endl;

    std::cout << "Comparison Hello and Hello: "
        << std::string("Hello").compare("Hello") << std::endl;

    std::cout << "Comparison Hello and World: "
        << std::string("Hello").compare("World") << std::endl;
}
