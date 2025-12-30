/**
 * Exercise 2.b.iv — Virtual Destructors
 * Tag: 2.b.iv virtual destructor
 *
 * Create a base class with a virtual destructor that prints
 * 'base destroy' and a derived class that prints 'derived destroy'.
 * Delete via base pointer.
 */

#include <iostream>

class Thing {
    public:
        virtual ~Thing() {
            std::cout << "base destroy" << std::endl;
        }
};

class SubThing : public Thing {

    public: 
        ~SubThing() {
            std::cout << "derived destroy" << std::endl;
        }
};

int main() {

    SubThing *sub = new SubThing();
    Thing *thing = sub;

    delete thing;

}
