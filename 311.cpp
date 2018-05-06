#include <unordered_map>
#include <vector>


typedef std::vector<std::vector<int>> matrix;

matrix multiply(const matrix& A, const matrix& B) {
    // By Row
    std::unordered_map<int, std::unordered_map<int, int>> AxRow;
    // By Col
    std::unordered_map<int, std::unordered_map<int, int>> BxCol;

    // Translate AxRow
    for(size_t i = 0; i < A.size(); ++i) {
        for(size_t j = 0; j < A[0].size(); ++j) {
            if (A[i][j] != 0) {
                AxRow[i][j] = A[i][j];
            }
        }
    }

    // Translate BxCol
    for(size_t i = 0; i < B[0].size(); ++i) {
        for(size_t j = 0; j < B.size(); ++j) {
            if (B[j][i] != 0) {
                BxCol[i][j] = B[j][i];
            }
        }
    }

    // Product
    matrix result(A.size(), std::vector<int>(B[0].size(), 0));
    for(size_t i = 0; i < A.size(); ++i) {
        for(size_t j = 0; j < B[0].size(); ++j) {
            for(const auto& ri: AxRow[i]) {
                if (BxCol[j].find(ri.first) != BxCol[j].end()) {
                    result[i][j] += ri.second * BxCol[j][ri.first];
                }
            }
        }
    }
    return result;
}

