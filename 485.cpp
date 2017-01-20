#include <vector>

int findMaxConsecutiveOnes(const std::vector<int>& nums) {
    int longest = 0;
    int currentCount = 0;
    for(auto i: nums) {
        if (i == 1) {
            ++currentCount;
        } else {
            longest = std::max(longest, currentCount);
            currentCount = 0;
        }
    }
    longest = std::max(longest, currentCount);
    return longest;
}
