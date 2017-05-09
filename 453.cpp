#include <algorithm>
#include <numeric>
#include <vector>

int minMoves(const std::vector<int>& nums) {
    // NOTE: Increase all element by 1 but one is equal to decrease one element
    // by 1.
    int min = *std::min_element(std::begin(nums), std::end(nums));
    return std::accumulate(
            std::begin(nums), std::end(nums), 0,
            [min](const int s, const int v) -> int {
        return s + v - min;
    });
}
