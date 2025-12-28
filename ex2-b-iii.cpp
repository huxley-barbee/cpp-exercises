/**
 * Exercise 2.b.iii — Move Semantics
 * Tag: 2.b.iii move semantics
 *
 * Create a struct that prints 'move' in its move constructor.
 * Move-construct an object.
 *
 * Compile with: g++ -std=c++11 ex2-b-iii.cpp
 */

#include <iostream>

struct Thing {
    
    private:
        int *data;

    public:

        Thing(int value) {
            data = new int (value);
        }

        Thing(Thing&& source) {
            data = source.data;
            source.data = nullptr;
            std::cout << "move" << std::endl;
        }

        ~Thing() {
            delete data;
        }

};

int main() {
    Thing one(47);
    Thing two = std::move(one);
}
