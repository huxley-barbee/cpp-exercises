/*
 * ========================================================================
 * EXERCISE 7: Function Overloading [1.a.iv]
 * ========================================================================
 * 
 * Write a program with overloaded 'display' functions:
 * 1. display(int) - prints "Integer: [value]"
 * 2. display(double) - prints "Double: [value]"
 * 3. display(const char*) - prints "String: [value]"
 * 4. display(int, int) - prints "Two integers: [v1], [v2]"
 * 
 * Requirements:
 * Call each version from main() to demonstrate overload resolution.
 * 
 * Expected output format:
 * Integer: 42
 * Double: 3.14
 * String: Hello
 * Two integers: 10, 20
 */ 

#include <iostream>

void display(int num) {
    std::cout << "Integer: " << num << std::endl;
}

void display(double num) {
    std::cout << "Double: " << num << std::endl;
}

void display(const char *s) {
    std::cout << "String: " << s << std::endl;
}

void display(int num1, int num2) {
    std::cout << "Two Integer: " << num1 << ", " << num2 << std::endl;
}

int main () {

    int i = 42;
    double pi = 3.14;
    const char *s = "hello";

    display(i);
    display(pi);
    display(s);
    display(10, 20);
}
