/*
 * ## EXERCISE 12: CRTP (Curiously Recurring Template Pattern) [2.c.ii]
 * 
 * Write a program demonstrating CRTP.
 * 
 * **Requirements:**
 * 1. Create base class template that takes derived class as parameter
 * 2. Implement static polymorphism with CRTP
 * 3. Compare with virtual function overhead
 * 4. Show interface enforcement without vtable
 * 5. Demonstrate compile-time polymorphism benefits
 * 
 * **Expected output format:**
 * ```
 * === CRTP Demo ===
 * 
 * template<typename Derived>
 * class Base {
 *     void interface() {
 *         static_cast<Derived*>(this)->implementation();
 *     }
 * };
 * 
 * class Derived : public Base<Derived> {
 */
 //     void implementation() { /* ... */ }
 /* };
 * 
 * === Static Polymorphism ===
 * Calling through CRTP:
 * Dog implementation: Woof!
 * Cat implementation: Meow!
 * 
 * No virtual functions - direct call at compile time!
 * 
 * === Performance Comparison ===
 * Virtual function calls (1M iterations): 45ms
 * CRTP calls (1M iterations): 12ms
 * CRTP is ~3.75x faster (no vtable lookup)
 * 
 * === Use Cases ===
 * - Need polymorphism without runtime overhead
 * - Interface enforcement at compile time
 * - Mixin classes
 * - Static polymorphism
 * 
 * CRTP: compile-time polymorphism without virtual functions!
 * ```
 */

#include <iomanip>
#include <iostream>
#include <chrono>
#include <cmath>


template <typename Derived>
class Animal {
public:
    void speak() {
        static_cast<Derived*>(this)->speak_impl();
    }
};

class Dog : public Animal<Dog> {
public:
    void speak_impl() { std::cout << "Woof!\n"; }
};

class Cat : public Animal<Cat> {
public:
    void speak_impl() { std::cout << "Meow!\n"; }
};

class RegularBase {
    public:
        virtual void speak() = 0;
};

class RegularDog : RegularBase {
    public:
        void speak() override {
            std::cout << "Woof!\n";
        }
};

int main() {
    std::cout <<
        R"EOF(=== CRTP Demo ===

template<typename Derived>
class Base {
    void interface() {
        static_cast<Derived*>(this)->implementation();
    }
};

class Derived : public Base<Derived> {

     void implementation() { /* ... */ }
};

=== Static Polymorphism ===
Calling through CRTP:
)EOF";

    Dog *dog = new Dog();
    Cat *cat = new Cat();

    std::cout << "Dog implementation: ";
    dog->speak();
    std::cout << "Cat implementation: ";
    cat->speak();

    std::cout <<
        R"EOF(
No virtual functions - direct call at compile time!

=== Performance Comparison ===
)EOF";

    RegularDog *regularDog = new RegularDog();

    auto t1 = std::chrono::high_resolution_clock::now();
    for (int index = 0; index < 1000000; index++) {
        regularDog->speak();
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto diff_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

    std::cout << "Virtual function calls (1M iterations): " << diff_ms1 << "ms\n";

    auto t3 = std::chrono::high_resolution_clock::now();
    for (int jndex = 0; jndex < 1000000; jndex++) {
        dog->speak();
    }
    auto t4 = std::chrono::high_resolution_clock::now();
    auto diff_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3).count();

    std::cout << "CRTP calls (1M iterations): " << diff_ms2 << "ms\n";

    std::cout << "CRTP is ~" << std::fixed << std::setprecision(2) << (double)diff_ms1 / diff_ms2 << "x faster (no vtable lookup)\n";

    std::cout <<
        R"EOF(
=== Use Cases ===
- Need polymorphism without runtime overhead
- Interface enforcement at compile time
- Mixin classes
- Static polymorphism

CRTP: compile-time polymorphism without virtual functions!
)EOF";

}
