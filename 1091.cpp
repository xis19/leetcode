#include <queue>
#include <tuple>
#include <unordered_set>
#include <vector>

int shortestPathBinaryMatrix(const std::vector<std::vector<int>>& grid) {
    const int R = grid.size();
    const int C = grid[0].size();
    const int DIRS[8][2] = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}
    };
    auto hash = [](int i, int j) { return i * 1000 + j; };

    // Corner case -- grid[0][0] == 1, then it is unreachable.
    if (grid[0][0] == 1) return -1;

    // (i, j) -> dist
    std::queue<std::tuple<int, int, int>> path;
    std::unordered_set<int> visitMark;
    path.push(std::make_tuple(0, 0, 1));
    visitMark.insert(hash(0, 0));
    while(!path.empty()) {
        auto t = path.front();
        path.pop();

        auto i = std::get<0>(t);
        auto j = std::get<1>(t);
        auto dist = std::get<2>(t);

        if (i == R - 1 && j == C - 1) {
            // Since we are using BFS, we will always get the shortest distance
            // when we reach the place
            return dist;
        }

        for (int _ = 0; _ < 8; ++_) {
            auto di = DIRS[_][0], dj = DIRS[_][1];
            auto ni = i + di, nj = j + dj;
            auto h = hash(ni, nj);
            if (ni < 0 || nj < 0 || ni >= R || nj >= R || grid[ni][nj] == 1 ||
                    visitMark.find(h) != visitMark.end()) {
                continue;
            }
            visitMark.insert(h);
            path.push(std::make_tuple(ni, nj, dist + 1));
        }
    }

    return -1;
}
