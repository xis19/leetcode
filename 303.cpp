#include <vector>


// s[i..j] = s[0..j] - s[0..i - 1]

class NumArray {
    std::vector<int> cache;
public:
    NumArray(std::vector<int> nums) : cache(nums.size()){
        if (nums.empty())
            return;
        cache[0] = nums[0];
        auto i = std::next(nums.begin()), j = std::next(cache.begin());
        for(; i < nums.end(); ++i, ++j) {
            *j = *std::prev(j) + *i;
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return cache[j];
        } else {
            return cache[j] - cache[i - 1];
        }
    }
};
