#include <vector>

void setZeroes(std::vector<std::vector<int>>& matrix) {
    // We use the first row and first column to record rows/columns to be
    // cleared.
    //
    //      1 1 1 1
    //      1 0 1 1
    //      1 1 1 1
    //      1 0 1 1
    //
    // will be transformed to
    //
    //      1 0 1 1
    //      0 0 1 1
    //      1 1 1 1
    //      0 0 1 1
    //
    // and we traverese the first row/column and clear the corresponding
    // rows/columns. For 0s in the first row/column, we use a bool flag.
    const int M = matrix.size();
    if (M == 0) return;
    const int N = matrix[0].size();
    if (N == 0) return;

    bool clearFirstRow(false), clearFirstColumn(false);

    for(int i = 0; i < M; ++i) {
        if (matrix[i][0] == 0) {
            clearFirstColumn = true;
            break;
        }
    }
    for(int i = 0; i < N; ++i) {
        if (matrix[0][i] == 0) {
            clearFirstRow = true;
            break;
        }
    }

    for(int i = 1; i < M; ++i) {
        for(int j = 1; j < N; ++j) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for(int i = 1; i < M; ++i) {
        if (matrix[i][0] == 0) {
            std::fill(std::next(matrix[i].begin()), matrix[i].end(), 0);
        }
    }

    for(int i = 1; i < N; ++i) {
        if (matrix[0][i] == 0) {
            for(int j = 1; j < M; ++j) {
                matrix[j][i] = 0;
            }
        }
    }

    if (clearFirstRow) std::fill(matrix[0].begin(), matrix[0].end(), 0);
    if (clearFirstColumn) for (int i = 0; i < M; ++i) matrix[i][0] = 0;

    return;
}
