#include <array>

int uniquePathsOverflow(int m, int n) {
    // C(m, m + n) = (m + n)! / (m! n!)
    // Note the robot is inside the cell, not on the border of the cell
    --m; --n;
    long result = 1;
    for(int i = m + n; i > m; --i) result *= i;
    for(int i = 1; i <= n; ++i) result /= i;
    return result;
}

// DP approach, avoid the overflow problem
int uniquePaths(int m, int n) {
    static const int MAX_DIM = 100;
    static std::array<std::array<int, MAX_DIM>, MAX_DIM> DP;
    static bool initialized(false);
    if (!initialized) {
        for(int i = 0; i < MAX_DIM; ++i) DP[i][0] = 1, DP[0][i] = 1;
        for(int i = 1; i < MAX_DIM; ++i)
            for(int j = 1; j < MAX_DIM; ++j)
                DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
    }

    return DP[m - 1][n - 1];
}
