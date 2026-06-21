/*
 * ## EXERCISE 20: Message Buses — Serialisation and Protocol Design [8.b.v]
 *
 * An inter-process message format must be compact, fast to serialise/deserialise,
 * and versioned for backwards compatibility.
 *
 * **Requirements:**
 * 1. Design a **binary message format** for market data ticks:
 *    - 4-byte magic number + 1-byte version
 *    - Fixed header: message type, length, sequence number, timestamp
 *    - Variable payload: depends on message type
 * 2. Implement `serialise(Tick) -> std::vector<uint8_t>` and
 *    `deserialise(bytes) -> Tick`
 * 3. Implement **message framing** for a stream protocol:
 *    length-prefixed framing so multiple messages can be sent over one TCP socket
 * 4. Show **versioning**: add a new field in v2 of the Tick message;
 *    v1 readers should ignore the new field gracefully
 * 5. Compare serialisation performance vs JSON (using `nlohmann/json` or hand-rolled):
 *    binary format should be 10-50× faster
 * 6. Implement a **checksum** (CRC32) to detect transmission errors
 * 7. Show **endianness handling**: always write little-endian for cross-platform compatibility
 *
 * **Expected output:**
 * ```
 * === Binary Tick Message (v1) ===
 * Bytes: [4C 4D 44 53] [01] [00 01] [00 40] [seq=12345] [ts=...] [payload]
 *          magic        ver  type   len
 * Total: 64 bytes per tick
 *
 * Serialise 1M ticks:
 *   Binary format: 48ms   (20.8M ticks/sec)
 *   JSON format:  820ms   (1.22M ticks/sec)
 *   Speedup: 17x
 *
 * === Versioning ===
 * v1 writer -> v2 reader:   v2 reads new fields as defaults  PASS
 * v2 writer -> v1 reader:   v1 ignores unknown trailing bytes  PASS
 *
 * Checksum: CRC32 mismatch detected and message dropped  PASS
 * Endianness: little-endian on LE machine, byte-swapped on BE  PASS
 * ```
 */

int main() {}
