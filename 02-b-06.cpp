/*
 * ## EXERCISE 6: Multiple Inheritance and Diamond Problem [2.b.iv]
 * 
 * Write a program demonstrating the diamond problem.
 * 
 * **Requirements:**
 * 1. Create base class Device
 * 2. Create two derived classes: Scanner, Printer (both inherit from Device)
 * 3. Create MultiFunctionDevice that inherits from both
 * 4. Show diamond problem (Device inherited twice)
 * 5. Fix with virtual inheritance
 * 6. Demonstrate proper initialization with virtual inheritance
 * 
 * **Expected output format:**
 * ```
 * === Diamond Problem (Without Virtual Inheritance) ===
 * Creating Device (ID: 1)
 * Creating Scanner
 * Creating Device (ID: 2)
 * Creating Printer
 * Creating MultiFunctionDevice
 * Device constructor called TWICE - diamond problem!
 * 
 * Base class Device exists twice in MultiFunctionDevice
 * Ambiguous: which Device::deviceId to use?
 * 
 * === Solution: Virtual Inheritance ===
 * Creating Device (ID: 100)
 * Creating ScannerV
 * Creating PrinterV
 * Creating MultiFunctionDeviceV
 * Device constructor called ONCE - problem solved!
 * 
 * ScannerV functions: scan()
 * PrinterV functions: print()
 * MultiFunctionDeviceV has both: scan() and print()
 * Device ID: 100 (single instance)
 * ```
 */

#include <iostream>

class Device {
    private:
        int deviceId;

    public:
        Device(int id) : deviceId(id) {
            std::cout << "Creating Device (ID: " << deviceId << ")\n";
        }
};

class Scanner : public Device {

    public:
        Scanner(int id) : Device(id) {
            std::cout << "Creating Scanner\n";
        }
};

class Printer : public Device {
    public:
        Printer(int id) : Device(id) {
            std::cout << "Creating Printer\n";
        }
};

class MultiFunctionDevice : public Scanner, public Printer {
    public:
        MultiFunctionDevice(int scannerId, int printerId) : Scanner(scannerId), Printer(printerId) {
            std::cout << "CreatingMultiFunctionDevice\n";
            std::cout << "Device constructor called TWICE - diamond problem!\n";
        }
};

class VDevice {
    private:
        int deviceId;

    public:
        VDevice(int id) : deviceId(id) {
            std::cout << "Creating Device (ID: " << deviceId << ")\n";
        }

        int getDeviceId() {
            return deviceId;
        }
};

class VScanner : public virtual VDevice {

    public:
        VScanner(int id) : VDevice(id) {
            std::cout << "Creating ScannerV\n";
        }
        void scan() {
            std::cout << "ScannerV functions: scan()\n";
        }
};

class VPrinter : public virtual VDevice {
    public:
        VPrinter(int id) : VDevice(id) {
            std::cout << "Creating PrinterV\n";
        }

        void print() {
            std::cout << "PrinterV functions: print()\n";
        }
};

class VMultiFunctionDevice : public VScanner, public VPrinter {
    public:
        VMultiFunctionDevice(int deviceId) : VDevice(deviceId), VScanner(1), VPrinter(2) {
            std::cout << "CreatingMultiFunctionDeviceV\n";
            std::cout << "Device constructor called TWICE - diamond problem!\n";
        }
};

int main() {

    std::cout << "=== Diamond Problem (Without Virtual Inheritance) ===\n";

    MultiFunctionDevice* device = new MultiFunctionDevice(1, 2);

    std::cout << "Base class Device exists twice in MultiFunctionDevice\n";
    std::cout << "Ambiguous: which Device::deviceId to use?\n\n";

    std::cout << "=== Solution: Virtual Inheritance ===\n";

    VMultiFunctionDevice* vDevice = new VMultiFunctionDevice(100);
    std::cout << "Device constructor called ONCE - problem solved!\n";
    vDevice->scan();
    vDevice->print();
    std::cout << "MultiFunctionDeviceV has both: scan() and print()\n";

    std::cout << "Device ID: " << vDevice->getDeviceId() << " (single instance)\n";
}
