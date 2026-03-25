/*
 * ## EXERCISE 7: Smart Pointers - Circular Reference Problem [2.a.iii]
 * 
 * Write a program demonstrating the circular reference problem with shared_ptr.
 * 
 * **Requirements:**
 * 1. Create Node class with shared_ptr to next node
 * 2. Create circular reference (A->B, B->A)
 * 3. Show memory leak (destructors never called)
 * 4. Fix using weak_ptr
 * 5. Demonstrate proper cleanup with weak_ptr solution
 * 
 * **Expected output format:**
 * ```
 * === Circular Reference with shared_ptr (MEMORY LEAK) ===
 * Creating Node A
 * Creating Node B
 * A points to B
 * B points to A (circular reference created)
 * use_count for A: 2, use_count for B: 2
 * 
 * Leaving scope...
 * (No destructors called - memory leaked!)
 * 
 * === Fixed with weak_ptr ===
 * Creating Node C
 * Creating Node D
 * C points to D
 * D weakly points back to C
 * use_count for C: 1, use_count for D: 1
 * 
 * Leaving scope...
 * Destroying Node D
 * Destroying Node C
 * (Proper cleanup - no leak!)
 * ```
 */

#include <iostream>
#include <memory>

class SharedPtrNode {

    private:
        std::shared_ptr<SharedPtrNode> next;
        std::string name;

    public:
        SharedPtrNode(std::string n) {
            name = n;
        }

        void setNext(std::shared_ptr<SharedPtrNode> new_next) {
            next = new_next;
        }

        ~SharedPtrNode() {
            std::cout << "Destroying Node " << name << std::endl;
        }
};

class WeakPtrNode {

    private:
        std::weak_ptr<WeakPtrNode> back;
        std::shared_ptr<WeakPtrNode> next;
        std::string name;

    public:
        WeakPtrNode(std::string n) {
            name = n;
        }

        void setNext(std::shared_ptr<WeakPtrNode> new_next) {
            next = new_next;
        }

        void setBack(std::shared_ptr<WeakPtrNode> new_back) {
            back = new_back;
        }

        ~WeakPtrNode() {
            std::cout << "Destroying Node " << name << std::endl;
        }
};

int main() {
    std::cout << "=== Circular Reference with shared_ptr (MEMORY LEAK) ===" << std::endl;

    {
        std::cout << "Creating Node A" << std::endl;
        std::shared_ptr<SharedPtrNode> A = std::make_shared<SharedPtrNode>("A");

        std::cout << "Creating Node B" << std::endl;
        std::shared_ptr<SharedPtrNode> B = std::make_shared<SharedPtrNode>("B");

        std::cout << "A points to B" << std::endl;
        A->setNext(B);

        std::cout << "B points to A (circular reference created)" << std::endl;
        B->setNext(A);

        std::cout << "use_count for A: " << A.use_count()
            << ", use_count for B: " << B.use_count() << std::endl;

        std::cout << "\nLeaving scope..." << std::endl;
    }
    std::cout << "(No destructors called - memory leaked!)" << std::endl;

    std::cout << "=== Fixed with weak_ptr ===" << std::endl;
    {
        std::cout << "Creating Node C" << std::endl;
        std::shared_ptr<WeakPtrNode> C = std::make_shared<WeakPtrNode>("C");

        std::cout << "Creating Node D" << std::endl;
        std::shared_ptr<WeakPtrNode> D = std::make_shared<WeakPtrNode>("D");

        std::cout << "C points to D" << std::endl;
        C->setNext(D);

        std::cout << "D weakly points back to C" << std::endl;
        D->setBack(C);

        std::cout << "use_count for C: " << C.use_count()
            << ", use_count for D: " << D.use_count() << std::endl;

        std::cout << "\nLeaving scope..." << std::endl;
    }
    std::cout << "(Proper cleanup - no leak!)" << std::endl;

}
