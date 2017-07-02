#include <vector>

int uniquePathsWithObstacles(const std::vector<std::vector<int>>& obstacleGrid) {
    const int M = obstacleGrid.size();
    const int N = obstacleGrid[0].size();
    std::vector<std::vector<int>> DP(M);
    for(auto& i: DP) i.resize(N);

    bool blocked = false;
    for(int i = 0; i < M; ++i) blocked = blocked || obstacleGrid[i][0], DP[i][0] = blocked ? 0 : 1;
    blocked = false;
    for(int i = 0; i < N; ++i) blocked = blocked || obstacleGrid[0][i], DP[0][i] = blocked ? 0 : 1;

    for(int i = 1; i < M; ++i)
        for(int j = 1; j < N; ++j)
            DP[i][j] = obstacleGrid[i][j] ? 0 : (DP[i - 1][j] + DP[i][j - 1]);

    return DP.back().back();
}
