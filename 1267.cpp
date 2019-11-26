#include <queue>
#include <utility>
#include <vector>

int countServers(std::vector<std::vector<int>>& grid) {
    const int RR = grid.size();
    const int CC = grid[0].size();

    std::vector<int> rowServerCount(RR, 0);
    std::vector<int> colServerCount(CC, 0);

    for (int i = 0; i < RR; ++i) {
        for (int j = 0; j < CC; ++j) {
            if (grid[i][j] != 0) {
                ++rowServerCount[i];
                ++colServerCount[j];
            }
        }
    }

    int result(0);
    for (int i = 0; i < RR; ++i) {
        for (int j = 0; j < CC; ++j) {
            if (grid[i][j] != 0 && (rowServerCount[i] > 1 || colServerCount[j] > 1)) {
                ++result;
            }
        }
    }

    return result;
}
