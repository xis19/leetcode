#include <unordered_set>
#include <vector>


int countCornerRectangles(std::vector<std::vector<int>>& grid) {
    // Of course, brutal force is useful
    // Here we store 1s in each row and col
    const int ROWS = grid.size();
    const int COLS = grid[0].size();
    // Store the column index for 1s in given row
    std::vector<std::unordered_set<int>> row1s(ROWS);
    // Store the row index for 1s in given column
    std::vector<std::unordered_set<int>> col1s(COLS);

    int count(0);
    for(int r = 0; r < ROWS; ++r) {
        for(int c = 0; c < COLS; ++c) {
            if (grid[r][c] == 0) continue;

            for(auto r1: row1s[r]) {
                for(auto c1: col1s[c]) {
                    if (grid[c1][r1] == 1) {
                        ++count;
                    }
                }
            }
            row1s[r].insert(c);
            col1s[c].insert(r);
        }
    }
    return count;
}
