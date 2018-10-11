#include <cmath>
#include <vector>

bool isMonotonic(const std::vector<int>& A) {
    auto sgn = [](int v) { return v > 0 ? 1 : (v < 0 ? -1 : 0); };
    if (A.size() == 0) {
        return true;
    }

    int sign = 0;
    int lastValue = A[0];
    for(size_t i = 1; i < A.size(); ++i) {
        auto s = sgn(lastValue - A[i]);
        lastValue = A[i];

        if (s == 0) continue;

        if (sign == 0) {
            sign = s;
            continue;
        }

        if (sign != s) return false;
    }

    return true;
}
