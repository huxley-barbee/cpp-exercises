/*
 * ## EXERCISE 8: Makefiles — Advanced Features [5.c.ii]
 *
 * Read and write the advanced Makefile idioms you will encounter in real quant codebases.
 *
 * **Requirements:**
 * 1. `$(wildcard src/*.cpp)` — auto-discover source files
 * 2. `$(patsubst src/%.cpp, obj/%.o, $(SRCS))` — derive object names
 * 3. `$(shell git describe --tags --always)` — embed a version string at build time
 * 4. Conditional block: `ifeq ($(ARCH), native)` → append `-march=native` to `CXXFLAGS`
 * 5. Write a `version.h` generation rule (target depends on a sentinel file that is
 *    updated whenever the git tag changes)
 * 6. `VPATH = src lib` — let Make find sources in multiple directories
 * 7. `$(info ...)` and `$(error ...)` for Makefile-level debug/error output
 * 8. `override CXXFLAGS += -Wall` — preserve user-supplied `CXXFLAGS` while adding flags
 * 9. A `tags` target using `ctags -R src/ include/` for IDE navigation
 *
 * **Expected output:**
 * ```
 * === Advanced Makefile Features ===
 *
 * Auto-discovered sources:
 *   SRCS = src/main.cpp src/pricer.cpp src/risk.cpp
 *
 * Derived objects:
 *   OBJS = obj/main.o obj/pricer.o obj/risk.o
 *
 * Version string embedded:
 *   #define BUILD_VERSION "v1.2.3-4-gabcdef"
 *
 * $ make ARCH=native
 *   Flags: -std=c++17 -O2 -Wall -march=native
 *
 * $ make info
 *   CXX  = g++
 *   SRCS = src/main.cpp src/pricer.cpp src/risk.cpp
 *   OBJS = obj/main.o obj/pricer.o obj/risk.o
 *
 * Generated include/version.h:
 *   #define BUILD_VERSION "v1.2.3"
 *   #define BUILD_DATE    "20240115"
 * ```
 */

int main() {}
