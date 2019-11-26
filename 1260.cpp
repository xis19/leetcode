#include <utility>
#include <vector>

std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int k) {
    // Well, if it is in C, there is a much easier solution as you could
    // directly access memory
    const int ROW = grid.size();
    const int COL = grid[0].size();
    const int NELEMS = ROW * COL;

    std::vector<std::vector<int>> result(ROW, std::vector<int>(COL, 0));

    std::pair<int, int> writeCursor{0, 0};
    std::pair<int, int> readCursor{0, 0};

    auto movePrev = [ROW, COL](std::pair<int, int>& cursor) {
        --cursor.second;
        if (cursor.second == -1) {
            --cursor.first;
            cursor.second = COL - 1;
        }
        if (cursor.first == -1) {
            cursor.first = ROW - 1;
        }
    };

    auto moveNext = [ROW, COL](std::pair<int, int>& cursor) {
        ++cursor.second;
        if (cursor.second == COL) {
            ++cursor.first;
            cursor.second = 0;
        }
        if (cursor.first == ROW) {
            cursor.first = 0;
        }
    };

    for (int i = 0; i < k; ++i) {
        movePrev(readCursor);
    }


    for (int i = 0; i < NELEMS; ++i) {
        result[writeCursor.first][writeCursor.second] = grid[readCursor.first][readCursor.second];
        moveNext(writeCursor);
        moveNext(readCursor);
    }

    return result;
}
