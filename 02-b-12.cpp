/*
 * ## EXERCISE 12: Covariant Return Types [2.b.ii]
 * 
 * Write a program demonstrating covariant return types.
 * 
 * **Requirements:**
 * 1. Create base class with virtual method returning Base*
 * 2. Override in derived class to return Derived*
 * 3. Show this is allowed (covariant return)
 * 4. Demonstrate practical use case (clone pattern)
 * 5. Show non-covariant returns not allowed
 * 
 * **Expected output format:**
 * ```
 * === Covariant Return Types ===
 * 
 * Base class method:
 * virtual Base* clone() const
 * 
 * Derived class can override with:
 * virtual Derived* clone() const override
 * 
 * This is allowed because Derived* is-a Base*
 * 
 * Example: Animal cloning
 * Animal* a = new Dog("Buddy");
 * Dog* d = a->clone();  // Returns Dog*, not just Animal*
 * 
 * Cloned dog: Buddy (type: Dog)
 * Original: Buddy (type: Dog)
 * 
 * Clone pattern with covariant returns:
 * - Base returns Base*
 * - Derived returns Derived* (more specific type)
 * - No casting needed!
 * 
 * Without covariant returns:
 * Animal* cloned = a->clone();
 * Dog* d = dynamic_cast<Dog*>(cloned);  // Need cast
 * ```
 */

#include <iostream>
#include <string>

class Animal {
    private:
        std::string name; 

    public:
        Animal(std::string n) : name(n) { }

        std::string getName() {
            return name;
        }

        virtual Animal* clone() {
            return new Animal(*this);
        }
};

class Dog : public Animal {
    public:
        Dog(std::string n) : Animal(n) {
        }
        Dog* clone() override {
            return new Dog(*this);
        }
};

class OtherDog : public Animal {
    public:
        OtherDog(std::string n) : Animal(n) {
        }
};

int main() {

    std::cout <<
        R"EOF(=== Covariant Return Types ===

Base class method:
virtual Base* clone() const

Derived class can override with:
virtual Derived* clone() const override

This is allowed because Derived* is-a Base*
)EOF";

    std::cout << "Example: Animal cloning\n";
    Dog* a = new Dog("Buddy");
    Dog* d = a->clone();  // Returns Dog*, not just Animal*

    std::cout << "Cloned dog: Buddy (type: " << typeid(Dog).name() << ")\n";
    std::cout << "Original: Buddy (type: " << typeid(a).name() << ")\n";

    std::cout << "\n";

    std::cout <<
        R"EOF(Clone pattern with covariant returns:
- Base returns Base*
- Derived returns Derived* (more specific type)
- No casting needed!
)EOF";

    std::cout << "Without covariant returns:\n";
    Animal *b = new OtherDog("Lassie");
    Animal* cloned = b->clone();
    OtherDog* otherDog = dynamic_cast<OtherDog*>(cloned);

}
