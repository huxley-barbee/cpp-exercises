/*
 * ## EXERCISE 3: RAII Basics - File Handle [2.a.ii]
 * 
 * Write a program demonstrating RAII with a file wrapper class.
 * 
 * **Requirements:**
 * 1. Create a class FileHandle that:
 *    - Opens a file in constructor
 *    - Closes file in destructor
 *    - Prints messages when opening/closing
 * 2. Demonstrate automatic cleanup even if exception occurs
 * 3. Compare with manual file handling (open/close)
 * 4. Show that RAII guarantees cleanup
 * 
 * **Expected output format:**
 * ```
 * === Manual File Handling === 
 * Opening file manually: test.txt
 * Writing to file...
 * Closing file manually
 * 
 * === RAII File Handling === 
 * FileHandle: Opening test_raii.txt
 * Writing via RAII...
 * FileHandle: Closing test_raii.txt (automatic)
 * 
 * === RAII with Exception === 
 * FileHandle: Opening exception_test.txt
 * Exception occurred: Simulated error
 * FileHandle: Closing exception_test.txt (cleanup guaranteed!)
 * 
 * RAII ensures cleanup even with exceptions!
 * ```
 */ 

#include <fstream>
#include <iostream>
#include <stdexcept>

class FileHandle {

    private:
        std::ofstream myfile;
        std::string name;

    public:
        FileHandle(std::string filename) {
            name = filename;
            std::cout << "FileHandle: Opening " << name << std::endl;
            myfile.open(filename);
        }

        void write(std::string data) {
            std::cout << "Writing via RAII" << std::endl;
            myfile << data;
        }

        void writeException(std::string data) {
            throw std::runtime_error("simulated error");

        }

        ~FileHandle() {
            std::cout << "FileHandle: Closing " << name << " (automatic)"
                << std::endl;
            myfile.close();
        }
};

int main() {

    std::cout << "=== Manual File Handling ===" << std::endl;
    std::ofstream myfile;
    std::cout << "Opening file manually: ex2a3.txt" << std::endl;
    myfile.open("ex2a3.txt");
    std::cout << "Writing to file..." << std::endl;
    myfile << "writing\n";
    std::cout << "Closing file manually" << std::endl;
    myfile.close();

    std::cout << std::endl;

    {
        std::cout << "=== RAII File Handling ===" << std::endl;
        FileHandle handle("ex2a3-raii.txt");
        handle.write("blah 123");
    }
    std::cout << std::endl;


    try {
        std::cout << "=== RAII File Handling  With Exception ==="
            << std::endl;
        FileHandle handle2("ex2a3-raii-exception.txt");
        handle2.writeException("blah 123");
    } catch(const std::runtime_error& e) {
        std::cout << "Caught exception" << std::endl;
    }
    std::cout << std::endl;

    return 0 ;
}

