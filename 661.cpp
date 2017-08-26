#include <vector>

std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& M) {
    static const std::vector<std::vector<int>> RANGE = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

    std::vector<std::vector<int>> result;
    const int R = M.size();
    const int C = M[0].size();

    result.resize(R);
    for(auto& i: result) i.resize(C);


    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            int value(M[i][j]), neighbors(0);
            for(auto& item: RANGE) {
                int u(i + item[0]), v(j + item[1]);
                if (u < 0 || u >= R || v < 0 || v >= C) continue;
                ++neighbors;
                value += M[u][v];
            }
            result[i][j] = value / (neighbors + 1);
        }
    }

    return result;
}
