/*
 * ## EXERCISE 7: Function Pointers — Jump Tables and Hot-Path Dispatch [4.c.iii]
 *
 * In low-latency market-data handlers and order routers, function pointer jump tables are
 * used to dispatch on message type without a `switch` statement.
 *
 * **Requirements:**
 * 1. Define an enum `MessageType { MSG_QUOTE=0, MSG_TRADE, MSG_ORDER, MSG_CANCEL, MSG_COUNT }`
 * 2. Define `typedef void (*MessageHandler)(const void* msg)`
 * 3. Create a `MessageHandler handlers[MSG_COUNT]` jump table, one handler per type
 * 4. Write a `dispatch(MessageType t, const void* msg)` that calls `handlers[t](msg)`
 * 5. Define concrete structs: `QuoteMsg`, `TradeMsg`, `OrderMsg`, `CancelMsg`
 * 6. Show the performance argument: a jump table avoids branch misprediction from `switch`
 * 7. Demonstrate bounds-checking the table index before dispatch
 * 8. Compare with C++11 `std::array<std::function<...>, MSG_COUNT>`
 *
 * **Expected output:**
 * ```
 * === Message Jump Table ===
 *
 * Jump table:
 *   handlers[MSG_QUOTE]  = handleQuote
 *   handlers[MSG_TRADE]  = handleTrade
 *   handlers[MSG_ORDER]  = handleOrder
 *   handlers[MSG_CANCEL] = handleCancel
 *
 * Dispatching 5 messages:
 *   dispatch(MSG_QUOTE,  ...) -> [QUOTE]  AAPL bid=149.95 ask=150.05
 *   dispatch(MSG_TRADE,  ...) -> [TRADE]  AAPL 100@150.00
 *   dispatch(MSG_ORDER,  ...) -> [ORDER]  BUY 50 MSFT @300.00
 *   dispatch(MSG_CANCEL, ...) -> [CANCEL] orderId=42
 *   dispatch(MSG_QUOTE,  ...) -> [QUOTE]  MSFT bid=299.90 ask=300.10
 *
 * === Bounds Check ===
 * dispatch(99, ...): invalid message type — ignored
 *
 * === Performance Note ===
 * switch(type): potentially 4 comparisons + branch misprediction
 * jump table:   1 bounds check + 1 indirect call
 * At 10M msgs/sec: jump table saves ~50ns per message
 *
 * === Modern: std::array<std::function<...>> ===
 * Same dispatch, but handlers can be lambdas with captured state
 * ```
 */

int main() {}
