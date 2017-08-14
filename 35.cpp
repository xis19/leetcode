#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
    const int LEN = nums.size();
    if (LEN == 0) {
        return 0;
    }

    int hi = LEN, lo = 0, mid = (lo + (hi - lo) / 2);
    while(lo < hi) {
        if (nums[mid] > target) {
            hi = mid;
        } else if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            return mid;
        }
        mid = lo + (hi - lo) / 2;
    }
    return lo;
}
