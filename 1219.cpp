#include <functional>
#include <unordered_set>
#include <utility>
#include <vector>


int getMaximumGold(const std::vector<std::vector<int>>& grid) {
    const int M = grid.size();
    const int N = grid[0].size();
    const int DIRS[4][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    int maxAmount = 0;
    int gold = 0;
    std::unordered_set<int> visitedMap;
    auto hash = [](const int y, const int x) -> int { return y * 100 + x; };
    std::function<void(int, int)> traverse = [&](const int y, const int x) {
        auto h = hash(y, x);
        if (y < 0 || x < 0 || y >=M || x >= N || grid[y][x] == 0 ||
                visitedMap.find(h) != visitedMap.end())
            return;

        visitedMap.insert(h);
        gold += grid[y][x];
        maxAmount = std::max(gold, maxAmount);
        for (int _ = 0; _ < 4; ++_) {
            traverse(y + DIRS[_][0], x + DIRS[_][1]);
        }
        gold -= grid[y][x];
        visitedMap.erase(h);
    };

    for (int y = 0; y < M; ++y) {
        for (int x = 0; x < N; ++x) {
            traverse(y, x);
        }
    }

    return maxAmount;
}

