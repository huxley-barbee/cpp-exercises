/*
 * ## EXERCISE 5: Order Gateways — FIX Protocol Message Builder [8.c.ii]
 *
 * The Financial Information eXchange (FIX) protocol is the industry standard
 * for order routing. Build a zero-copy FIX message serialiser.
 *
 * **Requirements:**
 * 1. Implement a `FixMessage` class with a `char buf_[512]` internal buffer:
 *    - `addTag(int tag, const char* value)` — appends `tag=value\x01`
 *    - `addTag(int tag, double value, int decimals)` — formats double without `printf`
 *    - `addTag(int tag, int64_t value)` — formats integer without `printf`
 * 2. Build a `NewOrderSingle` (FIX MsgType=D) message:
 *    - Tags: 35=D, 49 (SenderCompID), 56 (TargetCompID), 11 (ClOrdID),
 *      55 (Symbol), 54 (Side), 38 (OrderQty), 44 (Price), 40 (OrdType),
 *      60 (TransactTime)
 * 3. Implement FIX checksum: sum all bytes mod 256, append as tag 10
 * 4. Implement FIX `BeginString` (8=FIX.4.2) and `BodyLength` (9=N) headers
 * 5. Implement a **FIX parser** that extracts tags from a raw FIX string into
 *    a `std::array<std::pair<int,std::string_view>, 32>` without heap allocation
 * 6. Benchmark: build 1M NewOrderSingle messages — target < 200ns each
 * 7. Verify: serialise → parse → verify all fields round-trip correctly
 *
 * **Expected output:**
 * ```
 * === FIX NewOrderSingle ===
 * 8=FIX.4.2|9=148|35=D|49=TRADER1|56=EXCHANGE|11=ORD001|
 * 55=AAPL|54=1|38=100|44=150.25|40=2|60=20240115-10:23:45.123|10=247|
 *
 * Build benchmark (1M messages): 142ns avg  PASS (<200ns target)
 *
 * === Round-trip verification ===
 * Tag 35: 'D'     PASS
 * Tag 55: 'AAPL'  PASS
 * Tag 44: '150.25' PASS
 * Tag 38: '100'   PASS
 * Checksum: 247   PASS
 *
 * No heap allocations during build or parse  PASS
 * ```
 */

int main() {}
