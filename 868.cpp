#include <algorithm>
#include <vector>

std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> &A)
{
    std::vector<std::vector<int>> result;

    if (A.size() == 0)
        return result;

    result.resize(A[0].size());
    for(auto& r: result) r.resize(A.size());

    for(size_t i = 0; i < A.size(); ++i) {
        for(size_t j = 0; j < A[0].size(); ++j) {
            result[j][i] = A[i][j];
        }
    }

    return result;
}
