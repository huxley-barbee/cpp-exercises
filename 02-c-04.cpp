/*
 * ## EXERCISE 4: Class Templates - Multiple Parameters [2.c.ii]
 * 
 * Write a program with class templates using multiple parameters.
 * 
 * **Requirements:**
 * 1. Create template class Pair<T1, T2>
 * 2. Create template class Array<T, Size> with non-type parameter
 * 3. Show default template arguments
 * 4. Demonstrate template template parameters
 * 5. Show that non-type parameters must be compile-time constants
 * 
 * **Expected output format:**
 * ```
 * === Pair<T1, T2> ===
 * Pair of int and string: (42, "answer")
 * Pair of double and char: (3.14, 'A')
 * 
 * === Array<T, Size> ===
 * Array<int, 5>: [1, 2, 3, 4, 5]
 * Array<double, 3>: [1.1, 2.2, 3.3]
 * 
 * Size is compile-time constant: 5
 * Cannot create Array<int, n> where n is runtime variable
 * 
 * === Default Template Arguments ===
 * Vector<int> uses default allocator
 * Vector<int, CustomAllocator> uses custom allocator
 * 
 * === Template Template Parameters ===
 * Container<int, std::vector> - vector of ints
 * Container<string, std::list> - list of strings
 * ```
 */

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <list>

template <typename T, typename U> class Pair {
    private:
        T one;
        U two;

    public:
        Pair<T, U>(T first, U second) : one(first), two(second) {}

        void print() const {
            std::cout << "(" << one << ", " << two << ")\n";
        }
};

template <typename T, int SIZE> class Array {
    private:
        T data[SIZE];
        int current = 0;

    public:

        void push(const T& item) {
            data[current] = item;
            current++;
        }

        void print() {
            bool first = true;

            std::cout << "[";

            for (int index = 0; index < current; index++) {
                const auto& item = data[index];
                if (first) {
                    first = false;
                } else {
                    std::cout << ", ";
                }
                std::cout << item;
            }
            std::cout << "]";
        }




};

template <typename T, typename A = std::allocator<T>>
class Vector {
};

template <typename T> class BumpAllocator {

    private:
        char *pool;
        size_t end;
        size_t remainingStart;

    public:

        BumpAllocator(char *buffer, size_t size) :
            pool(buffer), end(size), remainingStart(0) {
        }

        T* allocate(size_t n) {

            size_t size = n * sizeof(T);

            if (remainingStart+size > end) {
                throw std::bad_alloc();
            }

            T* returnPtr = reinterpret_cast<T*>(pool+remainingStart);

            remainingStart += size;
            
            return returnPtr;

        }

        void deallocate(T*, size_t) {
            // no-op. BumpAllocator never gives up
        }
};

template <typename T, template <typename...> class A> class Container {
    A<T> storage;
};

int main() {

    std::cout << "=== Pair<T1, T2> ===\n";
    Pair<int, std::string> intString(42, "answer");
    std::cout << "Pair of int and string: ";
    intString.print();
    Pair<double, char> doubleChar(3.14, 'A');
    std::cout << "Pair of double and char: ";
    doubleChar.print();
    std::cout << "\n";

    std::cout << "=== Array<T, Size> ===\n";
    Array<int, 5> arrayI;
    arrayI.push(1);
    arrayI.push(2);
    arrayI.push(3);
    arrayI.push(4);
    arrayI.push(5);
    std::cout << "Array<int, 5>: ";
    arrayI.print();
    std::cout << "\n";

    Array<double, 3> arrayD;
    arrayD.push(1.1);
    arrayD.push(2.2);
    arrayD.push(3.3);
    std::cout << "Array<double, 3>: ";
    arrayD.print();
    std::cout << "\n";

    std::cout << "Size is compile-time constant: 5\n";
    std::cout << "Cannot create Array<int, n> where n is runtime variable\n";
    int n = 2;
//    Array<int, n> test; 

    std::cout << "\n";

    std::cout << "=== Default Template Arguments ===\n";
    std::cout << "Vector<int> uses default allocator\n";
    Vector<int> intVector;


    std::cout << "Vector<int, CustomAllocator> uses custom allocator\n";
    char pool[1024];
    Vector<int, BumpAllocator<int>> otherIntVector;

    std::cout << "\n";

    std::cout << "=== Template Template Parameters ===\n";
    std::cout << "Container<int, std::vector> - vector of ints\n";
    Container<int, std::vector> vectorOfInts;

    std::cout << "Container<string, std::list> - list of strings\n";
    Container<std::string, std::list> listOfStrings;

}
