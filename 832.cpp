#include <algorithm>
#include <vector>

std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A) {
    for(auto& row: A) {
        std::transform(row.begin(), row.end(), row.begin(), [](int& value) { return !value; });
        std::reverse(row.begin(), row.end());
    }
    return A;
}
