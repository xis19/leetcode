#include <limits>
#include <vector>

int maxSubArraySlow(const std::vector<int>& nums) {
    // Naive solution, O(n^2)
    const int LEN = nums.size();
    int max = std::numeric_limits<int>::min();
    for(int i = 0; i < LEN; ++i) {
        int sum = 0;
        for(int j = i; j < LEN; ++j) {
            sum += nums[j];
            if (sum > max) max = sum;
        }
    }
    return max;
}

int maxSubArray(const std::vector<int>& nums) {
    // The idea is divide the array into parts.
    // -2, 1, -3, 4, -1, 2, 1, -5, 4
    //     ^
    // start from one number,
    //      sum = 1
    // -2, 1, -3, 4, -1, 2, 1, -5, 4
    //         ^
    //      sum = -2
    // In this case, [1, -3] should no longer contribute to the max sum as
    // the sum of this region is negative.
    // -2, 1, -3, 4, -1, 2, 1, -5, 4
    //            ^
    //      sum = 4
    // -2, 1, -3, 4, -1, 2, 1, -5, 4
    //                ^
    //      sum = 3
    // [4, -1] might still be part of the max sum since it is contributing
    // positive value.
    //
    // [-2], [1, -3], [4, -1, 2, 1, -5, 4]
    //
    // and find max sum inside each part.
    const int LEN = nums.size();
    int max = std::numeric_limits<int>::min();

    for(int i = 0; i < LEN; ++i) {
        int sum = 0;
        while(i < LEN) {
            sum += nums[i];
            max = std::max(max, sum);
            if (sum < 0) break; else ++i;
        }
    }

    return max;
}
