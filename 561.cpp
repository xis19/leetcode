#include <algorithm>
#include <vector>

int arrayPairSum(std::vector<int>& nums) {
    std::sort(std::begin(nums), std::end(nums));
    int sum = 0;
    for(decltype(nums.size()) i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
    }
    return sum;
}
