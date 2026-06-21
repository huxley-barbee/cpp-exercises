/*
 * ## EXERCISE 13: Comprehensive Integration [All of 6.b]
 *
 * Build a **parallel Monte Carlo risk engine** that uses `async`/`futures`,
 * a thread pool, and the executor pattern together.
 *
 * **Requirements:**
 * 1. `RiskEngine` class:
 *    - Owns a `ThreadPool` (N threads, configurable)
 *    - `submitPricingJob(params) -> std::future<double>`: submit one pricing task
 *    - `computeVaR(portfolio, numScenarios) -> std::future<double>`: submits
 *      `numScenarios` parallel pricing tasks using `parallelFor`, then aggregates
 *    - `computeGreeks(option) -> std::future<Greeks>`: submits 9 bump tasks in parallel
 * 2. `MonteCarloEngine`:
 *    - `runScenario(params, seed) -> double`: prices the portfolio under one random scenario
 *    - Thread-safe: each thread gets its own RNG seeded from `seed + thread_id`
 * 3. Orchestration:
 *    - Launch VaR computation (10K scenarios) and Greeks (9 bumps) concurrently
 *    - Use `std::async` to launch the two top-level jobs simultaneously
 *    - Each delegates internally to the thread pool
 * 4. Measure total wall time — should be close to `max(VaR_time, Greeks_time)` not sum
 * 5. Add a `StrandExecutor` for result logging (serialised writes to cout)
 *
 * **Expected output:**
 * ```
 * === Parallel Monte Carlo Risk Engine ===
 *
 * Configuration:
 *   ThreadPool: 8 workers
 *   VaR scenarios: 10,000
 *   Greeks bump size: 0.01
 *
 * === Concurrent execution ===
 * Launching VaR and Greeks simultaneously...
 *
 * VaR computation:   10000 scenarios across 8 workers
 * Greeks computation: 9 bumps across 8 workers
 *
 * VaR job finished:    420ms
 * Greeks job finished: 38ms
 *
 * Total wall time:     422ms  (concurrent — close to max, not sum)
 * Serial equivalent:   ~460ms
 *
 * === Results ===
 * VaR (95%):    $12,340
 * CVaR (95%):   $15,820
 *
 * Greeks:
 *   delta:  0.6368
 *   gamma:  0.0188
 *   vega:  37.5240
 *   theta: -6.4140
 *   rho:   53.2325
 *
 * === Strand logger (serialised output) ===
 * [LOG] VaR job submitted      t=0ms
 * [LOG] Greeks job submitted   t=0ms
 * [LOG] Greeks job complete    t=38ms
 * [LOG] VaR job complete       t=420ms
 * (All log lines from strand — no interleaving)
 *
 * === Concurrency audit ===
 * std::async:        top-level VaR and Greeks jobs
 * std::future:       result collection from all sub-tasks
 * std::packaged_task: tasks in ThreadPool queue
 * ThreadPool:        amortised thread reuse, 8 workers
 * parallelFor:       VaR scenario distribution
 * StrandExecutor:    serialised logging
 * ```
 */

int main() {}
