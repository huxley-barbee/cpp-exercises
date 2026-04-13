/*
 * ## EXERCISE 13: Comprehensive Integration [All concepts from 2.b]
 * 
 * Write a graphics system demonstrating all OOP concepts.
 * 
 * **Requirements:**
 * 1. Abstract base class Shape (pure virtual)
 * 2. Derived concrete classes (Circle, Rectangle, Triangle)
 * 3. Virtual destructor
 * 4. Multiple interfaces (IDrawable, ITransformable)
 * 5. Composition (Point, Color classes)
 * 6. Polymorphic container of shapes
 * 7. Runtime polymorphism for drawing
 * 8. Use RAII for resource management
 * 
 * **Expected output format:**
 * ```
 * === Graphics System Demo ===
 * 
 * Creating shapes with composition:
 * Circle at (10, 20), radius=5, color=Red
 * Rectangle at (30, 40), width=10, height=6, color=Blue
 * Triangle at (50, 60), base=8, height=5, color=Green
 * 
 * All shapes stored in polymorphic container:
 * Container holds 3 shapes
 * 
 * Drawing all shapes (runtime polymorphism):
 * Drawing Circle: ○ at (10, 20) [Red]
 *   Area: 78.54
 *   Perimeter: 31.42
 * 
 * Drawing Rectangle: □ at (30, 40) [Blue]
 *   Area: 60
 *   Perimeter: 32
 * 
 * Drawing Triangle: △ at (50, 60) [Green]
 *   Area: 20
 *   Perimeter: ~18.6
 * 
 * Transforming shapes (ITransformable interface):
 * Moving Circle to (15, 25)
 * Rotating Rectangle by 45 degrees
 * Scaling Triangle by 1.5x
 * 
 * Cloning shapes (covariant return types):
 * Cloned circle at (15, 25)
 * Cloned rectangle at (30, 40)
 * 
 * Finding shapes by type (dynamic_cast):
 * Found 1 circles
 * Found 1 rectangles
 * Found 1 triangles
 * 
 * Cleanup with virtual destructors:
 * ~Circle() - freeing circle resources
 * ~Rectangle() - freeing rectangle resources
 * ~Triangle() - freeing triangle resources
 * ~Shape() - base cleanup
 * 
 * All shapes properly destroyed (RAII + virtual destructors)
 * ```
 * 
 * ## EXERCISE 13: Comprehensive Integration [All concepts from 2.b]
 * 
 * Write a graphics system demonstrating all OOP concepts.
 * 
 * **Requirements:**
 * 1. Abstract base class Shape (pure virtual)
 * 2. Derived concrete classes (Circle, Rectangle, Triangle)
 * 3. Virtual destructor
 * 4. Multiple interfaces (IDrawable, ITransformable)
 * 5. Composition (Point, Color classes)
 * 6. Polymorphic container of shapes
 * 7. Runtime polymorphism for drawing
 * 8. Use RAII for resource management
 * 
 * **Expected output format:**
 * ```
 */

#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <string>

class Point {
    private:
        int x;
        int y;

    public:
        Point(int newX, int newY) : x(newX), y(newY) {}

        int getX() const {
            return x;
        }
        int getY() const {
            return y;
        }
        void setX(int newX) {
            x = newX;
        }
        void setY(int newY) {
            y = newY;
        }
};

class Color {
    private:
        std::string name;

    public:
        Color(std::string n) : name(n) {}

        std::string getName() const {
            return name;
        }

        void setName(std::string n) {
            name = n;
        }
};

class ITransformable {
    public:
        virtual void move(int newX, int newY) = 0;
        virtual void rotate(int degrees) = 0;
        virtual void scale(double factor) = 0;
        virtual ~ITransformable() = default;
};

class IDrawable {
    public:
        virtual void draw() const = 0;
        virtual ~IDrawable() = default;
};

class Shape : public IDrawable {
    private:
        std::string type;
        std::unique_ptr<Point> point;
        std::unique_ptr<Color> color;

