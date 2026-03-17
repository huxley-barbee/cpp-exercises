/* 
 * ========================================================================
 * EXERCISE 9: const Correctness - Functions [1.a.v]
 * ========================================================================
 * 
 * Create a simple class 'Counter' with:
 * - Private int 'count'
 * - Constructor initializing count
 * - increment() - increases count (non-const method)
 * - getValue() const - returns count (const method)
 * - tryModify() const - attempts to modify count (should not compile - comment)
 * 
 * Requirements:
 * 1. Create const Counter object
 * 2. Try to call increment() on const object (won't compile - comment out)
 * 3. Call getValue() on const object (works)
 * 4. Create non-const Counter and call both methods
 * 
 * Expected output format:
 * Non-const counter incremented: 6
 * Non-const counter value: 6
 * Const counter value: 10
 * Const counter cannot call increment() - commented out
 */ 

#include <iostream>

class Counter {
    private:
        int count;

    public:
        Counter(int num) {
            count = num;
        }

        void increment() {
            count++;
        }

        int getCount() const {
            return count;
        }

        void tryModify() const {
            // can't compile
            // error: cannot assign to non-static data member within const
            // member function 'tryModify'
            // count++;
        }
};

int main() {

    const Counter* roCounter = new Counter(10);

    // can't compile
    // error: 'this' argument to member function 'increment' has type
    // 'const Counter', but function is not marked const
    // roCounter->increment();

    std::cout << "Const counter incremented: " << roCounter->getCount()
        << std::endl;

    Counter* rwCounter = new Counter(5);

    rwCounter->increment();
    rwCounter->tryModify();

    std::cout << "Non-const counter incremented: " << rwCounter->getCount()
        << std::endl;

}
