#include <algorithm>
#include <limits>
#include <vector>


int minFallingPathSum(const std::vector<std::vector<int>>& A) {
    // A squared matrix
    const int N = A.size();
    if (N == 0) return 0;

    std::vector<std::vector<int>> dp(N, std::vector<int>(N));
    std::copy(A[0].begin(), A[0].end(), dp[0].begin());

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int lt = j == 0 ? std::numeric_limits<int>::max() :
                dp[i - 1][j - 1];
            int rt = j == N - 1 ? std::numeric_limits<int>::max() :
                dp[i - 1][j + 1];
            int ab = dp[i - 1][j];
            dp[i][j] = A[i][j] + std::min(lt, std::min(rt, ab));
        }
    }

    return *std::min_element(dp.back().begin(), dp.back().end());
}

