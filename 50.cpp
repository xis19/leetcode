#include <functional>
double pow(double x, int n) {
    std::function<double (double, int)>p = [&](double u, int m) -> double {
        if (m == 0) {
            return 1.0;
        } else if (m == 1) {
            return u;
        } else if (m == 2) {
            return u * u;
        } else {
            return p(p(u, m / 2), 2) * (m % 2 ? u : 1);
        }
    };
    if (n < 0) {
        return p(1 / x, -n);
    } else {
        return p(x, n);
    }
}
