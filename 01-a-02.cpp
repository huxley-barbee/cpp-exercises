/**
* =========================================================================
* EXERCISE 2: Type System and Conversions [1.a.i]
* =========================================================================
* 
* Write a program that explores C++ type sizes and conversions.
* 
* Requirements:
* 1. Print sizeof() for: char, short, int, long, long long, float, double
* 2. Demonstrate implicit conversion: assign 3.7 to an int, print the result
* 3. Demonstrate explicit casting: convert int 65 to char, print as character
* 4. Show integer division: 7/2 and explicitly cast to show 7.0/2
* 5. Demonstrate unsigned overflow: unsigned char = 255, add 1, print result
* 
* Expected output format:
* sizeof(char): 1
* sizeof(short): 2
* sizeof(int): 4
* sizeof(long): [system-dependent]
* sizeof(long long): 8
* sizeof(float): 4
* sizeof(double): 8
* Implicit conversion 3.7 to int: 3
* Char cast of 65: A
* Integer division 7/2: 3
* Float division 7.0/2: 3.5
* Unsigned overflow 255+1: 0
*/ 

#include <iostream>

int main() {

    std::cout << "sizeof(char)" << sizeof(char) << std::endl;
    std::cout << "sizeof(short)" << sizeof(short) << std::endl;
    std::cout << "sizeof(int)" << sizeof(int) << std::endl;
    std::cout << "sizeof(long)" << sizeof(long) << std::endl;
    std::cout << "sizeof(long long)" << sizeof(long long) << std::endl;
    std::cout << "sizeof(float)" << sizeof(float) << std::endl;
    std::cout << "sizeof(double)" << sizeof(double) << std::endl;

    /* this does not compile. there is an error */
    //int intFromFloat = 3.7;
    //std::cout << "int from float is " << intFromFloat << std::endl;

    char charFromInt = (char)65;
    std::cout << "charFromInt is " << charFromInt << std::endl;

    std::cout << "7/2 is " << 7/2 << std::endl;

    std::cout << "7/2 as float is " << (float)7/2 << std::endl;

    unsigned char max = 255;
    max++;
    std::cout << "overflow is " << (int)max << std::endl;

}
