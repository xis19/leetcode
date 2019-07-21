#include <algorithm>
#include <vector>

int twoSumLessThanK(std::vector<int>& A, int K) {
    const int LEN = A.size();
    std::sort(A.begin(), A.end());
    int max = -1;
    for (auto i = LEN - 1; i > 0; --i) {
        const int V = A[i];
        if (V > K) continue;

        // We need the value strictly less than K
        int diff = K - V - 1;
        // upper_bound will find values larger than a given value
        auto iter = std::upper_bound(A.begin(), A.begin() + i, diff);
        if (iter == A.begin()) continue;
        max = std::max(max, *(iter - 1) + V);
    }

    return max;
}
