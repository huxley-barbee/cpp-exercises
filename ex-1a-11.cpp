/*
 * ========================================================================
 * EXERCISE 11: Comprehensive Integration [All concepts from 1.a]
 * ========================================================================
 * 
 * Write a temperature conversion program that integrates all concepts:
 * 
 * Requirements:
 * 1. Create namespace 'Temperature'
 * 2. Inside, define:
 *    - const double ABSOLUTE_ZERO = -273.15
 *    - Function: double celsiusToFahrenheit(const double& celsius)
 *    - Function: void convertAndDisplay(const double* temperatures, int size)
 *    - Overloaded: void convertAndDisplay(double temp) for single value
 * 3. In main():
 *    - Create array of 3 temperatures
 *    - Use pointers to iterate
 *    - Call appropriate functions
 *    - Demonstrate const correctness
 * 
 * Expected output format:
 * Converting array of temperatures:
 * 0.00°C = 32.00°F
 * 100.00°C = 212.00°F
 * -40.00°C = -40.00°F
 * Converting single temperature:
 * 37.00°C = 98.60°F
 * Absolute zero in Celsius: -273.15
 */ 

#include <iostream>

namespace Temperature {
    const double ABSOLUTE_ZERO = -273.15;

    double celsiusToFahrenheit(const double& celsius) {
        return (celsius/5*9)+32;
    }

    void convertAndDisplay(double temp) {
        std::cout << temp << "°C = " << celsiusToFahrenheit(temp) << "°F"
            << std::endl;
    }

    void convertAndDisplay(const double* temperatures, int size) {
        for (int index = 0; index < size; index++) {
            convertAndDisplay(*(temperatures+index));
        }
    }

}

int main() {

    double array[] = { 0.0, 100.0, -40.0 };

    Temperature::convertAndDisplay(array, 3);

    Temperature::convertAndDisplay(37.0);

    Temperature::convertAndDisplay(Temperature::ABSOLUTE_ZERO);

}
