#include <algorithm>
#include <vector>

int triangleNumber(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    int total(0);
    for (auto iter0 = nums.begin(); iter0 < nums.end() - 2; ++iter0) {
        for (auto iter1 = std::next(iter0); iter1 < nums.end() - 1; ++iter1) {
            const int S = *iter0 + *iter1;
            auto iter2 = std::lower_bound(std::next(iter1), nums.end(), S);
            total += iter2 - iter1 - 1;
        }
    }

    return total;
}

