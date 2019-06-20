#include <cmath>
#include <vector>

int fistMissingPositive(std::vector<int>& nums) {
    // The point is to use the array index to flag the value
    // Assume the index start with l

    const int LEN = nums.size();

    // First we remove all negative items with LEN + 1, so every value is positive
    for (auto& v: nums) if (v <= 0) v = LEN + 1;

    // Now we enumerate all values, if the value is between 1 and LEN, we mark
    // it negative, or "not missing"
    for (int i = 0; i < LEN; ++i) {
        const int value = std::abs(nums[i]);
        if (value <= LEN) {
            if (nums[value - 1] > 0) nums[value - 1] *= -1;
        }
    }

    // Now we find first non-negative index
    for (int i = 0; i < LEN; ++i) {
        if (nums[i] > 0) return i + 1;
    }

    return LEN + 1;
}
