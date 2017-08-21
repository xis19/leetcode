#include <vector>


int subarraySum(std::vector<int>& nums, int k) {
    // Solving a range of sum [i, j] = [0, j] - [0, i - 1]
    // the range of sum can be precalculated
    const int LEN = nums.size();
    if (LEN == 0) return 0;

    std::vector<int> v(LEN + 1);
    v[0] = 0;
    for(int i = 1; i <= LEN; ++i)
        v[i] = v[i - 1] + nums[i - 1];

    int result(0);
    for(int i = 1; i <= LEN; ++i) {
        for(int j = i; j <= LEN; ++j) {
            result += (v[j] - v[i - 1] == k);
        }
    }

    return result;
}
