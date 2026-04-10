/*
 * ## EXERCISE 7: Polymorphism vs Templates [2.b.v]
 * 
 * Write a program comparing runtime polymorphism and compile-time polymorphism.
 * 
 * **Requirements:**
 * 1. Create polymorphic solution using virtual functions
 * 2. Create template-based solution
 * 3. Compare performance (virtual has runtime overhead)
 * 4. Show when to use each approach
 * 5. Demonstrate type erasure with polymorphism
 * 6. Show template specialization
 * 
 * **Expected output format:**
 * ```
 * === Runtime Polymorphism (Virtual Functions) ===
 * Processing shapes through base class pointers:
 * Circle area: 78.54
 * Rectangle area: 20
 * Runtime dispatch - can store different types in same container
 * 
 * === Compile-Time Polymorphism (Templates) ===
 * Processing shapes through templates:
 * Circle area: 78.54
 * Rectangle area: 20
 * No runtime overhead - types resolved at compile time
 * 
 * === Performance Comparison ===
 * Virtual function calls (1000000 iterations): 45ms
 * Template function calls (1000000 iterations): 12ms
 * Templates are ~3.75x faster (no vtable lookup)
 * 
 * When to use:
 * - Virtual: Need runtime flexibility, heterogeneous containers
 * - Templates: Need maximum performance, types known at compile time
 * ```
 */

#include <iostream>

class ShapeV {
    public:
        virtual double getArea() = 0;
};

class CircleV : public ShapeV {
    private:
        size_t radius;

    public:
        CircleV(size_t r) : radius(r) { }

        double getArea() {
            return radius * radius * 3.14;
        }
};

class RectangleV : public ShapeV {
    private:
        size_t length;
        size_t width;

    public:
        RectangleV(size_t l, size_t w) : length(l), width(w) { }

        double getArea() {
            return length * width;
        }

};

class CircleT {
    private:
        size_t radius;

    public:
        CircleT(size_t r) : radius(r) { }

        double getArea() {
            return radius * radius * 3.14;
        }
};

class RectangleT {
    private:
        size_t length;
        size_t width;

    public:
        RectangleT(size_t l, size_t w) : length(l), width(w) { }

        double getArea() {
            return length * width;
        }

};

template <typename T> double getArea(T shape){
    return shape.getArea();
}


int main() {
    std::cout << "=== Runtime Polymorphism (Virtual Functions) ===\n";
    std::cout << "Processing shapes through base class pointers:\n";

    ShapeV* circle = new CircleV(5);
    std::cout << "Circle area: " << circle->getArea() << "\n";
    ShapeV* rectangle = new RectangleV(4, 5);
    std::cout << "Rectangle area: " << rectangle->getArea() << "\n";

    std::cout << "Runtime dispatch - can store different types in same container\n\n";

    std::cout << "=== Compile-Time Polymorphism (Templates) ===\n";
    std::cout << "Processing shapes through templates:\n";
    CircleT circleT(5);
    RectangleT rectangleT(3, 4);
    std::cout << "Circle area: " << getArea<CircleT>(circleT) << "\n";
    std::cout << "Rectangle area: " << getArea<RectangleT>(rectangleT) << "\n";
    std::cout << "No runtime overhead - types resolved at compile time\n";
}