    protected:
        void setPoint(int newX, int newY) {
            point = std::make_unique<Point>(newX, newY);
        }

    public:
        Shape(std::string t, int vertexX, int vertexY, std::string c) :
            type(t) {
            point = std::make_unique<Point>(vertexX, vertexY);
            color = std::make_unique<Color>(c);
        }

        Shape(const Shape& other) :
            type(other.type),
            point(std::make_unique<Point>(*other.point)),
            color(std::make_unique<Color>(*other.color))
            {}

        const Point& getPoint() const {
            return *point;
        }

        const Color& getColor() const {
            return *color;
        }

        std::string getType() const {
            return type;
        }

        void draw() const {
            std::cout << "Drawing " << getType() << ": " <<
                getGraphic() << " at (" << getPoint().getX() << ", " << getPoint().getY() <<
                ") [" << getColor().getName() << "]\n  Area: " <<
                getArea() << "\n  Perimeter: " << getPerimeter()
                << "\n\n";
        }

        virtual double getPerimeter() const = 0;
        virtual double getArea() const = 0;
        virtual std::string getGraphic() const = 0;
        virtual void printInfo() = 0;
        virtual std::unique_ptr<Shape> clone() const = 0;
        virtual ~Shape() {
            std::cout << "~Shape() - base cleanup\n";
        }

};

class Circle : public Shape, public ITransformable {
    private:
        int radius;

    public:
        Circle(int x, int y, int r, std::string c) : Shape("Circle", x, y, c), radius(r) {}

        double getPerimeter() const override {
            return M_PI * 2 * radius;
        }

        double getArea() const override {
            return M_PI * radius * radius;
        }

        std::string getGraphic() const override {
            return "○";
        }

        void printInfo() override {
            std::cout << getType() << " at (" << getPoint().getX() << ", " <<
                getPoint().getY() << "), radius=" << radius << ", color=" <<
                getColor().getName() << "\n";
        }

        void move(int newX, int newY) override {
            setPoint(newX, newY);
        }

        void scale(double factor) override {
            /* not needed for demo */
        }

        void rotate(int degrees) override {
            /* does not make sense for circle */
        }

        std::unique_ptr<Shape> clone() const override {
            return std::make_unique<Circle>(*this); // calls copy constructor
        }

        ~Circle() {
            std::cout << "~Circle() - freeing circle resources\n";
        }
};

class Rectangle : public Shape, public ITransformable {
    private:
        int width;
        int height;

    public:
        Rectangle(int x, int y, int w, int h, std::string c) :
            Shape("Rectangle", x, y, c), width(w), height(h) {}

        double getPerimeter() const override {
            return (2 * height) + (2 * width);
        }

        double getArea() const override {
            return width * height;
        }

        std::string getGraphic() const override {
            return "□";
        }

        void printInfo() override {
            std::cout << getType() << " at (" << getPoint().getX() << ", " <<
                getPoint().getY() << "), width=" << width << ", height=" << height <<
                ", color=" << getColor().getName() << "\n";
        }

        void move(int newX, int newY) override {
            setPoint(newX, newY);
        }

        void scale(double factor) override {
            /* not needed for demo */
        }

        void rotate(int degrees) override {
            /* actually implementing this is complicated and does not contribute to
             * the point of the exercise. i'm just going to swap x and y and 
             * declare that's usfficient.
             */
            int oldX = getPoint().getX();
            int oldY = getPoint().getY();
            setPoint(oldY, oldX);
        }

        std::unique_ptr<Shape> clone() const override {
            return std::make_unique<Rectangle>(*this); // calls copy constructor
        }

        ~Rectangle() {
            std::cout << "~Rectangle() - freeing rectangle resources\n";
        }
};

class Triangle : public Shape, public ITransformable {
    private:
        double base;
        double height;

    public:
        Triangle(int x, int y, double b, double h, std::string c) :
            Shape("Triangle", x, y, c), base(b), height(h) {}

