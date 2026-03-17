/* 
 * ========================================================================
 * EXERCISE 8: const Correctness - Basics [1.a.v]
 * ========================================================================
 * 
 * Write a program demonstrating const in different contexts:
 * 
 * Requirements:
 * 1. const int 'constantValue' = 100 (cannot be modified)
 * 2. int 'variable' = 50
 * 3. const int* 'ptrToConst' = &variable (pointer to const int)
 *    - Try to modify *ptrToConst (should not compile - comment out)
 *    - Reassign ptrToConst to point elsewhere (allowed)
 * 4. int* const 'constPtr' = &variable (const pointer)
 *    - Modify *constPtr (allowed)
 *    - Try to reassign constPtr (should not compile - comment out)
 * 5. const int* const 'constPtrToConst' (both const)
 * 
 * Expected output format:
 * Constant value: 100
 * Variable: 50
 * Pointer to const points to: 50
 * After changing where pointer to const points: 100
 * Const pointer can modify value: 51
 * Const pointer to const: 100
 */

#include <iostream>

int main() {
    const int constantValue = 100;
    std::cout << "Constant value: " << constantValue << std::endl;

    int variable = 50;
    std::cout << "Variable: " << variable << std::endl;

    const int* ptrToConst = &constantValue;
    std::cout << "Pointer to cont points to: " << *ptrToConst << std::endl;

    // cannot compile
    // error: read-only variable is not assignable
    //(*ptrToConst)++;

    ptrToConst = &variable;
    std::cout << "After changing where pointer to const points: "
        << *ptrToConst << std::endl;

    int* const constPtr = &variable;

    (*constPtr)++;

    std::cout << "Const pointer can modify value: " << *constPtr
        << std::endl;

    // cannot compile
    // error: cannot assign to variable 'constPtr' with const-qualified
    // type 'int *const'
    //constPtr = constantValue;

    const int* const constPtrToConst = &constantValue;
    std::cout << "Const pointer to const: " << *constPtrToConst
        << std::endl;

}
