#include <algorithm>
#include <vector>

int maxArea(const std::vector<int>& height) {
    // We scan from the left to right
    //
    //              ##........
    //      ##......####..##..
    //  ##..####..############
    // ------------------------
    //
    // Then scan from right to left
    //
    //              ##
    //      ##......####..##
    //  ##..####..############
    // ------------------------
    //
    // Then evaluate rain water volume.

    const int LEN = height.size();
    std::vector<int> trap(height.size(), 0);
    int maxHeight = 0;

    // Left to right
    for(int i = 0; i < LEN; ++i) {
        maxHeight = std::max(maxHeight, height[i]);
        trap[i] = maxHeight;
    }

    // Right to left;
    maxHeight = 0;
    for(int i = LEN - 1; i >= 0; --i) {
        maxHeight = std::max(maxHeight, height[i]);
        trap[i] = std::min(trap[i], maxHeight);
    }

    // Accumulate
    int sum = 0;
    for(int i = 0; i < LEN; ++i) {
        sum += trap[i] - height[i];
    }

    return sum;
}
