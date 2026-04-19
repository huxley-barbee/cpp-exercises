/* ## EXERCISE 3: Class Templates - Basics [2.c.ii]
 * 
 * Write a program demonstrating basic class templates.
 * 
 * **Requirements:**
 * 1. Create template class Stack<T>
 * 2. Implement push(), pop(), top(), empty()
 * 3. Test with different types: int, string, double
 * 4. Show that each instantiation is a separate type
 * 5. Demonstrate member function definition outside class
 * 
 * **Expected output format:**
 * ```
 * === Stack<int> ===
 * Pushing: 10, 20, 30
 * Top: 30
 * Popping: 30
 * Top after pop: 20
 * Size: 2
 * 
 * === Stack<string> ===
 * Pushing: "hello", "world"
 * Top: world
 * Popping: world
 * Empty: false
 * 
 * === Stack<double> ===
 * Pushing: 3.14, 2.71
 * Top: 2.71
 * 
 * Stack<int> and Stack<string> are different types
 * Cannot assign Stack<int> to Stack<double>
 * ```
 */

#include <iostream>
#include <vector>

template <typename T> class Stack {

    private:
        std::vector<T> list;

    public:

        void push(const T& item) {
            list.push_back(item);
        }

        T top() {
            return list.back();
        }

        T pop() {
            T last = list.back();
            list.pop_back();
            return last;
        }

        int size() {
            return list.size();
        }

        bool empty() {
            return list.empty();
        }

};

int main() {

    std::cout << "=== Stack<int> ===\n";
    Stack<int> stack1;
    std::cout << "Pushing: 10, 20, 30\n";
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    std::cout << "Top: " << stack1.top() << "\n";
    std::cout << "Popping: " << stack1.pop() << "\n";
    std::cout << "Top after pop: " << stack1.top() << "\n";;
    std::cout << "Size: " << stack1.size() << "\n";

    std::cout << "\n";

    std::cout << "=== Stack<string> ===\n";
    Stack<std::string> stack2;
    std::cout << "Pushing: \"hello\", \"world\"\n";
    stack2.push("hello");
    stack2.push("world");
    std::cout << "Top: " << stack2.top() << "\n";
    std::cout << "Popping: " << stack2.pop() << "\n";
    std::cout << "Empty: " << std::boolalpha << stack2.empty() << " \n";

    std::cout << "\n";

    std::cout << "=== Stack<double> ===\n";
    Stack<double> stack3;
    std::cout << "Pushing: 3.14, 2.71\n";
    stack3.push(3.14);
    stack3.push(2.71);
    std::cout << "Top: " << stack3.top() << "\n";

    std::cout << "\n";

    std::cout << "Stack<int> and Stack<string> are different types\n";
    std::cout << "Cannot assign Stack<int> to Stack<double>\n";
    // stack1 = stack3;

}
