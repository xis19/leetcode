#include <algorithm>
#include <vector>

std::vector<int> sortedSquares(std::vector<int>& A) {
    std::transform(A.begin(), A.end(), A.begin(), [&](int i) -> int { return i * i; });
    std::sort(A.begin(), A.end());
    return A;
}
