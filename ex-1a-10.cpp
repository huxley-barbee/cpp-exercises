/* 
 * ========================================================================
 * EXERCISE 10: Namespaces [1.a.vi]
 * ========================================================================
 * 
 * Write a program with two namespaces:
 * - namespace Math { int add(int a, int b); int multiply(int a, int b); }
 * - namespace Physics { double add(double a, double b); double multiply(double a, double b); }
 * 
 * Requirements:
 * 1. Implement all functions
 * 2. In main(), call both Math::add and Physics::add
 * 3. Demonstrate 'using' declaration for single function
 * 4. Demonstrate 'using namespace' directive
 * 5. Show namespace alias
 * 
 * Expected output format:
 * Math::add(5, 3): 8
 * Physics::add(5.5, 3.2): 8.7
 * Math::multiply(4, 7): 28
 * Using declaration - add(10, 20): 30
 * Using namespace - multiply(2.5, 4.0): 10
 * Namespace alias M::add(100, 50): 150
 */

#include <iostream>

namespace Math {
    int add (int a, int b) {
        return a + b;
    }
    int multiply(int a, int b) {
        return a * b;
    }
}

namespace Physics {
    double add(double a, double b) {
        return a + b;
    }
    double multiply(double a, double b) {
        return a * b;
    }
}

using Math::add;
using namespace Physics;
namespace M = Math;

int main() {
    std::cout << "Math::add(5, 3): " << Math::add(5, 3) << std::endl;
    std::cout << "Physics::add(5.5, 3.2): " << Physics::add(5.5, 3.2)
        << std::endl;
    std::cout << "Math::multiply(4, 7): " << Physics::multiply(4, 7)
        << std::endl;
    std::cout << "add(10, 20): " << add(10, 20) << std::endl;
    std::cout << "multiply(2.5, 4.0): " << multiply(2.5, 4.0) << std::endl;
    std::cout << "M::add(100, 50): " << M::add(100, 50) << std::endl;
}
