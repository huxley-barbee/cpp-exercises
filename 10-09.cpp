/*
 * ## EXERCISE 9: Python Bindings — pybind11 Basics [10.e]
 *
 * Expose a C++ Black-Scholes pricer to Python for use in quant research notebooks.
 *
 * **Requirements:**
 * 1. Write a pybind11 module `quant` that exposes:
 *    - A free function `black_scholes(S, K, T, sigma, r) -> float`
 *    - A class `EuropeanOption` with `price()`, `delta()`, `gamma()`, `vega()`, `theta()`
 *    - A class `BondPricer` (from Exercise 1) with `price(yield_) -> float`
 * 2. Handle Python exceptions correctly:
 *    - C++ `std::invalid_argument` → Python `ValueError`
 *    - C++ `std::runtime_error` → Python `RuntimeError`
 * 3. Support **NumPy arrays**: use `pybind11/numpy.h` to accept and return
 *    `py::array_t<double>` for vectorised pricing
 * 4. Implement `__repr__` and `__str__` for `EuropeanOption`
 * 5. Add Python **docstrings** to all exposed functions and classes
 * 6. Build with `pip install -e .` using a `setup.py` / `pyproject.toml`
 *
 * **Expected output (Python session):**
 * ```python
 * >>> import quant
 * >>> quant.black_scholes(100, 100, 1, 0.2, 0.05)
 * 10.450583572185565
 *
 * >>> opt = quant.EuropeanOption(S=100, K=100, T=1, sigma=0.2, r=0.05)
 * >>> opt.price()
 * 10.450583572185565
 * >>> opt.delta()
 * 0.6368306830627498
 * >>> repr(opt)
 * "EuropeanOption(S=100.0, K=100.0, T=1.0, sigma=0.2, r=0.05)"
 *
 * >>> import numpy as np
 * >>> S_vec = np.linspace(80, 120, 5)
 * >>> quant.black_scholes_vec(S_vec, K=100, T=1, sigma=0.2, r=0.05)
 * array([ 2.03,  5.97, 10.45, 16.24, 22.75])
 *
 * >>> quant.black_scholes("bad", 100, 1, 0.2, 0.05)
 * ValueError: invalid S
 *
 * >>> help(quant.black_scholes)
 * black_scholes(S, K, T, sigma, r) -> float
 *     Price a European call option using the Black-Scholes formula.
 *     Parameters: S (spot), K (strike), T (time to expiry in years),
 *                 sigma (vol), r (risk-free rate)
 * ```
 */

int main() {}
