/**
 * Exercise 2.b.ii — Copy Semantics
 * Tag: 2.b.ii copy semantics
 *
 * Create a struct that prints 'copy' in its copy constructor.
 * Create an object and copy it.
 */

#include <iostream>

struct Thing {

    private:
        int data;

    public:
        Thing() {
            std::cout << "construct" << std::endl;
        }
        Thing(const Thing &obj) {
            std::cout << "copy" << std::endl;
            data = obj.data;
        }
};

int main() {
    Thing thing1;
    Thing thing2(thing1);
}
