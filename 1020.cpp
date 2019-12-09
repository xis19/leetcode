#include <queue>
#include <vector>

int numEnclaves(std::vector<std::vector<int>>& A) {
    const int MOVE[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    const int RR = A.size();
    const int CC = A[0].size();

    int enclaves(0);
    auto atEdge = [RR, CC](int r, int c) -> bool {
        return r == 0 || r == RR - 1 || c == 0 || c == CC - 1;
    };
    auto outside = [RR, CC](int r, int c) -> bool {
        return r < 0 || r >= RR || c < 0 || c >= CC;
    };

    for(int i = 0; i < RR; ++i) {
        for(int j = 0; j < CC; ++j) {
            if (A[i][j] != 1) continue;

            std::queue<int> rQueue, cQueue;
            rQueue.push(i);
            cQueue.push(j);
            A[i][j] = -1;
            bool isEdgeAccessible = atEdge(i, j);
            int numBlocks(0);
            while (!rQueue.empty()) {
                int r = rQueue.front();
                int c = cQueue.front();
                rQueue.pop(); cQueue.pop();
                ++numBlocks;

                int testR, testC;
                for (auto _ = 0; _ < 4; ++_) {
                    testR = r + MOVE[_][0];
                    testC = c + MOVE[_][1];
                    if (outside(testR, testC)) continue;
                    if (A[testR][testC] != 1) continue;
                    A[testR][testC] = -1;
                    isEdgeAccessible = isEdgeAccessible || atEdge(testR, testC);
                    rQueue.push(testR); cQueue.push(testC);
                }

            }

            if (!isEdgeAccessible) {
                enclaves += numBlocks;
            }
        }
    }

    return enclaves;
}
