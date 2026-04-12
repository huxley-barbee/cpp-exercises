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

#include <chrono>
#include <iostream>
#include <memory>
#include <cmath>
#include <vector>

class ShapeV {
    public:
        virtual double getArea() const = 0;
        virtual ~ShapeV() = default;
};

class CircleV : public ShapeV {
    private:
        int radius;

    public:
        CircleV(int r) : radius(r) { }

        double getArea() const override {
            return radius * radius * M_PI;
        }
};

class RectangleV : public ShapeV {
    private:
        int length;
        int width;

    public:
        RectangleV(int l, int w) : length(l), width(w) { }

        double getArea() const override {
            return length * width;
        }

};

class CircleT {
    private:
        int radius;

    public:
        CircleT(int r) : radius(r) { }

        double getArea() const {
            return radius * radius * M_PI;
        }
};

class CircleTSpecial {
    private:
        int radius;

    public:
        CircleTSpecial(int r) : radius(r) { }

        double getArea() const {
            return radius * radius * M_PI;
        }
};

class RectangleT {
    private:
        int length;
        int width;

    public:
        RectangleT(int l, int w) : length(l), width(w) { }

        double getArea() const {
            return length * width;
        }

};

template <typename T> double getArea(const T& shape){
    return shape.getArea();
}

inline double toMs(auto d) {  // C++20, or use a named duration type
    return std::chrono::duration<double, std::milli>(d).count();
}

template <>
double getArea<CircleTSpecial>(const CircleTSpecial& shape) {
    std::cout << "[specialised: high-precision path] ";
    return shape.getArea();
}

int main() {
    std::cout << "=== Runtime Polymorphism (Virtual Functions) ===\n";
    std::cout << "Processing shapes through base class pointers:\n";

    auto circle = std::make_unique<CircleV>(5);
    std::cout << "Circle area: " << circle->getArea() << "\n";
    auto rectangle = std::make_unique<RectangleV>(5, 4);
    std::cout << "Rectangle area: " << rectangle->getArea() << "\n";

    std::cout << "Runtime dispatch - can store different types in same container\n\n";

    std::cout << "Heterogeneous container (type erasure):\n";
    std::vector<std::unique_ptr<ShapeV>> shapes;
    shapes.push_back(std::make_unique<CircleV>(5));
    shapes.push_back(std::make_unique<RectangleV>(5, 4));
    for (const auto& s : shapes) {
        std::cout << s->getArea() << "\n";
    }

    std::cout << "\n";
    std::cout << "=== Compile-Time Polymorphism (Templates) ===\n";
    std::cout << "Processing shapes through templates:\n";
    CircleT circleT(5);
    RectangleT rectangleT(5, 4);
    std::cout << "Circle area: " << getArea<CircleT>(circleT) << "\n";
    std::cout << "Rectangle area: " << getArea<RectangleT>(rectangleT) << "\n";
    std::cout << "No runtime overhead - types resolved at compile time\n";

    std::cout << "=== Template Specialization ===\n";
    CircleTSpecial specialCircle(5);
    std::cout << "Circle area: " << getArea(specialCircle) << "\n";

    std::cout << "=== Performance Comparison ===\n";
    std::cout << "Virtual function calls (1000000 iterations): ";

    volatile double sink = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (int index = 0; index < 1000000; index++) {
        sink += rectangle->getArea();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto durationVirtual = end - start;
    std::cout << toMs(durationVirtual) << "ms\n";

    std::cout << "Template function calls (1000000 iterations): ";
    start = std::chrono::high_resolution_clock::now();
    for (int index = 0; index < 1000000; index++) {
        sink += getArea<RectangleT>(rectangleT);
    }
    end = std::chrono::high_resolution_clock::now();
    auto durationTemplate = end - start;
    std::cout << toMs(durationTemplate) << "ms\n";

    double multiple = toMs(durationVirtual) / toMs(durationTemplate);

    if (multiple >= 1.0) {
        std::cout << "Templates are ~" << multiple << "x faster (no vtable lookup)\n";
    } else {
        std::cout << "Results inconclusive at this optimisation level\n";
    }

    std::cout <<
        R"EOF(When to use:
- Virtual: Need runtime flexibility, heterogeneous containers
- Templates: Need maximum performance, types known at compile time
)EOF";

}
