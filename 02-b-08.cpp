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

namespace bad_design {

    class IWorker {
        public:
            virtual void work() = 0;
            virtual void eat() = 0;
            virtual void sleep() = 0;
            virtual ~IWorker() = default;
    };

    class Robot : public IWorker {

        public:
            void work() {
                std::cout << "Robot working...\n";
            }
            void eat() {
                std::cout << "Robot eat: No-op (doesn't make sense!)\n";
            }
            void sleep() {
                std::cout << "Robot sleep: No-op (doesn't make sense!)\n";
            }
    };
};

namespace good_design {

    class IWorkable {
        public:
            virtual void work() = 0;
            virtual ~IWorkable() = default;
    };

    class IFeedable {
        public:
            virtual void eat() = 0;
            virtual ~IFeedable() = default;
    };

    class IRestable {
        public:
            virtual void sleep() = 0;
            virtual ~IRestable() = default;
    };

    class Human : public IWorkable, public IFeedable, public IRestable {
        public:
            void work() {
                std::cout << "Human working...\n";
            }
            void eat() {
                std::cout << "Human eating...\n";
            }
            void sleep() {
                std::cout << "Human sleeping...\n";
            }
    };

    class Robot : public IWorkable {
        public:
            void work() {
                std::cout << "Robot working...\n";
            }
    };
};

int main() {

    std::cout << "=== Fat Interface Problem ===\n";
    std::cout << "class IWorker {\n";
    std::cout << "\tvirtual void work() = 0;\n";
    std::cout << "\tvirtual void eat() = 0;\n";
    std::cout << "\tvirtual void sleep() = 0;\n";
    std::cout << "};\n";

    std::cout << "Robot must implement eat() and sleep() even though robots don't eat/sleep!\n";
    bad_design::Robot bloated;
    bad_design::IWorker& fatRobot = bloated;
    fatRobot.work();
    fatRobot.eat();
    fatRobot.sleep();

    std::cout << "\n";

    std::cout << "=== Interface Segregation Solution ===\n";
    std::cout << "Split into focused interfaces:\n";
    std::cout << "- IWorkable { work() }\n";
    std::cout << "- IFeedable { eat() }\n";
    std::cout << "- IRestable { sleep() }\n";

    std::cout << "\n";

    std::cout << "Human implements all three:\n";
    good_design::Human human;
    good_design::IWorkable& work = human;
    work.work();
    good_design::IFeedable& feed = human;
    feed.eat();
    good_design::IRestable& rest = human;
    rest.sleep();

    std::cout << "\n";

    std::cout << "Robot implements only IWorkable:\n";
    good_design::Robot robot;
    good_design::IWorkable& clean_robot = robot;
    clean_robot.work();
    std::cout << "(No eat/sleep methods - cleaner design!)\n";

}


