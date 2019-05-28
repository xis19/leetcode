#include <algorithm>
#include <utility>
#include <vector>

int deleteAndEarn(std::vector<int>& nums) {
    const int LEN = nums.size();
    if (LEN == 0) return 0;

    // Noticing that either you take *all* of a number, or not take it.
    // This is a "pick" or "drop" problem and can be solved using a direct DP
    // approach.
    std::sort(nums.begin(), nums.end());

    std::vector<std::pair<int, int>> count;
    for (auto n: nums) {
        if (count.size() == 0 || count.back().first != n) {
            count.push_back(std::make_pair(n, 1));
        } else {
            count.back().second++;
        }
    }

    const int COUNT_SIZE = count.size();

    // first -> maximum score if we take it
    // second -> maximum score if we ignore it
    std::vector<std::pair<int, int>> dp;
    dp.push_back(std::make_pair(count[0].first * count[0].second, 0));
    for (int i = 1; i < COUNT_SIZE; ++i) {
        auto& c = count[i];
        // If it is alone
        dp.push_back(std::make_pair(c.first * c.second, 0));
        if (c.first == count[i - 1].first + 1) {
            // If we pick this one, we have to drop the previous one
            dp[i].first += dp[i - 1].second;
        } else {
            dp[i].first += std::max(dp[i - 1].first, dp[i - 1].second);
        }
        dp[i].second += std::max(dp[i - 1].first, dp[i - 1].second);
    }

    return std::max(dp.back().first, dp.back().second);
}
