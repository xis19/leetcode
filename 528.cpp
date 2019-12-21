#include <map>
#include <random>
#include <vector>

class Solution {
    std::random_device device;
    std::mt19937 mt19937;
    std::uniform_int_distribution<> distribution;

    std::map<int, int> prefixSum;
public:
    Solution(const std::vector<int>& w): mt19937(device()) {
        // Modified version of reservoir sampling could be slow as you will need
        // to traverse all the elements of weights.
        // Prefix sum approach could be faster
        const int L = w.size();
        int sum = 0;
        for (int i = 0; i < L; ++i) {
            prefixSum[sum] = i;
            sum += w[i];
        }
        prefixSum[sum + 1] = L;
        distribution.param(decltype(distribution.param())(0, sum - 1));
    }

    int pickIndex() {
        auto value = distribution(mt19937);
        return std::prev(prefixSum.upper_bound(value))->second;
    }
};
