#include <algorithm>
#include <vector>

std::vector<int> findDiagonalOrder(const std::vector<std::vector<int>>& matrix) {
    // The original thought is simulation, but such approach may cause problems
    // when we meet corners. Noticing we can do a scan-per-diag-line.
    //      +-+     /-+
    //     1   2   3 /
    //    ^  /   /  /
    //     4   5   6
    //   /   /   /  v
    //  /  7   8   9
    //  +-/   +--/
    //  We can check diag starting with 1, 4, 7, 8, 9, reverse the order every
    //  other time

    const int R = matrix.size();
    if (R == 0) return std::vector<int>{};
    const int C = matrix[0].size();
    if (C == 0) return std::vector<int>{};
    std::vector<int> result;
    result.reserve(R * C);

    bool reverse = false;
    auto scan = [&reverse, &result, &matrix, C](int initX, int initY) {
        int x = initX, y = initY;
        int count = 0;
        while (x < C && y >= 0) {
            result.push_back(matrix[y][x]);
            --y, ++x, ++count;
        }
        if (reverse) {
            std::reverse(result.end() - count, result.end());
        }
        reverse = !reverse;
    };

    // Each row
    for (int i = 0; i < R; ++i) {
        scan(0, i);
    }

    // Each col
    for (int i = 1; i < C; ++i) {
        scan(i, R - 1);
    }

    return result;
}

