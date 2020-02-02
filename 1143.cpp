#include <string>
#include <vector>


int longestCommonSubsequence(const std::string& text1, const std::string& text2) {
    const int LEN1 = text1.size();
    const int LEN2 = text2.size();
    if (LEN1 == 0 || LEN2 == 0) return 0;

    std::vector<std::vector<int>> dp(LEN2, std::vector<int>(LEN1, 0));

    for (int x = 0; x < LEN1; ++x) {
        for (int y = 0; y < LEN2; ++y) {
            if (text1[x] == text2[y]) {
                if (x >= 1 && y >= 1) {
                    dp[y][x] = dp[y - 1][x - 1] + 1;
                } else {
                    dp[y][x] = 1;
                }
            } else {
                dp[y][x] = std::max(
                    x >= 1 ? dp[y][x - 1] : 0,
                    y >= 1 ? dp[y - 1][x] : 0
                );
            }
        }
    }

    return dp.back().back();
}
