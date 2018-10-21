#include <vector>


int surfaceArea(const std::vector<std::vector<int>>& grid) {
    // We count all surface area minus the overlapping parts
    const int SIZE = grid.size();

    int surface = 0;
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            // Note -- a tower with height 0 is not counted
            if (grid[i][j])
                surface += grid[i][j] * 4 + 2;
            if (i != 0) surface -= std::min(grid[i - 1][j], grid[i][j]) * 2;
            if (j != 0) surface -= std::min(grid[i][j - 1], grid[i][j]) * 2;
        }
    }

    return surface;
}
