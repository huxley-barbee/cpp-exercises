/*
 * ## EXERCISE 12: Global State — Legacy Patterns [4.a.v]
 *
 * C++98 code frequently used global variables and singletons implemented with raw pointers.
 *
 * **Requirements:**
 * 1. Implement a C++98 global configuration store: `namespace Config { extern int maxConnections; extern std::string serverName; }`
 * 2. Implement a C++98 raw-pointer Singleton: `static Logger* instance_; static Logger* getInstance()`
 * 3. Show the initialisation order fiasco: two global objects, one depends on the other
 * 4. Show thread-safety problem of the raw Singleton (mention — do not require threads)
 * 5. Demonstrate proper teardown (destructor / `atexit`) and what happens without it
 * 6. Note modern replacements: `inline` variables (C++17), `std::call_once`, function-local statics
 *
 * **Expected output:**
 * ```
 * === Global Configuration (C++98) ===
 * Config::maxConnections = 100
 * Config::serverName = "prod-server-01"
 * (Accessible from any translation unit — tight coupling)
 *
 * === Raw Singleton ===
 * Logger::getInstance() — first call, creating instance
 * Logger: [INFO] Application started
 * Logger::getInstance() — returning existing instance
 * Logger: [INFO] Processing request
 *
 * === Initialisation Order Fiasco ===
 * GlobalA constructor (depends on GlobalB)
 * GlobalB constructor
 * WARNING: GlobalA may have seen an uninitialised GlobalB!
 * (Order across TUs is undefined in C++98)
 *
 * Modern fix: function-local static (C++11 guarantees thread-safe init)
 * static Logger& getInstance() { static Logger inst; return inst; }
 *
 * === Teardown Problem ===
 * atexit handler: deleting Logger singleton
 * (Without atexit, destructor never called — resource leak at exit)
 *
 * Modern: function-local static destroyed automatically at program end
 * ```
 */

int main() {}
