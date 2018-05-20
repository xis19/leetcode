#include <limits>
#include <vector>


int minSubArrayLenSlow(int s, const std::vector<int>& nums) {
    const int LEN = nums.size();
    if (LEN == 0) return 0;

    int i = 0;
    int sum = 0;
    int minLen = std::numeric_limits<int>::max();

    for(int j = 1; j <= LEN; ++j) {
        sum += nums[j - 1];
        while(sum >= s && i <= j - 1) {
            minLen = std::min(minLen, j - i);
            sum -= nums[i++];
        }
    }

    if (minLen == std::numeric_limits<int>::max()) {
        return 0;
    }
    return minLen;

}


int minSubArrayLen(int s, const std::vector<int>& nums) {
    const int LEN = nums.size();
    if (LEN == 0) return 0;

    int i = 0;
    int minLen = std::numeric_limits<int>::max();

    for(int j = 1; j <= LEN; ++j) {
        s -= nums[j - 1];
        while(s <= 0 && i <= j - 1) {
            minLen = std::min(minLen, j - i);
            s += nums[i++];
        }
    }

    if (minLen == std::numeric_limits<int>::max()) {
        return 0;
    }
    return minLen;
}
