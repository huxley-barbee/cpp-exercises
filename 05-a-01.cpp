/*
 * ## EXERCISE 1: Memory Layout — The Five Segments [5.a.i]
 *
 * Every Linux process has a well-defined virtual address space divided into segments.
 * Write a program that maps its own address space and prints the address of a variable
 * from each segment.
 *
 * **Requirements:**
 * 1. Print the address of:
 *    - A global initialised variable (`int g_init = 42`) — **data segment**
 *    - A global uninitialised variable (`int g_uninit`) — **BSS segment**
 *    - A string literal (`const char* s = "hello"`) — **text/rodata segment**
 *    - A local variable inside `main` — **stack**
 *    - A heap allocation via `new` — **heap**
 *    - A function pointer (`&main`) — **text segment**
 * 2. Observe the relative ordering of addresses: text < data ≈ BSS < heap … stack (high)
 * 3. Print `/proc/self/maps` (Linux) or explain the equivalent on your platform
 * 4. Show that the stack grows downward: declare two locals in nested scopes and compare addresses
 * 5. Show that the heap grows upward: allocate two objects and compare addresses
 * 6. Explain what happens when the stack overflows (infinite recursion) — demonstrate with
 *    a depth counter that stops safely before crashing
 *
 * **Expected output:**
 * ```
 * === Process Memory Layout ===
 *
 * Segment         Address             Value
 * text (fn ptr):  0x[low addr]        main
 * rodata (str):   0x[low addr]        "hello"
 * data (g_init):  0x[mid addr]        42
 * BSS  (g_uninit):0x[mid addr]        0
 * heap (new int): 0x[mid-high addr]   100
 * stack (local):  0x[high addr]       77
 *
 * Address ordering (low to high):
 *   text < rodata < data < BSS < heap ... stack
 *
 * === Stack Grows Downward ===
 * outer local addr: 0x[addr_high]
 * inner local addr: 0x[addr_low]   <- lower (stack grew down)
 *
 * === Heap Grows Upward ===
 * first alloc:  0x[addr_low]
 * second alloc: 0x[addr_high]  <- higher (heap grew up)
 *
 * === Stack Overflow (safe demo) ===
 * Recursion depth 1000: stack frame addr 0x[addr]
 * Recursion depth 2000: stack frame addr 0x[lower addr]
 * Stopping before overflow...
 * Stack frame shrinks by ~[N] bytes per call
 * ```
 */

int main() {}
