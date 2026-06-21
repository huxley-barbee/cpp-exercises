/*
 * ## EXERCISE 8: std::optional [3.a.vi]
 *
 * Write a program demonstrating std::optional for nullable values.
 *
 * **Requirements:**
 * 1. Show optional creation and access
 * 2. Demonstrate has_value() and value()
 * 3. Show value_or() for default values
 * 4. Use optional as function return type
 * 5. Show optional with custom types
 * 6. Demonstrate optional chaining
 *
 * **Expected output format:**
 * ```
 * === std::optional Basics ===
 *
 * std::optional<int> opt1 = 42;
 * std::optional<int> opt2;  // Empty
 *
 * opt1.has_value(): true
 * opt1.value(): 42
 * opt2.has_value(): false
 *
 * Using value_or():
 * opt1.value_or(0) = 42
 * opt2.value_or(0) = 0
 *
 * === Optional as Return Type ===
 * std::optional<std::string> findUser(int id) {
 *     if (id == 1) return "Alice";
 *     return std::nullopt;  // Not found
 * }
 *
 * findUser(1): Alice
 * findUser(2): (no value)
 *
 * === Optional with Custom Types ===
 * struct User { std::string name; int age; };
 * std::optional<User> user = User{"Bob", 30};
 *
 * if (user) {  // Implicit bool conversion
 *     User: Bob, age 30
 * }
 *
 * === Safe Access ===
 * auto age = user.has_value() ? user->age : -1;
 * Age: 30
 *
 * // user.value();  // Safe: returns reference
 * // user2.value(); // Throws std::bad_optional_access
 *
 * === Optional Chaining ===
 * auto result = findUser(1)
 *     .and_then([](auto name) { return findAge(name); })
 *     .or_else([]() { return std::optional<int>(0); });
 *
 * optional eliminates nullptr checks and expresses intent clearly!
 * ```
 */

int main() {}
