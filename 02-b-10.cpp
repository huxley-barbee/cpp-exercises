/*
 * ## EXERCISE 10: Virtual Function Table (vtable) [2.b.ii]
 * 
 * Write a program demonstrating how vtables work.
 * 
 * **Requirements:**
 * 1. Create base and derived classes with virtual functions
 * 2. Print sizes of objects (virtual adds vtable pointer)
 * 3. Show virtual function call overhead
 * 4. Demonstrate vtable pointer in memory layout
 * 5. Show that static and non-virtual functions don't use vtable
 * 
 * **Expected output format:**
 * ```
 * === Virtual Function Table Demo ===
 * 
 * Class without virtual functions:
 * sizeof(NoVirtual): 4 bytes (just int member)
 * 
 * Class with virtual functions:
 * sizeof(WithVirtual): 16 bytes (int + vtable pointer + padding)
 * Vtable pointer adds 8 bytes on 64-bit system
 * 
 * Memory layout:
 * [vtable ptr][member data]
 * 
 * Virtual function call process:
 * 1. Dereference object pointer
 * 2. Load vtable pointer
 * 3. Look up function pointer in vtable
 * 4. Call function through pointer
 * 
 * Non-virtual function call:
 * 1. Direct call (address known at compile time)
 * 
 * Static function call:
 * 1. Direct call (no object needed)
 * 
 * Performance:
 * Virtual call: ~2 indirections
 * Non-virtual call: 0 indirections
 * ```
 */

#include <iostream>

class NoVirtual {
    private:
        int member;
    public:
        void function() {
            // noop
        }
};

class WithVirtual {
    public:
        virtual void function() = 0;
};

class Concrete : public WithVirtual {
    public:
        void function() {
            // noop
        }
};

static void function() {
    // noop
}

int main() {

    std::cout <<
        R"EOF(=== Virtual Function Table Demo ===

Class without virtual functions:
)EOF";

    std::cout << "sizeof(NoVirtual): " << sizeof(NoVirtual) << " bytes (just int member)\n";

    std::cout << "\n";

    std::cout << "Class with virtual functions:\n";
    std::cout << "sizeof(WithVirtual): " << sizeof(WithVirtual) << "bytes (int + vtable pointer + padding)\n";
    std::cout << "Vtable pointer adds 8 bytes on 64-bit system\n";

    std::cout << "Memory layout:\n";
    std::cout << "[";

    Concrete with;
    void*** ptr = (void***)&with;

    std::cout << *ptr;
    std::cout << "][";
    std::cout << **ptr;
    std::cout << "]\n\n";

    std::cout << "Virtual function call process:\n";

    WithVirtual* wv2 = new Concrete();

    std::cout << "1. Dereference object pointer\n";
    std::cout << static_cast<void*>(wv2) << "\n";

    std::cout << "2. Load vtable pointer\n";
    void*** ptr2 = (void***)wv2;
    std::cout << *ptr2 << "\n";

    std::cout << "3. Look up function pointer in vtable\n";
    std::cout << **ptr2 << "\n";

    std::cout << "4. Call function through pointer\n";

    std::cout << "\n";

    std::cout << "Non-virtual function call:\n";
    std::cout << "1. Direct call (address known at compile time)\n";
    NoVirtual no;
    no.function();

    std::cout << "\n\n";
    std::cout << "Static function call:\n";
    std::cout << "1. Direct call (no object needed)\n";

    std::cout <<
        R"EOF(Performance:
Virtual call: ~2 indirections
Non-virtual call: 0 indirections
)EOF";

}
