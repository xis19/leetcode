#include <algorithm>
#include <functional>
#include <vector>
#include <utility>

int maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid) {
    auto maxi = [](int i, int j) { return i > j ? i : j; };

    const int NROWS = grid.size();
    if (NROWS == 0) return 0;
    const int NCOLS = grid[0].size();
    if (NCOLS == 0) return 0;

    std::vector<int> topBottom(NCOLS, 0);
    for(const auto& row: grid) {
        std::transform(
            std::begin(row),
            std::end(row),
            std::begin(topBottom),
            std::begin(topBottom),
            maxi
        );
    }

    std::vector<int> leftRight(NROWS, 0);
    for(int i = 0; i < NROWS; ++i) {
        leftRight[i] = *std::max_element(std::begin(grid[i]), std::end(grid[i]));
    }

    int incr(0);
    for(int i = 0; i < NROWS; ++i) {
        for(int j = 0; j < NCOLS; ++j) {
            incr += std::min(topBottom[j], leftRight[i]) - grid[i][j];
        }
    }

    return incr;
}
