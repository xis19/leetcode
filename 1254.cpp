#include <queue>
#include <vector>

int closedIsland(std::vector<std::vector<int>>& grid) {
    const int ROW = grid.size();
    const int COL = grid[0].size();

    const int DIRECTIONS[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    auto isEdge = [ROW, COL](const int r, const int c) -> bool {
        return (r == 0 || r == ROW - 1 || c == 0 || c == COL - 1);
    };
    auto isOut = [ROW, COL](const int r, const int c) -> bool {
        return (r < 0 || r >= ROW || c < 0 || c >= COL);
    };

    int result = 0;
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (grid[i][j] != 0) {
                continue;
            }

            std::queue<int> rQueue;
            std::queue<int> cQueue;
            rQueue.push(i);
            cQueue.push(j);
            grid[i][j] = -1;
            bool reachEdge = false;
            while(!rQueue.empty()) {
                auto r0 = rQueue.front();
                auto c0 = cQueue.front();
                rQueue.pop();
                cQueue.pop();
                reachEdge |= isEdge(r0, c0);

                for (int _ = 0; _ < 4; ++_) {
                    auto r1 = r0 + DIRECTIONS[_][0];
                    auto c1 = c0 + DIRECTIONS[_][1];
                    if (isOut(r1, c1) || grid[r1][c1] != 0) {
                        continue;
                    }
                    grid[r1][c1] = -1;
                    rQueue.push(r1);
                    cQueue.push(c1);
                }
            }

            if (!reachEdge) ++result;
        }
    }

    return result;
}
