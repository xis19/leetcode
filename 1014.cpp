#include <vector>

int maxScoreSightseeingPair(const std::vector<int>& A) {
    // A[i] + A[j] + i - j
    // to
    // (A[i] + i) + (A[j] - j)
    // thus, keep the maximum A[i] + i, and find minimum A[j] - j
    int maxPair = 0;
    int maxAii = A[0];

    for(int i = 1; i < static_cast<int>(A.size()); ++i) {
        maxPair = std::max(maxPair, maxAii + A[i] - i);
        maxAii = std::max(A[i] + i, maxAii);
    }

    return maxPair;
}
