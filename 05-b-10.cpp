/*
 * ## EXERCISE 10: NUMA — Topology and Memory Placement [5.b.iv]
 *
 * On multi-socket servers (common in trading infrastructure) memory access to a remote
 * NUMA node is 1.5–3× slower than local access. Write a program that measures this.
 *
 * **Requirements:**
 * 1. Use `numa_available()` / `numa_num_configured_nodes()` to detect NUMA topology
 * 2. Allocate a 256 MB buffer on NUMA node 0 using `numa_alloc_onnode()`
 * 3. Run a read benchmark from a thread pinned to node 0 (local access)
 * 4. Run the same benchmark from a thread pinned to node 1 (remote access)
 * 5. Compare latencies — expect ~40ns local vs ~90ns remote
 * 6. Demonstrate `numa_alloc_interleaved()` for balanced NUMA allocation
 * 7. Show `numactl --hardware` output (document in a comment)
 * 8. State the trading-system rule: market-data threads, their ring buffers, and their
 *    NIC receive queues must all be on the same NUMA node
 *
 * **Expected output:**
 * ```
 * === NUMA Topology ===
 * NUMA nodes: 2
 * Node 0 CPUs: 0-11
 * Node 1 CPUs: 12-23
 * Node 0 memory: 64GB
 * Node 1 memory: 64GB
 *
 * === Memory Latency (pointer chasing, 256MB) ===
 * Local  access (thread on node 0, memory on node 0): 42ns/access
 * Remote access (thread on node 1, memory on node 0): 89ns/access
 * Remote penalty: 2.1x slower
 *
 * === Interleaved Allocation ===
 * numa_alloc_interleaved(256MB):
 *   Pages alternated across nodes
 *   Avg latency: 61ns  (between local and remote)
 *   Useful for: shared data structures accessed by threads on both nodes
 *
 * === Trading System Rule ===
 * Market-data pipeline on node 0:
 *   NIC RX queue -> NUMA node 0 IRQ affinity
 *   Receive thread pinned to node 0 core
 *   Ring buffer allocated on node 0
 *   -> all accesses local: 42ns latency
 * ```
 */

int main() {}
