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

class Base {

    protected:
        int protectedMember;

    public:
        int publicMember;

        Base() {
            protectedMember = 42;
            publicMember = 47;
        }

        void printProtected() {
            std::cout << protectedMember;
        }
};

class Derived : public Base {
};

class Animal {
    public:
        void sound() {
            std::cout << "noop";
        }
};

class Dog : public Animal {
    public:
        void sound() {
            std::cout << "bark";
        }
};

class DerivedProtected : protected Base {
};

class Vector {
    public:
        int size() {
            return 47;
        }
};

class ProtectedStack : protected Vector {

    public:
        int stackSize() {
            return Vector::size();
        }
};

class PrivateStack : protected Vector {

    public:
        int stackSize() {
            return Vector::size();
        }
};

int main() {

    std::cout <<
        R"EOF(=== Public Inheritance ===
class Derived : public Base
Derived "is-a" Base
Base public members are public in Derived
Base protected members are protected in Derived
)EOF";

    Derived derived;
    std::cout << derived.publicMember << "\n";
    // std::cout << derived.protectedMember;
    derived.printProtected();
    std::cout << "\n";

    Dog dog;
    std::cout << "Dog is-a Animal: " << dynamic_cast<Animal *>(&dog) << "\n";
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
    // protectedStack.size();
    std::cout << protectedStack.stackSize();

    std::cout <<
        R"EOF(=== Private Inheritance ===
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

    // Vector* privateStack = new PrivateStack();
    PrivateStack privateStack;
    //privateStack.size();


    std::cout << "\n";
    std::cout << "Most common: public inheritance (99% of cases)\n";
}
