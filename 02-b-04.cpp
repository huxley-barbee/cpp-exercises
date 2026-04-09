/*
 * ## EXERCISE 4:  Destructors [2.b.ii]
 * 
 * Write a program demonstrating the importance of virtual destructors.
 * 
 * **Requirements:**
 * 1. Create base class with non-virtual destructor
 * 2. Create derived class with resources to clean up
 * 3. Delete derived object through base pointer
 * 4. Show that derived destructor is NOT called (resource leak)
 * 5. Fix with virtual destructor
 * 6. Show proper cleanup with virtual destructor
 * 
 * **Expected output format:**
 * ```
 * === Without  Destructor (BUG) ===
 * Creating Base
 * Creating Derived (allocating resource)
 * Deleting through Base pointer...
 * ~Base() destructor
 * (Derived destructor NOT called - resource leaked!)
 * 
 * === With  Destructor (CORRECT) ===
 * Creating BaseProper
 * Creating DerivedProper (allocating resource)
 * Deleting through BaseProper pointer...
 * ~DerivedProper() destructor (freeing resource)
 * ~BaseProper() destructor
 * (Proper cleanup - derived destructor called!)
 * 
 * RULE: Always make base class destructor virtual when using polymorphism
 * ```
 */

#include <iostream>

class BaseProper {
    public:
        BaseProper() {
            std::cout << "Creating BaseProper\n";
        }
        ~BaseProper() {
            std::cout << "~BaseProper() destructor\n";
        }
};

class DerivedProper : public BaseProper {
    private:
        int* data;

    public:
        DerivedProper() {
            std::cout << "Creating DerivedProper (allocating resource)\n";
            data = (int*)malloc(sizeof(int));
        }
        ~DerivedProper() {
            std::cout << "~DerivedProper() destructor (freeing resource)\n";
            delete data;
        }
};

class Base {
    public:
        Base() {
            std::cout << "Creating Base\n";
        }
        ~Base() {
            std::cout << "~Base() destructor\n";
        }
};

class Derived : public Base {
    private:
        int* data;

    public:
        Derived() {
            std::cout << "Creating Derived (allocating resource)\n";
            data = (int*)malloc(sizeof(int));
        }
        ~Derived() {
            delete data;
        }
};

int main() {
    std::cout << "=== Without Destructor (BUG) ===\n";
    Base* base = new Derived();
    std::cout << "Deleting through Base pointer...\n";
    delete base;
    std::cout << "(Derived destructor NOT called - resource leaked)\n\n";

    std::cout << "=== With Destructor (CORRECT) ===\n";
    BaseProper* proper = new DerivedProper;
    std::cout << "Deleting through BaseProper pointer...\n";
    delete proper;
    std::cout << "(Proper cleanup - derived destructor called!)\n\n";

    std::cout << "RULE: Always make base class destructor virtual when using polymorphism\n";
}

