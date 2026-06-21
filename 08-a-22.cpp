/*
 * ## EXERCISE 22: Yield Curve Construction [8.a.i–iii]
 *
 * **Requirements:**
 * 1. Bootstrap a zero-coupon yield curve from par swap rates
 * 2. Fit a Nelson-Siegel-Svensson model to the bootstrapped curve using LM
 * 3. Implement cubic spline interpolation for the zero curve
 * 4. Compute DV01 for each instrument
 * 5. Compute key rate durations (sensitivities to 1bp moves at each knot)
 * 6. Implement PCA on historical curve changes to find level, slope, curvature modes
 *
 * **Expected output:**
 * ```
 * === Yield Curve Bootstrap ===
 * Par rates:  3M=3.20%  6M=3.45%  1Y=3.70%  2Y=3.95%  5Y=4.18%  10Y=4.30%
 * Zero rates: 3M=3.20%  6M=3.46%  1Y=3.72%  2Y=3.99%  5Y=4.27%  10Y=4.43%
 *
 * === NSS Fit ===
 * beta0=4.43, beta1=-1.23, beta2=2.11, tau1=0.92, tau2=3.84
 * RMSE: 0.4bp
 *
 * === PCA of Curve Changes ===
 * PC1 (level):     82% variance
 * PC2 (slope):     12% variance
 * PC3 (curvature):  4% variance
 * ```
 */

int main() {}
