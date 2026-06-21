/*
 * ## EXERCISE 11: Homegrown Containers — Legacy Linked List [4.a.v]
 *
 * Many quant legacy codebases contain hand-rolled data structures written before the STL was trusted.
 * Write a C++98-style intrusive singly-linked list.
 *
 * **Requirements:**
 * 1. `struct Node { int value; Node* next; }`
 * 2. `class LinkedList` with raw `Node*` head, `push_front()`, `pop_front()`, `print()`, destructor
 * 3. No smart pointers — all raw `new`/`delete`
 * 4. Implement copy constructor and copy assignment (deep copy)
 * 5. Show what happens without them (shallow copy / double-free)
 * 6. Demonstrate the list works correctly, then note the `std::list` / `std::forward_list` equivalent
 *
 * **Expected output:**
 * ```
 * === C++98 Intrusive Linked List ===
 * push_front(30), push_front(20), push_front(10)
 * List: 10 -> 20 -> 30 -> NULL
 *
 * pop_front(): removed 10
 * List: 20 -> 30 -> NULL
 *
 * === Deep Copy ===
 * list2 = list1 (copy constructor)
 * list1: 20 -> 30 -> NULL
 * list2: 20 -> 30 -> NULL (independent nodes)
 *
 * Modifying list1 (pop_front):
 * list1: 30 -> NULL
 * list2: 20 -> 30 -> NULL (unaffected)
 *
 * === Cleanup ===
 * ~LinkedList(list1): freed 1 node
 * ~LinkedList(list2): freed 2 nodes
 * No double-free!
 *
 * Modern equivalent: std::forward_list<int> — zero manual memory
 * ```
 */

int main() {}
