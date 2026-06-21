/*
 * ## EXERCISE 6: Rule of Zero [3.b.iii]
 *
 * Write a program demonstrating the Rule of Zero.
 *
 * **Requirements:**
 * 1. Create a class that holds only standard containers and smart pointers
 * 2. Show the compiler-generated copy constructor, copy assignment, move constructor, move assignment, and destructor are all correct
 * 3. Demonstrate that deep copy works without writing any special member
 * 4. Demonstrate that move semantics work without writing any special member
 * 5. Contrast with a class that incorrectly tries to manage raw memory
 *
 * **Expected output:**
 * ```
 * === Rule of Zero Demo ===
 *
 * class Document {
 *     std::string title;
 *     std::vector<std::string> lines;
 *     std::unique_ptr<Metadata> meta;
 *     // No custom special members!
 * };
 *
 * Creating original document: "Design Doc"
 * Lines: ["Intro", "Body", "Conclusion"]
 *
 * Copying document (compiler-generated copy):
 * Copy title: "Design Doc"
 * Copy lines: ["Intro", "Body", "Conclusion"]
 * (Deep copy — independent from original)
 *
 * Modifying original — copy unchanged:
 * Original: ["Intro", "MODIFIED", "Conclusion"]
 * Copy:     ["Intro", "Body", "Conclusion"]
 *
 * Moving document (compiler-generated move):
 * Moved title: "Design Doc"
 * Original after move: "" (empty — ownership transferred)
 *
 * Destructor (compiler-generated):
 * Document destroyed — all members cleaned up automatically
 *
 * Rule of Zero: let the compiler do the work!
 * ```
 */

int main() {}
