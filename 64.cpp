#include <vector>

int minPathSum(const std::vector<std::vector<int>>& grid) {
    const int M = grid.size();
    const int N = grid[0].size();
    std::vector<std::vector<int>> DP(M);
    for(auto& i: DP) i.resize(N);

    DP[0][0] = grid[0][0];

    for(int i = 1; i < M; ++i) DP[i][0] = DP[i - 1][0] + grid[i][0];
    for(int i = 1; i < N; ++i) DP[0][i] = DP[0][i - 1] + grid[0][i];

    for(int i = 1; i < M; ++i)
        for(int j = 1; j < N; ++j)
            DP[i][j] = std::min(DP[i][j - 1], DP[i - 1][j]) + grid[i][j];

    return DP.back().back();
}
