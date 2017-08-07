#include <algorithm>
#include <cmath>
#include <vector>

int maximumProduct(std::vector<int>& nums) {
    // Either three biggest positives, or
    // two smallest negatives multiples
    // one positive
    const int LEN = nums.size();
    std::sort(nums.begin(), nums.end());
    return std::max(nums[LEN - 1] * nums[LEN - 2] * nums[LEN - 3],
                    nums[0] * nums[1] * nums[LEN - 1]);
}
