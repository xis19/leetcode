#include <vector>

int search(const std::vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    while(hi > lo) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > target) {
            hi = mid - 1;
        } else if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            return mid;
        }
    }
    return nums[lo] == target ? lo : -1;
}
