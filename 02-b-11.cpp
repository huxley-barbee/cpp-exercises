/*
 * ## EXERCISE 11: Protected vs Private Inheritance [2.b.i]
 * 
 * Write a program demonstrating different inheritance access specifiers.
 * 
 * **Requirements:**
 * 1. Show public inheritance (is-a relationship)
 * 2. Show protected inheritance (implementation detail)
 * 3. Show private inheritance (implemented-in-terms-of)
 * 4. Demonstrate access rules for each
 * 5. Show use cases for each type
 * 
 * **Expected output format:**
 * ```
 * === Public Inheritance ===
 * class Derived : public Base
 * Derived "is-a" Base
 * Base public members are public in Derived
 * Base protected members are protected in Derived
 * 
 * Dog is-a Animal: true
 * Can use Dog as Animal: polymorphism works
 * 
 * === Protected Inheritance ===
 * class Derived : protected Base
 * Base public members become protected in Derived
 * Used for implementation detail (rare)
 * 
 * Stack inherits protected from Vector:
 * Can't access Vector methods outside Stack
 * Can access inside Stack implementation
 * 
 * === Private Inheritance ===
 * class Derived : private Base
 * Base public members become private in Derived
 * "Implemented-in-terms-of" relationship
 * 
 * Stack implemented using Vector (private inheritance):
 * Can't treat Stack as Vector
 * Can't access Vector methods
 * Used for implementation, not interface
 * 
 * Most common: public inheritance (99% of cases)
 * ```
 */

#include <iostream>

class Animal {
    public:

        virtual ~Animal() = default;
};

class Dog : public Animal {
    public:
};

class Vector {
    public:
        int size() {
            // stub
            return 47;
        }
};

class ProtectedStack : protected Vector {

    public:
        int stackSize() {
            return Vector::size();
        }
};

class PrivateStack : private Vector {

    public:
        int stackSize() {
            return Vector::size();
        }
};

int main() {

    std::cout << R"EOF(=== Public Inheritance ===
class Derived : public Base
Derived "is-a" Base
Base public members are public in Derived
Base protected members are protected in Derived
)EOF";

    Dog dog;
    std::cout << "Dog is-a Animal: " << std::boolalpha << (dynamic_cast<Animal *>(&dog) != nullptr) << "\n";
    std::cout << "Can use Dog as Animal: polymorphism works\n";

    std::cout << "\n";

    std::cout << 
        R"EOF(=== Protected Inheritance ===
class Derived : protected Base
Base public members become protected in Derived
Used for implementation detail (rare)
)EOF";

    std::cout <<
        R"EOF(Stack inherits protected from Vector:
Can't access Vector methods outside Stack
Can access inside Stack implementation
)EOF";

    ProtectedStack protectedStack;
    protectedStack.stackSize(); // accessible: compiles fine
    // protectedStack.size();   // inaccessible: would not compile

    std::cout <<
        R"EOF(
=== Private Inheritance ===
class Derived : private Base
Base public members become private in Derived
"Implemented-in-terms-of" relationship
)EOF";

    std::cout <<
        R"EOF(Stack implemented using Vector (private inheritance):
Can't treat Stack as Vector
Can't access Vector methods
Used for implementation, not interface
)EOF";

    PrivateStack privateStack;
    //privateStack.size();


    std::cout << "\n";
    std::cout << "Most common: public inheritance (99% of cases)\n";
}
