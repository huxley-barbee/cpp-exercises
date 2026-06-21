/*
 * ## EXERCISE 9: std::variant [3.a.vi]
 *
 * Write a program demonstrating std::variant for type-safe unions.
 *
 * **Requirements:**
 * 1. Create variant with multiple types
 * 2. Show std::get<T> and std::get<index>
 * 3. Demonstrate std::visit with variant
 * 4. Show std::holds_alternative
 * 5. Use variant for polymorphism without inheritance
 * 6. Show exception on wrong type access
 *
 * **Expected output format:**
 * ```
 * === std::variant Basics ===
 *
 * std::variant<int, double, std::string> v1;
 * v1 = 42;           // Now holds int
 * v1 = 3.14;         // Now holds double
 * v1 = "hello";      // Now holds string
 *
 * Accessing variant:
 * std::get<std::string>(v1) = "hello"
 * std::get<2>(v1) = "hello"  (by index)
 *
 * std::holds_alternative<std::string>(v1): true
 * std::holds_alternative<int>(v1): false
 *
 * === std::visit ===
 * auto visitor = [](auto&& arg) {
 *     using T = std::decay_t<decltype(arg)>;
 *     if constexpr (std::is_same_v<T, int>)
 *         std::cout << "int: " << arg << std::endl;
 *     else if constexpr (std::is_same_v<T, double>)
 *         std::cout << "double: " << arg << std::endl;
 *     else
 *         std::cout << "string: " << arg << std::endl;
 * };
 *
 * std::visit(visitor, v1);  // Output: string: hello
 *
 * === Variant for Polymorphism ===
 * using Shape = std::variant<Circle, Rectangle, Triangle>;
 *
 * std::vector<Shape> shapes;
 * shapes.push_back(Circle{5.0});
 * shapes.push_back(Rectangle{4.0, 3.0});
 *
 * for (auto& shape : shapes) {
 *     std::visit([](auto& s) { s.draw(); }, shape);
 * }
 *
 * Circle drawn
 * Rectangle drawn
 *
 * === Exception Handling ===
 * std::variant<int, std::string> v = 42;
 * try {
 *     std::get<std::string>(v);  // Wrong type!
 * } catch (std::bad_variant_access& e) {
 *     Error: bad variant access
 * }
 *
 * variant provides type-safe tagged unions!
 * ```
 */

int main() {}
