/*
 * ## EXERCISE 9: Composition vs Inheritance [2.b.i]
 * 
 * Write a program comparing composition and inheritance.
 * 
 * **Requirements:**
 * 1. Show inheritance approach for code reuse
 * 2. Show composition approach for same problem
 * 3. Demonstrate "has-a" vs "is-a" relationship
 * 4. Show flexibility of composition
 * 5. Demonstrate problems with deep inheritance hierarchies
 * 
 * **Expected output format:**
 * ```
 * === Inheritance Approach ===
 * class Car : public Engine, public Wheels {
 *   // Car "is-a" Engine? No - wrong relationship!
 * };
 * 
 * Car (via inheritance):
 * Engine: Starting 2.0L engine
 * Wheels: 4 wheels rolling
 * 
 * Problems:
 * - Car is-a Engine doesn't make logical sense
 * - Tight coupling
 * - Can't easily change engine type at runtime
 * 
 * === Composition Approach ===
 * class Car {
 *   Engine engine;    // Car "has-a" Engine
 *   Wheels wheels;    // Car "has-a" Wheels
 * };
 * 
 * Car (via composition):
 * Engine: Starting 2.0L engine
 * Wheels: 4 wheels rolling
 * 
 * Changing engine at runtime:
 * Engine: Starting 3.5L turbocharged engine
 * Wheels: 4 wheels rolling
 * 
 * Benefits:
 * - Logical "has-a" relationship
 * - Loose coupling
 * - Can swap components
 * - More flexible
 * 
 * Prefer composition over inheritance!
 * ```
 */

#include <iostream>

class Engine {
    public:
        void ignite() {
            std::cout << "Engine: Starting 2.0L engine\n";
        }
};

class TurboEngine : public Engine {
    public:
        void ignite() {
            std::cout << "Engine: Starting 3.5L turbocharged engine\n";
        }
};

class Wheel {
    public:
        void spin() {
            std::cout << "Wheels: 4 wheels rolling\n";
        }

};

class Car : public Engine, public Wheel {
};

class CompositionCar {
    private:
        Engine engine;
        Wheel wheel;


    public:
        Engine getEngine() {
            return engine;
        }
        Engine setEngine(Engine e) {
            return engine = e;
        }
        Wheel getWheel() {
            return wheel;
        }
};

int main() {

    std::cout << "=== Inheritance Approach ===\n";
    std::cout << "class Car : public Engine, public Wheels {\n";
    std::cout << "// Car \"is-a\" Engine? No - wrong relationship!\n";

    std::cout << "\n";

    std::cout << "Car (via inheritance):\n";
    Car car;
    car.ignite();
    car.spin();

    std::cout << "\n";

    std::cout <<
        R"EOF(Problems:
- Car is-a Engine doesn't make logical sense
- Tight coupling
- Can't easily change engine type at runtime


=== Composition Approach ===
class Car {
  Engine engine;    // Car "has-a" Engine
  Wheels wheels;    // Car "has-a" Wheels
};

Car (via composition):
)EOF";

CompositionCar compositionCar;

compositionCar.getEngine().ignite();
compositionCar.getWheel().spin();

std::cout << "\n";

std::cout << "Changing engine at runtime:\n";

TurboEngine turbo;
compositionCar.setEngine(turbo);
compositionCar.getEngine().ignite();
compositionCar.getWheel().spin();

    std::cout <<
        R"EOF(Benefits:
- Logical "has-a" relationship
- Loose coupling
- Can swap components
- More flexible

Prefer composition over inheritance!
)EOF";

}
