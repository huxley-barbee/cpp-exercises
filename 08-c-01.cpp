/*
 * ## EXERCISE 1: Market Data Handlers — Raw Packet Processing [8.c.i]
 *
 * The first step in any market data handler is receiving raw bytes from the
 * network and extracting structured messages.
 *
 * **Requirements:**
 * 1. Implement a `PacketBuffer` struct:
 *    - Fixed-size array `uint8_t data[1500]` (max Ethernet frame)
 *    - `uint16_t len` — actual bytes received
 *    - `int64_t rx_timestamp_ns` — hardware receive timestamp (or `CLOCK_REALTIME`)
 *    - `sizeof(PacketBuffer)` must be a multiple of 64 (cache-line aligned)
 * 2. Implement a `UDPReceiver` class that binds to a multicast group and
 *    receives packets into a pre-allocated pool of `PacketBuffer` objects
 *    (no heap allocation during packet receive)
 * 3. Implement a minimal **ITCH 5.0-style message parser**:
 *    - Message types: `'T'` (timestamp), `'A'` (add order), `'D'` (delete order),
 *      `'E'` (execution), `'P'` (price update)
 *    - Each message starts with a 2-byte length prefix and 1-byte type byte
 *    - Parse into a `ParsedMessage` variant-like union
 * 4. Implement a **message dispatch table**: an array of function pointers indexed
 *    by message type (`handlers_[256]`) — O(1) dispatch, no `switch` statement
 * 5. Show the packet receive → parse → dispatch latency end-to-end
 * 6. Demonstrate zero-copy parsing: parse fields directly from the receive buffer
 *    without copying bytes
 *
 * **Expected output:**
 * ```
 * === Packet Buffer ===
 * sizeof(PacketBuffer) = 1536 bytes (multiple of 64)  PASS
 * Packet pool: 256 pre-allocated buffers, 0 heap allocs during receive
 *
 * === ITCH Parser ===
 * Parsed 1M messages:
 *   'T' timestamp:    200K  avg parse=  8ns
 *   'A' add order:    400K  avg parse= 12ns
 *   'D' delete:       200K  avg parse=  9ns
 *   'E' execution:    150K  avg parse= 11ns
 *   'P' price update:  50K  avg parse= 10ns
 *
 * Dispatch table (256 entries, function pointers):
 *   handler['A'] = onAddOrder     (12ns including parse)
 *   handler['D'] = onDeleteOrder
 *   handler['E'] = onExecution
 *
 * End-to-end (recv -> parse -> dispatch): p50=85ns  p99=142ns
 * Zero-copy: fields read directly from recv buffer  PASS
 * ```
 */

int main() {}
