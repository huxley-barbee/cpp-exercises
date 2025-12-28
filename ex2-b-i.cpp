/**
 * Exercise 2.b.i — Constructors and Destructors
 * Tag: 2.b.i constructors destructors
 * 
 * Create a struct that prints 'construct' in its constructor and
 * 'destroy' in its destructor. Create one instance in main.
 */

#include <iostream>

struct Thing {
    public:
        Thing() {
            std::cout << "construct" << std::endl;
        }
        
        ~Thing() {
            std::cout << "destroy" << std::endl;
        }
};

int main() {
    Thing thing;
}
