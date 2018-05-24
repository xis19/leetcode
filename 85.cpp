#include <limits>
#include <vector>

int maximalRectangle(const std::vector<std::vector<char>>& matrix) {
    // For each cell, if it is 0, we ignore, if it is 1, we will find its
    // 1s and check any rows above it.
    //
    //
    // e.g.
    //     ["1","0","1","0","0"]
    //     ["1","0","1","1","1"]
    //     ["1","1","1","1","1"]
    //     ["1","0","0","1","0"]
    //
    // we get
    //
    //     [ 1   0   1   0   0 ]
    //     [ 1   0   1   2   3 ]
    //     [ 1   2   3   4  *5*]
    //     [ 1   0   0   1   0 ]
    //
    // and for each non-zero cell, we check for the previous rows.
    //
    //   *5*    check row 2 --> a rectangle with area 5
    //          check row 1 --> a rectangle with area min(5, 3) * 2 = 6
    //          check row 0 --> a rectangle with area min(5, 3, 0) * 3 = 0
    //
    const int RR = matrix.size();
    if (RR == 0) return 0;
    const int CC = matrix[0].size();
    std::vector<std::vector<int>> dp(RR, std::vector<int>(CC, 0));
    int maxRect = 0;

    for(int i = 0; i < RR; ++i) {
        for(int j = 0; j < CC; ++j) {
            if (matrix[i][j] == '0') continue;

            if (j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i][j - 1] + 1;
            }

            // Now we check the max rectangle
            int minWidth = std::numeric_limits<int>::max();
            for(int r = i; r >= 0; --r) {
                minWidth = std::min(dp[r][j], minWidth);
                if (minWidth == 0) break;
                maxRect = std::max(maxRect, minWidth * (i - r + 1));
            }
        }
    }

    return maxRect;
}
