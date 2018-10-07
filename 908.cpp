#include <algorithm>
#include <vector>

int smalletRangeI(const std::vector<int>& A, const int k) {
    const auto minMax = std::minmax_element(A.begin(), A.end());
    const int min = *minMax.first;
    const int max = *minMax.second;

    // Min should always no larger than max.
    if (max <= min + 2 * k) {
        return 0;
    }
    return max - min - 2 * k;
}
