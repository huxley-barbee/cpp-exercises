/*
 * ## EXERCISE 12: Memory Leaks Detection [2.a.iv]
 * 
 * Write a program demonstrating common memory leak patterns and detection.
 * 
 * **Requirements:**
 * 1. Implement simple leak detector that tracks allocations
 * 2. Show leak from forgetting to delete
 * 3. Show leak from exception thrown before delete
 * 4. Show leak from early return
 * 5. Show how RAII prevents all these leaks
 * 6. Track allocation count
 * 
 * **Expected output format:**
 * ```
 * === Memory Leak Detector Demo ===
 * Starting allocation tracking...
 * 
 * --- Leak Pattern 1: Forgot to Delete ---
 * Allocating memory...
 * Allocation count: 1
 * (Forgot to delete - LEAK)
 * 
 * --- Leak Pattern 2: Exception Before Delete ---
 * Allocating memory...
 * Allocation count: 2
 * Exception thrown before delete!
 * (Memory leaked due to exception)
 * 
 * --- Leak Pattern 3: Early Return ---
 * Allocating memory...
 * Allocation count: 3
 * Early return condition met
 * (Memory leaked due to early return)
 * 
 * Current leaks: 3 allocations
 * 
 * --- RAII Solution (No Leaks) ---
 * Allocating with unique_ptr...
 * Exception thrown!
 * Caught exception, but memory auto-cleaned by unique_ptr
 * 
 * Final leak count: 3 allocations leaked
 * (Only from manual patterns, RAII had zero leaks)
 * ```
 */

#include <iostream>
#include <memory>

// Tracks net live allocations; equals leaked count at program end
// since properly-freed memory decrements this on destruction
static int allocationCount = 0;

class Thing {
    public:
        Thing() {
            allocationCount++;
        }

        ~Thing() {
            allocationCount--;
        }
};

void doSomething() {
    std::cout << "Allocating memory..." << std::endl;
    Thing* thing3 = new Thing();
    std::cout << "Allocation count: " << allocationCount << std::endl;

    bool condition = true;
    if (condition) {
        std::cout << "Early return condition met" << std::endl;
        return;
    }
    delete thing3;
}

int main() {

    std::cout << "=== Memory Leak Detector Demo ===" << std::endl;
    std::cout << "Starting allocation tracking..." << std::endl;
    std::cout << std::endl;

    std::cout << "--- Leak Pattern 1: Forgot to Delete ---" << std::endl;
    std::cout << "Allocating memory..." << std::endl;
    Thing* thing1 = new Thing();
    std::cout << "Allocation count: " << allocationCount << std::endl;
    std::cout << "(Forgot to delete - LEAK)" << std::endl;
    std::cout << std::endl;

    std::cout << "--- Leak Pattern 2: Exception Before Delete ---" << std::endl;
    try {
        std::cout << "Allocating memory..." << std::endl;
        Thing* thing2 = new Thing();
        std::cout << "Allocation count: " << allocationCount << std::endl;
        std::cout << "Exception thrown before delete!" << std::endl;
        throw std::runtime_error("intentional error");
        delete thing2; // unreachable 
    } catch (const std::exception& e) {
        // intentionally empty — leak already occurred, nothing to report here
    } 

    std::cout << "(Memory leaked due to exception)" << std::endl;
    std::cout << std::endl;

    std::cout << "--- Leak Pattern 3: Early Return ---" << std::endl;
    doSomething();
    std::cout << "(Memory leaked due to early return)" << std::endl;
    std::cout << std::endl;

    std::cout << "Current leaks: " << allocationCount << " allocations" << std::endl;
    std::cout << std::endl;

    std::cout << "--- RAII Solution (No Leaks) ---" << std::endl;
    std::cout << "Allocating with unique_ptr..." << std::endl;
    try {
        auto thing4 = std::make_unique<Thing>();
        std::cout << "Exception thrown!" << std::endl;
        throw std::runtime_error("intentional error");
    } catch (const std::exception& e) {
        std::cout << "Caught exception, but memory auto-cleaned by unique_ptr" <<
            std::endl;
    } 

    std::cout << "Final leak count: " << allocationCount << " allocations leaked" <<
        std::endl;
    std::cout << "(Only from manual patterns, RAII had zero leaks)" << std::endl;

}
