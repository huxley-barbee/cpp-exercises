/*
 * ## EXERCISE 10: Legacy Virtual Dispatch Patterns [4.a.v / 4.a.i]
 *
 * Write a program showing how C++98 codebases implemented polymorphism and the pitfalls.
 *
 * **Requirements:**
 * 1. Create a `Shape` base class with a non-`override`-annotated virtual `area()` (C++98 style)
 * 2. Create `Circle` and `Rectangle` derived classes
 * 3. Show the missing-`virtual`-destructor bug: delete a derived object through a base pointer
 * 4. Show accidental hiding instead of overriding (typo in signature — no `override` keyword to catch it)
 * 5. Demonstrate the C++98 pattern of using `0` for pure virtual (`= 0`) and why it looks odd
 * 6. Add `override` and `final` annotations and explain what they would have caught
 *
 * **Expected output:**
 * ```
 * === C++98 Virtual Dispatch ===
 * Shape* s1 = new Circle(5.0);
 * Shape* s2 = new Rectangle(4.0, 6.0);
 *
 * area() via base pointer:
 * Circle area: 78.54
 * Rectangle area: 24.00
 *
 * === Missing Virtual Destructor (BUG) ===
 * class Shape { ~Shape() {} };   // NOT virtual!
 * delete s1 through Shape*:
 *   ~Shape() called
 *   ~Circle() NOT called — resource leak!
 *
 * Fix: virtual ~Shape() {}
 *
 * === Accidental Hiding (No 'override') ===
 * class Circle : public Shape {
 *     double area(int precision) { ... }  // DIFFERENT signature!
 *     // Intended to override, actually HIDES base method
 * };
 * Circle c; Shape* p = &c;
 * p->area() calls Shape::area() — wrong! (silent bug)
 *
 * Fix: use 'override' keyword — compiler catches mismatch
 *
 * === Pure Virtual Syntax ===
 * virtual double area() const = 0;
 * // The '= 0' is a C++ quirk — means "no implementation here"
 * // Derived classes must implement, or they are also abstract
 * ```
 */

int main() {}
