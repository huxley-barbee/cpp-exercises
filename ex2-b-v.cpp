/**
 * Exercise 2.b.v — Polymorphism
 * Tag: 2.b.v polymorphism
 *
 * Create a base class with a virtual function speak() returning 'base'.
 * Override it in a derived class returning 'derived'.
 * Call through base reference.
 */

#include <iostream>
#include <string>

class Thing {

    public:
        virtual std::string speak() {
            return "base";
        }
};

class SubThing : public Thing {

    public:
        std::string speak() {
            return "derived";
        }
};

int main() {
    SubThing *sub = new SubThing();
    Thing *thing = sub;
    std::cout << thing->speak() << std::endl;
}
