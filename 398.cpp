#include <random>
#include <vector>

class Solution {
    const std::vector<int> nums;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution;
public:
    Solution(const std::vector<int>& input) : nums(input), distribution(0, 1) {
        
    }
    
    int pick(int target) {
        int count = 0;
        int result = -1;
        for(int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] != target) continue;
            ++count;
            if (distribution(generator) < 1.0 / count) {
                result = i;
            }
        }
        return result;
    }
};
