/*
 * ## EXERCISE 2: Threads — `std::jthread` and Stop Tokens (C++20) [6.a.i]
 *
 * `std::jthread` auto-joins on destruction and supports cooperative cancellation
 * via `std::stop_token`. This is the preferred thread type for new code.
 *
 * **Requirements:**
 * 1. Create a `std::jthread` that loops, checking `stop_token::stop_requested()` each iteration
 * 2. Let it run for 200ms, then let it go out of scope (auto-join fires, stop is requested)
 * 3. Register a `std::stop_callback` that logs when cancellation is requested
 * 4. Compare with the C++11 manual pattern: `std::atomic<bool> running{true}` + `running=false` + `join()`
 * 5. Show `request_stop()` explicitly and verify the thread sees it immediately
 * 6. Demonstrate that `std::jthread` joining on destruction prevents the `std::terminate`
 *    bug from Exercise 1
 *
 * **Expected output:**
 * ```
 * === std::jthread ===
 * Worker started, will loop until stop requested
 * [stop_callback] cancellation requested!
 * Worker saw stop_requested — exiting cleanly
 * jthread destroyed (auto-joined)
 *
 * === Manual stop (C++11 style) ===
 * Worker running... (iteration 1)
 * Worker running... (iteration 2)
 * running=false set by main
 * Worker exiting (saw running==false)
 * Joined manually
 *
 * === request_stop() explicit ===
 * Worker iteration 1
 * Worker iteration 2
 * request_stop() called
 * Worker saw stop: exiting
 * Joined
 *
 * Comparison:
 *   jthread:  auto-join + stop_token — no forget-to-join bug
 *   thread:   manual join required — easy to forget
 * ```
 */

int main() {}
