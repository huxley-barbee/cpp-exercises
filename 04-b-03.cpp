/*
 * ## EXERCISE 3: Virtual Dispatch — Manual vtable Simulation [4.b.i]
 *
 * To understand vtables deeply, implement one by hand.
 *
 * **Requirements:**
 * 1. Create a `struct VTable` containing raw function pointers for `speak` and `describe`
 * 2. Create two "classes" as plain structs: `Dog` and `Cat`, each with a `VTable*` as first member
 * 3. Implement standalone functions `dog_speak`, `cat_speak`, `dog_describe`, `cat_describe`
 * 4. Initialise global `VTable` instances for Dog and Cat
 * 5. Write a `makeSound(void* obj)` function that casts `void*` to `VTable**` and dispatches
 * 6. Show this is exactly what the compiler does automatically with `virtual`
 * 7. Measure: does your manual vtable match compiler-generated dispatch speed?
 *
 * **Expected output:**
 * ```
 * === Manual vtable Simulation ===
 *
 * Dog vtable:
 *   [0] speak    -> dog_speak
 *   [1] describe -> dog_describe
 *
 * Cat vtable:
 *   [0] speak    -> cat_speak
 *   [1] describe -> cat_describe
 *
 * Dispatching via void* (C-style):
 * makeSound(&dog) -> Woof!
 * makeSound(&cat) -> Meow!
 *
 * describe(&dog)  -> I am a Dog
 * describe(&cat)  -> I am a Cat
 *
 * This is what the compiler generates for virtual functions.
 * Overhead: one pointer dereference + one indirect call.
 *
 * === With compiler-generated vtable ===
 * dog.speak()  -> Woof!   (same dispatch, done automatically)
 * cat.speak()  -> Meow!
 * ```
 */

int main() {}
