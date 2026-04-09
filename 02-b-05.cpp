/*
 * ## EXERCISE 5: Abstract Classes and Pure Virtual Functions [2.b.iii]
 * 
 * Write a program demonstrating abstract classes.
 * 
 * **Requirements:**
 * 1. Create abstract class Shape with pure virtual methods:
 *    - getArea() = 0
 *    - getPerimeter() = 0
 *    - draw() = 0
 * 2. Create concrete classes: Square, Triangle
 * 3. Show that abstract class cannot be instantiated
 * 4. Implement all pure virtual functions in derived classes
 * 5. Use abstract class as interface
 * 
 * **Expected output format:**
 * ```
 * Cannot instantiate abstract class (compile error if uncommented)
 * // Shape shape; // ERROR
 * 
 * Creating concrete shapes:
 * Square created: side=5
 * Triangle created: base=4, height=3, sides=3,4,5
 * 
 * Square:
 *   Area: 25
 *   Perimeter: 20
 *   Drawing: ■■■■■
 * 
 * Triangle:
 *   Area: 6
 *   Perimeter: 12
 *   Drawing: △
 * 
 * Abstract class used as interface for polymorphism
 * Shape 1 area: 25
 * Shape 2 area: 6
 * ```
 */

#include <cmath>
#include <iostream>

class Shape {
    public:
        virtual double getArea() = 0;
        virtual double getPerimeter() = 0;
        virtual void draw() = 0;
};

class Square : public Shape {
    private:
        size_t size;

    public:
        Square(size_t s) : size(s) { }

        double getArea() {
            return size * size;
        }

        double getPerimeter() {
            return 4 * size;
        }

        void draw() {
            for (int index = 0; index < size; index++) {
                std::cout << "■";
            }
        }
};

class Triangle : public Shape {
    private:
        size_t base;
        size_t height;

    public:
        Triangle(size_t b, size_t h) : base(b), height(h) { }

        double getArea() {
            return 0.5 * base * height;
        }

        double getPerimeter() {
            double third = std::sqrt(base * base + height * height);
            return base + height + third;
        }

        void draw() {
            std::cout << "△";
        }
};

int main() {

    std::cout << "Cannot instantiate abstract class (compile error if uncommented)\n";
    // Shape shape; // ERROR

    std::cout << "Creating concrete shapes:\n";
    Square square = Square(5);
    std::cout << "Square created: side=5\n";
    Triangle triangle = Triangle(3, 4);
    std::cout << "Triangle created: base=4, height=3, sides=3,4,5\n\n";

    std::cout << "Square:\n";
    std::cout << " Area: " << square.getArea() << "\n";
    std::cout << " Perimeter: " << square.getPerimeter() << "\n";
    std::cout << " Drawing: ";
    square.draw();
    std::cout << "\n\n";

    std::cout << "Triangle:\n";
    std::cout << " Area: " << triangle.getArea() << "\n";
    std::cout << " Perimeter: " << triangle.getPerimeter() << "\n";
    std::cout << " Drawing: ";
    triangle.draw();
    std::cout << "\n\n";
 
    std::cout << "Abstract class used as interface for polymorphism\n";
    Shape* one = new Square(5);
    Shape* two = new Triangle(3, 4);
    std::cout << "Shape 1 area: " << one->getArea() << "\n";
    std::cout << "Shape 2 area: " << two->getArea() << "\n";

}
