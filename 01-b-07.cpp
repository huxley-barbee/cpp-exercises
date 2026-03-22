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

    auto pos = std::min(view.find(' '), view.find(','));

    if (pos == std::string_view::npos) {
        return;
    }

    std::cout << "Substring view (0, " << pos << "): "
        << view.substr(0, pos) << std::endl;
}

std::string_view dangling() {
    std::string temp = "I won't survive";
    return temp; // temp destroyed here — returned view is dangling
}

int main() {

    std::string s2 = "C++ Programming";
    char s3[] = "Arrays work too";

    std::cout << "Processing: \"Hello, World\"" << std::endl;
    print_view("Hello, World");
    std::cout << "Processing std::string: \"C++ Programming\"" << std::endl;
    print_view(s2);
    std::cout << "Processing char array: \"Arrays work too\"" << std::endl;
    print_view(s3);

    std::cout << "Modifying original string:" << std::endl;
    std::string original = "Hello, World";
    std::string_view v = original;
    std::cout << "View of original is: " << original << std::endl;
    std::cout << "Original addr:    " << static_cast<const void*>(original.data()) << "\n";
    std::cout << "string_view addr: " << static_cast<const void*>(v.data()) << "\n";


    original[0] = 'H';
    original[1] = 'E';
    original[2] = 'L';
    original[3] = 'L';
    original[4] = 'O';

    std::cout << "Original changed to: " << original << std::endl;
    std::cout << "String_view now sees : " << v << std::endl;


    std::string_view v2 = dangling();
    // Accessing v2 here is UB — the string it pointed to is destroyed
    // std::cout << v2; // DO NOT do this — shown here only to illustrate the danger
    std::cout << "WARNING: Dangling string_view detected\n";
    std::cout << "  v2 points to freed memory — accessing it is undefined behavior\n";

}
