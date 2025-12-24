/*
 * Exercise 1.b.iii — string vs string_view
 * Tag: 1.b.iii string, string_view
 *
 * Create a string and a string_view and print both.
 */

#include <iostream>
#include <string>
#include <string_view>

int main() {

    std::string string = "this is a string";

    /**
     * std::string_view is a class template introduced in C++17
     * that provides read-only access to a sequence of characters
     * without taking ownership of the underlying data.
     */
    std::string_view string_view = string;

    std::cout << string << std::endl;
    std::cout << string_view << std::endl;

}
