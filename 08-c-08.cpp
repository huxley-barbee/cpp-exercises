/*
 * ## EXERCISE 8: Order Gateways — TCP Connection Management [8.c.ii]
 *
 * Order gateways maintain persistent TCP connections to exchanges.
 * Connection management must be robust and fast.
 *
 * **Requirements:**
 * 1. Implement a `GatewayConnection` class:
 *    - Non-blocking TCP socket with `SO_NODELAY` (disable Nagle's algorithm)
 *    - `SO_SNDBUF` and `SO_RCVBUF` tuned to 256KB
 *    - Connect with timeout (100ms)
 *    - Heartbeat: send a FIX heartbeat every 30 seconds if no message sent
 * 2. Implement **connection state machine**:
 *    `DISCONNECTED → CONNECTING → LOGON_SENT → LIVE → LOGOUT_SENT → DISCONNECTED`
 * 3. Implement **automatic reconnection**:
 *    - On disconnect: exponential backoff (100ms, 200ms, 400ms, ... max 30s)
 *    - After reconnect: resend any unacknowledged orders
 * 4. Implement the **send queue**: orders queued during disconnection are sent
 *    on reconnect in submission order
 * 5. Measure: time from `connect()` to first order sent (logon round-trip)
 * 6. Show `TCP_QUICKACK` and `TCP_NODELAY` effects on latency
 *
 * **Expected output:**
 * ```
 * === Gateway Connection ===
 *
 * TCP options:
 *   SO_NODELAY:  enabled (disable Nagle)
 *   TCP_QUICKACK: enabled
 *   SO_SNDBUF:   262144 bytes
 *   SO_RCVBUF:   262144 bytes
 *
 * Connection timeline:
 *   t=0µs:    connect() called
 *   t=85µs:   TCP handshake complete
 *   t=120µs:  FIX Logon sent
 *   t=380µs:  FIX Logon ACK received
 *   t=380µs:  LIVE — ready to send orders
 *
 * Reconnect (after disconnect):
 *   Attempt 1: t=100ms  FAILED (exchange not ready)
 *   Attempt 2: t=300ms  SUCCESS
 *   Queued orders resent: 3
 *
 * Nagle disabled: latency p99=42µs  (vs 52µs with Nagle enabled)
 * ```
 */

int main() {}
