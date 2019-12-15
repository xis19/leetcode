#include <algorithm>
#include <limits>
#include <vector>

std::vector<int> sortTransformedArray(std::vector<int>& nums, int a, int b, int c) {
    bool flip = false;
    if (a > 0) {
        flip = true;
        a = -a;
        b = -b;
        c = -c;
    }

    std::vector<int> evaluated(nums.size());
    std::transform(nums.begin(), nums.end(), evaluated.begin(),
            [a, b, c](int v) {
                return (a * v + b) * v + c;
            });

    auto left = evaluated.begin();
    auto right = std::prev(evaluated.end());

    std::vector<int> result;
    while(left <= right) {
        if (*left > *right) {
            result.push_back(*right);
            --right;
        } else {
            result.push_back(*left);
            ++left;
        }
    }

    if (flip) {
        std::transform(result.begin(), result.end(), result.begin(), [](int v) { return -v; });
        std::reverse(result.begin(), result.end());
    }

    return result;
}
