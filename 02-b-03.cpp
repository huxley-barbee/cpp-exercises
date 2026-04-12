/*
 * ## EXERCISE 3: Virtual Functions - Runtime Polymorphism [2.b.ii]
 * 
 * Write a program demonstrating virtual functions and dynamic dispatch.
 * 
 * **Requirements:**
 * 1. Create base class Animal with virtual speak() method
 * 2. Create derived classes: Dog, Cat, Bird
 * 3. Override speak() in each derived class
 * 4. Store different derived types in base class pointers
 * 5. Demonstrate runtime polymorphism (correct method called)
 * 6. Show difference between virtual and non-virtual functions
 * 
 * **Expected output format:**
 * ```
 * === Virtual Function Demo ===
 * Creating animals:
 * Dog created
 * Cat created
 * Bird created
 * 
 * Calling speak() through base class pointers:
 * Dog says: Woof!
 * Cat says: Meow!
 * Bird says: Chirp!
 * 
 * === Non-Virtual Function Demo ===
 * Without virtual: Base speak() called for all
 * Base animal sound
 * Base animal sound
 * Base animal sound
 * 
 * With virtual: Correct derived method called
 * Dog says: Woof!
 * Cat says: Meow!
 * Bird says: Chirp!
 * ```
 */ 

#include <iostream>

class Animal {
    public:
        virtual void speak() {
            std::cout << "Base animal sound\n";
        }

        void non_virt_speak() {
            std::cout << "Base animal sound\n";
        }

        virtual ~Animal() = default;  // Always add this when using virtual functions

};

class Dog : public Animal {
    public:
        Dog() {
            std::cout << "Dog created\n";
        }

        void speak() override {
            std::cout << "Dog says: Woof!\n";
        }
};

class Cat : public Animal {
    public:
        Cat() {
            std::cout << "Cat created\n";
        }

        void speak() override {
            std::cout << "Cat says: Meow!\n";
        }
};

class Bird : public Animal {
    public:
        Bird() {
            std::cout << "Bird created\n";
        }

        void speak() override {
            std::cout << "Bird says: Chirp!\n";
        }
};

int main() {
    std::cout << "=== Virtual Function Demo ===\n"; 


    std::cout << "Creating animals:\n";
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    Animal* bird = new Bird();

    std::cout << "\nCalling speak() through base class pointers:\n";
    dog->speak();
    cat->speak();
    bird->speak();

    std::cout << "\n=== Non-Virtual Function Demo ===\n";
    std::cout << "Without virtual: Base speak() called for all\n";
    dog->non_virt_speak();
    cat->non_virt_speak();
    bird->non_virt_speak();

    std::cout << "\nWith virtual: Correct derived method called\n";
    dog->speak();
    cat->speak();
    bird->speak();
    
    delete dog;
    delete cat;
    delete bird;
}
