/*
 * ## EXERCISE 10: Object Lifetime - Constructor/Destructor Order [2.a.v]
 * 
 * Write a program demonstrating object construction and destruction order.
 * 
 * **Requirements:**
 * 1. Create class that prints in constructor and destructor
 * 2. Create global, static, local, and member objects
 * 3. Show construction order: global -> static -> local -> members
 * 4. Show destruction order: reverse of construction
 * 5. Demonstrate with nested objects and inheritance
 * 
 * **Expected output format:**
 * ```
 * [Before main]
 * Global object constructed
 * 
 * [Entering main]
 * Static object constructed (first call to function)
 * 
 * Local object 1 constructed
 *   Member object constructed
 *   Composite object constructed
 * Local object 2 constructed
 * 
 * [Leaving scope]
 * Local object 2 destroyed
 * Composite object destroyed
 *   Member object destroyed
 * Local object 1 destroyed
 * 
 * [After main]
 * Static object destroyed
 * Global object destroyed
 * 
 * Construction order: Global -> Static -> Local -> Members
 * Destruction order: Reverse (LIFO - stack unwinding)
 * ```
 */

#include <iostream>
#include <string>

class Lifetime {
    private:
        std::string name;

    public:
        Lifetime(const std::string& n) : name(n) {
            std::cout << "\t" << name << " created" << std::endl;
        }

        ~Lifetime() {
            std::cout << "\t" << name << " destroyed" << std::endl;
        }
};

class Composite {
    private:
        Lifetime lifetime;
        std::string name;

    public:
        Composite(const std::string& n) : lifetime("member object"), name(n) {
            std::cout << "\t" << name << " created" << std::endl;
        }

        ~Composite() {
            std::cout << "\t" << name << " destroyed" << std::endl;
        }

};


Lifetime global("global");

void fn() {
    static Lifetime staticObj("static");
}

int main() {
    std::cout << "in main" << std::endl;

    fn();
    fn();

    Lifetime local1("local 1");

    Composite composite("composite");

    Lifetime local2("local 2");

    std::cout << "leaving main" << std::endl;
}
