#include <cstdlib>
#include <vector>

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    // We use the index of the array to store the existing values
    const int N = nums.size();
    for(int i = 0; i < N; ++i) {
        auto absValue = std::abs(nums[i]) - 1;
        if (nums[absValue] > 0) nums[absValue] *= -1;
    }
    std::vector<int> result;
    for(int i = 0; i < N; ++i) if (nums[i] > 0) result.push_back(i + 1);
    return result;
}

