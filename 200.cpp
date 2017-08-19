#include <functional>
#include <vector>

int numIslands(std::vector<std::vector<char>>& grid) {
    const int M = grid.size();
    if (M == 0) return 0;
    const int N = grid[0].size();
    if (N == 0) return 0;

    std::function<void(int, int)> explore = [&explore, M, N, &grid](int x, int y) {
        if (x < 0 || y < 0 || x >= M || y >= N || grid[x][y] == '0') return;
        grid[x][y] = '0';
        explore(x - 1, y);
        explore(x, y - 1);
        explore(x + 1, y);
        explore(x, y + 1);
    };
    int result(0);
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if (grid[i][j] == '1') {
                ++result;
                explore(i, j);
            }
        }
    }
    return result;
}
