/**
 * Exercise 2.a.v — Object Lifetime
 * Tag: 2.a.v object lifetime
 *
 * Create a struct that prints 'construct' in its constructor
 * and 'destroy' in its destructor. Create one instance in main
 * and one in a nested scope.
 */

#include <iostream>

struct Thing {
    private:
        std::string name;

    public:
        Thing(std::string n) {
            name = n;
            std::cout << "construct " << name << std::endl;
        }
        ~Thing() {
            std::cout << "destroy " << name << std::endl;
        }
};

int main() {

    Thing thing_one("one");

    {
        Thing thing_two("two");
    }

}
