/*
 * ## EXERCISE 4: RAII - Resource Guard [2.a.ii]
 * 
 * Write a program with a generic RAII resource guard.
 * 
 * **Requirements:**
 * 1. Create a LockGuard class that:
 *    - Acquires a resource in constructor (simulate with print)
 *    - Releases resource in destructor
 * 2. Demonstrate multiple guards in nested scopes
 * 3. Show automatic release in correct order (LIFO - stack unwinding)
 * 4. Create a counter to track active resources
 * 
 * **Expected output format:**
 * ```
 * Creating Resource 1
 *   LockGuard: Acquired Resource 1
 *   Active resources: 1
 *   
 *   Creating Resource 2
 *     LockGuard: Acquired Resource 2
 *     Active resources: 2
 *     
 *     Creating Resource 3
 *       LockGuard: Acquired Resource 3
 *       Active resources: 3
 *     LockGuard: Released Resource 3
 *     Active resources: 2
 *     
 *   LockGuard: Released Resource 2
 *   Active resources: 1
 *   
 * LockGuard: Released Resource 1
 * Active resources: 0
 * 
 * All resources properly released in LIFO order!
 * ```
 */ 

#include <iostream>

class LockGuard {

    private:
        static inline int counter = 0;

    public:
        LockGuard() {
            counter++;
            std::cout << "LockGuard: Acquired Resource " << counter
                << std::endl;
            std::cout << "Active resources: " << counter << std::endl;
        }

        ~LockGuard() {
            std::cout << "LockGuard: Released Resource " << counter
                << std::endl;
            counter--;
            std::cout << "Active resources: " << counter << std::endl;
        }
};

int main() {

    std::cout << "Creating Resource 1" << std::endl;
    {
        LockGuard guard1;

        std::cout << "Creating Resource 2" << std::endl;
        {
            LockGuard guard2;

            std::cout << "Creating Resource 3" << std::endl;
            {
                LockGuard guard3;
            }
            std::cout << std::endl;

        }
        std::cout << std::endl;

    }
    std::cout << std::endl;

}
