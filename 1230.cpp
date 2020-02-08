#include <vector>

double probabilityOfHeads(const std::vector<double>& prob, int target) {
    const int numCoins = prob.size();
    std::vector<std::vector<double>> dp(numCoins, std::vector<double>(target + 1, 0));

    dp[0][0] = 1 - prob[0];
    if (target > 0) dp[0][1] = prob[0];

    for (int i = 1; i < numCoins; ++i) {
        const double HEAD = prob[i];
        const double BACK = 1 - HEAD;
        for (int j = target; j > 0; --j) {
            dp[i][j] = dp[i - 1][j] * BACK + dp[i - 1][j - 1] * HEAD;
        }
        dp[i][0] = dp[i - 1][0] * BACK;
    }

    return dp.back()[target];
}
