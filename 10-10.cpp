/*
 * ## EXERCISE 10: Python Bindings — Advanced pybind11 [10.e]
 *
 * Expose a more complex C++ pricing library to Python, handling ownership,
 * callbacks, and NumPy integration properly.
 *
 * **Requirements:**
 * 1. Expose a **yield curve** class that accepts a Python `list` of
 *    `(tenor, rate)` tuples and returns discount factors and forward rates
 * 2. Implement a **callback interface**: allow Python to pass a pricing
 *    function that the C++ risk engine calls for each scenario:
 *    ```python
 *    def my_pricer(S, K, T, sigma, r):
 *        return custom_model(S, K, T, sigma, r)
 *    risk.run_scenarios(my_pricer, scenarios)
 *    ```
 * 3. Use `pybind11::gil_scoped_release` in long-running C++ functions so
 *    other Python threads can run while waiting
 * 4. Expose a C++ `std::vector<double>` as a Python list and as a NumPy array
 *    without copying (using `py::array_t` with `py::buffer_protocol`)
 * 5. Show proper **object lifetime**: a `BondPricer` held in Python must not
 *    be destroyed while the C++ `PortfolioManager` still references it
 * 6. Run the binding under `pytest` with 5 test cases
 *
 * **Expected output:**
 * ```python
 * >>> curve = quant.YieldCurve([(0.25, 0.032), (1.0, 0.037), (5.0, 0.042)])
 * >>> curve.discount_factor(1.0)
 * 0.9637
 * >>> curve.forward_rate(1.0, 2.0)
 * 0.0421
 *
 * >>> def my_pricer(S, K, T, sigma, r): return S - K * 0.95
 * >>> engine = quant.RiskEngine()
 * >>> results = engine.run_scenarios(my_pricer, [(100,100,1,0.2,0.05)] * 1000)
 * >>> len(results)
 * 1000
 *
 * >>> # NumPy zero-copy
 * >>> cf = bond.cashflows_as_array()  # returns np.ndarray backed by C++ memory
 * >>> cf.flags['OWNDATA']
 * False   # no copy made  PASS
 *
 * === pytest results ===
 * test_yield_curve.py::test_discount_factor    PASSED
 * test_yield_curve.py::test_forward_rate       PASSED
 * test_bindings.py::test_exception_translation PASSED
 * test_bindings.py::test_numpy_nocopy          PASSED
 * test_bindings.py::test_callback              PASSED
 * 5/5 passed
 * ```
 */

int main() {}
