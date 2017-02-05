#include <algorithm>
#include <vector>

int islandPerimeter(const std::vector<std::vector<int>>& grid) {
    const size_t M = grid.size();
    const size_t N = grid[0].size();

    int perimeter(0);

    for(size_t i = 0; i < M; ++i) {
        for(size_t j = 0; j < N; ++j) {
            if (grid[i][j]) {
                perimeter += 4;
                if (i != M - 1 && grid[i + 1][j]) perimeter -= 2;
                if (j != N - 1 && grid[i][j + 1]) perimeter -= 2;
            }
        }
    }

    return perimeter;
}
