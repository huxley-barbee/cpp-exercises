/*
 * Exercise 1 — Variable Scope Resolution
 * Tag: 1.a.i Variables, types, scope
 *
 * Declare a global int x initialized to 5.
 * Inside main(), declare a local int x initialized to 10.
 * Inside a nested block within main(), declare another int x initialized to 20.
 *
 * Print:
 *   1) the global x
 *   2) the local x in main
 *   3) the block-local x
 *
 * Use scope resolution explicitly where required.
 */

#include <iostream>

int x = 5;

int main() {
    int x = 10;

    /**
     * :: is the scope resolution operator.
     * normally, there is a scope qualifier,
     * which could be a struct name or namespace.
     *
     * When used without a scope qualifier, name lookup
     * searches the innermost enclosing scope outward,
     * and only reaches globals if no closer match exists.
     */
    std::cout << ::x << std::endl;
    std::cout << x << std::endl;

    {
        int x = 20;

        /* cannot print all three here.
         * there is not way to reference 
         * the outer block's x using the
         * scope resolution operator.
         */
        std::cout << x << std::endl;
    }

}
