/*
 * ## EXERCISE 2: Inheritance - Basic Hierarchy [2.b.i]
 * 
 * Write a program demonstrating single inheritance.
 * 
 * **Requirements:**
 * 1. Create base class Shape with:
 *    - Protected member: name
 *    - Public method: getName()
 *    - Public virtual method: getArea()
 * 2. Create derived classes: Rectangle, Circle
 * 3. Each derived class overrides getArea()
 * 4. Demonstrate "is-a" relationship
 * 5. Show access to protected members in derived classes
 * 
 * **Expected output format:**
 * ```
 * Creating shapes:
 * Rectangle: width=5, height=3
 * Circle: radius=4
 * 
 * Shape information:
 * Name: Rectangle
 * Area: 15
 * 
 * Name: Circle
 * Area: 50.2655
 * 
 * Rectangle is-a Shape: true
 * Can access protected 'name' in derived class
 * Cannot access protected 'name' from outside class
 * ```
 */

#include <iostream>
#include <string>

class Shape {
    protected:
        std::string name;

    public:

        Shape(std::string n) : name(n) { }

        std::string getName() {
            return name;
        }

        virtual double getArea() = 0;

        virtual ~Shape() = default;
};

class Rectangle : public Shape {
    private:
        int length;
        int width;

    public:
        Rectangle(std::string n, int l, int w) : Shape(n), length(l), width(w) { }

        double getArea() {
            return length * width;
        }

        void test() {

            std::cout << "Can access protected 'name' in derived class\n";

        }
};

class Circle : public Shape {
    private:
        int radius;

    public:
        Circle(std::string n, int r) : Shape(n), radius(r) { }

        double getArea() {
            return radius * radius * 3.14;
        }
};

int main() {
    std::cout << "Creating shapes:\n";
    std::cout << "Rectangle: width=5, height=3\n";
    Rectangle rectangle = Rectangle("Rectangle", 5, 3);
    std::cout << "Circle: radius=4\n";
    Circle circle = Circle("Circle", 4);

    std::cout << "\n\n";

    std::cout << "Shape information:\n";
    std::cout << "Name: " << rectangle.getName() << "\n";
    std::cout << "Area: " << rectangle.getArea() << "\n";
    std::cout << "\n";
    std::cout << "Name: " << circle.getName() << "\n";
    std::cout << "Area: " << circle.getArea() << "\n";

    if (dynamic_cast<Shape *>(&rectangle)) {
        std::cout << "Rectangle is-a Shape: true\n";
    }

    rectangle.test();

    std::cout << "Cannot access protected 'name' from outside class\n";
    //rectangle.name;


}
