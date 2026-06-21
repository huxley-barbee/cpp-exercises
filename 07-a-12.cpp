/*
 * ## EXERCISE 12: Incremental Modernisation — The Strangler Fig Pattern [7.a.iv]
 *
 * The Strangler Fig: build the new system alongside the old, route traffic gradually,
 * retire the old when fully replaced.
 *
 * **Requirements:**
 *
 * You have a legacy `OldOrderRouter` that must be replaced with a new `NewOrderRouter`.
 * You cannot do a big-bang replacement — the system must stay live.
 *
 * 1. Implement `OldOrderRouter` (C++98 style): routes orders via a raw function pointer
 *    callback, uses global state, no error handling
 * 2. Implement `NewOrderRouter` (C++17 style): uses `std::function`, `std::optional`,
 *    `std::variant` for error types, fully tested
 * 3. Implement `StranglerRouter` that:
 *    - Accepts a `double routingFraction` (0.0 = all old, 1.0 = all new)
 *    - Routes each order to old or new based on a deterministic hash of the order ID
 *    - Logs which router handled each order
 *    - Can be reconfigured at runtime (atomic swap of routing fraction)
 * 4. Demonstrate: start at 0% new, ramp to 10%, 50%, 100%, verify results match at each step
 * 5. Show rollback: if `NewOrderRouter` returns an error, `StranglerRouter` falls back
 *    to `OldOrderRouter`
 * 6. Show the final cutover: `routingFraction = 1.0`, then delete `OldOrderRouter`
 *
 * **Expected output:**
 * ```
 * === Strangler Fig Migration ===
 *
 * OldOrderRouter: C++98, global state, function pointer callbacks
 * NewOrderRouter: C++17, std::function, std::optional errors
 *
 * StranglerRouter at 0%:
 *   Order 1 -> OldRouter -> accepted
 *   Order 2 -> OldRouter -> accepted
 *   All orders: OldRouter (0/10 new)
 *
 * StranglerRouter at 50%:
 *   Order 1 -> OldRouter -> accepted
 *   Order 2 -> NewRouter -> accepted
 *   Order 3 -> OldRouter -> accepted
 *   ...
 *   5/10 orders via NewRouter
 *
 * StranglerRouter at 100%:
 *   All 10 orders -> NewRouter -> accepted
 *   OldRouter no longer called
 *
 * Rollback test:
 *   NewRouter returns error for order 7
 *   StranglerRouter fell back to OldRouter -> accepted
 *   PASS
 * ```
 */

int main() {}
