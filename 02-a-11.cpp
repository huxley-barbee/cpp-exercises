/*
 * ## EXERCISE 11: Object Lifetime - Copy Elision and RVO [2.a.v]
 * 
 * Write a program demonstrating copy elision and Return Value Optimization.
 * 
 * **Requirements:**
 * 1. Create class that tracks copy and move operations
 * 2. Return object by value from function
 * 3. Show RVO eliminates copy
 * 4. Pass object by value
 * 5. Compare with C++11 move semantics
 * 6. Show when copies actually occur
 * 
 * **Expected output format:**
 * ```
 * === Return Value Optimization (RVO) ===
 * Creating object in factory
 * Constructed: Object_1
 * (No copy - RVO optimizes away)
 * Received object: Object_1
 * 
 * === Copy vs Move ===
 * Creating object for passing
 * Constructed: Object_2
 * 
 * Passing by value (pre-C++11 would copy):
 * Copy constructor: Object_2 -> Object_3
 * Function received: Object_3
 * Destructor: Object_3
 * 
 * With move semantics:
 * Move constructor: Object_2 -> Object_4
 * Function received: Object_4
 * Destructor: Object_4
 * 
 * Destructor: Object_2
 * Destructor: Object_1
 * 
 * Modern C++ minimizes copies with RVO and move semantics!
 * ```
 */

#include <iostream>
#include <string>

class Thing {
    private:
        int index;

    public:
        std::string getName() const {
            return "Object_" + std::to_string(index);
        }

        Thing(const int n) : index(std::move(n)) {
            std::cout << "Constructed: " << getName() << std::endl;
        }

        Thing(const Thing& other) : index(other.index+1) {
            std::cout << "Copy constructor: " << other.getName() << " -> " <<
                getName() << std::endl;
        }

        Thing(Thing&& other) : index(other.index+2) {
            std::cout << "Move constructor: " << other.getName() << " -> " <<
                getName() << std::endl;
        }

        ~Thing() {
            std::cout << "Destructor: " << getName() << std::endl;
        }
};

Thing make_thing(const int index) {
    /* Typically, this return value will copied across the call stack.
     * With RVO, instead, it's the same address location in this scope and the
     * scope outside of it.
     */
    return Thing(index);
}

void do_something(Thing thing) {
    std::cout << "Function received: " << thing.getName() << std::endl;
}

int main() {
    std::cout << "=== Return Value Optimization (RVO) ===" << std::endl;
    std::cout << "Creating object in factory" << std::endl;
    Thing thing1 = make_thing(1);
    std::cout << "(No copy - RVO optimizes away)" << std::endl;
    std::cout << "Received object: " << thing1.getName() << std::endl;

    std::cout << std::endl;

    std::cout << "=== Copy vs Move ===" << std::endl;
    std::cout << "Creating object for passing " << std::endl;
    Thing thing2(2);

    std::cout << std::endl;

    std::cout << "Passing by value (pre-C++11 would copy):" << std::endl;
    do_something(thing2);

    std::cout << std::endl;

    std::cout << "With move semantics:" << std::endl;
    do_something(std::move(thing2));

    std::cout << "Modern C++ minimizes copies with RVO and move semantics!" << std::endl;


}
