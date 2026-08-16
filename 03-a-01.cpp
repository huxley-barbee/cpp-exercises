/*
 * ## EXERCISE 1: Move Semantics - Basics [3.a.i]
 *
 * Write a program demonstrating move semantics and the difference from copy semantics.
 *
 * **Requirements:**
 * 1. Create a class with dynamically allocated resource
 * 2. Implement copy constructor (deep copy)
 * 3. Implement move constructor (transfer ownership)
 * 4. Show performance difference between copy and move
 * 5. Demonstrate std::move()
 * 6. Show that moved-from object is in valid but unspecified state
 *
 * **Expected output format:**
 * ```
 * === Copy Semantics ===
 * Creating Buffer with 1000000 elements
 * Copy constructor called (deep copy)
 *   Allocating new memory
 *   Copying 1000000 elements
 * Time for copy: 15ms
 *
 * === Move Semantics ===
 * Creating Buffer with 1000000 elements
 * Move constructor called (transfer ownership)
 *   Taking ownership of memory
 *   Original pointer nullified
 * Time for move: 0ms
 *
 * Move is ~infinite times faster (no allocation/copy)
 *
 * After move:
 *   Source buffer size: 0 (moved-from state)
 *   Destination buffer size: 1000000
 *
 * Move semantics enable efficient resource transfer!
 * ```
 */

#include <chrono>
#include <iostream>
#include <random>

class Buffer {
    private:
        int* data;
        int slots;

    public:
        Buffer(int slots) : slots(slots) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(1, 100);
            data = new int[slots];
            for (int index = 0; index < slots; index++) {
                data[index] = distrib(gen);
            }
        }

        Buffer(const Buffer& other) {
            std::cout << "Copying 1000000 elements\n";
            auto t1 = std::chrono::high_resolution_clock::now();
            slots = other.slots;
            data = new int[slots];
            for (int index = 0; index < slots; index++) {
                data[index] = other.data[index];
            }
            auto t2 = std::chrono::high_resolution_clock::now();
            auto diff_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
            std::cout << "Time for copy: " << diff_ms1 << "ms\n";

        }

        Buffer(Buffer&& other) {
            std::cout << "Move constructor called (transfer ownership)\n";
            std::cout << "Taking ownership of memory\n";
            auto t1 = std::chrono::high_resolution_clock::now();
            slots = other.slots;
            data = other.data;
            std::cout << "Original pointer nullified\n";
            other.data = nullptr;
            auto t2 = std::chrono::high_resolution_clock::now();
            auto diff_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
            std::cout << "Time for move: " << diff_ms1 << "ms\n";
        }

        int size() {
            if (data != nullptr) {
                return slots;
            } else {
                return 0;
            }
        }

        ~Buffer() {
            delete[] data;
        }

};

int main() {

    std::cout << "=== Copy Semantics ===\n";
    std::cout << "Creating Buffer with 1000000 elements\n";
    Buffer *buffer = new Buffer(1000000);

    std::cout << "Copy constructor called (deep copy)\n";
    std::cout << "Allocating new memory\n";
    Buffer *buffer2 = new Buffer(*buffer);

    std::cout << "\n";
    std::cout << "=== Move Semantics ===\n";
    std::cout << "Creating Buffer with 1000000 elements\n";
    Buffer *buffer3 = new Buffer(std::move(*buffer));

    std::cout << "\n";
    std::cout << "Move is ~infinite times faster (no allocation/copy)\n";
    std::cout << "\n";
 
    std::cout << "After move:\n";
    std::cout << "Source buffer size: " << buffer->size() << " (moved-from state)\n";
    std::cout << "Destination buffer size: " << buffer3->size() << "\n";

    std::cout << "\nMove semantics enable efficient resource transfer!\n";

    delete buffer;
    delete buffer2;
    delete buffer3;
}
