#include <cmath>
#include <limits>
#include <vector>

int findPeakElement(std::vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while(l < r) {
        int m = l + (r - l) / 2;
        int cmp = m >= static_cast<int>(nums.size()) ? 1 : copysign(1, nums[m] - nums[m + 1]);
        if (cmp == 1) {
            r = m;
        } else if (cmp == -1) {
            l = m + 1;
        }
    }
    return l;
}

