/*
 * ## EXERCISE 7: std::string_view - Non-Owning String View [1.b.iii]
 * 
 * Write a program demonstrating string_view efficiency.
 * 
 * **Requirements:**
 * 1. Create a function that takes string_view and prints a substring
 * 2. Call it with: string literal, std::string, and char array
 * 3. Demonstrate zero-copy behavior
 * 4. Show that string_view doesn't own memory (modification of original affects view)
 * 5. Warning: show danger of dangling string_view
 * 
 * **Expected output format:**
 * ```
 * Processing: "Hello, World"
 *   Substring view (0, 5): Hello
 * Processing std::string: "C++ Programming"
 *   Substring view (0, 3): C++
 * Processing char array: "Arrays work too"
 *   Substring view (0, 6): Arrays
 * 
 * Modifying original string:
 * Original changed to: HELLO, World
 * String_view now sees: HELLO, World
 * 
 * WARNING: Dangling string_view detected
 * ```
 */ 

#include <iostream>
#include <string>
#include <string_view>

void print_view(const std::string_view view) {
    int position = view.find(' ');
    std::cout << "Substring view (0, " << position << "): "
        << view.substr(0, position) << std::endl;
}


int main() {

    std::string s2 = "C++ Programming";
    char s3[] = "Arrays work too";

    print_view("Hello World");
    print_view(s2);
    print_view(s3);

    std::cout << "Modifying original string:" << std::endl;
    std::string original = "Hello, World";
    std::string_view v { original };
    std::cout << "View of original is : " << original << std::endl;
    original.replace(0, 5, "HELLO");
    std::cout << "Original changed to: " << original << std::endl;
    std::cout << "Stirng_view now sees : " << v << std::endl;
}
