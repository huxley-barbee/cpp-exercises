/*
 * ## EXERCISE 8: Interface Segregation [2.b.iii]
 * 
 * Write a program demonstrating interface segregation principle.
 * 
 * **Requirements:**
 * 1. Create "fat" interface with many methods
 * 2. Show problem when class doesn't need all methods
 * 3. Split into smaller, focused interfaces
 * 4. Implement only needed interfaces
 * 5. Demonstrate multiple interface inheritance
 * 
 * **Expected output format:**
 * ```
 * === Fat Interface Problem ===
 * class IWorker {
 *   virtual void work() = 0;
 *   virtual void eat() = 0;
 *   virtual void sleep() = 0;
 * };
 * 
 * Robot must implement eat() and sleep() even though robots don't eat/sleep!
 * Robot working...
 * Robot eat: No-op (doesn't make sense!)
 * Robot sleep: No-op (doesn't make sense!)
 * 
 * === Interface Segregation Solution ===
 * Split into focused interfaces:
 * - IWorkable { work() }
 * - IFeedable { eat() }
 * - IRestable { sleep() }
 * 
 * Human implements all three:
 * Human working...
 * Human eating...
 * Human sleeping...
 * 
 * Robot implements only IWorkable:
 * Robot working...
 * (No eat/sleep methods - cleaner design!)
 * ```
 */

#include <iostream>

class IWorker {
    public:
        virtual void work() = 0;
        virtual void eat() = 0;
        virtual void sleep() = 0;
};

class FatRobot : public IWorker {

    public:
        void work() {
            std::cout << "working...";
        }
        void eat() {
            std::cout << "No-op";
        }
        void sleep() {
            std::cout << "No-op";
        }
};

class IWorkable {
    public:
        virtual void work() = 0;
};

class IFeedable {
    public:
        virtual void eat() = 0;
};

class IRestable {
    public:
        virtual void sleep() = 0;
};

class Human : public IWorkable, public IFeedable, public IRestable {
    public:
        void work() {
            std::cout << "working...";
        }
        void eat() {
            std::cout << "eating...";
        }
        void sleep() {
            std::cout << "sleeping...";
        }
};

class Robot : public IWorkable {
    public:
        void work() {
            std::cout << "working...";
        }
};

int main() {

    std::cout << "=== Fat Interface Problem ===\n";
    std::cout << "class IWorker {\n";
    std::cout << "\tvirtual void work() = 0;\n";
    std::cout << "\tvirtual void eat() = 0;\n";
    std::cout << "\tvirtual void sleep() = 0;\n";
    std::cout << "};\n";

    std::cout << "Robot must implement eat() and sleep() even though robots don't eat/sleep!\n";
    FatRobot fatRobot;
    std::cout << "Robot ";
    fatRobot.work();
    std::cout << "\n";
    std::cout << "Robot eat: ";
    fatRobot.eat();
    std::cout << " (doesn't make sense!)\n";
    std::cout << "Robot sleep: ";
    fatRobot.sleep();
    std::cout << " (doesn't make sense!)\n";

    std::cout << "\n";

    std::cout << "=== Interface Segregation Solution ===\n";
    std::cout << "Split into focused interfaces:\n";
    std::cout << "- IWorkable { work() }\n";
    std::cout << "- IFeedable { eat() }\n";
    std::cout << "- IRestable { sleep() }\n";

    std::cout << "\n";

    std::cout << "Human implements all three:\n";
    Human human;
    std::cout << "Human ";
    human.work();
    std::cout << "\n";
    std::cout << "Human ";
    human.eat();
    std::cout << "\n";
    std::cout << "Human ";
    human.sleep();
    std::cout << "\n";

    std::cout << "\n";

    std::cout << "Robot implements only IWorkable:\n";
    Robot robot;
    std::cout << "Robot ";
    robot.work();
    std::cout << "\n";
    std::cout << "(No eat/sleep methods - cleaner design!)\n";

}


