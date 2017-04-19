#include <vector>

template <typename T>
using vector = std::vector<T>;

vector<int> findDuplicates(vector<int>& nums) {
    const int N = nums.size();
    if (N == 0) {
        return vector<int>{};
    }

    vector<int> result;
    for(auto c: nums) {
        // NOTE: since 1 <= nums[i] <= N, when we have N, the modulus goes to
        // 0, otherwise the modolus makes it goes to the original value.
        int value = c % N;
        nums[value] += N;
    }

    for(auto i = 1; i < N; ++i) {
        // If nums[i] == N and occurred once, it would be 2 * N which is a
        // corner case. And we have nums[i] >= 1...
        if ((nums[i] - 1) / N == 2) {
            result.push_back(i);
        }
    }
    if ((nums[0] - 1) / N == 2) {
        result.push_back(N);
    }

    return result;
}
