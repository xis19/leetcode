#include <vector>

int findNumberOfLIS(const std::vector<int>& nums) {
    const int LEN = nums.size();
    if (LEN == 0) return 0;
    if (LEN == 1) return 1;

    // Use DP approach, store the longest length ends at this position
    //  DP[i + 1] = max(DP[v] for v in [0:i] if nums[v] < nums[i]) + 1
    // Also store the number of longest lengths.
    std::vector<std::pair<int, int>> dp;
    dp.push_back(std::make_pair(1, 1));

    for (int i = 1; i < LEN; ++i) {
        int maxLen = 0;
        int maxLenCount = 1;
        for(int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                if (dp[j].first > maxLen) {
                    maxLen = dp[j].first;
                    maxLenCount = dp[j].second;
                } else if (dp[j].first == maxLen) {
                    maxLenCount += dp[j].second;
                }
            }
        }
        // including current element
        dp.push_back(std::make_pair(maxLen + 1, maxLenCount));
    }

    int maxLen(0), maxLenCount(0);
    for (const auto& i: dp) {
        if (i.first > maxLen) {
            maxLen = i.first;
            maxLenCount = i.second;
        } else if (i.first == maxLen) {
            maxLenCount += i.second;
        }
    }

    return maxLenCount;
}
