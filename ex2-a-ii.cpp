/**
 * Exercise 2.a.ii — RAII
 * Tag: 2.a.ii RAII
 *
 * Create a struct that prints 'acquire' in its constructor and
 * 'release' in its destructor. Instantiate it in a nested scope
 * and print 'in scope' while inside that scope.
 */

#include <iostream>

struct Thing {

    public: 
        Thing() {
            std::cout << "acquire" << std::endl;
        }

        ~Thing() {
            std::cout << "release" << std::endl;
        }
};

int main() {

    {
        Thing thing;

        std::cout << "in scope" << std::endl;
    }

}
