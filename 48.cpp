#include <algorithm>
#include <vector>

void rotate(std::vector<std::vector<int>>& matrix) {
    const int N = matrix.size();
    for(int r = 1; r < N; ++r)
        for(int c = 0; c < r; ++c)
            std::swap(matrix[r][c], matrix[c][r]);

    for(auto& v : matrix)
        std::reverse(std::begin(v), std::end(v));
}
