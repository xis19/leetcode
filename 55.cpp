#include <functional>
#include <vector>

bool canJumpSlow(const std::vector<int>& nums) {
    // DP
    const int SITES = nums.size();
    std::vector<bool> reach(SITES);

    for(int i = SITES - 1; i >= 0; --i) {
        reach[i] = false;
        if (i + nums[i] >= SITES - 1) {
            reach[i] = true;
            continue;
        }
        for(int j = nums[i]; j > 0; --j) {
            if (reach[i + j]) {
                reach[i] = true;
                break;
            }
        }
    }

    return reach[0];
}

bool canJump(const std::vector<int>& nums) {
    // Greedy.
    const int N = nums.size();
    int soFar = 0;
    for(int i = 0; i <= soFar; ++i) {
        if ((soFar = std::max(soFar, i + nums[i])) >= N - 1)
            return true;
    }
    return false;
}
