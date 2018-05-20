#include <unordered_map>
#include <vector>

int maxSubArrayLen(const std::vector<int>& nums, const int k) {
    const int LEN = nums.size();

    // For a given array, we can have an auxiliary array with value sum(nums[0]..nums[i])
    // for i-th element. We then can calculate the longest range by finding the minimum
    // index for value (aux[j] - k) inside aux.

    // Key: the sum value in aux
    // Value: the minimum index in aux for the given sum
    std::unordered_map<int, int> sumIndex;

    // If we want 0, it can be done by starting from the begining of array.
    sumIndex[0] = -1;

    int sum = 0;
    int longest = 0;
    for(int i = 0; i < LEN; ++i) {
        sum += nums[i];
        if (sumIndex.count(sum) == 0) {
            sumIndex[sum] = i;
        }
        if (sumIndex.count(sum - k) != 0) {
            longest = std::max(longest, i - sumIndex[sum - k]);
        }
    }

    return longest;
}
