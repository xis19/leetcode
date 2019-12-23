#include <vector>

int findLength(const std::vector<int>& A, const std::vector<int>& B) {
    // Stanard LCS
    const int L1 = A.size();
    const int L2 = B.size();
    std::vector<std::vector<int>> dp(L1, std::vector<int>(L2, 0));

    int maxLen = 0;
    for (int i = 0; i < L1; ++i) {
        for (int j = 0; j < L2; ++j) {
            if (A[i] != B[j]) {
                continue;
            }
            if (i >= 1 && j >= 1) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 1;
            }
            maxLen = std::max(maxLen, dp[i][j]);
        }
    }
    return maxLen;
}
