#include <vector>

bool isToeplitzMatrix(const std::vector<std::vector<int>>& matrix) {
    const int RR = matrix.size();
    if (RR == 0) return true;
    const int CC = matrix[0].size();

    for(int i = 0; i < CC; ++i) {
        int val = matrix[0][i];
        for(int j = i + 1, r = 1; j < CC && r < RR; ++j, ++r) {
            if (matrix[r][j] != val) {
                return false;
            }
        }
    }

    for(int i = 1; i < RR; ++i) {
        int val = matrix[i][0];
        for(int j = i + 1, c = 1; j < RR && c < CC; ++j, ++c) {
            if (matrix[j][c] != val) {
                return false;
            }
        }
    }
    return true;
}