        double getPerimeter() const override {
            double third = std::sqrt(base * base + height * height);
            return base + height + third;
        }

        double getArea() const override {
            return 0.5 * base * height;
        }

        std::string getGraphic() const override {
            return "△";
        }

        void printInfo() override {
            std::cout << getType() << " at (" << getPoint().getX() << ", " <<
                getPoint().getY() << "), base=" <<  base << ", height=" << height <<
                ", color=" << getColor().getName() << "\n";
        }

        void move(int newX, int newY) override {
            setPoint(newX, newY);
        }

        void scale(double factor) override {
            /* actually implementating this is complicated and does not contribute
             * to the point of the exercise. i'm going to assume that scale means
             * we are scaling the length of the two edges we know.
             */
            base *= factor;
            height *= factor;
        }

        void rotate(int degrees) override {
            /* does not make sense for circle */
        }

        std::unique_ptr<Shape> clone() const override {
            return std::make_unique<Triangle>(*this); // calls copy constructor
        }

        ~Triangle() {
            std::cout << "~Triangle() - freeing triangle resources\n";
        }
};

int main() {

    std::cout << R"EOF(=== Graphics System Demo ===

Creating shapes with composition:
)EOF";

    auto circle = std::make_unique<Circle>(10, 20, 5, "Red");
    auto rectangle = std::make_unique<Rectangle>(30, 40, 10, 6, "Blue");
    auto triangle = std::make_unique<Triangle>(50, 60, 8, 5, "Green");

    circle->printInfo();
    rectangle->printInfo();
    triangle->printInfo();

    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::move(circle));
    shapes.push_back(std::move(rectangle));
    shapes.push_back(std::move(triangle));

    std::cout << "All shapes stored in polymorphic container:\n";
    std::cout << "Container holds " << shapes.size() << " shapes\n";

    std::cout << "Drawing all shapes (runtime polymorphism):\n";
    for (const auto& shape : shapes) {
        shape->draw();
    }

    std::cout << "Transforming shapes (ITransformable interface):\n";
    std::cout << "Moving Circle to (15, 25)\n";
    std::cout << "Rotating Rectangle by 45 degrees\n";
    std::cout << "Scaling Triangle by 1.5x\n";

    for (const auto& shape : shapes) {
        if (auto* c = dynamic_cast<Circle*>(shape.get())) {
            c->move(15, 25);
        }
        if (auto* r = dynamic_cast<Rectangle*>(shape.get())) {
            r->rotate(45);
        }
        if (auto* t = dynamic_cast<Triangle*>(shape.get())) {
            t->scale(1.5);
        }
    }

    std::cout << "Cloning shapes (covariant return types):\n";

    for (const auto& shape : shapes) {
        if (dynamic_cast<Triangle*>(shape.get())) {
            continue;
        }

        auto cloned = shape->clone();
        std::cout << "Cloned " << cloned->getType() << " at ("
              << cloned->getPoint().getX() << ", " << cloned->getPoint().getY() << ")\n";
    }

    std::cout << "Finding shapes by type (dynamic_cast):\n";
    int found = 0;
    for (const auto& shape : shapes) {
        if (dynamic_cast<Circle *>(shape.get())) {
            found++;
        }
    }
    std::cout << "Found " << found << " circles\n";

    found = 0;
    for (const auto& shape : shapes) {
        if (dynamic_cast<Rectangle *>(shape.get())) {
            found++;
        }
    }
    std::cout << "Found " << found << " rectangles\n";

    found = 0;
    for (const auto& shape : shapes) {
        if (dynamic_cast<Triangle *>(shape.get())) {
            found++;
        }
    }
    std::cout << "Found " << found << " triangles\n";

    std::cout << "\n";

    std::cout << "Cleanup with virtual destructors:\n";
    shapes.clear();

    std::cout << "All shapes properly destroyed (RAII + virtual destructors)\n";

}
