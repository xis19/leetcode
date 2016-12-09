#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> result(2, 0);

    for(size_t i = 0; i < nums.size() - 1; ++i)
        for(size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return std::vector<int>{static_cast<int>(i), static_cast<int>(j)};
            }
        }

    return std::vector<int>();
}
