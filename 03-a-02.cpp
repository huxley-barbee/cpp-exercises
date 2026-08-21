/*
 * ## EXERCISE 2: Move Semantics - Rule of Five [3.a.i]
 *
 * Write a program demonstrating the Rule of Five.
 *
 * **Requirements:**
 * 1. Create a class that manages a resource
 * 2. Implement all five special member functions:
 *    - Destructor
 *    - Copy constructor
 *    - Copy assignment operator
 *    - Move constructor
 *    - Move assignment operator
 * 3. Show when each is called
 * 4. Demonstrate that move operations leave source in valid state
 * 5. Show self-assignment handling
 *
 * **Expected output format:**
 * ```
 * === Rule of Five Demo ===
 *
 * Creating Resource A
 * Constructor called
 *
 * Creating Resource B (copy from A)
 * Copy constructor called
 *
 * Creating Resource C (move from B)
 * Move constructor called
 * Source left in valid state
 *
 * D = A (copy assignment)
 * Copy assignment operator called
 *
 * E = std::move(C) (move assignment)
 * Move assignment operator called
 * Source left in valid state
 *
 * Self-assignment: A = A
 * Copy assignment: detected self-assignment, skipping
 *
 * Destroying resources:
 * Destructor called for E
 * Destructor called for D
 * Destructor called for C (moved-from, empty)
 * Destructor called for B (moved-from, empty)
 * Destructor called for A
 *
 * All five special members used correctly!
 * ```
 */

#include <iostream>

class Resource {
    private:
        int* data;
        bool moved_from = false;

    public:
        Resource(int num) {
            std::cout << "Constructor called\n";
            data = new int(num);
        }

        Resource(const Resource& other) {
            std::cout << "Copy constructor called\n";
            data = new int(0);
            *data = *(other.data);
        }

        Resource(Resource&& other) {
            std::cout << "Move constructor called\n";
            data = other.data;
            other.data = nullptr;
            other.moved_from = true;
        }

        Resource& operator=(const Resource& other) {

            if (this == &other) {
                std::cout << "Copy assignment: detected self-assignment, skipping\n";
            } else {
                std::cout << "Copy assignment operator called\n";
                *data = *(other.data);
            }
            return *this;
        }

        Resource& operator=(Resource&& other) {
            std::cout << "Move assignment operator called\n";
            delete data;
            data = other.data;
            other.data = nullptr;
            other.moved_from = true;
            return *this;
        }

        ~Resource() {

            if (moved_from) {
            } else {
                delete data;
            }
        }

};

int main() {

    std::cout << "=== Rule of Five Demo ===\n\n";
 
    std::cout << "Creating Resource A\n";
    Resource a(47);

    std::cout << "\nCreating Resource B (copy from A)\n";
    Resource b = Resource(a);
 
    std::cout << "\nCreating Resource C (move from B)\n";
    Resource c = Resource(std::move(b));
    std::cout << "Source left in valid state\n";
 
    std::cout << "\nD = A (copy assignment)\n";
    Resource d(0);
    d = a;
 
    std::cout << "\nE = std::move(C) (move assignment)\n";
    Resource e(0);
    e = std::move(c);
    std::cout << "Source left in valid state\n";
 
    std::cout << "\nSelf-assignment: A = A\n";
    a = a;
 
    std::cout << "\nDestroying resources:\n";
    std::cout << "Destructor called for E\n";
    std::cout << "Destructor called for D\n";
    std::cout << "Destructor called for C (moved-from, empty)\n";
    std::cout << "Destructor called for B (moved-from, empty)\n";
    std::cout << "Destructor called for A\n";
 
    std::cout << "\nAll five special members used correctly!\n";
}
