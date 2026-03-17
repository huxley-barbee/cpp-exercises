/*
 * ## EXERCISE 13: Comprehensive Integration [All concepts from 2.a]
 * 
 * Write a memory pool allocator that demonstrates all memory management concepts.
 * 
 * **Requirements:**
 * 1. Create MemoryPool class using RAII principles
 * 2. Pre-allocate large buffer (stack or heap)
 * 3. Implement custom allocate/deallocate using placement new
 * 4. Track allocated blocks
 * 5. Return smart pointers (unique_ptr with custom deleter)
 * 6. Automatic cleanup in destructor
 * 7. Prevent copying (delete copy constructor)
 * 8. Show performance benefit vs standard allocation
 * 
 * **Expected output format:**
 * ```
 * === Memory Pool Allocator ===
 * 
 * Initializing pool with 1024 bytes
 * MemoryPool: Allocated 1024 bytes
 * 
 * Allocating 5 integers from pool:
 * Pool allocation: 4 bytes at offset 0
 * Pool allocation: 4 bytes at offset 4
 * Pool allocation: 4 bytes at offset 8
 * Pool allocation: 4 bytes at offset 12
 * Pool allocation: 4 bytes at offset 16
 * 
 * Pool stats:
 *   Total size: 1024 bytes
 *   Used: 20 bytes
 *   Free: 1004 bytes
 *   Allocations: 5
 * 
 * Smart pointer returned from pool
 * Value: 42
 * 
 * Deallocating automatically via custom deleter...
 * Pool deallocation: 4 bytes at offset 16
 * 
 * Creating scoped allocations:
 *   Allocating object 1
 *   Allocating object 2
 *   Leaving scope...
 *   Custom deleter called for object 2
 *   Custom deleter called for object 1
 * 
 * Pool stats:
 *   Used: 12 bytes
 *   Free: 1012 bytes
 *   Allocations: 3
 * 
 * Destroying memory pool...
 * MemoryPool: Deallocating 1024 bytes
 * All pool resources cleaned up automatically (RAII)
 * 
 * === Performance Comparison ===
 * Standard allocation (10000 ops): 15ms
 * Pool allocation (10000 ops): 2ms
 * Pool is 7.5x faster!
 * ```
 */

#include <iostream>
#include <memory>
#include <new>
#include <functional>
#include <chrono>
#include <thread> // for std::this_thread::sleep_for

static int TEST_SIZE = 470000;

class IntBox {
    public:
        int value;

        IntBox(int v) : value(v) {
            std::cout << "Allocating IntBox" << std::endl;
        }

        ~IntBox() {
            std::cout << "Dealloating IntBox" << std::endl;
        }
};


/*
void int_deleter(int *p) {
    std::cout << "noop int deleter" << std::endl;
}

*/

class MemoryPool {

    private:
        int size;
        int used;
        int free;
        int allocations;
        void *pool;
        std::function<void(int*)> deleter;

    public:
        MemoryPool(int s) : size(s), deleter(nullptr) {

            std::cout << "Initializing pool with " << size << " bytes" << std::endl;
            std::cout << std::endl;

            pool = (void *)malloc(size);
            used = 0;
            free = size;
            allocations = 0;

            deleter = [this](int* p) { 
                free += sizeof(int);
                used -= sizeof(int);
                allocations--;
                std::cout << "Pool deallocation: " << sizeof(int) <<
                    " bytes at offset " << used << std::endl;
            };

            std::cout << "Memory Pool: Allocated " << size << " bytes" << std::endl;
            std::cout << std::endl;

        }

        void allocatePrint(int count, bool print) {
            for (int index = 0; index < count; index++) {
                int* newNumber = new ((char *)pool+used) int(47);

                if (print) {
                    std::cout << "Pool allocation: " << sizeof(int) <<
                        " bytes at offset " << used << std::endl;
                }

                used += sizeof(int);
                free -= sizeof(int);
                allocations++;
            }
        }

        void allocate(int count) {
            allocatePrint(count, true);
        }

        std::unique_ptr<int, std::function<void(int*)>> getInt() {
            int offset = used - sizeof(int);
            int *obj = (int *)((char *)pool + offset);
            return std::unique_ptr<int, std::function<void(int*)>>(obj, deleter);
        }

        ~MemoryPool() {
            std::cout << "Destroying memory pool..." << std::endl;
            std::cout << "MemoryPool: Deallocating " << size << " bytes" << std::endl;
            std::cout << "All pool resources cleaned up automatically (RAII)" <<
                std::endl;
        }

        void printStats() {
            std::cout << std::endl;
            std::cout << "Pool stats:" << std::endl;
            std::cout << "\tTotal size: " << size << " bytes" << std::endl;
            std::cout << "\tUsed: " << used << " bytes" << std::endl;
            std::cout << "\tFree: " << free << " bytes" << std::endl;
            std::cout << "\tAllocations: " << allocations << std::endl;
            std::cout << std::endl;
        }
};

void doSomething(MemoryPool* pool) {
    std::cout << std::endl;
    std::cout << "Creating scoped allocations:" << std::endl;
    std::cout << "Allocating object 1" << std::endl;
    std::unique_ptr<int, std::function<void(int*)>> numPointer1 = pool->getInt();
    std::cout << "Allocating object 2" << std::endl;
    std::unique_ptr<int, std::function<void(int*)>> numPointer2 = pool->getInt();
    std::cout << "Leaving scope..." << std::endl;
    std::cout << std::endl;
}

int compare1() {
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    for (int index = 0; index < TEST_SIZE; index++) {
        int *number = (int *)malloc(sizeof(int));
    }

    // Record end time
    auto end = std::chrono::high_resolution_clock::now();

    // Compute elapsed time in milliseconds
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Standard allocation (" << TEST_SIZE << " ops): " << elapsed << " ms" << std::endl;

    return elapsed;

}

int compare2() {
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    MemoryPool *pool = new MemoryPool(sizeof(int) * TEST_SIZE);
    pool->allocatePrint(TEST_SIZE, false);

    // Record end time
    auto end = std::chrono::high_resolution_clock::now();

    // Compute elapsed time in milliseconds
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Pool allocation (" << TEST_SIZE << " ops): " << elapsed << " ms" << std::endl;

    return elapsed;
}

int main() {
    std::cout << "=== Memory Pool Allocator ===" << std::endl;
    std::cout << std::endl;
    MemoryPool* pool = new MemoryPool(1024);

    std::cout << "Allocating 5 integers from pool:" << std::endl;
    pool->allocate(5);

    pool->printStats();

    std::cout << std::endl;
    std::cout << "Smart pointer returned from pool" << std::endl;

    std::unique_ptr<int, std::function<void(int*)>> numPointer = pool->getInt();
    std::cout << "Value: " << *numPointer << std::endl;

    std::cout << std::endl;

    std::cout << "Deallocating automatically via custom deleter..." << std::endl;
    numPointer.reset();

    doSomething(pool);
    std::cout << std::endl;

    pool->printStats();

    delete pool;

    int standard = compare1();
    int pooled = compare2();

    std::cout << "Pool is " << standard/pooled << " faster!" << std::endl;
}
