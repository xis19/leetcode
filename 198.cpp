#include <algorithm>
#include <functional>
#include <vector>

int robSlow(const std::vector<int>& nums) {
    const int LEN = nums.size();
    std::function<int(int, int)> visitor = [&nums, &visitor, LEN](int index, int sum) -> int {
        if (index >= LEN) return sum;
        return std::max(visitor(index + 2, sum + nums[index]), visitor(index + 1, sum));
    };
    return visitor(0, 0);
}

int rob(const std::vector<int>& nums) {
    const int LEN = nums.size();
    if (LEN == 0) return 0;
    if (LEN == 1) return nums[0];
    if (LEN == 2) return std::max(nums[0], nums[1]);

    std::vector<int> DP(LEN);
    std::fill(DP.begin(), DP.end(), 0);

    DP[0] = nums[0];
    DP[1] = std::max(nums[0], nums[1]);
    for(int i = 2; i < LEN; ++i) {
        DP[i] = std::max(nums[i] + DP[i - 2], DP[i - 1]);
    }

    return *std::max_element(DP.begin(), DP.end());
}
