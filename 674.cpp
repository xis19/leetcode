#include <vector>

int findLengthOfLCIS(const std::vector<int>& nums) {
    const int SIZE = nums.size();
    if (SIZE == 0) return 0;

    int maxLen(0), currLen(1);
    int last(nums[0]);
    for(int i = 1; i < SIZE; ++i) {
        if (nums[i] > last) {
            ++currLen;
        }
        else {
            maxLen = std::max(maxLen, currLen);
            currLen = 1;
        }
        last = nums[i];
    }
    maxLen = std::max(maxLen, currLen);
    return maxLen;
}
